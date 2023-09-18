#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x)(void)(x)
#define BUFF_SIZE 1024

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*SIZES*/
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - struct op
 * @fn: The associated function
 * @fmt: The format
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - op struct
 * @fm_t: The associated function
 * @fmt: the format
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle _print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print strings and char */
int print_string(va_list types, char buffer[],
	int flags, int width, int percision, int size);
int print_char(va_list types, char buffer[],
	int flags, int width, int percision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int percision, int size);

/* Functions to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int percision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int prcision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int percision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int percision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int percision, int size);
int print_octa(va_list types, char buffer[],
	int flags, int width, int percision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int percision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, percision, int size);

/* functions to print non printable characters */
int print_non_printable(va_list types, char buffers[],
	int flags, int width, int percision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_percision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Functions to print a string in reverse */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int percision, int size);

/* Functions to print string in reverse */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int percision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int percision, int size);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags char extra_c, char padd, int padd_start);
int write_num(int ind, char bff[], int flags, int width, int percision,
	int length, char extra_c, char padd);
int write_number(int is_positive, int ind, char buffer[],
	int flags int percision, int width, int size);

int write_unsigned(int is_negative, int ind, char buffer[],
	int flags, int width, int percision, int size);

/***************** UTILS ******************/
int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);

long int convert_size_unsgnd(unsigned long int num, int size);
long int convert_size_number(long int num, int size);

#endif /* MAIN_H */
