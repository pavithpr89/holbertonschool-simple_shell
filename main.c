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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		nchar = getline(&line, &len, stdin);
		if (nchar == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (line[nchar - 1] == '\n')
			line[nchar - 1] = '\0';

		if (*line)
			status = execute_command(line);
	}

	free(line);
	return (status);
}
