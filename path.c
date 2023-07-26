#include "shell.h"

/**
 * handle_path - it is used to handle the path environ
 * @cmd: the command to check if its in the path environ
 * Return: the path if its in the path environ
 */

char *handle_path(const char *cmd)
{
	const char *var = "PATH";
	const char *delim = ":";
	char *path = _getenv(var), *path_copy = NULL, *path_token;
	char *file_path = NULL;
	size_t cmd_len = _strlen(cmd), dir_len;
	struct stat check_path;

	if (path == NULL)
	{
		_perror(cmd, "not found");
		exit(EXIT_FAILURE);
	}
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	path_token = strtok(path_copy, delim);
	while (path_token)
	{
		dir_len = _strlen(path_token);
		if (dir_len + cmd_len + 2 <= MAX_PATH_LENGTH)
		{
			file_path = (char *)malloc(dir_len + cmd_len + 2);
			if (file_path == NULL)
			{
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			if (stat(file_path, &check_path) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			free(file_path);
			file_path = NULL;
		}
		path_token = strtok(NULL, delim);
	}
	free(path_copy);
	if (access(cmd, X_OK) == 0)
		return ((char *)cmd);
	return (NULL);
}

/**
 * _getenv - it gets the environ variable
 * @str: the string to be checked if it's in the environ
 * Return: the environ if present
 */

char *_getenv(const char *str)
{
	char **env = environ;
	char *find_equalto;
	int len;

	while (*env != NULL)
	{
		find_equalto = _strchr(*env, '=');
		if (find_equalto != NULL)
		{
			len = find_equalto - *env;
			if (_strncmp(str, *env, len) == 0)
			{
				return (find_equalto + 1);
			}
		}
		env++;
	}

	return (NULL);
}
