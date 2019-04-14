#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool visit[10];
int n, m;

void dfs()
{
	if (v.size() == m)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {


		if (!visit[i])
		{
			v.push_back(i);
			dfs();
			v.pop_back();
		}




	}


}

int main() {
	cin >> n >> m;
	dfs();



}