#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "readline.h"
#include "command.h"

int main(int argc, char *argv[])
{
    // Setup: Initialize the shell and any configuration

    // Loop: Read commands from stdin and executes them
    run_shell();

    // Teardown: Shutdown cleanup logic

    return EXIT_SUCCESS;
}

void run_shell()
{
    bool run = true;
    do
    {

        // Show the prompt
        printf("$ ");

        // Read and parse input from the user
        const char *line = readline();
        char **args = parseline(line);

        // Execute the command
        run = execute_command(args);

        // Free allocated memory
        free(args);
        free(line);

    } while (run);
}

bool execute_command(char **args)
{
    // If no command was passed, simply continue running the shell
    if (args[0] == NULL)
    {
        // Empty command; simply continue.
        return true;
    }

    // Check to see if the command is builtin. If it is, execute it.
    int cmd = get_builtin_cmd(args[0]);
    if (cmd >= 0)
    {
        return execute_builtin(cmd, args);
    }

    // If we reach this point, the cmd was not found anywhere. Show a message and continue running the shell
    printf("Unknown Command: %s\n", args[0]);

    // Keep the shell alive
    return true;
}
