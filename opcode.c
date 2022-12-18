#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int stack_top = -1;

void push(int value)
{
	if (stack_top == MAX_STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: stack overflow\n");
		exit(EXIT_FAILURE);
	}

	stack[++stack_top] = value;
}

void pall()
{
	for (int i = stack_top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <opcode> <int>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *opcode = argv[1];

	if (strcmp(opcode, "push") == 0)
	{
		if (argc != 3)
		{
			fprintf(stderr, "L<line_number>: usage: push integer\n");
			exit(EXIT_FAILURE);
		}

		int value = atoi(argv[2]);
		push(value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall();
	}
	else
	{
		fprintf(stderr, "Error: invalid opcode\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
