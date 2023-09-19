#include "main.h"

/********** PRINT AN UNSINED NUMBER **********/
/**
 * print_unsigned - A function that prints an unsigned number
 * @buffer: The buffer array to handle print
 * @types: The list a of arguments
 * @flags: This calculates teh active flags
 * @percision: The percision specification
 * @width: The get width
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int percision, int width, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, percision, width, size));
}

/********** PRINT AN UNSIGNED NUMBER IN OCTAL **********/
/**
 * print_octal - A function that prints an unsigned number in octal notation
 * @buffer: The buffer array to handle print
 * @types: The list of arguments
 * @flags: This calculates active flags
 * @percision: The percision specification
 * @width: The get width
 * @size: The size specifer
 * Return: The number of char printed
 *
 */
int print_octal(va_list types, char buffer[],
	int flags, int percision, int width, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, percision, width, size));
}

/********** PRINT AN UNSIGNED NUMBER IN HEXADECIMAL **********/
/**
 * print_hexadecimal - A function that prints an unsigned number in hexadecimal
 * notation
 * @buffer: The buffer array to handle print
 * @types: The list of argument
 * @flags: This calculates active flags
 * @percision: The percision specification
 * @width: The get width
 * @size: The size specifier
 * Return: number of chars printed
 */
int print_hexadecima(va_list types, char buffer[],
	int flags, int percision, int width, int size)
{
	return (print_hexa(type, "0123456789abcdef", buffer, flags, 'X',
		percision, width, size));
}

/********** PRINT AN UNSIGNED NUMBER IN UPPER HEXADECIMAL **********/
/**
 * print_hexa_upper - A function that prints an unsigned number in
 * upper hexadecimal notation
 * @buffer: The buffer array to handle print
 * @types: The list a of argument
 * @flags: This calculates active flags
 * @percision: The percision specification
 * @width: The get width
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int percision, int width, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', percision, width, size));
}

/********** PRINT HEXA NUMBER IN UPPER OR LOWER **********/
/**
 * print_hexa - A function that prints hexadecimal nuber in upper or lower
 * @buffer: The buffer array to handle print
 * @map_to: The array of values to map number to
 * @types: The list a of argument
 * @flags: This calculates active flags
 * @flag_ch: This calculates active flags
 * @percision: The percision specification
 * @width: The get width
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int percision, int width, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, percision, width, size));
}
