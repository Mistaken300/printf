#include "main.h"
/**
 * handle_print - Print an argument based on its format specifier.
 * @fmt: Formatted string containing specifiers for printing arguments.
 * @list: List of arguments to be printed.
 * @ind: Current index in the format string.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags affecting printing behavior.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for argument casting.
 *
 * Return: The number of characters printed, or -1 in case of an error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_length = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_length += write(1, &fmt[*ind], 1);
		return (unknow_length);
	}
	return (printed_chars);
}
