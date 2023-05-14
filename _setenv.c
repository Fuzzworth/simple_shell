#include "main.h"

/**
 * _setenv - short description
 *
 * Description: The setenv() function adds the variable name to the
 * environment with the value value, if name does not already exist.
 * If name does exist in the environment, then its value is changed
 * to value if overwrite is  nonzero;  if overwrite is zero, then the
 * value of name is not changed (and setenv() returns a suc-cess status).
 * This function makes copies of the strings pointed to by name  and
 * value  (by  contrast with putenv(3)). The unsetenv() function deletes
 * the variable name from the environment. If name does not exist in the
 * environment, then the function succeeds, and the environment is unchanged.
 *
 * @argument_1: argument_1 description
 * @argument_2: argument_2 description
 * @argument_3: argument_3 description
 *
 * Return: return description
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int env_index, envar_length, new_env_index, free_new_env_index, is_found;
	char *env_var;
	char **new_environ;

	is_found = 0;
	envar_length = strlen(name) + strlen(value) + 2;
	env_var = malloc(sizeof(char) * envar_length);
	if (env_var == NULL)
	{
		perror("_setenv() Error: env_var malloc failed");
		return (-1);
	}
	strcpy(env_var, name);
	strcat(env_var, "=");
	strcat(env_var, value);
	strcat(env_var, "\0");

	for (env_index = 0; __environ[env_index]; env_index++)
	{

		if (strncmp(__environ[env_index], name, strlen(name)) == 0)
			is_found = 1;
		if (strncmp(__environ[env_index], name, strlen(name)) == 0 && overwrite != 0)
		{
			free(__environ[env_index]);
			__environ[env_index] = malloc(sizeof(char) * envar_length);
			if (__environ[env_index] == NULL)
			{
				perror("_setenv() Error: __environ[env_index] malloc failed");
				free(env_var);
				return (-1);
			}
			strcpy(__environ[env_index], env_var);
			free(env_var);
			return (0);
		}
	}

	if (!is_found)
	{
		new_environ = (char **) malloc(sizeof(char *) * (env_index + 2));
		if (new_environ == NULL)
		{
			perror("_setenv() Error: new_environ malloc failed");
			free(env_var);
			return (-1);
		}
		for (new_env_index = 0; __environ[new_env_index]; new_env_index++)
		{
			new_environ[new_env_index] = malloc(sizeof(char) *
					strlen(__environ[new_env_index]));
			if (new_environ[new_env_index] == NULL)
			{
				perror("_setenv() Error: new_environ[new_env_index] malloc failed");
				for (free_new_env_index = 0; free_new_env_index < new_env_index;
						free_new_env_index++)
					free(new_environ[new_env_index]);
				free(new_environ);
				free(env_var);
				return (-1);
			}
			strcpy(new_environ[new_env_index], __environ[new_env_index]);
		}
		new_environ[env_index] = malloc(sizeof(char) * envar_length);
		if (new_environ[env_index] == NULL)
		{
			perror("_setenv() Error: new_environ[env_index] malloc failed");
			for (free_new_env_index = 0; free_new_env_index < new_env_index;
					free_new_env_index++)
				free(new_environ[new_env_index]);
			free(new_environ);
			free(env_var);
			return (-1);
		}
		strcpy(new_environ[env_index], env_var);
		new_environ[env_index + 1] = NULL;
		free(env_var);
		__environ = new_environ;
	}
	return (0);
}
