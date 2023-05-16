#include "main.h"

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
	path_var = _getenv("PATH");
	if (!path_var)
	{
		perror("_which Error: getenv returned NULL");
		return (NULL);
	}
	array_of_tokens = array_maker(path_var, delimiter);
	if (!array_of_tokens)
	{
		perror("_which Error: array_of_tokens is NULL");
		return (NULL);
	}
	for (token_index = 0; array_of_tokens[token_index]; token_index++)
	{
		malloc_char(&file_path,
				(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
				"_which Error: malloc failed for file_path");
		strcpy(file_path, array_of_tokens[token_index]);
		strcat(file_path, "/");
		strcat(file_path, filename);
		strcat(file_path, "\0");
		file_path_exist = stat(file_path, &sb);
		if (file_path_exist == -1)
			free(file_path);
		else if (file_path_exist == 0)
			return (file_path);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0)
		return (file_path);

	return (NULL);
}
