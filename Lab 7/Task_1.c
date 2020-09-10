#include <stdio.h>
#include <string.h>

void read_line(char[], int);

struct User {
	char address[101];
	char city[101];
	char state[3];
	char zip_code[6];
};

int main(void) {
	struct User my_user;
	read_line(my_user.address, 101);
	read_line(my_user.city, 101);
	read_line(my_user.state, 3);
	read_line(my_user.zip_code, 6);
	
	printf("%s\n%s, %s %s\n", my_user.address, my_user.city, my_user.state, my_user.zip_code);

	return 0;
}

void read_line(char str[], int len) {
	fgets(str, len, stdin);
	while(str[strlen(str) - 1] == '\n' || str[strlen(str) - 1] == '\r')
		str[strlen(str) - 1] = '\0';
	scanf(" ");
}