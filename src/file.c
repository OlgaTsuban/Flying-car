#include "../inc/file.h"

void write_int_to_file(int number, char *path_to_file) {
    FILE *output = NULL;

	output = fopen(path_to_file, "wb");
	if (output == NULL) {
		printf("Error opening file");
	}

	fwrite(&number, sizeof(int), 1, output);

	fclose(output);
}

int load_int_from_file(char *path_to_file) {
    int number = 0;
 
    FILE *file = fopen(path_to_file, "a+b");
    if (file != NULL) {
    	fread(&number, sizeof(int), 1, file);
    	fclose(file);
	}
	
	return number;
}

