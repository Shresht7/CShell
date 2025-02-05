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

///  @brief Retrieves the home directory path of the current user.
///
///  This function fetches the home directory path from the environment variable "HOME".
///  On Windows systems, if the "HOME" environment variable is not set, it attempts to
///  retrieve the path from the "USERPROFILE" environment variable.
///
///  @return A pointer to a string containing the home directory path, or NULL if the
///          environment variables are not set.
char *get_home()
{
    char *home = getenv("HOME");
#ifdef _WIN32
    if (!home)
    {
        // Copilot did this!
        size_t len;
        _dupenv_s(&home, &len, "USERPROFILE");
    }
#endif
    return home;
}

/// @brief Changes the current working directory.
///
/// If no argument is provided or the argument is "~", changes the directory to the user's home directory.
/// If an argument is provided, changes the directory to the specified path.
///
/// @param args An array of arguments where args[1] is the directory to change to.
/// @return true if the directory change is successful, otherwise prints an error message.
bool execute_cmd_cd(char **args)
{
    char *home = get_home();
    if (args[1] == NULL || strcmp(args[1], "~") == 0)
    {
        if (chdir(home) != 0)
        {
            perror("CShell");
        }
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
