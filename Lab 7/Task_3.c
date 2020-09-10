#include <stdio.h>

double calc_time(int);

struct run {
	double distance;
	int time;
};

struct runner {
	char name[101];
	struct run runs[3];
};

int main(void) {
	int n;
	printf("Array size: ");
	scanf("%d", &n);
	struct runner runners[n];
	printf("\n");
	
	for(int i = 0; i < n; i++) {
		printf("Runner %d\nName: ", i + 1);
		scanf("%s", runners[i].name);
		for(int j = 0; j < 3; j++) {
			printf("Distance and time of run %d: ", j + 1);
			scanf("%lf%d", &runners[i].runs[j].distance, &runners[i].runs[j].time);
		}
		printf("\n");
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			printf("%s's Speed - Run %d: %.2f\n", runners[i].name, j + 1, runners[i].runs[j].distance / calc_time(runners[i].runs[j].time));
		}
		printf("\n");
	}

	return 0;
}

double calc_time(int time) {
	double hours = (time % 100) / 60.0 / 60.0 + (time / 100) / 60.0;
	return hours;
}