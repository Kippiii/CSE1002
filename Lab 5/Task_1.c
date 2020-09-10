#include <stdio.h>

void swap(int[], int[], int);

int main(void) {
	int size;
	printf("Array size: ");
	scanf("%d", &size);
	
	int first[size];
	int second[size];
	printf("Input first array: ");
	for(int i = 0; i < size; i++)
		scanf("%d", first + i);
	printf("Input second array: ");
	for(int i = 0; i < size; i++)
		scanf("%d", second + i);

	swap(first, second, size);
	
	printf("First array after swapping: ");
	for(int i = 0; i < size; i++)
		printf("%d ", first[i]);
	printf("\n");
	printf("Second array after swapping: ");
	for(int i = 0; i < size; i++)
		printf("%d ", second[i]);
	printf("\n");
	
	return 0;
}

void swap(int a[], int b[], int n) {
	for(int i = 0; i < n; i++) {
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}