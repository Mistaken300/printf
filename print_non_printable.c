#include "main.h"

/**
 * print_non_printable - Hex representation of non-printable ASCII codes.
 * @types: List of arguments.
 * @buffer: Buffer array to handle printing.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
