#include "main.h"

/**
 * print_reverse - Prints a string in reverse.
 * @types: List of arguments.
 * @buffer: Buffer array for printing (not used).
 * @flags: Active flags for formatting (not used).
 * @width: Width specifier (not used).
 * @precision: Precision specifier (not used).
 * @size: Size specifier (not used).
 * Return: Number of characters printed.
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
