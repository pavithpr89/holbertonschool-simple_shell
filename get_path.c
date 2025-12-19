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

	if (!env)
		return NULL;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return env[i] + 5;
	}
	return NULL;
}
