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
	char *input, *delimiter, *which;
	size_t number_of_malloc_bytes_allocated;
	char **array_of_tokens;

	input = NULL;
	number_of_malloc_bytes_allocated = 0;
	delimiter = " \n";
	while (1)
	{
		_getline(&input, &number_of_malloc_bytes_allocated);
		array_of_tokens = array_maker(input, delimiter);
		which = _which(array_of_tokens[0]);
		if (which !=  NULL)
		{
			array_of_tokens[0] = which;
			_fork(array_of_tokens);
		}
	}
	return (0);
}
