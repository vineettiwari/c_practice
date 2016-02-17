#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_BUFF 20
#define LINE_BUFF 200

typedef struct stackNode
{
	char value[STR_BUFF];
	struct stackNode *pNext;
} StackNode;

void push(StackNode **pHead, char *pToken)
{
	StackNode *pNew = malloc(sizeof(StackNode));

	if(!pNew)
		printf("%s not pushed. No memory available.\n", pToken);

	strcpy(pNew->value, pToken);
	pNew->pNext = *pHead;
	*pHead = pNew;
}

char *pop(StackNode **pHead)
{
	if(!*pHead)
		printf("%s\n", "Stack is empty.");

	char *popValue = malloc(sizeof(char) * STR_BUFF);
	StackNode *pTemp = *pHead;
	*pHead = (*pHead)->pNext;

	strcpy(popValue, pTemp->value);
	free(pTemp);

	return popValue;
}

int main()
{
	char input[LINE_BUFF], temp[LINE_BUFF];
	char *pToken = NULL;
	StackNode *pHead = NULL;
	unsigned length;

	printf("\nEnter a sentence:\n");

	fgets(input, LINE_BUFF, stdin);
	length = strlen(input);
	input[length - 1] = '\0';

	strcpy(temp, input);

	pToken = strtok(temp, ",. ");
	while(pToken)
	{
		push(&pHead, pToken);
		pToken = strtok(NULL, ",. ");
	}

	printf("\n");

	while(pHead)
	{
		printf("%s\n", pop(&pHead));
	}

	printf("\n");
	return EXIT_SUCCESS;
}
