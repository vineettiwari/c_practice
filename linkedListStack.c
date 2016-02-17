/**
		linkedListStack.c

		@author		Vineet Tiwari
		@version	1.0
		@date			Feb 15, 2016
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
	int data;
	Node *next;
};

Node *top;

Node 	*GetNewNode(int);
void	Push(int);
int 	Pop();
void 	Print();

int main()
{
	top = NULL;

	printf("\n");
	Push(4);
	Push(8);
	Push(3);
	Pop();
	Push(12);
	Push(16);

	return(EXIT_SUCCESS);
}

Node *GetNewNode(int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if(!newNode)
		exit(EXIT_FAILURE);

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void Push(int value)
{
	Node *newNode = GetNewNode(value);

	if(!top)
	{
		top = newNode;
		return;
	}

	newNode->next = top;
	top = newNode;
	Print();
}

int Pop()
{
	if(!top)
	{
		printf("Error: List already empty.\n");
		exit(EXIT_FAILURE);
	}

	int popedValue;
	Node *tempNode = top;

	popedValue = tempNode->data;
	top = top->next;
	free(tempNode);

	return popedValue;
}

void Print()
{
	if(!top)
	{
		printf("List is empty.\n");
		return;
	}

	Node *currentNode = top;

	printf("Stack:\n");
	while(currentNode)
	{
		printf("%d --> ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n\n");
}

