#include "main.h"

/**
 * filepath_creator - short description
 *
 * Description: long description
 *
 * @file_path: argument_1 description
 * @array_of_tokens: argument_2 description
 * @filename: file name string
 * @token_index: index to copy
 *
 * Return: void
 */
void filepath_creator(char **file_path, char **array_of_tokens,
		char *filename, int token_index)
{
	malloc_char(file_path,
			(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, array_of_tokens[token_index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _which - short description
 *
 * Description: long description
 *
 * @filename: argument_1 description
 *
 * Return: return description
 */
char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **array_of_tokens;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = _getenv("PATH=");
	if (path_var != NULL)
	{
		array_of_tokens = array_maker(path_var, delimiter);
		if (array_of_tokens != NULL)
		{
			for (token_index = 0; array_of_tokens[token_index]; token_index++)
			{
				filepath_creator(&file_path, array_of_tokens, filename, token_index);
				file_path_exist = stat(file_path, &sb);
				if (file_path_exist == 0)
				{
					free_which(&path_var, array_of_tokens);
					return (file_path);
				}
				free(file_path);
			}
			free_which(&path_var, array_of_tokens);
		}
		else
			free(path_var);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0 && strchr(filename, '/'))
		return (strdup(filename));
	return (NULL);
}
