#include "shell.h"

/* CONTINUE EXECUTION OF THE SHELL COMMAND */

/**
 * special_commands - handles commands entered into the stdin
 * @cmd: command received
 *
 * Return: void
 */
void special_commands(char *cmd)
{
	char *status = NULL, *exit_str = "exit ", *status_copy, *dup;

	if (_strcmp(cmd, "env") == 0)
	{
		handle_env();
		free(cmd);
		cmd = NULL;
		return;
	}
	if (_strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		cmd = NULL;
		exit_builtin(cmd, NULL);
		return;
	}
	/* Handle cd command */
	dup = _strdup(cmd);
	if (_strcmp(strtok(dup, " \t\r\n"), "cd") == 0)
	{
		change_dir(cmd);
		free(cmd);
		free(dup);
		dup = cmd = NULL;
		return;
	}
	free(dup);
	if (_strncmp(cmd, exit_str, _strlen(exit_str)) == 0)
	{
		status = cmd + _strlen(exit_str);
		if (status[0] == '\0')
			status = NULL;
		status_copy = (status != NULL) ? _strdup(status) : NULL;
		free(cmd);
		cmd = NULL;
		exit_builtin(status_copy, status_copy);
		free(status_copy);
		status_copy = NULL;
		return;
	}
}

/**
 * execute_list - executes all the commands in the linked list
 * @head: address of pointer to the list hed
 *
 * Return: 0
 */
void execute_list(struct Node **head)
{
	struct Node *tmp;

	tmp = *head;
	while (tmp->next != NULL)
	/* for the && and ||, let implement a return value here */
	{
		special_commands(tmp->data);
	}
}
