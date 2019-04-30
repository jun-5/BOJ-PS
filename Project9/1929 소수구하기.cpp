#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
	int  m, n;
	cin >> m >> n;
	vector<int>v;
	for (int i = 0; i <=n; i++) {
		v.push_back(i);
	}
	for (int i =2 ; i <= n; i++) {
		for (int j = i * i; j <= n; j = j + i) {
			if (v[j] == 0) { continue; }
			v[j] = 0;
		}
	}
	vector<int> result;
	for (int i = m; i <= n; i++) {
		if (v[i] == 0) { continue; }
			result.push_back(i);
	}
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) { printf("%d", result[i]); return 0; }
		printf("%d\n", result[i]);
		
	}
	
	return 0;
}