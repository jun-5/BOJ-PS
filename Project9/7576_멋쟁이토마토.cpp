#include <iostream>
#include <array>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int board[1000][1000];
int vis[1000][1000]={0};

int main(void) {
	int n, m;
	int cnt = 0;
	int c = 0;
	cin >> m >> n;

	queue<pair<int, int>> Q;

	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == -1) {

					vis[i][j] = -1;
				}
			}
		}





	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				if (vis[i][j] != 1) {

					Q.push({ i,j });
					vis[i][j] = 1;
					//				cout << "push(" << i << "," << j << ")" << endl;

				}
			}
		}
	}

	//cout << "타임"<<endl;
	while (!Q.empty()) {
		int a = Q.size();
		cnt++;
		for (int i = 0; i < a; i++) {
			auto cur = Q.front();
			Q.pop();

			//cout << "\npop(" << cur.first << "," << cur.second << ")\n팝\n";


			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue; // 범위 밖일 경우 넘어감
			//	if (vis[nx][ny] == -1)  continue; 
		//		if (board[nx][ny] == -1) { vis[nx][ny] = 1; continue; }
				if (board[nx][ny] == 0 && vis[nx][ny] == 0) {
					//		cout << "\nboard[nx][ny]" << nx << "," << ny <<","<<board[nx][ny]<< endl;
					Q.push({ nx,ny }); vis[nx][ny] = true;
					//	cout << "push(" << nx << "," << ny << ")\n";

				}
			}

		}


		//cout << "\ncnt++"<<cnt<<endl;

	}
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j ++) {
			
			if (vis[i][j] == 0) { cout << -1; return 0; }

					
		}
	}
	cnt--;
	cout << cnt;



}
