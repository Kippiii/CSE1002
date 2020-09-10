/*
@author: Ian Orzel
@Program: Lab 18 Task 2
@version: 1.0
@Date: 29 October 2019
@Description: Encrypts a string using the xor operation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* xor_encrypt(char*, char);

int main(void) {
	char* str = (char*) malloc(sizeof(char) * 101);			/* Declares a string using malloc for storing the original string */
	printf("Please enter the string you want encrypted: ");
	scanf("%s", str);										/* Initializes string str using user input */
	
	char key;												/* Declares a character variable for the key */
	printf("Please enter the key: ");
	scanf(" %c", &key);										/* Initializes the value of key through user input */
	
	char* new_str = xor_encrypt(str, key);					/* Runs the xor_encrypt function to generate the encrypted string */
	
	printf("The encrypted string is %s\n", new_str);		/* Prints the ecrypted string to the user */
	
	free(str);												/* Frees the str variable */
	free(new_str);											/* Frees the new_str variable */

	return 0;
}

/*
 * Encrypts a string str using a character key with the xor operation and returns the result
 */
char* xor_encrypt(char* str, char key) {
	char* new_str = (char*) malloc((strlen(str) + 1) * sizeof(char));	/* Uses malloc in order to allocate a new string */
	/*
	 * Loops through every character in str and adds a new encrypted character to new_str
	 */
	for(int i = 0; i < strlen(str); i++) {
		new_str[i] = str[i] ^ key;								/* Sets a character from new_str to a character from str xor the key */
	}
	new_str[strlen(str) + 1] = '\0';
	return new_str;												/* Returns the new string */
}