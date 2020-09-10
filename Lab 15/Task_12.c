#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	char extension[5];
	int file_size;
} file_t;

void print_file(file_t);

int main(void) {
	int n;
	scanf("%d", &n);
	int n2;
	scanf("%d", &n2);
	
	file_t* files = (file_t*) calloc(n, sizeof(file_t));
	for(int i = 0; i < n; i++) {
		scanf("%s%s%d", files[i].name, files[i].extension, &files[i].file_size);
	}
	
	files = (file_t*) realloc(files, n2);
	for(int i = n; i < n2; i++)
		scanf("%s%s%d", files[i].name, files[i].extension, &files[i].file_size);
	
	int largest_size_i = 0;
	int longest_name_i = 0;
	for(int i = 1; i < n2; i++) {
		if(files[i].file_size > files[largest_size_i].file_size)
			largest_size_i = i;
		if(strlen(files[i].name) > strlen(files[longest_name_i].name))
			longest_name_i = i;
		print_file(files[i]);
	}
	
	printf("\nLargest file size: \n");
	print_file(files[largest_size_i]);
	printf("Largest file name: \n");
	print_file(files[longest_name_i]);
	
	free(files);

	return 0;
}

void print_file(file_t file) {
	printf("%s.%s, %d bytes\n", file.name, file.extension, file.file_size);
}