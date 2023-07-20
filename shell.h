#ifndef SHELL_H
#define SHELL_H

/* INCLUDE HEADER FILES */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stddef.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>

/* STRUCTURE  */

/**
 * struct Node_env - structure that handles the env
 * @data: the env list
 * @next: pointer to the next node
 */

typedef struct Node_env
{
	char *data;
	struct Node_env *next;
} Node_env;

/* FUNCTIONS PROTOTYPES */

void handle_signal(int sig);
void prompt(void);
int countArgs(const char *cmd);
char **split_string(const char *cmd);
void execute_cmd(const char *cmd, char *const envp[]);
void free_new_av(char **new_av);
char *_getenv(const char *str);
char *handle_path(const char *cmd);
int print_error(char *str);
void _perror(const char *cmd, char *error_message);
void exit_builtin(void);
Node_env *add_new_var(Node_env *head, char *new_var);
void print_env(Node_env *head);
void handle_env(void);
void free_env(Node_env *head);
char *_strtok(char *str, const char *delim);

/* STRING FUNCTIONS PROTOTYPE */

int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
size_t _strcspn(const char *str, const char *charset);
char *_strdup(char *str);
void *_memcpy(void *dest, const void *src, size_t n);
size_t _strspn(const char *str, const char *charset);
char *_strchr(const char *str, int character);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *to, const char *from);
char *_strcat(char *to, const char *from);

/* MACROS */

static char *cmd __attribute__((unused));
extern char **environ;
#define MAX_PATH_LENGTH 1024

#endif /* SHELL_H */
