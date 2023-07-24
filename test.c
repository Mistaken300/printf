#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string containing zero or more directives.
 * Return: Number of characters printed
 *
 * This function produces output according to the given format and variable 
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (!format)
        return -1;

    va_start(list, format);

    for (int i = 0; format[i]; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            i++;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return printed_chars;
}

