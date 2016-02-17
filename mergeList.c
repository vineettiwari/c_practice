/**
    COMP 2717 Asn 4
    mergeList.c
    Purpose: 	Create two sorted linkedlists based on user input.
    					Merge said linkedlists into one big sorted list without
    					allocating memory for any new node.

    @author Vineet Tiwari
    @version 1.0 02/11/16
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Linked list structure
typedef struct node Node;
struct node
{
	int value;
	Node *pNext;
};

// List title enumeration
typedef enum
{
	firstList,
	secondList,
	mergedList
} listNum;

// Function forward declaration
void Insert(Node **, int);
Node *Create(int);
Node *Merge(Node *, Node *);
void Print(Node **, int);

int main()
{
	Node *pHead1; // Pointers to the base
	Node *pHead2; // of each Linked lists

	pHead1 = Create(1); // Create first list

	pHead2 = Create(2); // Create second list

	putchar('\n');

	listNum currentList = firstList; // Setup list title
	Print(&pHead1, currentList); // Print first list

	currentList = secondList; // Setup list title
	Print(&pHead2, currentList); // Print second list

	pHead1 = Merge(pHead1, pHead2); // Merge both lists and point pHead1
																	// to the base of the merged list
	currentList = mergedList; // Setup list title
	Print(&pHead1, currentList); // Print merged list

	return EXIT_SUCCESS;
}

// Function to insert new node with input value
void Insert(Node **pHead, int input)
{
	if(input >= 0)
	{
		Node *pPrevious, *pCurrent, *pNew;	// Pointers needed to reference
																				// and menuplate the list
		pPrevious = NULL;
		pCurrent = *pHead;

		pNew = malloc(sizeof(Node));	// Allocate memory in Heap(free memory pool)
		if(!pNew)											// for new node
		{															// Print error message if memory in Heap
																	// is unavalable and exit function
			printf("%d not inserted. No memory available.\n", input);
			return;
		}

		pNew->value = input; // Store input in new node
		pNew->pNext = NULL;	// Set the next pointer of new node to 0

		while(pCurrent && input > pCurrent->value)
		{																// As long as pointer to current is 
			pPrevious = pCurrent;					// not NULL and the input is greate  
			pCurrent = pCurrent->pNext;		// than the value in current node
		}																// keep traversing the list

		if(!pPrevious)           	// If the base node is NULL then point
		{													// the head pointer to the new node
			pNew->pNext = *pHead;
			*pHead = pNew;
		}
		else												// Otherwise, insert the new node right
		{														// before the current node and assign the 
			pPrevious->pNext = pNew;	// memory addresses to pointers accordingly
			pNew->pNext = pCurrent;
		}
	}
}

// Function to create the sorted linked lists
// Has the insert function nested within
Node *Create(int listNum)
{
	Node *pHead = NULL;	// Not pointing at any list
	int input = 0;

	if(listNum == 1)	// Check the list title
	{									// and print instructions accordingly
		printf("\n%s\n",	"Input positive integers for the first list "
											"(end with a negative integer):");
	}
	else if(listNum == 2)
	{
		printf("\n%s\n",	"Input positive integers for the second list "
											"(end with a negative integer):");
	}

	do 	// Loop for populating the linked lists
	{
		printf("? ");

		scanf("%d", &input);
		while(getchar() != '\n');

		Insert(&pHead, input);
	} while(input >= 0); 	// Populate until the input
												// is a neditive number
	return pHead;
}

// Function for merging bothe linked lists
Node *Merge(Node *pHead1, Node *pHead2)
{
	Node *pHead;

	if(!pHead1)				// If first list is empty then return
		return pHead2;	// second list

	if(!pHead2)				// If second list is empty then return
		return pHead1;	// first list

	// Compare the nodes in both linked lists and swape the nodes
	// if needed to make sure the merged linked list is ordered
  if(pHead1->value < pHead2->value)
  {
    pHead = pHead1;
  } 
  else 
  {
    pHead = pHead2;
    pHead2 = pHead1;
    pHead1 = pHead;
  }

  while(pHead1->pNext && pHead2)
  {
    if(pHead1->pNext->value > pHead2->value)
    {
      Node *pTemp = pHead1->pNext;
      pHead1->pNext = pHead2;
      pHead2 = pTemp;
    }
    pHead1 = pHead1->pNext;
  } 

  if(!pHead1->pNext)
  	pHead1->pNext = pHead2;

  return pHead; // Return the pointer to the base node to 
}								// the merged list

// Function to print all the nodes in the list
// starting from the base node
void Print(Node **pHead, int listNum)
{
	Node *pCurrent = *pHead; 	// Assign the address for base node of
	char list[16];						// the linked list to current pointer

	// Copy the linked list's title appropriately
	if(listNum == 0)
	{
		strcpy(list, "first");
	}
	else if(listNum == 1)
	{
		strcpy(list, "second");
	}
	else if(listNum == 2)
	{
		strcpy(list, "merged");
	}

	if (!pCurrent)
  {
  	printf("List is empty.\n\n");
  }
  else
  { 
  	printf("Contents of %s list:\n", list);

    while (pCurrent)	// Print the linked list nodes in order
    { 
      printf("%d --> ", pCurrent->value);
      pCurrent = pCurrent->pNext;  
    }

    printf("NULL\n\n");
  }
}

