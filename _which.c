#include "main.h"
#include <sys/stat.h>

char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *path_var_cpy,*delimiter, *file_path;
	char **array_of_tokens;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = getenv("PATH");
	if (!path_var)
	{
		perror("_which Error: getenv returned NULL");
		return (NULL);
	}
	path_var_cpy = (char *) malloc(sizeof(char) * strlen(path_var));
	if (path_var_cpy == NULL)
	{
		perror("_which Error: malloc error path_var_cpy is NULL");
		return (NULL);
	}
	strcpy(path_var_cpy, path_var);
	array_of_tokens = array_maker(path_var_cpy, delimiter);
	if (!array_of_tokens)
	{
		perror("_which Error: array_of_tokens is NULL");
		return (NULL);
	}
	for (token_index = 0; array_of_tokens[token_index]; token_index++)
	{
		file_path = malloc(sizeof(char) * (strlen(array_of_tokens[token_index]) + strlen(filename) + 2));
		if (!file_path)
		{
			perror("_which Error: malloc failed for file_path");
			return (NULL);
		}
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
		return (filename);
	return (NULL);
}
