#include "monty.h"
/**
 * check_integer - Check is a integer and convert to it.
 * @value: String to convert and validate.
 * @line_number: Line number read from bytecode file.
 *
 * Return: Always nothing.
 */
int check_integer(stack_t **head, char *value, unsigned int line_number)
{
	int data, i;

	data = atoi(value);
	if (data == 0 && *value != '0')
	{
		free_all(head, vars.buffer, vars.fd);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; value[i] != '\0'; i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '-')
		{
			free_all(head, vars.buffer, vars.fd);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (data);
}
