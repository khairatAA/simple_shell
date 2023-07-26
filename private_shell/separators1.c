#include "shell.h"

/**
 * tokenise_cmd - tokenise cmd from last position taking ; as delimeter
 * @position: 
 */
char *tokenise_cmd(int position, char *cmd)
{
	char *dup, *new_str;

	dup = _strdup(cmd);
	dup[position] = '\0';
	_strcpy(new_str, dup);

	return(new_str);
}


/*** CREATE NODE ***/
/**
 * createNode - creates a node and adds initializes data
 * @cmd: command to set as node's data
 *
 * Return: pointer to newly created node
 */
struct Node *createNode(char *cmd)
{
	struct Node *newNode;

	newNode = malloc(sizeof(struct Node));
	newNode->data = cmd;
	newNode->next = NULL;
	
	return(newNode);
}


/*** ADD TO LIST ***/
/**
 * addToList - Adds node to list
 * @head: head of linked list to add node
 * @cmd: new command to add to linked list
 *
 * Return: void
 */
void addToList(char **head, char *cmd)
{
	struct Node *newNode, *ptr;

	newNode = createNode(cmd);
	if (*head == NULL)
	{
		*head = newNode;
		ptr = NULL;
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
}


/**
 * handle_list - creates linked list from data received
 * @head: Pointer to first node in the linked list
 * @cmd: Command to add to list
 * @loop: Determines which token to set as head
 *
 * Return: null
 */
void handle_list(char **head, char *data, int loop)
{

	if (loop == 1) /* set first command as first node */
	{
		*head = createNode(token_cmd);
	}
	else
	/* add subsequent command to end of list */
	{
		addToList(*head, token_cmd);
	}


/**
 * separate_cmd - separates command if the ; delimeter is found
 * @cmd: command entered into the terminal
 * 
 * Return: cmd if no valid ; command syntax is not found,
 * linked list of commands otherwise
 */
char *separate_cmd(char *cmd)
{
	int i, last_p, loop;
	struct Node *head;

	loop = last_p = 0;

	if (cmd[0] == '&' || cmd[0] == '|' || cmd[0] == ';')
		return (cmd);
	if (_strlen(cmd) < 3)
		return (cmd);

	for (i = 0; cmd[i + 1] != '\0'; i++)
	{
		if (cmd[i] == ';')
		{
			if (cmd[i - 1] == ';' || cmd[i + 1] == ';') /* Invalid syntax */
				return (cmd);			
			if (cmd[i - 1] == '&' || cmd[i + 1] == '&') /* Invalid syntax */
				return (cmd);
			if (cmd[i - 1] == '|' || cmd[i + 1] == '|') /* Invalid syntax */
				return (cmd);

			char *token = tokenise_cmd(i, cmd);
			loop++;
		/**
		 * For && and ||, increment i by 1 (i++)
		 * This will continue check after the 2nd sign
		 */
			handle_list(&head, token, loop);
		}
	}

	return (head);
}
/**
 * create function go free each of the memory used in the list
 * call these two functions in shell.c
 */
