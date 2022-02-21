/*
** EPITECH PROJECT, 2021
** my lib
** File description:
** print of a certain color pt 2
*/

#include <stdlib.h>

#include "my.h"

void write_purple(char *str)
{
    if (str == NULL)
        return;
    my_printf("\x1B[35m%s\x1B[0m", str);
}
