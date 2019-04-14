#include<iostream>
#include<array>
#include<queue>

#define X first
#define Y second

int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };
int result[52] = {};

using namespace std;

int main() {
	int t_num, m, n, b_num;
	cin >> t_num;

	for (int z = 0; z < t_num; z++) {
		cin >> n >> m >> b_num;
		int i, j, k;
		int board[52][52] = { 0 };
		int vis[52][52] = { 0 };

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				board[i][j] = 0;
			}

		}
		for (k = 0; k < b_num; k++) {
			cin >> i >> j;
			board[i][j] = 1;

		}

		queue<pair<int, int>>q;
		int result_num = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (q.empty()) {
			//		cout << "\n" << board[i][j] << "," << vis[i][j] << endl;
					if (board[i][j] == 0) { continue; }
					if (vis[i][j] == 1) { continue; }
					q.push({ i,j });
					vis[i][j] = 1;
				//			cout<<"("<<i<<","<<j<<")"<<endl;
					result_num++;

				}

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (k = 0; k < 4; k++) {
						int nx = cur.X + dir_x[k];
						int ny = cur.Y + dir_y[k];

						if (nx < 0 or ny < 0 or nx >= n or ny >= m) { continue; }
						if (vis[nx][ny] == 1)continue;
						if (board[nx][ny] == 0) {
							continue;
						}
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}

				}



			}

		}
//		cout << result_num << "\n";



		result[z] = result_num;
	}	for (int i = 0; i < t_num; i++) {
			if (i == (t_num - 1)) {
				cout << result[i];
				continue;
			}
			cout << result[i] << "\n";
		}
	}
