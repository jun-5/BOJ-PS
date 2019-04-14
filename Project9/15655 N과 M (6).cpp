#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[10];
int n, m;
int visit[10];

void dfs(int k) {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}

	for (int i = k+1; i <= n; i++)
	{
		//if (v[i] > arr[i]) {continue;}
		if (!visit[i]) {
			v.push_back(arr[i - 1]);
			visit[i] = true;
			dfs(k+1);
			visit[i] = false;
			v.pop_back();
			k++;
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

	dfs(0);

}