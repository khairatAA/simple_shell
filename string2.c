#include "shell.h"

/**
 * _strspn - get length of a prefix substring
 * @str: the string to be used
 * @charset: the set of characters to match against
 * Return: the function count
 */

size_t _strspn(const char *str, const char *charset)
{
	size_t i = 0;
	const char *ptr;

	while (*str)
	{
		ptr = charset;
		while (*ptr)
		{
			if (*str == *ptr)
			{
				i++;
				break;
			}
			ptr++;
		}
		if (!*ptr)
			break;
		str++;
	}

	return (i);
}
