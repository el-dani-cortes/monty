#include "monty.h"
/**
 * check_integer - Check is a integer and convert to it.
 * @value: String to convert and validate.
 * @line_number: Line number read from bytecode file.
 *
 * Return: Always nothing.
 */
int check_integer(char *value, unsigned int line_number)
{
	int data, i;

	data = atoi(value);
	if (data == 0 && *value != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	for (i = 0; value[i] != '\0'; i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (EXIT_FAILURE);
		}
	}
	return (data);
}
