#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stddef.h> // added this


#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

void execute_command(char *line);

#endif /* SHELL_H */


//int main(void);

//#endif
