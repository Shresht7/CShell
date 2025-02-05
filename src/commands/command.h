#ifndef COMMAND_H
#define COMMAND_H

#include "builtin.h"

// COMMANDS
// --------

/// @return The total number of builtin commands
int num_builtins();

/// @brief Finds the given cmd name in the builtin commands table and returns its index.
/// @param cmd The name of the command to lookup
/// @returns The index of the given command. -1 if the command was not found.
int get_builtin_cmd(const char *cmd);

/// @brief Executes the builtin command corresponding to the given index
/// @param idx The index of the builtin command to execute
/// @param args The arguments to pass to the command
/// @return A boolean indicating whether the shell should continue running
bool execute_builtin(int idx, char **args);

bool execute_cmd_help(char **args);

static BuiltinCommand cmd_help = {
    .name = "help",
    .func = execute_cmd_help,
};

#endif
