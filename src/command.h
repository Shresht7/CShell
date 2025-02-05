#ifndef COMMAND_H
#define COMMAND_H

/// Function prototype for the builtin commands function
typedef bool (*builtin_cmd)(char **args);

/// @brief Maps a command-name to its corresponding builtin function
typedef struct
{
    char *name;       // The name of the command
    builtin_cmd func; // The corresponding function to execute
} BuiltinCommand;

// COMMANDS
// --------

/// @return The total number of builtin commands
int num_builtins();

/// @brief Finds the given cmd name in the builtin commands table and returns its index.
/// @param cmd The name of the command to lookup
/// @returns The index of the given command. -1 if the command was not found.
int get_builtin_cmd(char *cmd);

/// @brief Executes the builtin command corresponding to the given index
/// @param idx The index of the builtin command to execute
/// @param args The arguments to pass to the command
/// @return A boolean indicating whether the shell should continue running
bool execute_builtin(int idx, char **args);

/// @brief Exit the shell
bool cmd_exit(char **args);

/// @brief Echo the input back
bool cmd_echo(char **args);

/// @brief Shows a help message about the shell
bool cmd_help(char **args);

#endif
