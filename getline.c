#include "main.h"

/**
 * _getline - short description
 *
 * Description: long description
 *
 * @input: description
 * @number_of_malloc_bytes_allocated: description
 * @status: the exit status
 *
 * Return: -1 on failure greater than 0 on success
 */
ssize_t _getline(char **input,
		size_t *number_of_malloc_bytes_allocated, int status)
{
	ssize_t number_of_characters_read;

	prompt();
	number_of_characters_read = getline(input,
			number_of_malloc_bytes_allocated, stdin);
	if (number_of_characters_read == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (number_of_characters_read);
}
