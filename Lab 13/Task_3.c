#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool_t;

bool_t is_palindrome(char*);

int main(void) {
	char* msg = (char*) malloc(101 * sizeof(char));
	fgets(msg, 101, stdin);
	
	printf("%s%s\n", is_palindrome(msg) ? "" : "not a ", "palindrome");
	
	free(msg);

	return 0;
}

bool_t is_palindrome(char* str) {
	char* new_str = (char*) malloc((strlen(str) + 1) * sizeof(char));
	int j = 0;
	for(int i = 0; i < strlen(str); i++)
		if(isalpha(str[i]))
			new_str[j++] = tolower(str[i]);
	new_str[j] = '\0';
	
	for(int i = 0, j = strlen(new_str) - 1; i <= j; i++, j--)
		if(new_str[i] != new_str[j]) {
			free(new_str);
			return FALSE;
		}
	
	return TRUE;
}