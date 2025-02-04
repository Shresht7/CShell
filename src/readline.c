#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "readline.h"

const char *readline()
{
    int buffer_size = BUFFER_SIZE; // Mutable local variable for when we need to resize/reallocate

    // Allocate memory for a buffer to read the user input into
    char *buffer = malloc(sizeof(char) * buffer_size);
    if (!buffer)
    {
        fprintf(stderr, "CShell:readline: Memory Allocation Error. Cannot allocate memory for readline buffer!");
        exit(EXIT_FAILURE);
    }

    int cursor = 0; // Cursor to keep track of our position in the buffer

    while (true)
    {
        // Read a character
        int c = getchar();

        // Check for termination condition
        if (c == EOF || c == '\n')
        {
            buffer[cursor] = '\0'; // Add the null terminator at the end of the buffer
            return buffer;         // Return the string buffer
        }
        else
        {
            // ... Otherwise, if we are not at the end yet, add the character to the buffer
            buffer[cursor] = c;
        }
        cursor++;

        // See if we need to reallocate memory to resize the buffer
        if (cursor >= buffer_size)
        {
            buffer_size += BUFFER_SIZE; // Increase the buffer size
            buffer = realloc(buffer, buffer_size);
            if (!buffer)
            {
                fprintf(stderr, "CShell:readline: Memory Allocation Error. Cannot re-allocate memory for readline buffer!");
                exit(EXIT_FAILURE);
            }
        }
    }
}
