#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "readline.h"

void run_shell();
bool execute_command();

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
        puts(line);

        // Execute the command
        run = execute_command();

    } while (run);
}

bool execute_command()
{
    return false;
}
