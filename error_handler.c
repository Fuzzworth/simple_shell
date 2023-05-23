#include "main.h"

/**
 * error_not_found - Printing custom error for not found command
 * @arvs: command-line args
 * @array_of_tokens: tokenized array of strings
 * @command_num: counter
 *
 * Return: void
 */
int error_not_found(char **arvs, char **array_of_tokens, size_t command_num)
{
	char *error_str;
	char *command_num_str = _itoa(command_num);
	int size = (strlen(arvs[0]) + (2 * strlen(": ")) +
			digit_counter(command_num) + strlen(array_of_tokens[0]) +
			strlen(": not found\n") + 1);

	malloc_char(&error_str, size, "error_not_found Error: malloc error");
	strcpy(error_str, arvs[0]);
	strcat(error_str, ": ");
	strcat(error_str, command_num_str);
	strcat(error_str, ": ");
	strcat(error_str, array_of_tokens[0]);
	strcat(error_str, ": not found\n");
	strcat(error_str, "\0");

	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(command_num_str);
	return (127);
}
