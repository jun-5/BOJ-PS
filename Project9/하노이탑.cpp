#include <iostream>
using namespace std;
int num = 0;
void func(int a, int b, int n) {
	if (n == 1) { // a에 있는 원판 1개를 b로 옮기기만 하면 됨
		cout << a << ' ' << b << ","<<n<<'\n';
		num++;
		return;
	}
	num++;
	int c = 6 - a - b; // a, b가 아닌 나머지 기둥의 번호
	func(a, c, n - 1); // a에 있던 1 to n-1번째 원판을 a에서 c로 이동
	cout << a << ' ' << b << "," << n << '\n'; // a에 남아있던 n번째 원판을 b로 이동
	func(c, b, n - 1); // c에 있던 1 to n-1번째 원판을 c에서 b로 이동
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 2의 n승 - 1
	func(1, 3, n);
	cout << "\n\n" << num;
}