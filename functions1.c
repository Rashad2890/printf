#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 */
int print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    num = convert_size_unsgnd(num, size);
    return print_number(num, buffer, flags, width, precision, '0');
}

/**
 * print_octal - Prints an unsigned number in octal notation
 */
int print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    num = convert_size_unsgnd(num, size);
    return print_number_base(num, buffer, flags, width, precision, '0', "01234567");
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 */
int print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    num = convert_size_unsgnd(num, size);
    return print_number_base(num, buffer, flags, width, precision, 'x', "0123456789abcdef");
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 */
int print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    unsigned long int num = va_arg(types, unsigned long int);
    num = convert_size_unsgnd(num, size);
    return print_number_base(num, buffer, flags, width, precision, 'X', "0123456789ABCDEF");
}

/**
 * print_number_base - Prints a number in a given base with a specified prefix character
 */
int print_number_base(unsigned long int num, char buffer[],
    int flags, int width, int precision, char prefix, const char* base_chars)
{
    int i = BUFF_SIZE - 2;
    if (num == 0) {
        buffer[i--] = '0';
    }
    else {
        while (num > 0) {
            buffer[i--] = base_chars[num % strlen(base_chars)];
            num /= strlen(base_chars);
        }
        if (flags & F_HASH && prefix != '\0') {
            buffer[i--] = prefix;
            buffer[i--] = '0';
        }
    }
    return write_unsgnd(0, i+1, buffer, flags, width, precision, 0);
}

/**
 * print_number - Prints a number without any prefix character
 */
int print_number(unsigned long int num, char buffer[],
    int flags, int width, int precision, char pad_char)
{
    int i = BUFF_SIZE - 2;
    if (num == 0) {
        buffer[i--] = '0';
    }
    else {
        while (num > 0) {
            buffer[i--] = (num % 10) + '0';
            num /= 10;
        }
    }
    return write_unsgnd(0, i+1, buffer, flags, width, precision, pad_char);
}
