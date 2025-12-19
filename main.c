#include "shell.h"


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nchar;

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
			execute_command(line);
	}

	free(line);
	return (0);
}
