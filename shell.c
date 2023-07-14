#include "shell.h"

/**
 * prompt - displays the prompt for the shell
 */

void prompt(void)
{
	int _prompt;

	_prompt = write(STDOUT_FILENO, "$ ", 2); /* Display prompt */
	if (_prompt == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - the entry point of the simple shell
 * @ac: command line argument count
 * @av: string containing the command line argument
 * Return: 0 on success
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char cmd1[MAX_CMD_LENGTH];

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		cmd = fgets(cmd1, sizeof(cmd1), stdin);
		if (cmd == NULL)
			exit(0);
		cmd1[_strcspn(cmd1, "\n")] = '\0';
		if (_strlen(cmd1) == 0)
			continue;
		execute_cmd(cmd, NULL);
	}

	return (0);
}

/**
 * handle_signal - signal handler when ctrl + c is pressed
 * @sig: holds the SIGINT
 * Return: nothing
 */
void handle_signal(int sig)
{
	write(1, "\n", 1);
	if (sig == SIGINT)
	{
		if (cmd != NULL)
		{
			/* free(cmd); */
			cmd = NULL;
		}
		exit(0);
	}
}
