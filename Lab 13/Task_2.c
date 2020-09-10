#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* str_alpha(char*);

int main(void) {
	char* msg = (char*) malloc(101 * sizeof(char));
	fgets(msg, 101, stdin);
	
	char* new_msg = str_alpha(msg);
	
	printf("%s\n", new_msg);
	
	free(msg);
	free(new_msg);

	return 0;
}

char* str_alpha(char* str) {
	char* msg = (char*) malloc((strlen(str) + 1) * sizeof(char));
	int j = 0;
	for(int i = 0; i < strlen(str); i++)
		if(isalpha(str[i]))
			msg[j++] = str[i];
	msg[j] = '\0';
	return msg;
}