#include "shell.h"

/**
 * create_node - creats a new node to the list
 * @data: the variable to set
 * @number: keeps track of the varible
 * Return: a pointer to the node
 */
Node_env *create_node(char *data, int number)
{
	Node_env *new_node;

	new_node = (Node_env *)malloc(sizeof(Node_env));
	if (new_node == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->data = data;
	new_node->number = number;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_to_list - adds a node to the list
 * @head: head of the linked list
 * @new_node: the node to be added
 */

void add_to_list(Node_env **head, Node_env *new_node)
{
	Node_env *current;

	if (*head != NULL)
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	else
		*head = new_node;
}

/**
 * print_env - prints the node to the stderr
 * @head: head of the linked list
 * Return: nothing
 */

void print_env(Node_env *head)
{
	Node_env *current;

	current = head;
	while (current != NULL)
	{
		write(STDOUT_FILENO, current->data, _strlen(current->data));
		write(STDOUT_FILENO, "\n", 1);

		current = current->next;
	}
}

/**
 * handle_env - handles the env built-in
 * Return: 0 on success
 */

int handle_env(void)
{
	char **env = environ;
	Node_env *head = NULL;

	while (*env != NULL)
	{
		add_to_list(&head, create_node(*env, 0));
		env++;
	}
	print_env(head);
	free_env(head);
	return (0);
}

/**
 * free_env - frees the list
 * @head: head to the linked list
 */

void free_env(Node_env *head)
{
	Node_env *current = head;
	Node_env *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		if (temp->number == 1)
			free(temp->data);
		free(temp);
	}
}
