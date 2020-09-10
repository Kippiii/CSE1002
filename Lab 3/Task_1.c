#include <stdio.h>

double average(int[]);

int main(void) {
	for(int i = 0; i < 2; i++) {
		int grades[3];
		printf("Student %d: ", i + 1);
		scanf("%d%d%d", &grades[0], &grades[1], &grades[2]);
		printf("Average of student %d: %f\n", i + 1, average(grades));
	}
	
	
	return 0;
}

double average(int grades[]) {
	return (grades[0] + grades[1] + grades[2]) / 3.0;
}