#include "main.h"

/**
 * get_perc - Calculates the perc for printing
 * @format: format.
 * @i: List of arguments to be printed.
 * @list: the list of arguments.
 * Return: Perc.
 */
int get_perc(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int perc = -1;

	if (format[curr_i] != '.')
		return (perc);

	perc = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			perc *= 10;
			perc += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			perc = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (perc);
}

