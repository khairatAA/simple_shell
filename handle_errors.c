#include "shell.h"

/**
 * print_error - writes a string to the stderr
 * @str: the string to be written
 * Return: the number of character written
 */

int print_error(char *str)
{
	int i = 0;

	if (!(str))
		return (0);
	while (str[i])
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}

	return (i);
}

/**
 * _perror - prints the error format to the stderr
 * @cmd: the command passed by the user
 * @error_message: the error message to be displayed by the user
 */

void _perror(const char *cmd, char *error_message)
{
	char *program_name = _strdup((char *)cmd);
	char *first_command = strtok(program_name, " \t\r\n");

	print_error(_getenv("_"));
	print_error(": 1: ");
	print_error(first_command);
	print_error(": ");
	print_error(error_message);
	print_error("\n");
	free(program_name);
}
