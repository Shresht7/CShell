#ifndef CWD_H
#define CWD_H

#include "builtin.h"

bool execute_cmd_cwd(char **args);

static BuiltinCommand cmd_cwd = {
    .name = "cwd",
    .func = execute_cmd_cwd,
};

#endif
