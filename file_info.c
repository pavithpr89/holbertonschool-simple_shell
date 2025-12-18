#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - simple _which using stat
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;
    char *path, *path_copy, *dir;
    char full_path[1024];

    if (ac < 2)
        return (0);

    path = getenv("PATH");
    if (!path)
        return (0);

    i = 1;
    while (av[i])
    {
        path_copy = strdup(path);
        dir = strtok(path_copy, ":");

        while (dir)
        {
            sprintf(full_path, "%s/%s", dir, av[i]);
            if (stat(full_path, &st) == 0)
            {
                printf("%s\n", full_path);
                break;
            }
            dir = strtok(NULL, ":");
        }
        free(path_copy);
        i++;
    }
    return (0);
}
