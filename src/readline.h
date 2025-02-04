#ifndef READLINE_H
#define READLINE_H

#define BUFFER_SIZE 1024

/// @brief Reads a line of input from the standard input (stdin).
///
/// This function dynamically allocates memory for a buffer to store the input
/// line. It reads characters one by one until it encounters a newline character
/// ('\n') or the end-of-file (EOF). If the buffer becomes full, it reallocates
/// memory to increase the buffer size.
///
/// @return A pointer to the dynamically allocated buffer containing the input line.
///         The caller is responsible for freeing the allocated memory.
///
/// @note If memory allocation fails, the function prints an error message to
///       stderr and terminates the program with an exit status of EXIT_FAILURE.
const char *readline();

#endif
