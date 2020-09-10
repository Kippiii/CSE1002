#include <stdio.h>

int is_sorted(int[], int);
void add_value(int[], int, int, int[]);

int main(void) {
	int size;
	printf("n = ");
	scanf("%d", &size);
	
	int input[size];
	printf("Input array: ");
	for(int i = 0; i < size; i++)
		scanf("%d", input + i);
	
	if(!is_sorted(input, size)) {
		printf("ERROR: The input must be sorted!\n");
		return 0;
	}
	
	int insert;
	printf("Input value to insert: ");
	scanf("%d", &insert);
	
	int output[size + 1];
	add_value(input, size, insert, output);
	printf("Array with newly inserted value: ");
	for(int i = 0; i < size + 1; i++)
		printf("%d ", output[i]);
	printf("\n");

	return 0;
}

int is_sorted(int arr[], int n) {
	for(int i = 1; i < n; i++)
		if(arr[i - 1] > arr[i])
			return 0;
	return 1;
}

void add_value(int old_arr[], int n, int new_value, int new_arr[]) {
	int flag = 0;
	for(int i = 0; i < n + 1; i++) {
		if(!flag && new_value < old_arr[i]) {
			new_arr[i] = new_value;
			flag = 1;
		}else{
			new_arr[i] = old_arr[i - flag];
		}
	}
}