/*
 * Name:	ReduceFile.c
 * Purpose:	Reduces your files by two-thirds
 */

#include <stdio.h>
#include <stdlib.h> /* for exit() */
#include <string.h>

int main(int argc, char *argv[]) {

	FILE *in, *out; /* declare two FILE pointers */
	int ch, length = strlen(argv[1]) - 4;
	char name[length]; /* storage for output filename */
	unsigned long count1 = 0, count2 = 0;	
	
	printf("1\n In Length: %ld\n    Length: %d\nOut Length: %ld\n",
	strlen(argv[1]), length, strlen(name));
	
	/* check for command-line arguments */
	if (argc < 2) {	
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	/* set up input */
	if (!(in = fopen(argv[1], "r"))) {
		fprintf(stderr, "I couldn't open the file \"%s\"\n",
		argv[1]);
		exit(EXIT_FAILURE);
	}
	
	/* set up output */
	strncpy(name, argv[1], length); /* copy filename */
	name[length] = '\0'; /* add null terminater at the end */
	strcat(name,"_red.txt"); /* append .red */
	if (!(out = fopen(name, "w"))) {
		/* open file for writing */
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	
	/* copy data */
	while ((ch = getc(in)) != EOF) {
		if (count1++ % 3 == 0 || ch == ' ' || ch == '\n') {
			putc(ch, out); /* print every 3rd char */
			count2++;
		}
	}

	/* clean up */
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr,"Error in closing files\n");
	
	printf("2\n In Length: %ld\n    Length: %d\nOut Length: %ld\n",
	strlen(argv[1]), length, strlen(name));

	printf("\nFile %s has %lu characters.\n"
		"File %s has %lu characters.\n\n",
		argv[1], count1, name, count2);

	return EXIT_SUCCESS;
}




