#include <iostream>
#include <vector>


using namespace std;

bool visit[10];
vector<int> v;
int a[10];
int n, m;

void dfs(int k) {

	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	for (int i = k + 1; i <= n; i++) {
		if (!visit[i]) {
			v.push_back(i);
			visit[i] = true;
			dfs(k+1 );
			v.pop_back();
			visit[i] = false;
			k++;
		}


	}



}



int main() {

	cin >> n >> m;
	
	dfs(0);


}


