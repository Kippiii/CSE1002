#include <stdio.h>
#include <string.h>

struct employee get_employee();
void print_employee(struct employee emp);
void read_line(char[], int);
int str_to_int(char[]);
int my_pow(int, int);
void substring(char[], int, int, char[]);

struct start_date_t {
	int day, month, year;
};

struct employee {
	char name[101];
	char job [101];
	char salary[101];
	struct start_date_t start_date;
};

int main(void) {
	struct employee employee1 = get_employee();
	struct employee employee2 = get_employee();
	
	print_employee(employee1);
	printf("\n");
	print_employee(employee2);

	return 0;
}

struct employee get_employee() {
	struct employee tmp;
	read_line(tmp.name, 101);
	read_line(tmp.job, 101);
	read_line(tmp.salary, 101);
	
	char date[11];
	read_line(date, 11);
	
	char daystr[3];
	substring(date, 0, 2, daystr);
	tmp.start_date.day = str_to_int(daystr);
	
	char monthstr[3];
	substring(date, 3, 5, monthstr);
	tmp.start_date.month = str_to_int(monthstr);
	
	char yearstr[3];
	substring(date, 6, 11, yearstr);
	tmp.start_date.year = str_to_int(yearstr);
	return tmp;
}

void print_employee(struct employee emp) {
	printf("%s\n%s\n$%s\n%d/%d/%d\n", emp.name, emp.job, emp.salary, emp.start_date.day, emp.start_date.month, emp.start_date.year);
}

void read_line(char str[], int len) {
	fgets(str, len, stdin);
	while(str[strlen(str) - 1] == '\n' || str[strlen(str) - 1] == '\r')
		str[strlen(str) - 1] = '\0';
	scanf(" ");
}

int str_to_int(char str[]) {
	int n = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++)
		n += (str[i] - '0') * my_pow(10, len - i - 1);
	return n;
}

int my_pow(int a, int b) {
	if(b <= 0)
		return 1;
	return a * my_pow(a, b - 1);
}

void substring(char str[], int start, int stop, char new_str[]) {
	strncpy(new_str, str + start, stop - start);
	new_str[stop - start] = '\0';
}