// printfC.c
#include <stdio.h>


int main(void)
{
	int charCountAll;
	int charCountPartial;
	
	_set_printf_count_output(1); // for %n functionality

	charCountAll = printf("Character count test\n");
	printf("%d characters were output\n\n", charCountAll);

	charCountAll = printf("Second character %ncount test\n", &charCountPartial);
	printf("Output %d characters to n\n", charCountPartial);
	printf("Output %d characters total\n\n\n", charCountAll);

	return 0;
}