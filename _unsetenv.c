#include "main.h"

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

	new_environ = NULL;
	env_index = _env_length();
	found_index = _env_name_exists(name);
	if (found_index != -1)
	{
		new_environ = malloc_array(new_environ, env_index,
				"_unsetenv() Error: new_environ malloc failed");
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
