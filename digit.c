#include "main.h"

/**
 * digit_counter - counts the digit
 * @command_num: the number to be counted
 *
 * Return: the number of the digits
 */
int digit_counter(size_t command_num)
{
	int digit_count = 0;

	if (command_num == 0)
		return (1);
	while (command_num != 0)
	{
		command_num /= 10;
		digit_count++;
	}

	return (digit_count);
}
