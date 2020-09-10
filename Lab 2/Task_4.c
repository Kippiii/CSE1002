#include <stdio.h>

int main(void) {
	int n;
	printf("n = ");
	scanf("%d", &n);
	
	int length = 2 * n - 1;
	int box[length][length];
	
	for(int i = n; i > 0; i--) {
		for(int j = n - i; j < length - (n - i); j++) {
			box[n - i][j] = i;
			box[length - 1 - (n - i)][j] = i;
			
			box[j][n - i] = i;
			box[j][length - 1 - (n - i)] = i;
		}
	}
	
	for(int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++) {
			printf("%d", box[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}