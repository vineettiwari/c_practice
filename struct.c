#include <stdio.h>

typedef struct 
{
	int value;
} Node;

Node nodeFunction(Node testNode)
{
   testNode.value = 12;
   return testNode;
}

int main(void)
{
  Node mainNode;
  mainNode = nodeFunction(mainNode);
  printf("The value in mainNode is: %d and its located at: %p\n", mainNode.value, &mainNode);

}