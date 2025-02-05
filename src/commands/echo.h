#ifndef ECHO_H
#define ECHO_H

#include "builtin.h"

bool execute_cmd_echo(char **args);

static BuiltinCommand cmd_echo = {
    .name = "echo",
    .desc = "Echoes the input back to the terminal",
    .aliases = (char *[]){NULL},
    .func = execute_cmd_echo,
};

#endif
