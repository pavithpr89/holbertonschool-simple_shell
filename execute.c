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
	char *cmd_path;

	/* tokenize the input line */
	argv[i] = strtok(line, " ");
	while (argv[i])
		argv[++i] = strtok(NULL, " ");

	/* IMPORTANT FIX: ignore empty or space-only input */
	if (argv[0] == NULL)
		return (0);

	/* find full executable path */
	cmd_path = find_command(argv[0]);
	if (!cmd_path)
	{
		/* command not found */
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (127);
	}

	/* create child process */
	pid = fork();
	if (pid == -1)
	{
		/* handle fork failure */
		perror("fork");
		return (0);
	}
	if (pid == 0)
	{
		/* execute child process command */
		execve(cmd_path, argv, environ);

		/* only reach exit if execve fails */
		_exit(126);
	}
	else
	{
		int wstatus;

		/* parent process waits for child process */
		wait(&wstatus);

		/* retrieve the child process's exit status */
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
