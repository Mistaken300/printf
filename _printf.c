#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: The format specifier
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed += selector(format, args);
			format++;
		}
		else
		{
			_putchar(*format);
			printed++;
			format++;
		}
	}

	va_end(args);
	return (printed);
}

