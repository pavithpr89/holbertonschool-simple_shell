#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


extern char **environ;

int execute_command(char *line);
char *find_command(char *cmd);
char *get_path(char **env);
void print_env(void);

#endif /* SHELL_H */
