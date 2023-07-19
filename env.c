#include "shell.h"

/**
 * add_new_var - adds a new node to the list
 * @head: the 1st node
 * @new_var: the new node
 * Return: a pointer to the node
 */

Node_env *add_new_var(Node_env *head, char *new_var)
{
	Node_env *new_node;

	new_node = malloc(sizeof(Node_env));
	if (new_node == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->data = _strdup(new_var);
	new_node->next = head;

	return (new_node);
}

/**
 * print_env - prints the node to the stderr
 * @head: the first node
 * Return: nothing
 */

void print_env(Node_env *head)
{
	Node_env *current;
	size_t length;

	current = head;
	while (current != NULL)
	{
		length = _strlen(current->data);
		write(STDOUT_FILENO, current->data, length);
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}

/**
 * handle_env - handles the env built-in
 */

void handle_env(void)
{
	Node_env *env_list = NULL;
	char **env = environ;
	int i = 0;

	while (env[i] != NULL)
	{
		env_list = add_new_var(env_list, env[i]);
		i++;
	}
	print_env(env_list);
	free_env(env_list);
}

/**
 * free_env - frees the list
 * @head: the first node
 */

void free_env(Node_env *head)
{
	Node_env *current = head;
	Node_env *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->data);
		free(temp);
	}
}
