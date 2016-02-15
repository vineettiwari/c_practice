// printfA.c
#include <stdio.h>

int main(void)
{
	printf("Without formatting\n\n");
	printf("%s %s %s\n%s\n", "Part#","Description","Price", "-------------------------------------------");
	printf("%s %s %f\n", "AB001", "WD 2TB Hard Drive", 159.99);
	printf("%s %s %f\n", "CC012", "Intel 4770K CPU", 339.99);
	printf("%s %s %f\n", "CC008", "Intel 3550 CPU", 229.99);
	printf("%s %s %f\n", "AB003", "WD 3TB Hard drive", 219.99);
	printf("%s %s %f\n\n", "ME015", "GSkill 16GB (2x8GB) Memory", 149.99);

	printf("With Formatting\n\n");
	printf("%-6s %-28s %7s\n%s\n", "Part#","Description","Price", "-------------------------------------------");
	printf("%-6s %-28s %7.2f\n", "AB001", "WD 2TB Hard Drive", 159.99);
	printf("%-6s %-28s %7.2f\n", "CC012", "Intel 4770K CPU", 339.99);
	printf("%-6s %-28s %7.2f\n", "CC008", "Intel 3550 CPU", 229.99);
	printf("%-6s %-28s %7.2f\n", "AB003", "WD 3TB Hard drive", 219.99);
	printf("%-6s %-28s %7.2f\n\n\n", "ME015", "GSkill 16GB (2x8GB) Memory", 149.99);

	return 0;
}
