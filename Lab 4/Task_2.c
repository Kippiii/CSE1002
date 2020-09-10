#include <stdio.h>

#define SIZE 3

int largeNum(int[][SIZE]);
void sumCols(int[][SIZE], int[]);
void print(int[]);

int main(void) {
	int nums[SIZE][SIZE];
	
	printf("Please enter the values for the array: \n");
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			scanf("%d", &nums[i][j]);
	
	printf("The largest number in this array is %d.\n", largeNum(nums));
	
	int sums[SIZE];
	sumCols(nums, sums);
	printf("Here is the array with the summed columns:\n");
	print(sums);
	
	return 0;
}

int largeNum(int nums[][SIZE]) {
	int largest = nums[0][0];
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			if(nums[i][j] > largest)
				largest = nums[i][j];
	return largest;
}

void sumCols(int nums[][SIZE], int cols[]) {
	for(int i = 0; i < SIZE; i++) {
		int sum = 0;
		for(int j = 0; j < SIZE; j++)
			sum += nums[j][i];
		cols[i] = sum;
	}
}

void print(int arr[]) {
	for(int i = 0; i < SIZE; i++) 
		printf("%d ", arr[i]);
}