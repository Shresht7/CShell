#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "command.h"

BuiltinCommand builtins[] = {
    {"exit", cmd_exit},
    {"quit", cmd_exit},
    {"help", cmd_help},
    {"echo", cmd_echo},
    {"cwd", cmd_cwd},
    {"pwd", cmd_cwd},
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
