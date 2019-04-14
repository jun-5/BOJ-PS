	#include <iostream>
	#include <utility>
	#include <stack>
	#include <array>
	#include <algorithm>
	#include <stdio.h>

	#define X first
	#define Y second

	int dir_x [4]= { 1,0,-1,0 };
	int dir_y [4]= { 0,1,0,-1 };
	int board[27][27] ;
	int vis[27][27] = { 0 };
	int num = 0;
	int num_h[600];



	using namespace std;
	int main() {
		int cnt = 0;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &board[i][j]);
			}
		}


		stack<pair<int, int>>s;
		//출력순서 1. 총 단지수  2.각 단지내 집의 수를 오름차순으로 정렬하여 한줄에 하나씩 출력
		for (int i = 0; i < n; i++) {;

		for (int j = 0; j < n; j++) {
			if (s.empty()) {
				if (vis[i][j] == 1) { continue; }

				if (board[i][j] == 1) { s.push({ i,j }); num = 1; }
				vis[i][j] = 1;
	//			cout << "stack push(" << i << "," << j << ")==" << board[i][j] << endl;
			}	
			
	
				while (!s.empty()) {


					
					auto cur = s.top();
					s.pop();
					
			//	cout << "stack pop★(" << cur.X << "," << cur.Y << ")" << endl;
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dir_x[k];
						int ny = cur.Y + dir_y[k];

						if (nx < 0 or nx >= n or ny < 0 or ny >= n) { continue; }
						if (board[nx][ny] == 0 or vis[nx][ny] == 1) { continue; }
						s.push({ nx,ny });
					//	cout << "stack push2222(" << nx << ", " << ny << ")==" << board[nx][ny] << endl;
						vis[nx][ny] = 1;

						num++;

					}
				}
				if (num > 0) {
					num_h[cnt] = num; 
				
				//	cout << "num==" << num << endl;
			//	cout << "num_h[" << cnt << "]==" << num_h[cnt] << endl;
					num = 0;
					cnt++;

				}

			}
		}


		sort(num_h, num_h + cnt);

		//cout <<"cnt"<< cnt;
		cout << cnt;
		for (int i = 0; i < cnt; i++) {
			//cout << "\nnum_h["<<i<<"]" <<num_h[i] ;
			cout << "\n" << num_h[i];
		}
	



	}