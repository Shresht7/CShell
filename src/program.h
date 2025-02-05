#ifndef PROGRAM_H
#define PROGRAM_H

/// @brief Runs an external program in a cross-platform way
/// @param args The arguments to run the program
/// @return Returns true to keep the shell running, and false to quit
bool execute_external(char **args);

#endif
