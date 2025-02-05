#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "program.h"

#ifdef _WIN32
#include <process.h> // For _spawnvp
#else
#include <unistd.h>
#include <sys/wait.h>
#endif

bool execute_external(char **args)
{
#ifdef _WIN32
    // On Windows, _spawnvp executes a program.
    // _spawnvp searches the PATH for the executable.
    // _P_WAIT means the parent waits for the spawned process to finish.
    intptr_t ret = _spawnvp(_P_WAIT, args[0], args);
    if (ret == -1)
    {
        perror("CShell");
        return false; // Indicate failure.
    }
    return true;
#else
    pid_t pid = fork(); // Create/Fork a new process
    if (pid < 0)
    {
        perror("CShell: fork error");
        return false;
    }
    else if (pid == 0)
    { // Child process
        // Replace current process image with a new process image.
        // execvp searches the PATH for the executable and runs it.
        if (execvp(args[0], args) == -1)
        {
            perror("CShell");
        }
        exit(EXIT_FAILURE); // Exit the child-process if execvp fails.
    }
    else
    { // Parent process: Wait for the child-process to finish
        int status = 0;
        pid_t wpid;
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
            if (wpid == -1)
            {
                perror("CShell: waitpid error");
                return false;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        // Check the exit status: if nonzero, assume failure.
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            return false;
        }
    }
    return true;
#endif
}
