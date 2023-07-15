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

/**
 * _strdup - duplicates the string
 * @str: the string to me duplicated
 * Return: the new string
 */
char *_strdup(char *str)
{
	size_t length = _strlen(str) + 1;
	char *new_str = malloc(length);

	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, length);

	return (new_str);
}

/**
 * _memcpy -  copy memory area
 * @dest: the destination string
 * @src: the source string
 * @n: number of bytes to be copied
 * Return: returns a pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr = (unsigned char *)dest;
	const unsigned char *src_ptr = (const unsigned char *)src;
	size_t i = 0;

	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}

	return (dest);
}
