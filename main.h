#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

ssize_t _getline(char **input,
		size_t *number_of_malloc_bytes_allocated);
char **array_maker(char *input);
int _fork(char **array_of_tokens);

#endif
