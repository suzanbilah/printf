#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function that handles %s, %c, and %%
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int char_count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					char_count += handle_string(&args);
					break;
				case 'c':
					char_count += handle_char(&args);
					break;
				case '%':
					putchar('%');
					char_count++;
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			char_count++;
		}
		format++;
	}

	va_end(args);

	return (char_count);
}

/**
 * handle_string - Handles %s format specifier.
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
int handle_string(va_list *args)
{
	char *str = va_arg(*args, char *);

	return (printf("%s", str));
}

/**
 * handle_char - Handles %c format specifier.
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */

int handle_char(va_list *args)
{
	char c = va_arg(*args, int);

	return (printf("%c", c));
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	char name[] = "John";
	char character = 'A';

	_printf("Hello, %s!\n", name);
	_printf("My favorite character is %c.\n", character);
	_printf("This is a %% character.\n");

	return (0);
}
