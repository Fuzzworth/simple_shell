#include "main.h"

/**
 * prompt - short description
 *
 * Description: long description
 *
 * Return: -1 on failure greater than 0 on success
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
