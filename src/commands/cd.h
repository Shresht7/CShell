#ifndef CD_H
#define CD_H

#include "builtin.h"

bool execute_cmd_cd(char **args);

static BuiltinCommand cmd_cd = {
    .name = "cd",
    .desc = "Change Directory",
    .aliases = (char *[]){NULL},
    .func = execute_cmd_cd,
};

#endif
