#include "main.h"

/**
 * _printf - Custom implementation of the printf function.
 * @format: A format string that specifies the output format.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int output = 0;

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
