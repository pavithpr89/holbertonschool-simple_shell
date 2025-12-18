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

	while (1)
	{
		printf("($) ");
		nchar = getline(&line, &len, stdin);
		if (nchar == -1)
		{
			putchar('\n');
			break;
		}
		
		line[nchar - 1] = '\0';

		if (line[0] == '\0')
			continue;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;
			if (execve(argv[0], argv, NULL) == -1)
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

	free(line);
	return (0);
}
