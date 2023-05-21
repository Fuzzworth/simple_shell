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
	int status;
	char *input, *delimiter, *which;
	size_t number_of_malloc_bytes_allocated, command_num;
	char **array_of_tokens;

	signal(SIGINT, sigint_handler);
	input = NULL;
	number_of_malloc_bytes_allocated = command_num = 0;
	delimiter = " \n";
	while (1)
	{
		command_num++;
		_getline(&input, &number_of_malloc_bytes_allocated, status);
		array_of_tokens = array_maker(input, delimiter);
		if (!(*array_of_tokens))
		{
			free_main(array_of_tokens);
			status = 0;
			continue;
		}
		which = _which(array_of_tokens[0]);
		if (which !=  NULL)
		{
			status = _fork(which, array_of_tokens);
		}
		else
		{
			error_not_found(arvs, array_of_tokens, command_num);
			status = 127;
		}
		free_main(array_of_tokens);
		free(input);
		input = NULL;
	}
	return (0);
}
