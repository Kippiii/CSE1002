#include <stdio.h>

int count_fives(int, int[], int);

int main(void) {
	int n;
	printf("n = ");
	scanf("%d", &n);
	
	int nums[n];
	for(int i = 0; i < n; i++)
		scanf("%d", nums + i);
	
	printf("%d\n", count_fives(n, nums, 0));

	return 0;
}

int count_fives(int n, int arr[], int index) {
	if(index >= n)
		return 0;
	
	int flag = 0;
	if(arr[index] == 5)
		flag = 1;
	return flag + count_fives(n, arr, index + 1);
}