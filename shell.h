#ifndef SHELL_H
#define SHELL_H

/* standard library headers */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/* access environment variables */
extern char **environ;

/* Executes a command line by forking and running the program */
int execute_command(char *line);

/* Resolves a command name to its full executable path */
char *find_command(char *cmd);

/* Retrieves the PATH environment variable from env array */
char *get_path(char **env);

/* Prints all current environment variables */
void print_env(void);

#endif /* SHELL_H */
