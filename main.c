#include "shell.h"

/**
 * main - Main function
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nchar;
	int status = 0;

	/* infinite loop for shell prompt */
	while (1)
	{
		/* print prompt while allowing user input */
		if (isatty(STDIN_FILENO))
			printf("($) ");

		/* read a line of input from user */
		nchar = getline(&line, &len, stdin);
		if (nchar == -1)
		{
			/* if user ends, print new line and exit loop */
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		/* remove trailing new line */
		if (line[nchar - 1] == '\n')
			line[nchar - 1] = '\0';

		/* if user types exit, exit */
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(status);
		}
		
		/* print all env variables if user input is env */
		if (strcmp(line, "env") == 0)
		{
			print_env();
			continue;
		}

		/* execute command line if not empty */
		if (*line)
			status = execute_command(line);
	}

	/* free allocated memory */
	free(line);

	/* return executed command status */
	return (status);
}
