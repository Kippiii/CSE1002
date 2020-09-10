#include <stdio.h>

int dec_to_bin(int);

int main(void) {
	int n;
	scanf("%d", &n);
	
	int count = 0;
	int tempn = n;
	while(!(tempn & 1) && tempn > 0) {
		tempn = tempn >> 1;
		count++;
	}
	
	printf("%d has %d trailing zeros\n", dec_to_bin(n), count);

	return 0;
}

//Taken from Task 2
int dec_to_bin(int n) {
	if(n <= 0)
		return 0;
	return (n & 1) + 10 * dec_to_bin(n >> 1);
}