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

/* FUNCTIONS PROTOTYPES */
/* char *get_command(char *cmd1); */
void handle_signal(int sig);
void prompt(void);
int countArgs(const char *cmd);
char **spilt_string(const char *cmd, int ac);
void execute_cmd(const char *cmd, char *const envp[]);
void free_new_av(char **new_av);
/* char *_fgets(char* str, int buf_size, FILE *stream); */

/* STRING FUNCTIONS PROTOTYPE */
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
size_t _strcspn(const char *str, const char *charset);
char *_strdup(char *str);
void *_memcpy(void *dest, const void *src, size_t n);

/* MACROS */

static char *cmd __attribute__((unused));

#endif /* SHELL_H */
