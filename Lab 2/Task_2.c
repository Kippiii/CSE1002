#include <stdio.h>

#define SENTINEL 0

int main(void) {
	int sum = 0;
	int value;
	scanf("%d", &value);
	
	while(value != SENTINEL) {
		sum += value;
		scanf("%d", &value);
	}
	
	printf("\n%d\n", sum);
	
	return 0;
}