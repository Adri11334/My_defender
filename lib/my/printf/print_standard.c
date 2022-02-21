/*
** EPITECH PROJECT, 2021
** printf
** File description:
** basics print functions
*/

#include <stdarg.h>
#include <stdlib.h>

#include "my.h"

void print_string(va_list arg)
{
    char *str = va_arg(arg, char*);

    if (str == NULL)
        return;
    my_putstr(str);
}

void print_integer(va_list arg)
{
    int nb = va_arg(arg, int);

    my_put_nbr(nb);
}
