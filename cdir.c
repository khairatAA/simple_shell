#include "shell.h"

/**
 * _cdir - changes current working directory and updates OLDPWD
 * @cmd: command to change working directory
 *
 * Return: 0 if successful, -1 otherwise
 */
int _cdir(char *cmd)
{
	char *path, *oldpwd, *pwd, *dup;
	int words;

	oldpwd = _getenv("PWD");
	dup = _strdup(cmd);
	words = wcount(dup, " \t\r");
	if (words > 2)
	{
		perror("Invalid Argument");
		return (-1);
	}
	strtok(cmd, " \t\r");
	path = strtok(NULL, " ");
	if (path == NULL)			/* home directory */
	{
		/* store current path in oldpwd */
		chdir(_getenv("HOME"));
		setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
		setenv("PWD", _getenv("PWD"), 1);
		return (0);
	}
	if (_strcmp(path, "-") == 0)
	{
		oldpwd = _getenv("PWD");
		if (_getenv("OLDPWD") == NULL)
		{
			perror("OLDPWD");	/* OLDPWD not net */
			return (-1);
		}
		else
		{
			/* get current path and store in oldpwd */
			chdir(_getenv("OLDPWD"));
			setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
			/* get current path and store in PWD */
			setenv("PWD", _getenv("PWD"), 1);
			return (0);
		}
	}
	/* get current path and store in oldpwd */
	if (chdir(path) == -1)
	{
		perror("Invalid Argument");
		return (-1);
	}
	setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
	/* get current path and store in PWD */
	setenv("PWD", _getenv("PWD"), 1);
	return (0);
}
