#include <limits.h>
#include <math.h>

//Task 1
int arr_min(int arr[], int n) {
	int min = INT_MAX;
	for(int i = 0; i < n; i++)
		if(arr[i] < min)
			min = arr[i];
	return min;
}

int arr_max(int arr[], int n) {
	int max = INT_MIN;
	for(int i = 0; i < n; i++)
		if(arr[i] > max)
			max = arr[i];
	return max;
}

double arr_average(int arr[], int n) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	return (double) sum / n;
}

//Task 2
int* arr_two_power(int arr[], int n) {
	static int new_arr[100];
	for(int i = 0; i < n; i++)
		new_arr[i] = ldexp(1, arr[i]);
	return new_arr;
}

//Task 3
int* arr_sort(int arr[], int n) {
	static int new_arr[100];
	for(int i = 0; i < n; i++)
		new_arr[i] = arr[i];
	
	for(int i = 0; i < n; i++) {
		int min_index = i;
		for(int j = i + 1; j < n; j++)
			if(new_arr[j] < new_arr[min_index])
				min_index = j;
		int temp = new_arr[i];
		new_arr[i] = new_arr[min_index];
		new_arr[min_index] = temp;
	}
	return new_arr;
}