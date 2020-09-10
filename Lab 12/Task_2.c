#include <stdio.h>

int dec_to_bin(int);

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%08d\n", dec_to_bin(n));

	return 0;
}

int dec_to_bin(int n) {
	if(n <= 0)
		return 0;
	return (n & 1) + 10 * dec_to_bin(n >> 1);
}