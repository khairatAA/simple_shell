#include "shell.h"

/**
 * exit_builtin - handles the exit built-in
 * @cmd: the entered command
 * @status: the status passed wirh the exit
 */

void exit_builtin(char *cmd, char *status)
{
	int i = 0, exit_status;


	if (status == NULL)
	{
		exit(0);
	}
	while (status[i] != '\0')
	{
		if (!(status[i] >= '0' && status[i] <= '9'))
		{
			print_error(_getenv("_"));
			print_error(": 1: exit: Illegal number: ");
			write(2, status, strlen(status));
			write(2, "\n", 1);
			return;
		}
		i++;
	}
	exit_status = _atoi(status);
	free(cmd);
	cmd = NULL;
	exit(exit_status);
}

/**
 * _atoi - coverts string to integer
 * @str: the string to be converted
 * Return: the integer
 */

int _atoi(char *str)
{
	int result = 0, sign = 1, i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}

	return (sign * result);
}
