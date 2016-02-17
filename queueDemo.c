/*
	=================================================================================
	Name				: queueDemo.c
	Author			: Vineet Tiwari
	Version			:	1.0
	Description	:
	=================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
	int data;
	Node *next;
};

Node *top = NULL;
Node *tail = NULL;

void Enqueue(int);
void Dequeue();
void Print();

int main()
{
	printf("\n");
	Enqueue(3);
	Enqueue(12);
	Enqueue(9);
	Dequeue();
	Enqueue(4);
	Print();

	return EXIT_SUCCESS;
}

void Enqueue(int value)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(!newNode)
	{
		printf("Error: %d was not queued. Memory not available.\n",
		value);
		return;
	}
	
	newNode->data = value;
	newNode->next = NULL;

	if(!top)
	{
		top = newNode;
	}
	else
	{
		tail->next = newNode;
	}

	tail = newNode;
}

void Dequeue()
{
	int dequeueValue;
	Node *tempNode = top;

	if(!top)
	{
		printf("Error: List is already empty.\n");
		exit(EXIT_FAILURE);
	}

	dequeueValue = top->data;
	top = top->next;

	free(tempNode);
}

void Print()
{
	Node *current = top;
	if(!top)
	{
		printf("%s\n", "List is empty.");
	}

	printf("%s\n", "Queue:");
	while(current)
	{
		printf("%d --> ", current->data);
		current = current->next;
	}
	printf("NULL\n\n");
}

