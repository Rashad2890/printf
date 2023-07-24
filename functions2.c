#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable in hexadecimal format
 */
int print_pointer(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    void *ptr = va_arg(types, void *);
    unsigned long int num = (unsigned long int)ptr;
    return print_number_base(num, buffer, flags, width, precision, '\0', "0123456789abcdef");
}

/**
 * print_non_printable - Prints a string in hexadecimal format, with non-printable characters represented in ASCII code
 */
int print_non_printable(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    int i, j, offset = 0;

    if (str == NULL) {
        str = "(null)";
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (is_printable(str[i])) {
            buffer[i + offset] = str[i];
        } else {
            offset += append_hexa_code(str[i], buffer, i + offset);
        }
    }

    buffer[i + offset] = '\0';

    return write_str(buffer, flags, width, precision);
}

/**
 * print_reverse - Prints a string in reverse order
 */
int print_reverse(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    int i, j, count = 0;

    if (str == NULL) {
        str = "(null)";
    }

    for (i = 0; str[i] != '\0'; i++);
    for (j = i - 1; j >= 0; j--) {
        buffer[i - j - 1] = str[j];
    }

    buffer[i] = '\0';

    return write_str(buffer, flags, width, precision);
}

/**
 * print_rot13string - Prints a string in ROT13 format
 */
int print_rot13string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    int i, j, count = 0;
    char x;

    if (str == NULL) {
        str = "(ahyy)";
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            x = 'A' + ((str[i] - 'A' + 13) % 26);
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            x = 'a' + ((str[i] - 'a' + 13) % 26);
        } else {
            x = str[i];
        }

        buffer[i] = x;
    }

    buffer[i] = '\0';

    return write_str(buffer, flags, width, precision);
}
