#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> arr;
int n, m;
int visit[10];

void dfs(int k) {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= arr.size(); i++)
	{
		if (!visit[i]) {
			v.push_back(arr[i - 1]);
			visit[i] = true;
			dfs(k+1);
			visit[i]=false;
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
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	  arr.erase(unique(arr.begin(), arr.end()), arr.end());

	 
	dfs(0);

}