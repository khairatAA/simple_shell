#include "shell.h"

/**
 * word_count - counts the tokenised string
 * @av: the string
 * @args: the token
 * Return: the count
 */
int word_count(char *av, char ***args)
{
	int count = 0, i;
	char *token;
	char **tokens = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (tokens == NULL)
		return (-1);
	token = strtok(av, " \t\r\n");
	while (token != NULL && count < MAX_ARGS)
	{
		(tokens)[count] = _strdup(token);
		token = strtok(NULL, " \t\r\n");
		count++;
	}
	tokens[count] = NULL;
	*args = tokens;
	for (i = 0; i < count; i++)
		free(tokens[i]);
	free(tokens);
	return (count);
}

/**
 * free_environ - frees the environ
 * @env: the eniron to be freed
 */

void free_environ(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
	free(env);
}
