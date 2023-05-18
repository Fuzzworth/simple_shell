#include "main.h"

/**
 * _getline - short description
 *
 * Description: long description
 *
 * @input: description
 * @number_of_malloc_bytes_allocated: description
 *
 * Return: -1 on failure greater than 0 on success
 */
ssize_t _getline(char **input,
		size_t *number_of_malloc_bytes_allocated)
{
	ssize_t number_of_characters_read;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	number_of_characters_read = getline(input,
			number_of_malloc_bytes_allocated, stdin);
	if (number_of_characters_read == -1)
	{
		free(*input);
		exit(EXIT_FAILURE);
	}
	return (number_of_characters_read);
}
