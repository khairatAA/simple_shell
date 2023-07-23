#include "shell.h"

/**
 * _cdir - changes current working directory and updates OLDPWD
 * @cmd: command to change working directory
 *
 * Return: 0 if successful, -1 otherwise
 */
int _cdir(char *cmd)
{
	char *path, *oldpwd, *pwd, *dup, buf[256];
	int words;
	size_t size = 256;

	dup = _strdup(cmd);
	words = wcount(dup, " \t\r");
	if (words > 2)
	{
		perror("Invalid Argument");
		free(dup);
		dup = NULL;
		return (-1);
	}
	strtok(cmd, " \t\r");
	path = strtok(NULL, " ");
	if (path == NULL)			/* home directory */
	{
		oldpwd = getcwd(buf, size);
		chdir(_getenv("HOME"));
		setenv("OLDPWD", oldpwd, 1);
		setenv("PWD", _getenv("PWD"), 1);
		free(dup);
		dup = NULL;
		return (0);
	}
	if (_strcmp(path, "-") == 0)
	{
		if (_getenv("OLDPWD") == NULL)
		{
			perror("OLDPWD");	/* OLDPWD not net */
			free(dup);
			dup = NULL;
			return (-1);
		}
		else
		{
			oldpwd = getcwd(buf, size);
			chdir(_getenv("OLDPWD"));
			setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
			pwd = getcwd(buf, size);
			setenv("PWD", pwd, 1);
			free(dup);
			dup = NULL;
			return (0);
		}
	}
	oldpwd = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror("Invalid Argument");
		free(dup);
		dup = NULL;
		return (-1);
	}
	setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
	pwd = getcwd(buf, size);
	setenv("PWD", pwd, 1);
	free(dup);
	dup = NULL;
	return (0);
}
