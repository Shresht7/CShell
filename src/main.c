#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void run_shell();
void read_line();
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
        read_line();
        // Execute the command
        run = execute_command();
    } while (run);
}

void read_line()
{
}

bool execute_command()
{
    return false;
}
