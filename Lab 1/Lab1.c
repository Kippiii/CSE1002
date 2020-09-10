#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    printf("n = ");
    scanf("%d", &n);

    char names[n][100];
    int ages[n];
    double salaries[n];

    for(int i = 1; i <= n; i++) {
        printf("Employee %d Name: ", i);
        scanf("%*c");
        fgets(names[i - 1], 100, stdin);
        names[i - 1][strlen(names[i - 1]) - 1] = '\0';
        printf("Employee %d Age: ", i);
        scanf("%d", &ages[i - 1]);
        printf("Employee %d Salary: ", i);
        scanf("%lf", &salaries[i - 1]);
        printf("\n");
    }

    printf("Employee Information: \n");
    for(int i = 0; i < n; i++) {
        printf("%s:\nAge: %d, Salary: $%.2f\n\n", names[i], ages[i], salaries[i]);
    }

	return 0;
}
