#include <stdio.h>

typedef enum {
	False,
	True
} boolean;

int main(void) {
	char str[101];
	printf("Please enter string: ");
	fgets(str, 101, stdin);
	
	boolean flag = True;
	int index = -1;
	while(flag) {
		index++;
		if(str[index] >= 'A' && str[index] <= 'Z')
			flag = False;
	}
	
	printf("The first uppercase letter in the string is %c\n", str[index]);

	return 0;
}