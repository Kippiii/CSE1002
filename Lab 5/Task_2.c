#include <stdio.h>
#include <string.h>

int to_decimal(char[]);

int main(void) {
	while(1) {
		char bin_num[21];
		scanf("%s", bin_num);
		printf("%d\n", to_decimal(bin_num));
	}

	return 0;
}

int to_decimal(char my_binary[]) {
	int len = strlen(my_binary);
	if(len < 1)
		return 0;
	
	int bit = my_binary[len - 1] - '0';
	my_binary[len - 1] = '\0';
	return bit + 2 * to_decimal(my_binary);
}