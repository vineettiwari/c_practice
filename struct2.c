// struct2.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


struct address
{
	char address1[50];
	char address2[50];
	char city[30];
	char prov[3];
	char postal[8];
};

struct contact
{
	char firstName[20];
	char lastName[20];
	struct address contactAddress;
	int age;
};


int main(void)
{
	struct contact contactOne = { "Johnny"
		                        , "Programmer"
				                , "1234 Main Street"
						        , ""
							    , "Burnaby"
						        , "BC"
							    , "V6T 3R4"
							    , 43 }; 

	struct contact *pContactOne = NULL;

    pContactOne = &contactOne;



	printf("%s %s\n%s\n%s\n%s %s  %s\n\nAge: %d\n\n", contactOne.firstName
		                                            , contactOne.lastName
											        , contactOne.contactAddress.address1
											        , contactOne.contactAddress.address2
											        , contactOne.contactAddress.city
											        , contactOne.contactAddress.prov
											        , contactOne.contactAddress.postal
											        , contactOne.age);


    printf("%s %s\n%s\n%s\n%s %s  %s\n\nAge: %d\n\n", pContactOne->firstName
		                                            , pContactOne->lastName
											        , pContactOne->contactAddress.address1
											        , pContactOne->contactAddress.address2
											        , pContactOne->contactAddress.city
											        , pContactOne->contactAddress.prov
											        , pContactOne->contactAddress.postal
											        , pContactOne->age);


    printf("%s %s\n%s\n%s\n%s %s  %s\n\nAge: %d\n\n", (*pContactOne).firstName
		                                            , (*pContactOne).lastName
											        , (*pContactOne).contactAddress.address1
											        , (*pContactOne).contactAddress.address2
											        , (*pContactOne).contactAddress.city
											        , (*pContactOne).contactAddress.prov
											        , (*pContactOne).contactAddress.postal
											        , (*pContactOne).age);


	return 0;
}