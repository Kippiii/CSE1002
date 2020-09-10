#include <stdio.h>

int main(void) {
	char stack[101];
	int top = -1;
	char curr = getc(stdin);
	
	while (curr != '$') {
		if (curr == '(') {
			stack[++top] = curr;
		} else if (curr == ')') {
			if (top > -1 && stack[top] == '(') {
				top--;
			} else {
				printf("wrong\n");
				return 0;
			}
		}
		curr = getc(stdin);
	}
	
	if (top < 0) {
		printf("correct\n");
	} else {
		printf("wrong\n");
	}

	return 0;
}