#include "main.h"

/**
 * _fork - short description
 *
 * Description: long description
 *
 * @array_of_tokens: argument_1 description
 *
 * Return: return description
 */
int _fork(char **array_of_tokens)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("_fork() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(array_of_tokens[0], array_of_tokens, __environ);
		if (is_execve_error == -1)
		{
			perror("_fork() Error: exece failed to run");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
