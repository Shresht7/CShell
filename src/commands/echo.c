#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/// @brief Executes the echo command which prints the provided arguments to the standard output.
///
/// This function takes an array of strings (arguments) and prints each argument followed by a space.
/// It continues printing until it encounters a NULL pointer in the array.
/// After printing all arguments, it prints a newline character.
///
/// @param args An array of strings representing the arguments to be printed.
///             The first element (args[0]) is typically the command name ("echo").
///             The function starts printing from args[1].
/// @return true Always returns true indicating the command executed successfully.
bool execute_cmd_echo(char **args)
{
    int i = 1;
    do
    {
        printf("%s ", args[i]);
    } while (args[++i] != NULL);
    printf("\n");
    return true;
}
