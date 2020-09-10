/*
@author: Ian Orzel
@Program: Lab 18 Task 1
@version: 1.0
@Date: 29 October 2019
@Description: Sums positive numbers from a text file
*/

#include <stdio.h>

int main(void) {
	int sum = 0;			/* Variable to store the sum of the numbers */
	int value;				/* Variable to store the most recent value obtained from input */
	scanf("%d", &value);	/* Initializes the value of value with the first input from the file */ 
	
	
	/*
	 * Loops through input and adds each value to the sum
	 */
	while(value >= 0) {
		sum += value;			/* Adds the current value to the sum */
		scanf("%d", &value);	/* Obtains a new value from the input stream */
	}
	
	printf("%d\n", sum);		/* Prints the sum to the console */

	return 0;
}