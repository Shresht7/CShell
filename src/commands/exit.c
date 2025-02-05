#include <stdbool.h>
#include <stdlib.h>

/// @brief Exits the program with a success status.
///
/// This function terminates the program by calling the `exit` function with
/// `EXIT_SUCCESS` status. It does not use the `args` parameter.
///
/// @param args The arguments passed in to the command. The first argument is the status code
/// @return This function does not return.
bool execute_cmd_exit(char **args)
{
    if (args[1] != NULL)
    {
        exit(atoi(args[1]));
    }
    exit(EXIT_SUCCESS);
}
