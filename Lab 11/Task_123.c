#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Utilities.h"

int main(void) {
	int n;
	printf("How long should the array be? ");
	scanf("%d", &n);
	
	int nums[n];
	srand(time(NULL));
	for(int i = 0; i < n; i++)
		nums[i] = rand() % 30 + 1;
	
	printf("\nHere is the array:\n");
	for(int i = 0; i < n; i++)
		printf("%d ", nums[i]);
	printf("\n");
	
	//Task 1
	printf("Minimum value in array: %d\n", arr_min(nums, n));
	printf("Maximum value in array: %d\n", arr_max(nums, n));
	printf("Average value in array: %.2f\n", arr_average(nums, n));
	
	//Task 2
	int *powers_nums = arr_two_power(nums, n);
	printf("Two to the power of array elements: ");
	for(int i = 0; i < n; i++)
		printf("%d ", powers_nums[i]);
	printf("\n");
	
	//Task 3
	int *sorted_nums = arr_sort(nums, n);
	printf("Sorted array: ");
	for(int i = 0; i < n; i++)
		printf("%d ", sorted_nums[i]);
	printf("\n");

	return 0;
}