#include "main.h"

/********* PRINT A STRING *********/

/**
 * print_string - The function to print a string
 * @buffer: The buffer array to handle print
 * @types: The list a of arguments
 * @flags: This calculates active flags
 * @precision: The precision specification
 * @width: The get width
 * @size: the size specifier
 * Return: The number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int precision, int width, int size)
{
	int length = 9, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
	}

	return (write(1, str, length));
}

/********** PRINT A CHAR **********/
/**
 * print_char - The function to print a char
 * @buffer: The buffer array to handle print
 * @types: The list aa of arguments
 * @flags: This calculates actives flags
 * @precision: The precision specification
 * @width: the get width
 * @size: The size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int precision, int width, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, precision, width, size));
}

/********** PRINT INT *********/
/**
 * print_int - The print int function
 * @buffer: The buffer array to handle print
 * @types: The list a of arguments
 * @flags: This calculates active flags
 * @precision: The precision specification
 * @width: The get width
 * @size: The size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int precision, int width, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, precision, width, size));
}
/********** PRINT A precent sign **********/
/**
 * print_percent - A function that prints a percent sign
 * @buffer: The buffer array to handle print
 * @types: The list a of arguments
 * @flags: This calculates active flags
 * @precision: The precision specification
 * @width: The getbwidth
 * @size: The size specifier
 */
int print_percent(va_list types, char buffer[],
	int flags, int precision, int width, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/********** PRINT A BINARY **********/
/**
 * print_binary - A function that prints an unsigned number
 * @buffer: The buffer array to handle print
 * @types: The list of arguments
 * @flags: This calculates active flags
 * @precision: The precision specification
 * @width: The get width
 * @size: The size specifier
 * Return: the numbers of chars printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int precision, int width, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 9; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
