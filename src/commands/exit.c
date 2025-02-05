#include <stdbool.h>
#include <stdlib.h>

/// @brief Exits the program with a success status.
///
/// This function terminates the program by calling the `exit` function with
/// `EXIT_SUCCESS` status. It does not use the `args` parameter.
///
/// @param args Unused parameter.
/// @return This function does not return.
bool cmd_exit(char **args)
{
    exit(EXIT_SUCCESS);
}
