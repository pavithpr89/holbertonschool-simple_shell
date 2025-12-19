#include "shell.h"

/**
 * execute_command - executes cmd the user enters
 * @line: - line by user
 */

int execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[64];
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i])
		argv[++i] = strtok(NULL, " ");

	/* IMPORTANT FIX: ignore empty or space-only input */
	if (argv[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	if (pid == 0)
	{
		char *cmd_path = find_command(argv[0]);
		
		if (!cmd_path)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			return (127);
		}
		execve(cmd_path, argv, environ);
		_exit(126);
	}
	else
	{
		int wstatus;
		wait(&wstatus);

		if (WIFEXITED(wstatus))
		{
			status = WEXITSTATUS(wstatus);
		}
		else
			status = 1;
		return (status);
	}
	return (1);
}
