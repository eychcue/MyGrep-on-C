#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char *argv[]) {

	char* filename = argv[argc - 1];
	FILE* f = fopen(filename, "r");

	if (f == NULL) {						/* Checks that file exists */
		printf("Error: file %s not found\n", argv[argc - 1]);
		exit(-1);
	}

	if (strcmp(argv[1], "-c")) {
		if (argc == 5) {
			/* Call case insensitive -c func with specified arguments */
		}
		else {
			/* Call -c func with specified arguments */
		}
	}

	else if (strcmp(argv[1], "-o")) {
		/* Call -o func with specified arguments */
	}

	else if (strcmp(argv[1], "-s")) {
		funcS(f);
	}

	else if (strcmp(argv[1], "-n")) {
		if (argc == 4) {
			/* Call -n func with string argument included */
		}
		/* Call -n func with specified arguments */
	}

	else if (strcmp(argv[1], "-k")) {
		/* Call -k func with specified arguments */
	}

	else {
		printf("Error, command %s not found\n", argv[1]);
	}
}


/* -s command, removes leading spaces from each line and then outputs the result */
/* Does not edit the source file */
void funcS(FILE* f) {
	char c;								// character to store value of fgetc() from file
	int lineStart = 1;					// boolean to represent whether or not this is a new line, initialized as true.
	while ((c = fgetc(f)) != EOF) {		// while not end of file, reads whole file
		if (!lineStart) {
			if (c == '\n') {			// new line, start removing spaces again
				lineStart = 1;
			}
			else {						// prints line until it reaches \n
				printf("%c", c);
			}
		}
		else {
			if (c != ' ') {				// find first non-space char in line and starts printing
				lineStart = 0;
				printf("%c", c);
			}
		}
	}
}