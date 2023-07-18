#include "shell.h"

/**
 * handle_env - handle the env built-in
 */

void handle_env(void)
{
	char **_env = environ;
	char *holder;

	while (*_env)
	{
		holder = *_env;
		while (*holder != '\0')
		{
			write(STDOUT_FILENO, holder, 1);
			holder++;
		}
		write(STDOUT_FILENO, "\n", 1);
		_env++;
	}
}
