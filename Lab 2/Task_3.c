#include <stdio.h>

int min_of_four(int[]);
int max_of_four(int[]);

int main(void) {
	int nums[4];
	for(int i = 0; i < 4; i++)
		scanf("%d", &nums[i]);
	
	printf("\nMin: %d\n", min_of_four(nums));
	printf("Max: %d\n", max_of_four(nums));
	
	return 0;
}

int min_of_four(int nums[]) {
	int min = nums[0];
	for(int i = 1; i < 4; i++)
		if(nums[i] < min)
			min = nums[i];
	return min;
}

int max_of_four(int nums[]) {
	int max = nums[0];
	for(int i = 1; i < 4; i++)
		if(nums[i] > max)
			max = nums[i];
	return max;
}