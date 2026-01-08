#include "shell.h"

/**
 * print_env - prints the current environment
 */
void print_env(void)
{
	int i;

	/* iterate through environ array and print each variable */
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
