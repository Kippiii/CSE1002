#include <stdio.h>
#include <string.h>

void four_bits(char[]);

int main(void) {
	while(1) {
		char string[100];
		scanf("%s", string);
		four_bits(string);
	}
	
	return 0;
}

void four_bits(char binary[]) {
	int length = strlen(binary);
	int first_bit_end = length % 4;
	for(int i = 0; i < length; i++) {
		printf("%c", binary[i]);
		if((i + 1 - first_bit_end) % 4 == 0)
			printf(" ");
	}
	printf("\n");
}