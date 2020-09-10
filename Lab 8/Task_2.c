#include <stdio.h>

typedef struct {
	double x, y;
} point_t;
typedef struct {
	point_t top_left;
	double length;
} square_t;

point_t bottom_right(square_t);
int is_within(point_t, square_t);
int is_contained(square_t, square_t);

int main(void) {
	square_t squares[2];
	for(int i = 0; i < 2; i++) {
		printf("Square %d\nTop-left coord: ", i + 1);
		scanf("%lf%lf", &squares[i].top_left.x, &squares[i].top_left.y);
		printf("Side length: ");
		scanf("%lf", &squares[i].length);
	}
	printf("Square 1 is%s contained in Square 2!\n", is_contained(squares[0], squares[1]) ? "" : " not");

	return 0;
}

point_t bottom_right(square_t s) {
	point_t p;
	p.x = s.top_left.x + s.length;
	p.y = s.top_left.y - s.length;
	return p;
}

int is_within(point_t p, square_t s) {
	return (p.x >= s.top_left.x && p.x <= s.top_left.x + s.length) && (p.y <= s.top_left.y && p.y >= s.top_left.y - s.length);
}

int is_contained(square_t s1, square_t s2) {
	if(!is_within(s1.top_left, s2))
		return 0;
	double xdiff = s1.top_left.x - s2.top_left.x;
	double ydiff = s2.top_left.y - s1.top_left.y;
	return (s2.length - xdiff >= s1.length) && (s2.length - ydiff >= s1.length);
}