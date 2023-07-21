#include "shell.h"

/**
 * _cdir - changes current working directory and updates OLDPWD
 * @cmd: command to change working directory
 *
 * Return: 0 if successful, -1 otherwise
 */

int _cdir(char *cmd)
{
	char *name, *path, *oldpwd, *pwd;

	name = (strtok(cmd, " \n"));
	if (name == NULL || _strcmp(name, "cd") != 0)
	{
		perror("Invalid command");
		return (-1);
	}
	path = strtok(NULL, " ");
	if (path == NULL)	/* home directory */
	{
		oldpwd = _getenv("PWD");
		path = _getenv("HOME");
		chdir (path);
		setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
		/* update PWD */
		return (0);
	}
	if (path == "-" && strtok(NULL, " ") == NULL)
	{	
		oldpwd = _getenv("PWD");
		path = _getenv("OLDPWD");
		if (path == NULL)
		{
			perror ("OLDPWD");
			return(-1);
		}
		else
		{
			chdir (path);
			setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
			/* update PWD */
			return (0);
		}
	}
	/* handle other arguments */
	if (strtok(NULL, " ") != NULL)	/* path dont contain spaces */
	{
		perror("Invalid Path");
		return (-1);
	}
	oldpwd = _getenv("PWD");
	chdir (path);
	setenv("OLDPWD", oldpwd, 1);	/* Update OLDPWD */
	/* update PWD */
	return (0);
}
