#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char course_name[25];
	double* quiz_grades;
	double average;
} course_t;
typedef struct {
	char student_name[25];
	course_t* courses;
	double gpa;
} student_t;

int main(void) {
	int n;
	scanf("%d", &n);
	
	student_t* students = (student_t*) malloc(n * sizeof(student_t));
	
	for(int i = 0; i < n; i++) {
		scanf("%s", students[i].student_name);
		course_t* courses = (course_t*) malloc(3 * sizeof(course_t));
		students[i].courses = courses;
		students[i].gpa = 0;
		for(int j = 0; j < 3; j++) {
			scanf("%s", courses[j].course_name);
			double* quiz_grades = (double*) malloc(2 * sizeof(double));
			scanf("%lf%lf", quiz_grades, quiz_grades + 1);
			courses[j].quiz_grades = quiz_grades;
			courses[j].average = 0.0;
			courses[j].average += quiz_grades[0] + quiz_grades[1];
			courses[j].average /= 2;
			students[i].gpa += courses[j].average;
		}
		students[i].gpa /= 3;
	}
	
	int highest_index = 0;
	for(int i = 1; i < n; i++)
		if(students[i].gpa > students[highest_index].gpa)
			highest_index = i;
		
	printf("%s\nCourses: %s %s %s\nGPA: %.2f\n", students[highest_index].student_name, students[highest_index].courses[0].course_name, students[highest_index].courses[1].course_name, students[highest_index].courses[2].course_name, students[highest_index].gpa);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++)
			free(students[i].courses[j].quiz_grades);
		free(students[i].courses);
	}
	free(students);

	return 0;
}