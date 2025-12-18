#include <stdio.h>
#include <string.h>

extern char **environ;

int main(void)
{
    char *path = NULL;
    char *token = NULL;
    int i = 0;

    /* Find PATH in the environment */
    while (environ[i])
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            path = environ[i] + 5; /* skip "PATH=" */
            break;
        }
        i++;
    }

    if (!path)
    {
        printf("PATH not found in environment\n");
        return 1;
    }

    /* Split the PATH string by ':' and print each directory */
    token = strtok(path, ":");
    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }

    return 0;
}
