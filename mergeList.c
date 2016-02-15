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

typedef struct node
{
	int value;
	struct node *pNext;
} Node;

typedef enum
{
	firstList,
	secondList,
	mergedList
} listNum;

void pushNode(Node **, int );
Node *create(int);
Node *merge(Node *, Node *);
void printList(Node **, int );

int main()
{
	Node *pHead1;
	Node *pHead2;

	pHead1 = create(1);

	pHead2 = create(2);

	putchar('\n');

	listNum currentList = firstList;
	printList(&pHead1, currentList);

	currentList = secondList;
	printList(&pHead2, currentList);

	pHead1 = merge(pHead1, pHead2);
	currentList = mergedList;
	printList(&pHead1, currentList);

	return EXIT_SUCCESS;
}

void pushNode(Node **pHead, int input)
{
	if(input >= 0)
	{
		Node *pPrevious, *pCurrent, *pNew;

		pPrevious = NULL;
		pCurrent = *pHead;

		pNew = malloc(sizeof(Node));
		if(!pNew)
			printf("%d not inserted. No memory available.\n", input);

		pNew->value = input;
		pNew->pNext = NULL;

		while(pCurrent && input > pCurrent->value)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		if(!pPrevious)
		{
			pNew->pNext = *pHead;
			*pHead = pNew;
		}
		else
		{
			pPrevious->pNext = pNew;
			pNew->pNext = pCurrent;
		}
	}
}

Node *create(int listNum)
{
	Node *pHead = NULL;
	int input = 0;

	if(listNum == 1)
	{
		printf("\n%s\n",	"Input positive integers for the first list "
											"(end with a negative integer):");
	}
	else if(listNum == 2)
	{
		printf("\n%s\n",	"Input positive integers for the second list "
											"(end with a negative integer):");
	}

	do
	{
		printf("? ");

		scanf("%d", &input);
		while(getchar() != '\n');

		pushNode(&pHead, input);
	} while(input >= 0);

	return pHead;
}

Node *merge(Node *pHead1, Node *pHead2)
{
	Node *pHead;

	if(!pHead1)
		return pHead2;

	if(!pHead2)
		return pHead1;

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

  return pHead;
}

void printList(Node **pHead, int listNum)
{
	Node *pCurrent = *pHead;
	char list[16];

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

    while (pCurrent)
    { 
      printf("%d --> ", pCurrent->value);
      pCurrent = pCurrent->pNext;  
    }

    printf("NULL\n\n");
  }
}

