#include <stdio.h>
#include <string.h>

void scan_exam_data(int, int, int*, char*);
void analyze_data(int, char*, char[], int[], double[]);
void print_data(int, char[], int[], double[], int[]);
int is_all_lower(char[]);

int main(void) {
	//Grabs the number of students
	int student_count;
	scanf("%d", &student_count);
	
	//Grabs the number of questions
	int n;
	scanf("%d", &n);
	
	//Ensures question count input is correct
	if(n < 5 || n > 20) {
		printf("ERROR! Number of questions must be between 5 and 20!\n");
		return 0;
	}
	
	//Grabs the answer key
	char key[n + 1];
	scanf("%s", key);
	
	//Ensures that all of the answers in the key are lower case
	if(!is_all_lower(key)) {
		printf("ERROR! All answer choices must be written as lower-case numbers!\n");
		return 0;
	}
	
	//Creates and initializes an array for wrong answers with zeros
	int wrong[n];
	for(int i = 0; i < n; i++)
		wrong[i] = 0;
	
	//Creates arrays for storing student ids and answers
	int ids[student_count];
	char answers[student_count][n + 1];
	
	//Scans all of the student data from the text file
	scan_exam_data(student_count, n, ids, answers[0]);
	
	//Creates an array for storing the student scores and calculates student scores as well as how many times answers were missed
	double student_scores[student_count];
	analyze_data(student_count, answers[0], key, wrong, student_scores);
	
	//Prints the result in a formatted table
	print_data(student_count, key, ids, student_scores, wrong);

	return 0;
}

//Collects and stores information from text file
void scan_exam_data(int n, int question_count, int *student_ids, char *student_answer) {
	for(int i = 0; i < n; i++) {
		//Grabs the student's id
		scanf("%d", student_ids + i);
		
		//Grabs the student's answer choices
		for(int j = 0; j < question_count; j++)
			scanf(" %c", student_answer++);
		*(student_answer++) = '\0';
	}
}

//Analyzes the data of each student to calculate their score and how many times each answer was missed
void analyze_data(int n, char *answer, char key[], int wrong_answers[], double scores[]) {
	for(int i = 0; i < n; i++) {
		int correct = 0;
		//Stores whether their choices are correct or incorrect
		for(int i = 0; i < strlen(key); i++) {
			if(*answer == key[i])
				correct++;
			else
				wrong_answers[i]++;
			answer++;
		}
		//Calculates the score for the student
		scores[i] = (double) correct / strlen(key) * 100;
		answer++;
	}
}

//Prints all of the information about the exam
void print_data(int n, char key[], int student_ids[], double scores[], int wrong_answers[]) {
	printf("Exam Report\n\n");
	
	printf("%-13s%3d\n", "Students", n);
	
	//Prints a list of question numbers
	printf("%-13s", "Question");
	for(int i = 1; i <= strlen(key); i++)
		printf("%3d", i);
	
	//Prints the answer key
	printf("\n%-13s", "Answer");
	for(int i = 0; i < strlen(key); i++)
		printf("%3c", key[i]);
	printf("\n\n");
	
	//Prints every student's id and score
	printf("%-7s%-7s\n", "ID", "Score(%)");
	for(int i = 0; i < n; i++)
		printf("%-7d%-7.0f\n", student_ids[i], scores[i]);
	printf("\n");
	
	//Prints a list of every question and how many times it was missed
	printf("\n%-13s", "Question");
	for(int i = 1; i <= strlen(key); i++)
		printf("%3d", i);
	printf("\n%-13s", "Missed by");
	for(int i = 0; i < strlen(key); i++)
		printf("%3d", wrong_answers[i]);
	printf("\n");
}

//Checks if a given string is all lower case
int is_all_lower(char s[]) {
	for(int i = 0; i < strlen(s); i++)
		if(s[i] < 'a' || s[i] > 'z')
			return 0;
	return 1;
}