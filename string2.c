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

/**
 * _strchr - locate character in string
 * @str: the string where the character is to be located
 * @character: the character to be located
 * Return: pointer to the matched character
 */

char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}

/**
 * _strncmp - compare two strings
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 * @n: the first n bytes to be compared
 * Return: return an interger if successful
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			break;
		i++;
	}

	return (0);
}

/**
 * _strcpy - copy a string
 * @to: the destination string
 * @from: the source string
 * Return: the destination string
 */

char *_strcpy(char *to, const char *from)
{
	int i = 0;

	while (from[i] != '\0')
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';

	return (to);
}

/**
 * _strcat - concatenate two strings
 * @to: the destination string
 * @from: the source string
 * Return: the destination string
 */

char *_strcat(char *to, const char *from)
{
	int to_len = 0, i = 0;

	while (to[to_len] != '\0')
		to_len++;
	for (; from[i] != '\0'; i++)
	{
		to[to_len + i] = from[i];
	}
	to[to_len + i] = '\0';

	return (to);
}
