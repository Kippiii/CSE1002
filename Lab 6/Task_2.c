#include <stdio.h>

int is_prime(int, int);

int main(void) {
	int n;
	printf("n = ");
	scanf("%d", &n);
	
	printf("This number is%s prime!\n", (is_prime(n, 2) ? "" : " not"));

	return 0;
}

int is_prime(int prime, int current) {
	if(prime % current == 0)
		return 0;
	if(current > prime / 2)
		return 1;
	return is_prime(prime, current + 1);
}