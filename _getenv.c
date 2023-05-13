#include "main.h"

/**
 * _getenv - short description
 *
 * Description: long description
 *
 * @name: argument_1 description
 *
 * Return: return description
 */
char *_getenv(const char *name)
{
	unsigned int env_index, envar_length;
	char *env_var;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		if (strncmp(__environ[env_index], name, strlen(name)) == 0)
		{
			envar_length = strlen(__environ[env_index]) - ( 1 + strlen(name));
			env_var = malloc(sizeof(char) * envar_length);
			if (env_var == NULL)
			{
				perror("_getenv() Error: env_var malloc failed");
				return (NULL);
			}
			strncpy(env_var,__environ[env_index] += (strlen(name) + 1), envar_length);
			return (env_var);
		}
	}
	return (NULL);
}
