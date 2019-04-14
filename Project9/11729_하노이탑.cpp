#include <iostream>

using namespace std;

int cnt;
void recursion(int a,int b,int c) {
	if (c == 1) {
		cout << a << " " << b << "\n";
		return;
	}

	//1번에 있는 원판을 3번으로 3개옮긴다
	recursion(a, 6 - a - b, c-1);
	cout << a << " " << b << "\n";
	recursion(6 - a - b, b, c - 1);


}



int main() {
	int num;
	cin >> num;
	cout << (1 << num) - 1 << "\n";
	recursion(1, 3, num);
	


}

