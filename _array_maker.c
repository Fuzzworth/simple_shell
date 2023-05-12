#include "main.h"

/**
 * array_maker - short description
 *
 * Description: long description
 *
 * @input: argument_1 description
 *
 * Return: return description
 */
char **array_maker(char *input)
{
	char *delimiter, *input_cpy, *token;
	char **array_of_tokens;
	int token_count, token_index, token_free_index;

	delimiter = " \n";
	token_count = 0;
	input_cpy = (char *) malloc(sizeof(char) * strlen(input));
	if (input_cpy == NULL)
	{
		perror("array_maker() Error: input_cpy maoloc failure");
		return (NULL);
	}
	strcpy(input_cpy, input);
	token = strtok(input_cpy, delimiter);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delimiter);
	}
	array_of_tokens = (char **) malloc(sizeof(char *) * (token_count + 1));
	if (array_of_tokens == NULL)
	{

		perror("array_maker() Error: array_of_tokens** maoloc failure");
		return (NULL);
	}
	token = strtok(input, delimiter);
	for (token_index = 0; token_index < token_count; token_index++)
	{
		array_of_tokens[token_index] = (char *) malloc(sizeof(char) * strlen(token));
		if (array_of_tokens[token_index] == NULL)
		{
			for (token_free_index = 0;
					token_free_index < token_index;
					token_free_index++)
			{
				free(array_of_tokens[token_free_index]);
			}
			free(array_of_tokens);
			perror("array_maker() Error: array_of_tokens maoloc failure");
			return (NULL);
		}
		strcpy(array_of_tokens[token_index], token);
		token = strtok(NULL, delimiter);
	}
	array_of_tokens[token_count] = NULL;

	return (array_of_tokens);
}
