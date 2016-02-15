// typedef.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


struct person
{
	char firstName[30];
	char lastName[30];
	int age;
};

typedef struct person Person;

int main(void)
{
	Person person = { "Moe", "Howard", 63 };
	Person person2 = person;
	Person person3;

	Person *pPerson = NULL;

	pPerson = &person2;

	strcpy(person3.firstName, "Larry");
	strcpy(person3.lastName, "Fine");
	person3.age = 59;

	strcpy(person2.firstName, "Curley");

	printf("%s\n%s\n%d\n\n"
		   , person.firstName
		   , person.lastName
		   , person.age);


	printf("%s\n%s\n%d\n\n"
		   , person2.firstName
		   , person2.lastName
		   , person2.age);


	printf("%s\n%s\n%d\n\n"
		   , pPerson->firstName
		   , pPerson->lastName
		   , (*pPerson).age);


	printf("%s\n%s\n%d\n\n"
		   , person3.firstName
		   , person3.lastName
		   , person3.age);


    printf("\nAddress of struct:    %p", &person);
    printf("\nAddress of firstname: %p", &person.firstName);
    printf("\nAddress of lastname:  %p", &person.lastName);
    printf("\nAddress of age:       %p\n", &person.age);

	printf("\nSize of struct: %u\n", sizeof(person));

	return 0;
}