#include "main.h"

/**
 * main - short description
 *
 * Description: long description
 *
 * @ac: argument_1 description
 * @arvs: argument_2 description
 * @envp: argument_3 desctiontion
 *
 * Return: return description
 */
int main(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	char *input;
	size_t number_of_malloc_bytes_allocated;
	char **array_of_tokens;

	while (1)
	{
		_getline(&input, &number_of_malloc_bytes_allocated);
		array_of_tokens = array_maker(input);
		_fork(array_of_tokens);
	}
	return (0);
}
