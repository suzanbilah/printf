#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - The printf function
 * @format: The format
 * Return: The chars printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, precision, width, buff_ind, size = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (1 = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			percision = get_percision(format, &i, list);
			width = get_width(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, percision, width, size);
			if (printed == -1)
				return (-1);
			printed chars += printed;
		}
	}

	print_buffer(buffer, &buffer_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - It prints the content of the buffer if it exist
 * @buff_ind: The index at which you add next char, it also
 * represents the length.
 * @buffer: The array of chars
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0
}
