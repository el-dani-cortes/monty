#include "monty.h"
/**
 * push_stack - add node into a doubly linked list(stack).
 * @stack: Pointer head of the double linkedlist.
 * @line_number: line number of bytecode file.
 *
 * Return: Always nothing.
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *value;
	int data;

	value = strtok(NULL, " ");
	data =  check_integer(stack, value, line_number);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(stack, vars.buffer, vars.fd);
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;
	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	*stack = new_node;
}
