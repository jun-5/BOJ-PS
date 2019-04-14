#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <math.h>


using namespace std;

deque<int> d[5];
void init();
void r_turn(deque<int>& q);
void l_turn(deque<int>& q);
void r_check(int right, int dir, int c);
void l_check(int left, int dir, int c);

//void arr_init(deque<int>& q,int j);
//int check_r(int a);
//int check_l(int a);
//int arr_r[5];
//int arr_l[5];

int main() {
	init();
	int K;
	cin >> K;
	int result = 0;
	for (int i = 0; i < K; i++) {
		int num, dir;
		cin >> num >> dir;

		int right = d[num][2];
		int left = d[num][6];

		if (dir == 1) {
			r_turn(d[num]);
		}

		else if (dir == -1) {

			l_turn(d[num]);
		}

		r_check(right, dir, num + 1);
		l_check(left, dir, num - 1);



	}


	for (int i = 1; i < 5; i++) {
		if (d[i].at(0) == 1) {
			result = result + pow(2, i - 1);

		}

	}
	cout << result;
		


	
	}



/*int main() {
	init();
	int K;
	cin >> K;
	int cnt_r=0;
	int cnt_l=0;
	for (int i = 0; i < K; i++) {
		int num;
		int dir;
		cin >> num >> dir;
		for (int j = 0; j < 4; j++) {
			arr_init(d[j+1], j);
		}

		
		cnt_r = check_r(num);
		cnt_l = check_l(num);
	
	
		if (dir == 1) {
			r_turn(d[num]);
			cout << "\n cnt_r,==" << cnt_r << "cnt_l"<<cnt_l<<endl;
			if (cnt_r == 1) { l_turn(d[num + 1]); }
			else if (cnt_r == 2) { l_turn(d[num + 1]); r_turn(d[num + 2]); }
			else if (cnt_r == 3) { l_turn(d[num + 1]); r_turn(d[num + 2]); l_turn(d[num + 3]); }

			if (cnt_l == 1) { l_turn(d[num - 1]); }
			else if (cnt_l == 2) { l_turn(d[num - 1]); r_turn(d[num - 2]); }
			else if (cnt_l == 3) { l_turn(d[num - 1]); r_turn(d[num - 2]); l_turn(d[num - 3]); }

		}

		else {
			l_turn(d[num]);

			cout << "\n cnt_r,==" << cnt_r << "cnt_l" << cnt_l << endl;
			if (cnt_r == 1) { r_turn(d[num + 1]); }
			else if (cnt_r == 2) { r_turn(d[num + 1]); l_turn(d[num + 2]); }
			else if (cnt_r == 3) { r_turn(d[num + 1]); l_turn(d[num + 2]); r_turn(d[num + 3]); }

			if (cnt_l == 1) { r_turn(d[num - 1]); }
			else if (cnt_l == 2) { r_turn(d[num - 1]); l_turn(d[num - 2]); }
			else if (cnt_l == 3) { r_turn(d[num - 1]); l_turn(d[num - 2]); r_turn(d[num - 3]); }

		}


	}
	
	int result = 0;
	int temp=1;
	for (int i = 1; i < 5; i++) {
		if (d[i].at(0) == 1) {
			result =result+ pow(2, i - 1);
		
		}

	}
	cout << result;

}
*/

void init() {

	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			int num;
			scanf("%1d", &num);
			d[i].push_back(num);
		}
	}

	/*for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d", d[i].at(j));
		}

		cout << endl;
	}
	*/

}

void r_turn(deque<int>& q) {
	int temp = q.back();
	q.pop_back();
	q.push_front(temp);
}

void l_turn(deque<int>& q) {
	int temp = q.front();
	q.pop_front();
	q.push_back(temp);

}

/*void arr_init(deque<int>& q,int j) {
	cout << "arr_r["<<j<<"]=" <<arr_r[j]<< endl;
	cout<< " arr_l["<<j<<"]=" <<arr_l[j]<<endl;
		arr_r[j] = q.at(2);
		arr_l[j] = q.at(6);
		cout << "arr_r[" << j << "]=" << arr_r[j] << endl;
		cout << " arr_l[" << j << "]=" << arr_l[j] << endl;
			cout << "けけけけけけけけけけけ" << endl;

	;
}
*/

/*
int check_r(int a) {
	int cnt_r=0;

	if (a == 4) { return cnt_r; }
	cout << "\n a=" << a << endl;

	for (int i = a; i < 4; i++) {
		//cout << "\n食奄左社arr " << i << "=" << arr_r[1] << "," << "arr_l[]" << i + i<<"="<< arr_l[2] << endl;

		if (arr_r[i] == arr_l[i + 1]) {
		//cout << "\ni==" << i << endl << arr_r[i] << "," << arr_l[i + 1] << endl;

	return cnt_r; }
		else {
			cnt_r++;
		}
	}
	return cnt_r;
}



int check_l(int a) {
	int cnt_l = 0;
	if (a == 1) { return cnt_l; }

	for (int i = a; i > 0; i--) {
//		cout << "\n i==" << i << endl;

	//	cout << "arr_[l],arr_r[i-1])" << arr_l[i] << ", " << arr_r[i - 1]<<endl;
		if (arr_l[i] == arr_r[i - 1]) { //cout << "return cnt_l"<<endl; 
		return cnt_l; }
		else {
	//		cout << "\n cnt_l++" << endl;
	//		cout << cnt_l;
			cnt_l++;
	//		cout << "   " << cnt_l;
		}
	//	cout << "斐五";
	}
	return cnt_l;
}*/
void l_check(int left, int dir, int c) {
	for (; c > 0; c--) {
		if (left == d[c][2]) {
			break;
		}
		if (dir == -1) {
			left = d[c][6];
			r_turn(d[c]);
			dir *= -1;
		
		}
		else {
			left = d[c][6];
			l_turn(d[c]);
			dir *= -1;

		
		}
	}


}
void r_check(int right, int dir, int c) {
	for (; c <= 4; c++) {
		if (right == d[c][6]) {
			break;
		}

		if (dir == -1) {
			right = d[c][2];
			r_turn(d[c]);
			dir *= -1;
		}
		else {
			right = d[c][2];
			l_turn(d[c]);
			dir *= -1;

		}

	}

}