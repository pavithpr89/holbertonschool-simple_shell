#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int nchar;
	pid_t child_pid;
	int status;
	char *argv[2];
	extern char **environ;
	char *token;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		nchar = getline(&line, &len, stdin);
		if (nchar == -1)
		{
			if (isatty(STDIN_FILENO))
				putchar('\n');
			break;
		}

		line[nchar - 1] = '\0';

		token = strtok(line, " \t\n");
		while (token != NULL)

			child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			argv[0] = token;
			argv[1] = NULL;
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
		token = strtok(NULL, " \t\n");
	}
}

free(line);
	return (0);
}
