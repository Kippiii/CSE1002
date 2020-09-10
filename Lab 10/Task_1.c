#include <stdio.h>

typedef enum {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
} month_t;

int main(void) {
	month_t month;
	printf("Please enter a month integer: ");
	scanf("%d", &month);
	
	if(month == September)
		printf("True\n");
	else
		printf("False\n");

	return 0;
}