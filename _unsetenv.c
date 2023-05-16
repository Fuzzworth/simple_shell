#include "main.h"

/**
 * size_of_environ - short description
 *
 * Description: long description
 *
 *
 * Return: return description
 */
unsigned int size_of_environ(void)
{
	int size;

	for (size = 0; __environ[size]; size++)
		;
	return (size);
}

/**
 * _env_exists - short description
 *
 * Description: long description
 *
 * @name: name string
 *
 * Return: return description
 */
int _env_exists(const char *name)
{
	unsigned int env_index;
	int found_index;

	found_index = -1;
	for (env_index = 0; __environ[env_index]; env_index++)
		if (strncmp(__environ[env_index], name, strlen(name)) == 0)
			found_index = env_index;
	return (found_index);
}
/**
 * _unsetenv - short description
 *
 * Description: log description
 *
 * @name: argument_1 description
 *
 * Return: return description
 */
int _unsetenv(const char *name)
{
	unsigned int env_index;
	int new_env_index, free_new_env_index, found_index;
	char **new_environ;

	env_index = size_of_environ();
	found_index = _env_exists(name);
	if (found_index != -1)
	{
		new_environ = (char **) malloc(sizeof(char *) * (env_index));
		if (new_environ == NULL)
		{
			perror("_unsetenv() Error: new_environ malloc failed");
			return (-1);
		}
		for (new_env_index = 0; __environ[new_env_index]; new_env_index++)
		{
			if (new_env_index != found_index)
			{
				new_environ[new_env_index] = malloc(sizeof(char) *
						strlen(__environ[new_env_index]));
				if (new_environ[new_env_index] == NULL)
				{
					perror("_unsetenv() Error: new_environ[new_env_index] malloc failed");
					for (free_new_env_index = 0; free_new_env_index < new_env_index;
							free_new_env_index++)
						free(new_environ[new_env_index]);
					free(new_environ);
					return (-1);
				}
				strcpy(new_environ[new_env_index], __environ[new_env_index]);
			}
		}
		new_environ[env_index] = NULL;
		__environ = new_environ;
	}
	return (0);
}
