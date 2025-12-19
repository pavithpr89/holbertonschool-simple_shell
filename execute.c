#include "shell.h"

/**
 * execute_command - executes cmd the user enters
 * @line: - line by user
 */

void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[64];
	int i = 0;
	char *cmd_path;

	argv[i] = strtok(line, " ");
	while (argv[i])
		argv[++i] = strtok(NULL, " ");

	/* IMPORTANT FIX: ignore empty or space-only input */
	if (argv[0] == NULL)
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		cmd_path = find_command(argv[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: command not found\n", argv[0]);
			exit(127);
		}
		execve(cmd_path, argv, environ);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
