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
	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		cmd = get_command(); /* gets the command */
		/* cmd[_strcspn(cmd, "\n")] = '\0'; */
		/* if (_strlen(cmd) == 0) */
			/* continue; */
	}

	return (0);
}

/**
 * get_command - gets the command from the CL
 * Return: returns the command as a sring
 */
char *get_command(void)
{
	char cmd1[MAX_CMD_LENGTH];
	char *cmd_gotten = fgets(cmd1, sizeof(cmd1), stdin);

	if (cmd_gotten == NULL)
		exit(0);
	return (cmd_gotten);
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
