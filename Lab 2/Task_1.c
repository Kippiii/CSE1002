#include <stdio.h>

int main(void) {
	int count;
	scanf("%d", &count);
	
	int nums[count];
	for(int i = 0; i < count; i++)
		scanf("%d", &nums[i]);
	
	for(int i = 0; i < count; i++)
		printf("%d ", nums[i]*nums[i]);
	printf("\n");
	for(int i = 0; i < count; i++)
		printf("%d ", nums[i]*nums[i]*nums[i]);
	printf("\n");
	
	return 0;
}