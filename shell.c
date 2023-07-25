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

int updated = 0;

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
	char *status = NULL, *exit_str = "exit ", *status_copy, *dup;

	cmd = NULL;
	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		characters = getline(&cmd, &bufsize, stdin);
		if (characters == -1)
		{
			break;
		}
		cmd[characters - 1] = '\0';
		if (_strlen(cmd) == 0 || _strspn(cmd, " \t\r\n") ==
			(size_t)_strlen(cmd))
			continue;
		/* check for comments, handle_comment modifies cmd */
 		if (handle_comment(cmd) == NULL)
 		{
			free(cmd);
			cmd = NULL;
			continue;
		}
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
			exit_builtin(cmd, NULL);
			continue;
		}
		/* Handle cd command */
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
		if (_strncmp(cmd, exit_str, _strlen(exit_str)) == 0)
		{
			status = cmd + _strlen(exit_str);
			if (status[0] == '\0')
				status = NULL;
			status_copy = (status != NULL) ? _strdup(status) : NULL;
			free(cmd);
			cmd = NULL;
			exit_builtin(status_copy, status_copy);
			free(status_copy);
			status_copy = NULL;
			continue;
		}
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
		if (updated == 1)
		{
			free_environ(environ);
		}
		exit(0);
	}
}
