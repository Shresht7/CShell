#ifndef PARSELINE_H
#define PARSELINE_H

#define TOKEN_BUFFER_SIZE 64
#define TOKEN_DELIMITERS " \r\n\t\a"

/**
 * Parses the given line into an array of strings.
 *
 * @param line The input line to be parsed.
 * @return A NULL-terminated array of strings, where each string is a token from the input line.
 */
char **parseline(char *line);

#endif
