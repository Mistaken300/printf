#include "main.h"

/**
 * print_rot13string - Prints a string in rot13 encoding.
 * @types: List of arguments.
 * @buffer: Buffer array for printing (not used).
 * @flags: Active flags for formatting (not used).
 * @width: Width specifier (not used).
 * @precision: Precision specifier (not used).
 * @size: Size specifier (not used).
 * Return: Number of characters printed.
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int d, m;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (d = 0; str[d]; d++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == str[d])
			{
				x = out[m];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[m])
		{
			x = str[d];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
