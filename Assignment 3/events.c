/*
@author: Ian Orzel
@Program: Event Manager
@version: 2.0
@Date: 6 November 2019
@Description: Reads a list of events from a text file and prints events through use of a linked list
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
 * Structure for saving the time of an event through an hour and minute field
 */
typedef struct {
	int hour;		/* Value between 0 and 23 */
	int minute;		/* Value between 0 and 59 */
} event_time_t;


/*
 * Structure for saving the date that an event occured
 */
typedef struct {
	int month;	/* Value between 1 and 12 */
	int day;	/* Value between 1 and 31 */
	int year;	/* Four-digit number */
} event_date_t;


/*
 * Structure for saving the information about an event that occured
 */
typedef struct Event {
	char title[21];
	event_time_t *time;
	event_date_t *date;
	struct Event *next;	/* Next node for use in linked list */
} event_t;


void add_events(event_t **);
void print_list(event_t *);
void print_selected_events(event_t *, event_date_t *);
int get_line(char *, int);
void free_list(event_t **);


int main(void) {
	event_t *head_ptr = NULL;												/* Initializes the linked list */
	
	add_events(&head_ptr);													/* Adds all events to the linked list */
	
	print_list(head_ptr);													/* Prints all events in the linked list */
	
	event_date_t *date = (event_date_t *) malloc(sizeof(event_date_t));		/* Creates a new date object */
	date->month = 6;
	date->day = 15;
	date->year = 2018;
	
	print_selected_events(head_ptr, date);									/* Prints all events on the given date */
	
	free(date);
	free_list(&head_ptr);													/* Frees all of the pointers in the linked list */
	
	return 0;
}


/*
 * Adds all events from the input to a linked list and stops when the end of the file is reached
 * Takes a pointer to the pointer to the head of the linked list as input
 */
void add_events(event_t **head_ptr) {
	char title[21];																					/* These strings are used for temporary string storage */
	char time_str[6];
	char date_str[11];
	while (get_line(title, 21) && get_line(time_str, 6) && get_line(date_str, 11)) {				/* Loop takes input for all three strings and stops if EOF is reached */
		event_t *new_ptr = (event_t *) malloc(sizeof(event_t));
		
		strcpy(new_ptr->title, title);
		
		event_time_t *time = (event_time_t *) malloc(sizeof(event_time_t));							/* Converts time string to an event_time_t struct */
		time->hour = (time_str[0] - '0') * 10 + (time_str[1] - '0');
		time->minute = (time_str[3] - '0') * 10 + (time_str[4] - '0');
		new_ptr->time = time;
		
		event_date_t *date = (event_date_t *) malloc(sizeof(event_date_t));							/* Converts date string to an event_date_t struct */
		date->month = (date_str[0] - '0') * 10 + (date_str[1] - '0');
		date->day = (date_str[3] - '0') * 10 + (date_str[4] - '0');
		date->year = (date_str[6] - '0') * 1000 + (date_str[7] - '0') * 100 + 
		             (date_str[8] - '0') * 10 + (date_str[9] - '0');
		new_ptr->date = date;
		
		if (*head_ptr == NULL) {																	/* Sets new_ptr to the head if linked list is empty */
			*head_ptr = new_ptr;
			(*head_ptr)->next = NULL;
		} else if (strcmp((*head_ptr)->title, new_ptr->title) > 0) {									/* Sets new_ptr as head if it is less than the current head */
			new_ptr->next = *head_ptr;
			*head_ptr = new_ptr;
		} else {																					/* Adds new_ptr to the center of the linked list */
			event_t *tmp_ptr;
			for (tmp_ptr = *head_ptr; tmp_ptr->next != NULL; tmp_ptr = tmp_ptr->next) {				/* Loops through linked list until it hits the last element */
				if (strcmp(tmp_ptr->next->title, new_ptr->title) > 0) {								/* Ends the loop if new_ptr is greater than the next value in the linked list */
					break;
				}
			}
			
			new_ptr->next = tmp_ptr->next;															/* Adds new_ptr to the center of the linked list */
			tmp_ptr->next = new_ptr;
		}
	}
}


/*
 * Prints all events in the linked list when given the head
 */
void print_list(event_t *head_ptr) {
	printf("Schedule of Events\n");
	for (event_t *tmp_ptr = head_ptr; tmp_ptr != NULL; tmp_ptr = tmp_ptr->next) {	/* Loops through every element in the linked list */
		printf("\t%-24s at: %02d:%02d\t on: %02d/%02d/%04d\n", tmp_ptr->title,
			tmp_ptr->time->hour, tmp_ptr->time->minute, 
			tmp_ptr->date->month, tmp_ptr->date->day, tmp_ptr->date->year);
	}
	printf("\n");
}


/*
 * Prints all events from a linked list that occur on a specific day
 */
void print_selected_events(event_t *head_ptr, event_date_t *date) {
	printf("Date:\t%02d/%02d/%04d\n", date->month, date->day, date->year);
	printf("Events:\n");
	for (event_t *tmp_ptr = head_ptr; tmp_ptr != NULL; tmp_ptr = tmp_ptr->next) {												/* Loops through all elements in the linked list */
		if (tmp_ptr->date->month == date->month && tmp_ptr->date->day == date->day && tmp_ptr->date->year == date->year) {		/* Checks if the event happened at the given day */
			printf("\t%-24s at: %02d:%02d\n", tmp_ptr->title, tmp_ptr->time->hour, tmp_ptr->time->minute);
		}
	}
}


/*
 * Gets the next line of input from stdin while removing any trailing whitespace. This also skips any empty lines.
 * Takes a pointer to the line and the number of characters as input
 * Returns 0 if EOF is reached
 */
int get_line(char *line, int n) {
	int flag = 1;								/* Flag variable is used to check when EOF is reached */
	do {
		flag = fgets(line, n,  stdin) != NULL;	/* fgets returns NULL when EOF is reached */
		while (isspace(line[strlen(line) - 1])) {
			line[strlen(line) - 1] = '\0';		/* Replaces any trailing whitespace in the string with null terminator */
		}
	} while (strlen(line) < 1 && flag);			/* Keeps looping if line is blank and stops if the blank line was end of input */
	return flag;
}


/*
 * Frees the memory of the linked list
 */
void free_list(event_t **head_ptr) {
	if (*head_ptr == NULL) {				/* Does nothing if linked list is already empty */
		return;
	}
	if ((*head_ptr)->next != NULL) {
		free_list(&((*head_ptr)->next));	/* Calls function recursively until at end of list */
	}
	free((*head_ptr)->date);				/* Frees spot in memory and sets its pointer to NULL */
	free((*head_ptr)->time);
	free(*head_ptr);						
	*head_ptr = NULL;
}