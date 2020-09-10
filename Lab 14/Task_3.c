#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
}date_t;
typedef struct {
	date_t* start_date; //upper limit date
	date_t* end_date; //lower limit date
}interval_t;

date_t* generate_date(char*);

int main(void) {
	interval_t interval;
	
	char* start_str = (char*) malloc(11 * sizeof(char));
	char* end_str = (char*) malloc(11 * sizeof(char));
	printf("Start date: ");
	scanf("%s", start_str);
	printf("End date: ");
	scanf("%s", end_str);
	interval.start_date = generate_date(start_str);
	interval.end_date = generate_date(end_str);
	free(start_str);
	free(end_str);
	
	int months = 0;
	months += (interval.end_date->year - interval.start_date->year) * 12;
	months += (interval.end_date->month - interval.start_date->month);
	if(interval.end_date->day < interval.start_date->day)
		months--;
	
	printf("Number of months: %d\n", months);

	return 0;
}

date_t* generate_date(char* str) {
	date_t* day = (date_t*) malloc(sizeof(date_t));
	sscanf(str, "%d/%d/%d", &day->month, &day->day, &day->year);
	//day->month = (str[0] - '0') * 10 + (str[1] - '0');
	//day->day = (str[3] - '0') * 10 + (str[4] - '0');
	//day->year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
	return day;
}