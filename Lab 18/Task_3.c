/*
@author: Ian Orzel
@Program: Lab 18 Task 2
@version: 1.0
@Date: 29 October 2019
@Description: Adds, subtracts, and prints complex numbers
*/

#include <stdio.h>

/*
 * Structure for the storage of complex numbers
 */
typedef struct {
	double real;
	double imaginary;	
} complex_t;

complex_t add(complex_t, complex_t);
complex_t sub(complex_t, complex_t);
void print(complex_t);

int main(void) {
	//Gets two inputs from the user for input
	complex_t number1;													
	complex_t number2;
	printf("Please enter the first complex number (real imaginary): ");
	scanf("%lf%lf", &number1.real, &number1.imaginary);
	printf("Please enter the second complex number (real imaginary): ");
	scanf("%lf%lf", &number2.real, &number2.imaginary);
	
	//Prints the sum and difference the two complex numbers
	printf("Sum of the numbers\n");
	print(add(number1, number2));
	printf("Difference of the numbers\n");
	print(sub(number1, number2));

	return 0;
}

/*
 * Adds two complex numbers together and returns their sum
 */
complex_t add(complex_t n1, complex_t n2) {
	complex_t sum;									
	sum.real = n1.real + n2.real;					
	sum.imaginary = n1.imaginary + n2.imaginary;	
	return sum;										
}

/*
 * Subtracts two complex numbers in the format n1 - n2
 */
complex_t sub(complex_t n1, complex_t n2) {
	complex_t difference;
	difference.real = n1.real - n2.real;
	difference.imaginary = n1.imaginary - n2.imaginary;
	return difference;
}

/*
 * Prints a complex number in the form of a + b
 */
void print(complex_t num) {
	printf("%f + %fi\n", num.real, num.imaginary);
}