#ifndef ECHO_H
#define ECHO_H

#include "builtin.h"

bool execute_cmd_echo(char **args);

static BuiltinCommand cmd_echo = {
    .name = "echo",
    .func = execute_cmd_echo,
};

#endif
