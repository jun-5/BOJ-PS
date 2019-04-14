#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[10];
int n, m;
int visit[10];

void dfs() {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i]) {
			v.push_back(arr[i - 1]);
			dfs();
			v.pop_back();

		}



	}


}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + n);

	dfs();

}