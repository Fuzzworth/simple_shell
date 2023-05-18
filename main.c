#include "main.h"

/**
 * free_main - free array of tokens in the main function
 * @array_of_tokens: tokenized string
 *
 * Return: void
 */
void free_main(char **array_of_tokens)
{
	int index;

	for (index = 0; array_of_tokens[index]; index++)
		free(array_of_tokens[index]);
	free(array_of_tokens);
}
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
			_fork(which, array_of_tokens);
		}
		free_main(array_of_tokens);
	}
	return (0);
}
