#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt(void);
void sigint_handler(int signal);
ssize_t _getline(char **input,
		size_t *number_of_malloc_bytes_allocated);
char **array_maker(char *input, char *delimiter);
int _fork(char *command, char **array_of_tokens);
char *_which(char *filename);
int _print_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *malloc_char(char **string, size_t size_of_malloc, char *error_message);
char **malloc_array(char **array, size_t size_of_malloc, char *error_message);
int copy_array(char **destination, char **source);
int _env_name_exists(const char *name);
int _env_length(void);
#endif
