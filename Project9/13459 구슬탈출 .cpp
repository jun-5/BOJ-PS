#include <cstdio>
#include <queue>
using namespace std;

struct bead {
	int rx, ry, bx, by, d;

};

int n, m;
char a[10][10];
bool check[10][10][10][10];
queue<bead> q;
const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

void move(int &x, int &y, int &c, int dx, int dy)
{
	while (a[x + dx][y + dx] = !'#' && a[x][y] != '0') 
	{
		x += dx;
		y += dy;
		c += 1;
	}
}
s
void bfs() 
{
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int d = q.front().d;
		q.pop();
		if (d >= 10)break;
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0;
			move(nrx, nry, rc, dx[i], dy[i]);
			move(nbx, nby, rc, dx[i], dy[i]);
			if (a[nbx][nby] == '0')continue;
			if (a[nrx][nry] == '0') {
				printf("1\n");
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}
			if (check[nrx][nry][nbx][nby])continue;
			check[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,d + 1 });
		}
	}

	printf("0\n");
}

int main() {
	scanf("%d %d", &n, &m);
	int rx = 0, ry = 0, bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1s", &a[i][j]);
			if (a[i][j] == 'R') rx = i, ry = j;
			else if (a[i][j] == 'B')bx = i, by = j;
		}
	}
	q.push({ rx,ry,bx,by,0 });
	check[rx][ry][bx][by] = true;
	bfs();
	return 0;
	

}

