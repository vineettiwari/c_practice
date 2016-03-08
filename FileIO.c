#include <stdio.h>
#include <stdlib.h>

#define BUFF 100

int main()
{
	FILE *input_ptr, *output_ptr;
	char ch,
	*input_file = malloc(sizeof(char) * BUFF),
	*output_file = malloc(sizeof(char) * BUFF);

	if (!input_file || !output_file) {
		fprintf(stderr, "%s\n", "ERROR: Memory unavailable");
		exit(EXIT_FAILURE);
	}

	printf("\n");
	printf("%26s ", "Enter the input filename:");
	scanf("%s", input_file);
	while (getchar() != '\n')
		continue;

	printf("%26s ", "Enter the output filename:");
	scanf("%s", output_file);
	while (getchar() != '\n')
		continue;

	input_ptr = fopen(input_file, "r");
	output_ptr = fopen(output_file, "w");

	if (!input_ptr || !output_ptr) {
		fprintf(stderr, "%s\n",
			"ERROR: Unable to open one of the files");
		exit(EXIT_FAILURE);
	}

	while (!feof(input_ptr)) {
		fscanf(input_ptr, "%c", &ch);
		fprintf(output_ptr, "%c", ch);
	}
	
	fflush(output_ptr);
	fclose(input_ptr);
	fclose(output_ptr);

	free(input_file);
	free(output_file);

	return EXIT_SUCCESS;
}

