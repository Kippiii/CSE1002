#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for file
typedef struct {
	char name[20];
	char extension[5];
	int file_size;
} file_t;

int main(void) {
	//Creates the files array
	int n = 15;
	file_t *files = (file_t *) malloc(sizeof(file_t) * n);
	
	//Reads from the binary file
	FILE *file = fopen("mybin.bin", "rb");
	fread(files, sizeof(file_t), n, file);
	fclose(file);
	
	//Finds the file with the longest name and largest size
	int highest_size = 0;
	int longest_name = 0;
	
	for (int i = 1; i < n; i++) {
		if (files[i].file_size > files[highest_size].file_size) {
			highest_size = i;
		}
		if (strlen(files[i].name) > strlen(files[longest_name].name)) {
			longest_name = i;
		}
	}
	
	//Prints the results of the query to the console
	printf("Largest file size: %s.%s, %d bytes\n", files[highest_size].name, files[highest_size].extension, files[highest_size].file_size);
	printf("Longest file name: %s.%s, %d bytes\n", files[longest_name].name, files[longest_name].extension, files[longest_name].file_size);

	return 0;
}