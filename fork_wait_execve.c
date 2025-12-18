#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    pid_t child_pid;
    int status;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork(); // Create child
        if (child_pid == -1)
        {
            perror("fork failed");
            exit(1);
        }

        if (child_pid == 0) // Child process
        {
            // Execute ls -l /tmp
            char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("execve failed");
                exit(1);
            }
        }
        else // Parent process
        {
            // Wait for this child to finish before creating next
            wait(&status);
            printf("Parent: Child %d finished\n", i + 1);
        }
    }

    return 0;
}
