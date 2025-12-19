#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
char *find_command(char *cmd)
{

  char full_path[64];
  char *path, *path_copy, *dir; 


  if (strchr(cmd, '/')) 
  {
    
    return(cmd);
    
    
  }

  else
  {

    path = getenv("PATH");
    if (!path)
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
	return(full_path);
      }
     
      free(path_copy);
      dir = strtok (NULL, ":");



    } 

    free(path_copy);
    

  }

return (NULL);
}

