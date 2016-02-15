// enum.c
#include <stdio.h>

enum DayOfWeek
{
	  SUN = 1
	, MON
	, TUE
	, WED
	, THU
	, FRI
	, SAT
};

//typedef enum DayOfWeek Dow;


int main(void)
{
	enum DayOfWeek dow;
	//Dow dow;

	const char *dayNames[] = { "", "Sunday", "Monday", "Tuesday", "Wednesday"
		                         , "Thursday", "Friday", "Saturday" };

	dow = SAT;
	printf("%s\n", dayNames[dow]);

	dow = TUE;

	printf("%s\n", dayNames[dow]);

	printf("%s\n", dayNames[THU]);

	printf("%d\n", WED);
	
	return 0;
}