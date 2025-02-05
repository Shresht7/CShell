#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "command.h"
#include "cd.h"
#include "cwd.h"
#include "echo.h"
#include "exit.h"

BuiltinCommand *builtins[] = {
    &cmd_exit,
    &cmd_help,
    &cmd_echo,
    &cmd_cwd,
    &cmd_cd,
};

// Get the number of builtins.
int num_builtins()
{
    return sizeof(builtins) / sizeof(BuiltinCommand *);
}

int get_builtin_cmd(const char *cmd)
{
    // Iterate through the builtin commands table...
    for (int i = 0; i < num_builtins(); i++)
    {
        // If the name of the command matches...
        if (strcmp(cmd, builtins[i]->name) == 0)
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
    return builtins[idx]->func(args);
}

bool execute_cmd_help(char **args)
{
    printf("\nBuilt-in commands:\n");
    for (int i = 0; i < num_builtins(); i++)
    {
        printf("  %s\t%s\n", builtins[i]->name, builtins[i]->desc);
    }
    printf("\n");
    return true;
}
