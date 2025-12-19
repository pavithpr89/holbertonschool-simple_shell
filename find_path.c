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

	if (strchr(cmd, '/'))
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);

	path = getenv("PATH");
	if (!path || path[0] == '\0')
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":" );
	while (dir)
	{
		strcpy (full_path, dir);
		strcat (full_path, "/");
		strcat (full_path, cmd);
		if(access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
