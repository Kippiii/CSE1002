#include <stdio.h>
#include <ctype.h>

int main(void) {
	int stack[200];
	int top = -1;
	
	char curr = getc(stdin);
	
	while (curr != '$') {
		if (isdigit(curr)) {
			stack[++top] = curr - '0';
		} else if (!isspace(curr)) {
			int second = stack[top--];
			int first = stack[top--];
			if (curr == '+') {
				printf("%d + %d\n", first, second);
				stack[++top] = first + second;
			} else if (curr == '-') {
				printf("%d - %d\n", first, second);
				stack[++top] = first - second;
			} else if (curr == '*') {
				printf("%d * %d\n", first, second);
				stack[++top] = first * second;
			} else if (curr == '/') {
				printf("%d / %d\n", first, second);
				stack[++top] = first / second;
			}
		}
		curr = getc(stdin);
	}
	
	printf("Answer: %d\n", stack[top]);

	return 0;
}