#ifndef EXIT_H
#define EXIT_H

#include "builtin.h"

bool execute_cmd_exit(char **args);

static BuiltinCommand cmd_exit = {
    .name = "exit",
    .func = execute_cmd_exit,
};

#endif
