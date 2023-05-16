#include "main.h"

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
 * create_envar - short description
 *
 * Description: long description
 *
 * @env_var: argument_1 description
 * @envar_length: argument_2 description
 * @name: name string
 * @value: value string
 *
 * Return: return description
 */
void create_envar(char **env_var, unsigned int envar_length, const char *name,
		const char *value)
{
	*env_var = malloc_char(env_var, envar_length,
			"_setenv() Error: env_var malloc failed");
	envar_length = strlen(name) + strlen(value) + 2;
	*env_var = malloc_char(env_var, envar_length,
			"_setenv() Error: env_var malloc failed");
	strcpy(*env_var, name);
	strcat(*env_var, "=");
	strcat(*env_var, value);
	strcat(*env_var, "\0");
}

/**
 * env_exists - short description
 *
 * Description: long description
 *
 * @env_var: argument_1 description
 * @envar_length: argument_2 description
 * @name: name string
 * @overwrite: overwrite integer
 *
 * Return: return description
 */
int _env_set_exists(char *env_var, unsigned int envar_length, const char *name,
		int overwrite)
{
	unsigned int env_index, is_found;

	is_found = 0;
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
			return (-1);
		}
	}
	if (is_found)
		return (env_index);
	else
		return (0);
}

/**
 * env_does_not_exists - short description
 *
 * Description: long description
 *
 * @env_var: argument_1 description
 * @envar_length: argument_2 description
 * @env_length: length of enviroment
 *
 * Return: return description
 */
int env_does_not_exists(char *env_var, unsigned int envar_length,
		unsigned int env_length)
{
	unsigned int free_new_env_index;
	char **new_environ;

	new_environ = (char **) malloc(sizeof(char *) * (env_length + 2));
	if (new_environ == NULL)
	{
		perror("_setenv() Error: new_environ malloc failed");
		free(env_var);
		return (-1);
	}
	copy_array(new_environ, __environ);
	new_environ[env_length] = malloc(sizeof(char) * envar_length);
	if (new_environ[env_length] == NULL)
	{
		perror("_setenv() Error: new_environ[env_index] malloc failed");
		for (free_new_env_index = 0; free_new_env_index < env_length;
				free_new_env_index++)
			free(new_environ[free_new_env_index]);
		free(new_environ);
		free(env_var);
		return (-1);
	}
	strcpy(new_environ[env_length], env_var);
	new_environ[env_length + 1] = NULL;
	free(env_var);
	__environ = new_environ;
	return (0);
}
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
 * @name: name string
 * @value: value string
 * @overwrite: overwrite intger
 *
 * Return: -1 on failure 0 on success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int env_legnth, envar_length;
	char *env_var;

	envar_length = strlen(name) + strlen(value) + 2;
	create_envar(&env_var, envar_length, name, value);
	env_legnth = _env_set_exists(env_var, envar_length, name, overwrite);
	if (env_legnth)
		env_does_not_exists(env_var, envar_length, env_legnth);
	return (0);
}
