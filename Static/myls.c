//P1-SSOO-23/24
// Code by Matthew Shepard, February 2024

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
	DIR * directory;

	if (argc < 2) {
		// Use current directory
		directory = opendir(".");
		if (directory == NULL) { 
			printf("Unable to access current directory.");
			closedir(directory);
			return -1;
		}

		struct dirent *currentFile;
		currentFile = readdir(directory);
	

		while (currentFile != NULL) {
			printf("%s\n", currentFile->d_name);
			currentFile = readdir(directory);
		}
		closedir(directory);
		return 0;
	} else {
		// Use argument as directory
		directory = opendir(argv[1]);
		if (directory == NULL) { 
			printf("Unable to access directory %s \n", argv[1]);
			closedir(directory);
			return -1;
		}

		struct dirent *currentFile;
		currentFile = readdir(directory);
	

		while (currentFile != NULL) {
			printf("%s\n", currentFile->d_name);
			currentFile = readdir(directory);
		}

		closedir(directory);
		return 0;
	}

	return -1;
}
