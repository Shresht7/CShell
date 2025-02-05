#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "readline.h"

char *readline()
{
    int buffer_size = BUFFER_SIZE; // Mutable local variable for when we need to resize/reallocate

    // Allocate memory for a buffer to read the user input into
    char *buffer = malloc(sizeof(char) * buffer_size);
    if (!buffer)
    {
        // If memory allocation fails, print an error message and exit
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

char **parseline(char *line)
{
    int buffer_size = TOKEN_BUFFER_SIZE; // Mutable local variable for when we need to resize/reallocate

    // Allocate memory for a buffer to store the tokens
    char **tokens = malloc(sizeof(char *) * buffer_size);
    if (!tokens)
    {
        // If memory allocation fails, print an error message and exit
        fprintf(stderr, "CShell:parseline: Memory Allocation Error. Cannot allocate memory for parseline tokens buffer!");
        exit(EXIT_FAILURE);
    }

    int cursor = 0;                               // Cursor to keep track of our position in the tokens array
    char *token = strtok(line, TOKEN_DELIMITERS); // Get the first token
    while (token != NULL)
    {
        // Add the token to the tokens array
        tokens[cursor] = token;
        cursor++;

        // See if we need to reallocate memory to resize the tokens array
        if (cursor >= buffer_size)
        {
            buffer_size += TOKEN_BUFFER_SIZE; // Increase the buffer size
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens)
            {
                // If memory reallocation fails, print an error message and exit
                fprintf(stderr, "CShell:parseline: Memory Allocation Error. Cannot re-allocate memory for parseline tokens buffer!");
                exit(EXIT_FAILURE);
            }
        }

        // Get the next token
        token = strtok(NULL, TOKEN_DELIMITERS);
    }

    tokens[cursor] = NULL; // Null-terminate the tokens array

    return tokens; // Return the array of tokens
}
