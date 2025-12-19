#include "shell.h"

/**
 * find_command - finds path of the command
 * @cmd: command entered by user
 * Return: path of cmd
 */
char *find_command(char *cmd)
{
	static char full_path[64];
	char *path, *path_copy, *dir;

	if (strchr(cmd, '/'))
		return (cmd);
	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(path_copy);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
