#include <stdio.h>

int main(void) {
	for(int i = 0; i < 5; i++) {
		for(int j = 4; j >= 0; j--) {
			printf((j <= i) ? "*" : " ");
		}
		printf("\n");
	}
	
	return 0;
}