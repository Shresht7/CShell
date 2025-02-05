#ifndef EXIT_H
#define EXIT_H

#include "builtin.h"

bool execute_cmd_exit(char **args);

static BuiltinCommand cmd_exit = {
    .name = "exit",
    .desc = "Exits the program",
    .aliases = (char *[]){"quit", NULL},
    .func = execute_cmd_exit,
};

#endif
