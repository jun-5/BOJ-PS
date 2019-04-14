#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool arr[15][15];
int n;
int  check(int x, int y);
int cnt;

void dfs(int z) {

	if (z <= n) {
		for (int j = 0; j < n; j++) {
			if (check(z - 1, j) == 1) {
				arr[z - 1][j] = 1;
				dfs(z + 1);
				arr[z - 1][j] = 0;

			}
		}
	
	}
	else {
		cnt++;
	
	}
	return;
}
int check(int x, int y) {

	if (arr[x][y] == 1) { return 0; }
	
	for (int i = 0; i < n; i++) {
		if (arr[i][y] == 1) { return 0; }
	}
	int i = x;
	int j = y;

	while (0 <= (i--) && 0 <= (j--)) {
		if (arr[i][j] == 1)
			return 0;
	}

	i = x; j = y;
	while (0 <= (i--) && (j++) < n)
	{
		if (arr[i][j] == 1)
			return 0;
	}
	return 1;
}


int main() {
	cin >> n;

	dfs(1);
	cout << cnt;





}