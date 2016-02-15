// struct1.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct person
{
	char firstName[30];
	char lastName[30];
	int age;
};


int main(void)
{
	struct person member = { "Moe", "Howard", 63 };
	struct person member2 = member;
	struct person member3;

	struct person *pMember = NULL;

	pMember = &member2;

	strcpy(member3.firstName, "Larry");
	strcpy(member3.lastName, "Fine");
	member3.age = 59;

	strcpy(member2.firstName, "Curley");

	printf("%s\n%s\n%d\n\n"
		   , member.firstName
		   , member.lastName
		   , member.age);


	printf("%s\n%s\n%d\n\n"
		   , member2.firstName
		   , member2.lastName
		   , member2.age);


	printf("%s\n%s\n%d\n\n"
		   , pMember->firstName
		   , pMember->lastName
		   , (*pMember).age);


	printf("%s\n%s\n%d\n\n"
		   , member3.firstName
		   , member3.lastName
		   , member3.age);


    printf("\nAddress of struct:    %p", &member);
    printf("\nAddress of firstname: %p", &member.firstName);
    printf("\nAddress of lastname:  %p", &member.lastName);
    printf("\nAddress of age:       %p\n", &member.age);

	printf("\nSize of struct: %u\n", sizeof(member));

	return 0;
}