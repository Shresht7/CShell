#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir
#else
#include <unistd.h>
#endif

#include "command.h"

BuiltinCommand builtins[] = {
    {"exit", cmd_exit},
    {"help", cmd_help},
    {"echo", cmd_echo},
    {"pwd", cmd_pwd},
    {"cd", cmd_cd},
};

// Get the number of builtins.
int num_builtins()
{
    return sizeof(builtins) / sizeof(BuiltinCommand);
}

int get_builtin_cmd(char *cmd)
{
    // Iterate through the builtin commands table...
    for (int i = 0; i < num_builtins(); i++)
    {
        // If the name of the command matches...
        if (strcmp(cmd, builtins[i].name) == 0)
        {
            // Return the index position of the command in the array
            return i;
        }
    }
    // ... Otherwise, if the command was not found
    return -1;
}

// Function to lookup and execute a builtin command.
bool execute_builtin(int idx, char **args)
{
    // Call the corresponding function.
    return builtins[idx].func(args);
}

bool cmd_exit(char **args)
{
    return false; // Propagate the result up to affect loop continuity
}

bool cmd_echo(char **args)
{
    int i = 1;
    do
    {
        printf("%s ", args[i]);
    } while (args[++i] != NULL);
    printf("\n");
    return true;
}

bool cmd_help(char **args)
{
    printf("Built-in commands:\n");
    printf("  echo - Echo the input back to the terminal\n");
    printf("  help - Display this help message\n");
    printf("  exit - Exit the shell\n");
    return true;
}

bool cmd_pwd(char **args)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("CShell");
    }
    return true;
}

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
