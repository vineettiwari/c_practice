/**
		arrayStack.c

		@author 	Vineet Tiwari
		@version 	1.0
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int Stack[MAX_SIZE];
int top = -1;

void Push(int);
int Pop();
int Top();
void Print();

int main()
{
	Push(4);
	Push(8);
	Push(3);
	Pop();
	Push(12);
	Push(16);

	printf("\n");
	return EXIT_SUCCESS;
}

void Push(int value)
{
	if(top == MAX_SIZE - 1)
	{
		printf("Error: Stack overflow\n");
		return;
	}

	Stack[++top] = value;
	Print();
}

int Pop()
{
	if(top == -1)
	{
		printf("Error: Stack empty\n");
	}

	int popedValue = Top();
  top--;

	return popedValue;
}

int Top()
{
	return Stack[top];
}

void Print()
{
	int index;

	printf("\nStack:\n");
	for(index = 0; index <= top; index++)
		printf("%d --> ", Stack[index]);
	printf("NULL\n");
}



