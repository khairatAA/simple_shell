#include "shell.h"

/**
 * countArgs - count the number of command line arguments
 * @cmd: the command line argument
 * Return: the number of command line arguments
 */

int countArgs(const char *cmd)
{
	char *token, *delimiters = " \n\t\r", *copy_cmd;
	int num_tokens = 0;

	copy_cmd = _strdup((char *)cmd);
	if (copy_cmd == NULL)
	{
		perror("Error duplicating command string");
		exit(EXIT_FAILURE);
	}
	token = strtok(copy_cmd, delimiters);
	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delimiters);
	}
	free(copy_cmd);
	return (num_tokens);
}

/**
 * split_string - this function tokenize the string
 * @cmd: command to be tokenized
 * Return: the tokenized command
 */

char **split_string(const char *cmd)
{
	char *token, *delimiters = " \n\t\r", *copy_cmd;
	char **av;
	int i = 0, j, num_tokens;

	copy_cmd = _strdup((char *)cmd);
	if (copy_cmd == NULL)
	{
		perror("Error duplicating command string");
		exit(EXIT_FAILURE);
	}
	num_tokens = countArgs(copy_cmd);
	av = (char **)malloc(sizeof(char *) * (num_tokens + 1));
	if (av == NULL)
	{
		perror("Allocating memory using malloc failed");
		free(copy_cmd);
		exit(EXIT_FAILURE);
	}
	token = strtok(copy_cmd, delimiters);
	while (token)
	{
		av[i] = _strdup(token);
		if (av[i] == NULL)
		{
			perror("Error duplicating token string");
			for (j = 0; j < i; j++)
				free(av[j]);
			free(av);
			free(copy_cmd);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delimiters);
		i++;
	}
	av[i] = NULL;
	free(copy_cmd);
	return (av);
}

/**
 * execute_cmd - it executes the command
 * @cmd: the command to be executed
 * @envp: envp is set to NULL
 * Return: nothing
 */
void execute_cmd(const char *cmd, char *const envp[])
{
	int status;
	char **new_av = split_string(cmd);
	pid_t pid;
	char *path_cmd = NULL;

	if (new_av == NULL)
	{
		perror("Error splitting command");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		_perror(cmd, "not found");
		free_new_av(new_av);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		path_cmd = handle_path(new_av[0]);
		if (path_cmd == NULL)
		{
			_perror(cmd, "not found");
			free_new_av(new_av);
			free(path_cmd);
			free((void *)cmd);
			exit(EXIT_FAILURE);
		}
		else if (execve(path_cmd, new_av, envp) == -1)
		{
			_perror(cmd, "not found");
			free_new_av(new_av);
			free(path_cmd);
			free((void *)cmd);
			_exit(1);
		}
	}
	else
		waitpid(pid, &status, 0);
	free_new_av(new_av);
	free(path_cmd);
}

/**
 * free_new_av - it frees the new_av variable used in the execve function
 * @new_av: the variable to be freed
 */
void free_new_av(char **new_av)
{
	int i = 0;

	if (new_av == NULL)
		return;
	for (; new_av[i] != NULL; i++)
	{
		free(new_av[i]);
	}
	free(new_av);
}
