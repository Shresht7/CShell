#include <stdio.h>
#include <stdbool.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir
#else
#include <unistd.h>
#endif

/// @brief Prints the current working directory.
///
/// This function retrieves the current working directory using the `getcwd` function
/// and prints it to the standard output. If the current working directory cannot be
/// retrieved, it prints an error message using `perror`.
///
/// @param args Unused parameter.
/// @return Always returns true.
bool execute_cmd_cwd(char **args)
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
