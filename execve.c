#include "shell.h"

/**
 * countArgs - count the number of command line arguments
 * @cmd: the command line argument
 * Return: the number of command line arguments
 */

int countArgs(const char *cmd)
{
	char *token, *delimiters = " \n\t\r", *copy_cmd;
	int count = 0;

	copy_cmd = _strdup((char *)cmd);
	if (copy_cmd == NULL)
	{
		perror("Error duplicating the string");
		exit(EXIT_FAILURE);
	}
	token = strtok(copy_cmd, delimiters);
	while (token)
	{
		count++;
		token = strtok(NULL, delimiters);
	}
	free(copy_cmd);

	return (count);
}

/**
 *
 */
char **spilt_string(const char *cmd, int ac)
{
	char *token, *delimeters = " \n\t\r", *copy_cmd;
	char **av;
	int i = 0;

	copy_cmd = _strdup((char*)cmd);
	av = (char **)malloc(sizeof(char *) * (ac + 1));
	if (av == NULL)
	{
		perror("Allocating memory using malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(copy_cmd, delimeters);
	while (token)
	{
		av[i] = _strdup(token);
		token = strtok(NULL, delimeters);
		i++;
	}
	av[ac] = NULL;
	free(copy_cmd);
	return (av);
}

/**
 *
 */
void execute_cmd(const char *cmd, char *const envp[])
{
	int ac = countArgs(cmd), status;
	char **new_av = spilt_string(cmd, ac);
	pid_t pid;

	if (new_av == NULL)
	{
		perror(new_av[0]);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(new_av[0]);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(new_av[0], new_av, envp) == -1)
		{
			perror(new_av[0]);
			free_new_av(new_av);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free_new_av(new_av);
}

/**
 *
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
