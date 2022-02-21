/*
** EPITECH PROJECT, 2021
** printf
** File description:
** print pointeurs
*/

#include <stdarg.h>
#include <stdlib.h>

#include "my.h"

void print_ptr(va_list arg)
{
    long long nb = va_arg(arg, long long);
    char *hexa = malloc(33);
    int start_print = 0;

    if (hexa == NULL)
        return NULL;
    to_hex_long(nb, hexa, 33);
    hexa = my_strlowcase(hexa);
    my_putchar('0');
    my_putchar('x');
    while (hexa[start_print] > 102)
        (start_print)++;
    for (int i = start_print; hexa[i] != '\0'; ++i)
        my_putchar(hexa[i]);
    free(hexa);
}
