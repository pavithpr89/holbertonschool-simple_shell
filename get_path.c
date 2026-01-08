#include "shell.h"

/**
 * get_path - retrieves the PATH environment variable
 * @env: the environment variables array (environ)
 *
 * Return: pointer to PATH string (skip "PATH="), or NULL if not found
 */
char *get_path(char **env)
{
	int i;

	/* check if env is empty or NULL */
	if (!env)
		return NULL;

	/* iterate through environment variables */
	for (i = 0; env[i]; i++)
	{
		/* look for path variable */
		if (strncmp(env[i], "PATH=", 5) == 0)
			return env[i] + 5;
	}
	/* PATH not found */
	return NULL;
}
