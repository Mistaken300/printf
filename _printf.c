#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: the format specifier
 * Return: chars to be printed
 */

int _printf(const char *format, ...)
{
        int printed = 0;

        va_list args;

        va_start(args, format);

        while (*format != '\0')
        {
                if (*format == '%')
                {
                        format++;
                        printed = selector(format, args, printed);
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
