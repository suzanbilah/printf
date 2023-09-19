#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	char *buffer;

	if (!format)
		return (-1);

	va_start(args, format);
	buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			if (format[1] == '\0')
			{
				print_buf(buffer, len);
				free(buffer);
				va_end(args);
				return (-1);
			}
			else
			{
				format++;
				len += handle_format(&format, args, buffer);
			}
		}
		else
		{
			buffer[len++] = *format;
		}

		if (len >= 1024)
		{
			print_buf(buffer, len);
			len = 0;
		}

		format++;
	}

	print_buf(buffer, len);
	free(buffer);
	va_end(args);
	return (len);
}
