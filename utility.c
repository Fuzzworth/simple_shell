#include "main.h"

/**
 * malloc_char - short description
 *
 * Description: long description
 *
 * @string: reference to string
 * @size_of_malloc: int size of malloc
 * @error_message: string error message
 *
 * Return: return description
 */
char *malloc_char(char **string, size_t size_of_malloc, char *error_message)
{
	*string = (char *) malloc(sizeof(char) * size_of_malloc);
	if (string == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (*string);
}

/**
 * malloc_array - short description
 *
 * Description: long description
 *
 * @array: reference to string
 * @size_of_malloc: int size of malloc
 * @error_message: string error message
 *
 * Return: return description
 */
char **malloc_array(char **array, size_t size_of_malloc, char *error_message)
{
	array = (char **) malloc(sizeof(char *) * size_of_malloc);
	if (array == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (array);
}

/**
 * copy_array - short description
 *
 * Description: long description
 *
 * @destination: argument_1 description
 * @source: argument_2 description
 *
 * Return: return description
 */
int copy_array(char **destination, char **source)
{
	size_t new_env_index, free_new_env_index;

	for (new_env_index = 0; source[new_env_index]; new_env_index++)
	{
		destination[new_env_index] = malloc(sizeof(char) *
				strlen(source[new_env_index]));
		if (destination[new_env_index] == NULL)
		{
			perror("_setenv() Error: new_environ[new_env_index] malloc failed");
			for (free_new_env_index = 0; free_new_env_index < new_env_index;
					free_new_env_index++)
				free(destination[new_env_index]);
			free(destination);
			return (-1);
		}
		strcpy(destination[new_env_index], source[new_env_index]);
	}
	return (0);
}

/**
 * _env_name_exists - short description
 *
 * Description: long description
 *
 * @name: name string
 *
 * Return: return description
 */
int _env_name_exists(const char *name)
{
	int env_index, is_found;

	is_found = -1;
	for (env_index = 0; __environ[env_index]; env_index++)
		if (strncmp(__environ[env_index], name, strlen(name)) == 0)
			is_found = env_index;
	return (is_found);
}

/**
 * _env_length - short description
 *
 * Description: long description
 *
 * Return: return description
 */
int _env_length(void)
{
	unsigned int env_length;

	for (env_length = 0; __environ[env_length]; env_length++)
		;
	return (env_length);
}
