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
 * free_which - short description
 *
 * Description: long description
 *
 * @path_var: argument_1 description
 * @array_of_tokens: argument_2 description
 *
 * Return: return description
 */
void free_which(char **path_var, char **array_of_tokens)
{
	int index;

	if (array_of_tokens != NULL)
	{
		for (index = 0; array_of_tokens[index]; index++)
			if (array_of_tokens[index] != NULL)
				free(array_of_tokens[index]);
		free(array_of_tokens);
	}
	if (*path_var != NULL)
		free(*path_var);
}
