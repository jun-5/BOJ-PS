#include <stdio.h>

int main(void) {
	int n = 10;
	int a = 1;
	int m;

	while (1) {

	
		m = (a > n / 2) ? a - (n / 2) : (n/2) - a + 1;
		for (int i = 1; i <= m; i++) {
			printf("*");
		}
		printf("\n");
		a = a + 1;
		if (a > n) { break; }
	
	
	}

}