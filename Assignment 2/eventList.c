#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
	int hour;
	int minute;
} EVENT_TIME;

typedef struct {
	int month;
	int day;
	int year;
} EVENT_DATE;

typedef struct {
	char title[25];
	EVENT_TIME *time;
	EVENT_DATE *date;
} EVENT;

EVENT* make_events(char[], int);
void print_events(EVENT*, int);
void print_selected_events(EVENT*, EVENT_DATE, EVENT_DATE, int);
void get_line(char[], int, FILE*);

int main(void) {
	printf("Event Database:\n");
	char file_name[101];
	printf("Enter the name of the input file: ");
	get_line(file_name, 101, stdin);
	char count_str[21];
	printf("How many events are in the input file? ");
	get_line(count_str, 21, stdin);
	int n = atoi(count_str);
	
	EVENT *events = make_events(file_name, n);
	
	if(events == NULL) {
		printf("\n\nERROR: Could not read file!\n");
		return 0;
	}
	
	printf("\nSchedule of events:\n\n");
	for(int i = 0; i < n; i++)
		print_events(events, i);
	printf("\n");
	
	EVENT_DATE start_date, end_date;
	start_date.day = 1;
	start_date.month = 1;
	start_date.year = 2018;
	end_date.day = 20;
	end_date.month = 12;
	end_date.year = 2019;
	print_selected_events(events, start_date, end_date, n);
	
	//Freeing memory
	for(int i = 0; i < n; i++) {
		free(events[i].time);
		free(events[i].date);
	}
	free(events);

	return 0;
}

EVENT* make_events(char file_name[], int n) {
	FILE *file = fopen(file_name, "r");
	//Error check
	if(file == NULL)
		return NULL;
	
	EVENT *events = (EVENT*) malloc(n * sizeof(EVENT));
	
	for(int i = 0; i < n; i++) {
		get_line(events[i].title, 21, file);
		
		EVENT_TIME *time = (EVENT_TIME*) malloc(sizeof(EVENT_TIME));
		events[i].time = time;
		char time_str[6];
		get_line(time_str, 6, file);
		time->hour = (time_str[0] - '0') * 10 + (time_str[1] - '0');
		time->minute = (time_str[3] - '0') * 10 + (time_str[4] - '0');
		
		EVENT_DATE *date = (EVENT_DATE*) malloc(sizeof(EVENT_DATE));
		events[i].date = date;
		char date_str[11];
		get_line(date_str, 11, file);
		date->month = (date_str[0] - '0') * 10 + (date_str[1] - '0');
		date->day = (date_str[3] - '0') * 10 + (date_str[4] - '0');
		date->year = (date_str[6] - '0') * 1000 + (date_str[7] - '0') * 100 + (date_str[8] - '0') * 10 + (date_str[9] - '0');
	}
	
	fclose(file);
	
	return events;
}

void print_events(EVENT *events, int index) {
	EVENT event = *(events + index);
	printf("\tEvent: %-25s %02d:%02d on: %02d/%02d/%04d\n", strcat(event.title, " at:"), event.time->hour, event.time->minute, event.date->month, event.date->day, event.date->year);
}

void print_selected_events(EVENT *events, EVENT_DATE start, EVENT_DATE end, int n) {
	//TODO ensure you can add lenght as parameter
	printf("Date:\t%02d/%02d/%04d\t%02d/%02d/%04d\n\nEvents:\n\n", start.month, start.day, start.year, end.month, end.day, end.year);
	for(int i = 0; i < n; i++) {
		EVENT_DATE *date = events[i].date;
		
		//Checking if event is within date range
		if(date->year < start.year || date->year > end.year) continue;
		if(date->year == start.year) {
			if(date->month < start.month) continue;
			if(date->month == start.month) {
				if(date->day < start.day) continue;
			}
		}
		if(date->year == end.year) {
			if(date->month > end.month) continue;
			if(date->month == end.month) {
				if(date->day > end.day) continue;
			}
		}
		
		print_events(events, i);
	}
}

void get_line(char line[], int n, FILE *stream) {
	do {
		fgets(line, n,  stream);
		while(isspace(line[strlen(line) - 1]))
			line[strlen(line) - 1] = '\0';
	} while(strlen(line) < 1);
}