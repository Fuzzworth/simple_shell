#include "main.h"

/**
 * _unsetenv - short description
 *
 * Description:
 *
 * @argument_1: argument_1 description
 *
 * Return: return description
 */
int _unsetenv(const char *name)
{
	unsigned int env_index, new_env_index, free_new_env_index,
		     is_found, found_index;
	char **new_environ;

	is_found = 0;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		if (strncmp(__environ[env_index], name, strlen(name)) == 0)
		{
			found_index = env_index;
			is_found = 1;
		}
	}

	if (is_found)
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
