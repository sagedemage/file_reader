#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../third_party_libs/sds/sds.h"

bool read_file(const char* file_path, sds *buffer);

int main(int argc, char *argv[]) {
	const char* file_path = argv[1];
	
	if (file_path == NULL) {
		printf("File path is empty!\n");
		return -1;
	}

	sds buffer = sdsempty();
	
	if (!read_file(file_path, &buffer)) {
		return -1;
	}

	printf("Text file content: \n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%s\n", buffer);
	printf("-----------------------------------------------------------------------------\n");

	return 0;
}

bool read_file(const char* file_path, sds *buffer) {

	FILE *fptr;

	fptr = fopen(file_path, "r");

	if (fptr == NULL) {
		printf("Unable to open the file!: %s\n", file_path);
		return false;
	}

	char line[100];

	while(fgets(line, 100, fptr)) {
		char* line_p = line;
		*buffer = sdscat(*buffer, line_p);
	}

	sdstrim(*buffer, "\n");

	fclose(fptr);

	return true;
}
