#include <stdio.h>

void double_arr(int[], int);

int main(void) {
	int n;
	printf("Please enter a value of n that satisfies 0 < n < 100: ");
	scanf("%d", &n);
	int nums[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	double_arr(nums, n);
	for(int i = 0; i < n; i++)
		printf("%d ", nums[i]);
	printf("\n");
	
	return 0;
}

void double_arr(int arr[], int n) {
	for(int i = 0; i < n; i++)
		arr[i] *= 2;
}