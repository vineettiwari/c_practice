/*
 * Name:	CopyFileIO.c
 * Purpose:	Copy the contents of one file to another 
 * 		using the File I/O operations.
 */

#include <stdio.h>
#include <stdlib.h> /* exit() prototype */

int main(int argc, char *argv[])
{
	
	int ch; /* place to store each character as read */
	FILE *input_ptr, *output_ptr; /* "file pointer" */
	
	if (argc != 3) {
		fprintf(stderr,
		"Usage: %s filename\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	input_ptr = fopen(argv[1], "r");
	output_ptr = fopen(argv[2], "w");
	if (!input_ptr || !output_ptr) {
		fprintf(stderr,
		"Error: Failed to open one of the files.\n");
		exit(EXIT_FAILURE);
	}
		
	while ((ch = getc(input_ptr)) != EOF) {
		putc(ch, output_ptr); /* same as putchar(ch) */
	}
	
	if ((fclose(input_ptr) != 0) || (fclose(output_ptr) != 0)) {
		fprintf(stderr,
		"Error: Failed to close one of the files.\n");
		exit(EXIT_FAILURE);
	}
		
	printf("\n%s was copied into %s successfully.\n\n",
	argv[1], argv[2]);
	
	return EXIT_SUCCESS;
}




