#include <iostream>
using namespace std;
int num = 0;
void func(int a, int b, int n) {
	if (n == 1) { // a�� �ִ� ���� 1���� b�� �ű�⸸ �ϸ� ��
		cout << a << ' ' << b << ","<<n<<'\n';
		num++;
		return;
	}
	num++;
	int c = 6 - a - b; // a, b�� �ƴ� ������ ����� ��ȣ
	func(a, c, n - 1); // a�� �ִ� 1 to n-1��° ������ a���� c�� �̵�
	cout << a << ' ' << b << "," << n << '\n'; // a�� �����ִ� n��° ������ b�� �̵�
	func(c, b, n - 1); // c�� �ִ� 1 to n-1��° ������ c���� b�� �̵�
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 2�� n�� - 1
	func(1, 3, n);
	cout << "\n\n" << num;
}