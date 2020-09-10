#include <stdio.h>
#include <stdlib.h>

//Struct for file
typedef struct {
	char name[20];
	char extension[5];
	int file_size;
} file_t;

int main(void) {
	//Obatins number of object
	int n;
	scanf("%*d%d", &n);
	
	//Generates the array of files
	file_t *files = (file_t *) malloc(sizeof(file_t) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &files[i].name);
		scanf("%s", &files[i].extension);
		scanf("%d", &files[i].file_size);
	}
	
	//Puts the array of files into a binary file
	FILE *file = fopen("mybin.bin", "wb");
	fwrite(files, sizeof(file_t), n, file);
	fclose(file);
	
	return 0;
}