#include <iostream>
#include <utility>
#include <array>
#include <queue>
#include <stdio.h>
#include <algorithm>


#define X first
#define Y second

int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };


using namespace std;
int vis[101][101] = {0};
int board[101][101] = {0};
int dis[101][101] = {0};
int main() {
	int num = 0;
	int n, m;
	cin >> n >> m;
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	
	queue<pair<int, int>>q;
	
	
		q.push({ 0,0 });
		vis[0][0] = 1;
		
			while (!q.empty()) {
				int a = q.size();
				num++;
				for(int i=0;i<a;i++){
				auto cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.X + dir_x[k];
					int ny = cur.Y + dir_y[k];

					if (nx >= n or nx < 0 or ny >= m or ny < 0) { continue; }
					if (board[nx][ny] == 0)continue;
					if (vis[nx][ny] == 1){continue;}// { cout << "\n여기는요vis["<<nx<<","<<ny<<"]="<<vis[nx][ny] << endl;
				

//					cout << "\n(" << dis[nx][ny] << "," << num << ")" << endl;
					if (dis[nx][ny] > 0) { dis[nx][ny] = min(dis[nx][ny], num); }
					else { dis[nx][ny] = num; }
					
		//			cout << "\n(" << dis[nx][ny] << "," << num << ")" << endl;
					q.push({ nx, ny });
					vis[nx][ny] = 1;
					dis[nx][ny] = num;
			//		cout << "\nnum=" << num << "dis==" << dis[nx][ny]<<"      "<<num<<"바퀴끝" << endl;
			//		if (dis[nx][ny] > 0) { dis[nx][ny] = min(dis[nx][ny], num); }
				//	else { dis[nx][ny] = num; }
					
				//	cout << "\n(" << nx << "," << ny << ")=" << dis[nx][ny]; 
				}
				}
			}
		

	
	
			int result = dis[n - 1][m - 1];
			result += 1;
	cout <<result;

}