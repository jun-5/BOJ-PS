#include <iostream>
#include <array>
#include <memory.h>

using namespace std;
int n_1,n_2;
int visit_1[20001];
int cnt = 0;


int main() {
	int n, v, e;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v >> e;
		cnt = 0;
	

		for (int i = 0; i < e; i++) {
			cin >> n_1 >> n_2;

			if (visit_1[n_1] == 2) { continue; }
			else if (visit_1[n_2] == 1) {  continue; }
			else {
				visit_1[n_1] = 1;
				visit_1[n_2] = 2;
				cnt++;
			}
		}
			if (cnt == e ) {
				cout << "Yes\n";
			}
			else {
				cout << "NO\n";
			}
			memset(visit_1, 0, sizeof(visit_1));

		}
	}
