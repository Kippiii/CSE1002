#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
	char* student_name;
	char* id_number;
	char* major;
} student_t;

void get_line(char*, int);

int main(void) {
	char* n_str = (char*) malloc(21 * sizeof(char));
	get_line(n_str, 21);
	int n = atoi(n_str);
	free(n_str);
	
	student_t* students = (student_t*) malloc(n * sizeof(student_t));
	
	for(int i = 0; i < n; i++) {
		char* student_name = (char*) malloc(101 * sizeof(char));
		get_line(student_name, 101);
		students[i].student_name = student_name;
		
		char* id_number = (char*) malloc(101 * sizeof(char));
		get_line(id_number, 101);
		students[i].id_number = id_number;
		
		char* major = (char*) malloc(101 * sizeof(char));
		get_line(major, 101);
		students[i].major = major;
	}
	
	for(int i = 0; i < n; i++) {
		printf("%s (%s): %s\n", students[i].student_name, students[i].id_number, students[i].major);
		
		free(students[i].student_name);
		free(students[i].id_number);
		free(students[i].major);
	}
	
	free(students);

	return 0;
}

void get_line(char* str, int n) {
	do {
		fgets(str, n, stdin);
		while(isspace(str[strlen(str) - 1]))
			str[strlen(str) - 1] = '\0';
	}while(strlen(str) < 1);
}