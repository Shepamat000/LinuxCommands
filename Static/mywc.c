//P1-SSOO-23/24
// Code by Matthew Shepard, February 2024

#include <stdio.h>
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error and return -1*/
	if (argc < 2) {
		printf("Not enough arguments!");
		return -1;
	}
	int fd;

	// Open file
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) return -1;

	// Read file
	long long fileSize = 1;
	int num_bytes = 1;
	long long returnSize = 0;
	bool hitSpace = true;
	// Return vars
	long long numLines = 0;
	long long numWords = 0;
	
	while (fileSize > 0) {
		char data[num_bytes];
		fileSize = read(fd, data, num_bytes);
		// If the reader hits a space, or is just beginning, we can iterate numWords next time a char is hit
		if (data[0] == ' ' || data[0] == '	') {
			hitSpace = true;
		// Iterate numLines when a line character is hit
		} else if (data[0] == '\n'){
			numLines++;
			hitSpace = true;
		} else if (hitSpace)  {
			numWords++;
			hitSpace = false;
		}
		// Iterate numbytes each sucessful bitread
		if (fileSize > 0) returnSize++;
	}
	printf(" %lld %lld %lld %s\n", numLines, numWords, returnSize, argv[1]);

	fd = close(fd);

	return 0;
}



