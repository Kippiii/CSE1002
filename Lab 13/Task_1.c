#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* str_to_lower(char*);

int main(void) {
	char* msg = (char*) malloc(101 * sizeof(char));
	fgets(msg, 101, stdin);
	if(msg[strlen(msg) - 1] == '\n')
		msg[strlen(msg) - 1] = '\0';
	
	char* new_msg = str_to_lower(msg);
	
	printf("%s\n", new_msg);
	
	free(msg);
	free(new_msg);

	return 0;
}

char* str_to_lower(char* str) {
	char* msg = (char*) malloc((strlen(str) + 1) * sizeof(char));
	for(int i = 0; i < strlen(str); i++)
		if(isalpha(str[i]))
			msg[i] = tolower(str[i]);
		else
			msg[i] = str[i];
		
	return msg;
}