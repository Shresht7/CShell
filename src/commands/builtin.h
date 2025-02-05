#ifndef BUILTIN_H
#define BUILTIN_H

/// Function prototype for the builtin commands function
typedef bool (*builtin_cmd)(char **args);

/// @brief Maps a command-name to its corresponding builtin function
typedef struct
{
    char *name;       // The name of the command
    char *desc;       // A helpful description
    char **aliases;   // Aliases for the command
    builtin_cmd func; // The corresponding function to execute
} BuiltinCommand;

#endif
