#ifndef CD_H
#define CD_H

#include "builtin.h"

bool execute_cmd_cd(char **args);

static BuiltinCommand cmd_cd = {
    .name = "cd",
    .func = execute_cmd_cd,
};

#endif
