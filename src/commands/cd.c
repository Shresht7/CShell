#include <stdio.h>
#include <stdbool.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir
#else
#include <unistd.h>
#endif

bool cmd_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "CShell: expected argument\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("CShell");
        }
    }
    return true;
}
