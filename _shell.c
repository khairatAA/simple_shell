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
	size_t bufsize = 0;
	ssize_t characters;
	char *dup;	/* added variable */

	cmd = NULL;
	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		characters = getline(&cmd, &bufsize, stdin);
		if (characters == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error reading input");
				exit(EXIT_FAILURE);
			}
		}
		cmd[characters - 1] = '\0';
		if (_strlen(cmd) == 0 || _strspn(cmd, " \t\r\n") ==
			(size_t)_strlen(cmd))
			continue;
		/* check for comments */
		if (handle_comment(cmd) == NULL)
		{
			free(cmd);
			cmd = NULL;
			continue;
		}
		/* handle_comment modifies cmd */
		if (_strcmp(cmd, "env") == 0)
		{
			handle_env();
			free(cmd);
			cmd = NULL;
			continue;
		}
		if (_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			cmd = NULL;
			exit_builtin();
		}
		/* start of code to handle cd command */
		dup = _strdup(cmd);
		if (_strcmp(strtok(dup, " \t\r\n"), "cd") == 0)
		{
			change_dir(cmd);
			free(cmd);
			free(dup);
			dup = cmd = NULL;
			continue;
		}
		free(dup);
		/* end of code to handle cd command */
		execute_cmd(cmd, NULL);
		free(cmd);
		cmd = NULL;
	}
	free(cmd);
	cmd = NULL;
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
			free(cmd);
			cmd = NULL;
		}
		exit(0);
	}
}
