#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
int main(void) {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	do {
		for (int it =0; it < m; it++) {
			cout << v[it] << " ";
		
		}
		cout << "\n";

	} while (next_permutation(v.begin(), v.end()));






}