#include "shell.h"

/**
 * change all standard string function to local ones later
 *
 * STEP 1: Loop through the command to check command occurrence
 * STEP 2: If not found, continue the execution of other codes
 * STEP 3: If found, check the command received
 *	FOR COMMAND ;
 *	use strtok to get the string before the separator and execute
 *	note current postion of read string and continue till '\0'
 *
 *  **	When checking for next character, do it in a loop that continues
 *	to next iteration if the next token is a space delimeter
 *	# condition to end loop is if the next token is not a character
 *	if next token is a space, continue but
 *
 *	FOR COMMAND &
 *	compare with str[i + 1], if different, return syntax error and
 *	continue checking
 *	if str[i] and str[i + 1] are same, check str[i + 2], if str [i + 2]
 *	is any of the commands, return syntax error and continue
 */

/**
 * handle_commands - handles command separators && and ||
 * @cmd: command entered into the command line
 *
 * Return: cmd if command is absent, linked list of tokenised commands otherwise
 */

char *handle_commands(char *cmd)
{
	int i;
	char check[3];

	check[2] = '\0';
	
	if (_strlen(cmd) < 3)
		return (cmd);
	for (i = 0; cmd[i + 1] != '\0'; i++)
	{
		if (cmd[i] == '&' || cmd[i] == '|')
		{
			if (cmd[i + 2] == '&' || cmd[i - 1] == '&') /* Invalid syntax */
				return (cmd);
			if (cmd[i + 2] == '|' || cmd[i + 2] == ';') /* Invalid syntax */
				return (cmd);
			if (cmd[i - 1] == '|' || cmd[i - 1] == ';') /* Invalid syntax */
				return (cmd);
			if (cmd[i + 2] == '|' || cmd[i - 1] == '|') /* Invalid syntax */
				return (cmd);
			if (cmd[i + 2] == '&' || cmd[i + 2] == ';') /* Invalid syntax */
				return (cmd);
			if (cmd[i - 1] == '&' || cmd[i - 1] == ';') /* Invalid syntax */
				return (cmd);

			check[0] = cmd[i];
			check[1] = cmd[i + 1];
			if (_strcmp(check, "&&") == 0)
			{
				and_operator(cmd);
				/* store the returned string in linked list */
				continue;
			}
			if (_strcmp(check, "||") == 0)
			{
				or_operator(cmd);
				/* store the returned string in linked list */
				continue;
			}
		}
	}
	
	/**
	 * If linked list is empty, return (cmd), else return linked list
	 * In shell.c - Check if a pointer to a linked list
	 * or just cmd was returned
	 *
	 * NOTE: Whatever is returned from the linked list
	 * will be freed in the main
	 */

	return (/* cmd or linked_list of tokenised commands*/);
}

