#include <stdio.h>

int naive_add(int, int);

int main(void) {
	int n, m;
	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);
	
	printf("The sum is %d\n", naive_add(n, m));

	return 0;
}

int naive_add(int n, int m) {
	if(m == 0 && n == 1)
		return 1;
	else if(m==0)
		return 1 + naive_add(n - 1, m);
	
	return 1 + naive_add(n, m - 1);
}