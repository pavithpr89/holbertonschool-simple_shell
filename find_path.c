#include "shell.h"

/**
 * find_command - finds path of the command
 * @cmd: command entered by user
 * Return: path of cmd
 */
char *find_command(char *cmd)
{
	static char full_path[1024];
	char *path, *path_copy, *dir;

	/* check for NULL */
	if (!cmd)
		return (NULL);
	
	/* if command is already a path, check if it's executable */
	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}

	/* retrieve PATH environmentvariable */
	path = get_path(environ);

	if (!path || path[0] == '\0')
		return (NULL);

	/* Duplicate PATH to safely tokenize directories */
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	/* iterate through each directory in PATH */
	dir = strtok(path_copy, ":" );
	while (dir)
	{
		/* build full path */
		sprintf(full_path, "%s/%s", dir, cmd);

		/* check if command exists and is executable */
		if(access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	/* command not found */
	free(path_copy);
	return (NULL);
}
