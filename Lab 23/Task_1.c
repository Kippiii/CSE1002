#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *);

int main(void) {
	char palindrome[101];
	scanf("%s", palindrome);
	
	printf("%spalindrome\n", is_palindrome(palindrome) ? "" : "not a ");

	return 0;
}

int is_palindrome(char *str) {
	int midpoint = (strlen(str) % 2 == 0) ? (strlen(str) / 2) : (strlen(str) / 2 + 1);
	
	char stack[midpoint + 1];
	int top = -1;
	
	for (int i = 0; i < midpoint; i++) {
		if (!ispunct(str[i]) && !isspace(str[i])) {
			stack[++top] = str[i];
		} else {
			midpoint++;
		}
	}
	
	for (int i = midpoint; i < strlen(str); i++) {
		if (!ispunct(str[i]) && !isspace(str[i])) {
			if (tolower(stack[top--]) != tolower(str[i])) {
				return 0;
			}
		}
	}
	
	return 1;
}