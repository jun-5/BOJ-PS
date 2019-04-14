#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool visit[10] = { false };
vector<int> v;

void dfs(int k) {
	
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i]<<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = k+1; i <= n; i++) {
		
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			visit[i] = false;

			dfs(k);
			visit[i] = false;
			v.pop_back();
			k++;
		
		}

	}


}


int main() {
	cin >> n >> m;
	dfs(0);

}
