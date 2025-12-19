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

#endif /* SHELL_H */
