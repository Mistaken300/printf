#include "main.h"

/**
 * write_number - Print a formatted number.
 * @is_negative: Flag for negative number (1) or non-negative number (0).
 * @ind: Current index in the buffer array.
 * @buffer: Buffer array to handle printing.
 * @flags: Active flags affecting printing behavior.
 * @width: Width specification for formatting.
 * @precision: Precision specifier for formatting.
 * @size: Size specifier for argument casting (not used in this function).
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}
