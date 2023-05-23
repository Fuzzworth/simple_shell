#include "main.h"

/**
 * is_builtin - short description
 *
 * Description: long description
 *
 * @array_of_tokens: command array
 *
 * Return: 1 if success 0 if failure
 */
int is_builtin(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (1);
	return (0);
}

/**
 * builin_handler - short description
 *
 * Description: long description
 *
 * @array_of_tokens: command array
 *
 * Return: 1 if success 0 if failure
 */
int builin_handler(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
	{
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (builtins[builtin_index].function(array_of_tokens));
	}
	return (0);
}
