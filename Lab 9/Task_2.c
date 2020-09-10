#include <stdio.h>
#include <math.h>

#define PI 3.14159

typedef struct {
	double x, y;
} point_t;
typedef struct {
	point_t top_left;
	double length;
} square_t;
typedef struct {
	point_t center;
	double radius;
} circle_t;

typedef struct {
	int shape_indicator;
	union {
		square_t square;
		circle_t circle;
	} shape_union;
} shape_t;

double get_area(shape_t*);

int main(void) {
	shape_t shape;
	printf("Do you want the area of a square (0) or a circle (1)? ");
	scanf("%d", &shape.shape_indicator);
	if(shape.shape_indicator == 0) {
		printf("What is the length of the square? ");
		scanf("%lf", &shape.shape_union.square.length);
	}else{
		printf("What is the radius of the circle? ");
		scanf("%lf", &shape.shape_union.circle.radius);
	}
	
	double area = get_area(&shape);
	
	printf("The area of the shape is %.4f\n", area);

	return 0;
}

double get_area(shape_t *s) {
	if(s->shape_indicator == 0) {
		return pow(s->shape_union.square.length, 2);
	}else{
		return PI * pow(s->shape_union.circle.radius, 2);
	}
}