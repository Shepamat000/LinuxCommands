//P1-SSOO-23/24

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
	bool isFound = false;

	DIR * directory;

	if (argc < 3) {
		printf("Not enough arguments!");
		return -1;
	}

	directory = opendir(argv[1]);
	if (directory == NULL) { 
		printf("Unable to access directory %s \n", argv[1]);
		closedir(directory);
		return -1;
	}

	struct dirent *fileCheck;
	fileCheck = readdir(directory);
	

	while (fileCheck != NULL) {
		if (strcmp(fileCheck->d_name, argv[2]) == 0) {
			isFound = true;
		}
		fileCheck = readdir(directory);

	}

	if (isFound) 
		printf("File %s is in directory %s\n", argv[2], argv[1]);
	else
		printf("File %s is not in directory %s\n", argv[2], argv[1]);

}
