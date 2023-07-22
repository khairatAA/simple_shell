#include "shell.h"

/**
  * wcount - counts the number of words in a string
  * @str: string to count words in
  * @delim: delimeters separating words
  *
  * Return: Number of words in string, -1 on failure
  */
int wcount(char *str, char *delim)
{
	int count;
	char *dup;

	dup = str;
	if (str == NULL)
	{
		perror("Invalid String");
		return (-1);
	}

	strtok(dup, delim);
	for (count = 1; strtok(NULL, delim) != NULL; count++)
		;

	return (count);
}
