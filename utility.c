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
	array = (char **) malloc(sizeof(char) * size_of_malloc);
	if (array == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (array);
}
