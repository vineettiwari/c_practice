/*
	============================================================================
 	Name        :	doublyLinkedList.c
 	Author      :	Vineet Tiwari
 	Version     :	1.0
 	Description	:	Understand how to create and manipulate doubly linked lists.
 	============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
	int 	data;
	Node 	*prev,
				*next;
};

Node *GetNewNode(int);
void InsertAtHead(int);
void InsertAtTail(int);
void Print();
void ReversePrint();

Node *head;

int main()
{
	head = NULL;
	int value;

	fprintf(stdout, "\n%s\n%s\n", "Populate the list with positive integer.",
		"Then to exit, enter a negative integer.");

	do
	{
		printf("? ");
		scanf("%d", &value);
		
		// InsertAtHead(value);
		InsertAtTail(value);
	} while(value >= 0);

	printf("\n");
	Print();
	ReversePrint();
	
	return EXIT_SUCCESS;
}

Node *GetNewNode(int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	if(!newNode)
		fprintf(stderr, "Error: %d not inserted. No memory available.\n", value);

	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void InsertAtHead(int value)
{
	if(value < 0)
		return;

	Node *newNode = GetNewNode(value);

	if(!head)
	{
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void InsertAtTail(int value)
{
	if(value < 0)
		return;

	Node *newNode = GetNewNode(value);
	Node *currentNode = head;

	if(!head)
	{
		head = newNode;
		return;
	}

	while(currentNode->next)
		currentNode = currentNode->next;

	currentNode->next = newNode;
	newNode->prev = currentNode;
}

void Print()
{
	Node *currentNode = head;
	if(!currentNode)
		return;

	printf("%s\n", "Forward:");
	while(currentNode)
	{
		printf("%d --> ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n\n");
}

void ReversePrint()
{
	Node *currentNode = head;
	if(!currentNode)
		return;

	while(currentNode->next)
		currentNode = currentNode->next;

	printf("%s\n", "Reverse:");
	while(currentNode)
	{
		printf("%d --> ", currentNode->data);
		currentNode = currentNode->prev;
	}
	printf("NULL\n\n");
}
