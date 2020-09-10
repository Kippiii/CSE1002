#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} point_t;

double distance(point_t, point_t);
void print(point_t);

int main(void) {
	point_t point1, point2;
	printf("Please input coords for first point: ");
	scanf("%lf%lf", &point1.x, &point1.y);
	printf("Please input coords for second point: ");
	scanf("%lf%lf", &point2.x, &point2.y);
	
	printf("\n");
	print(point1);
	print(point2);
	printf("The distance between these points is %.2f\n", distance(point1, point2));

	return 0;
}

double distance(point_t p1, point_t p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void print(point_t p) {
	printf("(%.2f, %.2f)\n", p.x, p.y);
}