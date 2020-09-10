#include <stdio.h>

char switch_case(char);

int main(void) {
	char str[101];
	printf("Please enter a string: ");
	char ch;
	int counter = -1;
	do {
		counter++;
		ch = getchar();
		str[counter] = switch_case(ch);
	} while(ch != '\n');
	str[counter] = '\0';
	printf("The opposite case of that string is %s\n", str);

	return 0;
}

char switch_case(char c) {
	return c ^ 32;
}