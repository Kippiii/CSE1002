#include <stdio.h>

#define PI 3.14159265359

double triangle_area(double, double);
double circle_area(double);
double square_area(double);

int main(void) {
	char shape;
	printf("What shape would you like the area of? (T = triangle, C = circle, S = square): ");
	scanf(" %c", &shape);
	
	double area;
	switch(shape) {
		double length, height, radius;
		case 'T':
			printf("What two side lengths does the triangle have? ");
			scanf("%lf%lf", &length, &height);
			area = triangle_area(length, height);
			break;
		case 'C':
			printf("What is the radius of the circle? ");
			scanf("%lf", &radius);
			area = circle_area(radius);
			break;
		case 'S':
			printf("What is the length of the square? ");
			scanf("%lf", &length);
			area = square_area(length);
			break;
	}
	
	printf("The area of the shape is %f.\n", area);
	
	return 0;
}

double triangle_area(double length, double height) {
	return length * height / 2;
}

double circle_area(double radius) {
	return PI * radius * radius;
}

double square_area(double length) {
	return length * length;
}