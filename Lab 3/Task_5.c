#include <stdio.h>

int factorial(int);

int main(void) {
	int n, k;
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	
	printf("The solution is %d.\n", factorial(n) / factorial(k) / factorial(n - k));
	
	return 0;
}

int factorial(int n) {
	int solution = 1;
	for(int i = 2; i <= n; i++)
		solution *= i;
	return solution;
}