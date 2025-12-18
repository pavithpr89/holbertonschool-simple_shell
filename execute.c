#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[64];
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i])
		argv[++i] = strtok(NULL, " ");

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
