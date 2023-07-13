#include "shell.h"

/**
 * _strlen - determines the string length
 * @str: the string whoes length is to be determined
 * Return: the length
 */

int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcmp - compare two strings
 * @str1: the first string to be conpared
 * @str2: the second string to be compared
 * Return: the compared string
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}

	return (str1[i] - str2[i]);
}

/**
 * _strcspn - get length of a prefix substring
 * @str: the string
 * @charset: the character set
 * Return: returns the length
 */
size_t _strcspn(const char *str, const char *charset)
{
	size_t len = 0;
	const char *pointer = str, *charPointer = charset;

	while (*pointer != '\0')
	{
		while (*charPointer != '\0')
		{
			if (*pointer == *charPointer)
				return (len);
			charPointer++;
		}
		pointer++;
		len++;
	}

	return (len);
}
