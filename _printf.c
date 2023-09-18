#include "main.h"

/**
 * _printf - Custom implementation of the printf function.
 * @format: A format string that specifies the output format.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int output = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					break;
				case 's':
					break;
				case '%':
					break;
				case 'b':
				{
					unsigned int num = va_arg(args, unsigned int);
					int binary = sizeof(unsigned int) * 8;

					for (int i = binary - 1; i >= 0; ++i)
					{
						putchar((num & (1 << i)) ? '1' : '0');
						output++;
					}
				}
					break;
				default:
					putchar('%');
					putchar(*format);
					output += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			output++;
		}
		format++;
	}

	va_end(args);

	return (output);
}
