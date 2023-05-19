#include "main.h"

/**
 * sigint_handler - handle signals
 * @signal: signal
 *
 * Return: nothing
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
