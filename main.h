#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdint.h>
/**
 * struct builtin_command - Short description
 * @name: First member
 * @function: Second member
 *
 * Description: Longer description
 */
struct builtin_command
{
	char *name;
	int (*function)(char **array_of_tokens);
};


void prompt(void);
void sigint_handler(int signal);
ssize_t _getline(char **input,
		size_t *number_of_malloc_bytes_allocated, int status);
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
void free_which(char **path_var, char **array_of_tokens);
void free_main(char **array_of_tokens, char *input);
void rev_string(char *s);
char *_itoa(size_t command_num);
int digit_counter(size_t command_num);
int error_not_found(char **arvs, char **array_of_tokens, size_t command_num);
int is_builtin(char **array_of_tokens);
int builin_handler(char **array_of_tokens);
int _exit_builtin(char **array_of_tokens);
int _env_builtin(char **array_of_tokens);
#endif
