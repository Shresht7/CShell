#ifndef CWD_H
#define CWD_H

#include "builtin.h"

bool execute_cmd_cwd(char **args);

static BuiltinCommand cmd_cwd = {
    .name = "cwd",
    .desc = "Current Working Directory",
    .aliases = (char *[]){"pwd", NULL},
    .func = execute_cmd_cwd,
};

#endif
