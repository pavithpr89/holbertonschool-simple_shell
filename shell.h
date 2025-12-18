#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

extern char **environ;

void execute_command(char *line);

#endif /* SHELL_H */
