/*
** EPITECH PROJECT, 2021
** my lib [WSL: Ubuntu]
** File description:
** printing
*/

#include <stdlib.h>

#include "my.h"

void red_header(const char *str)
{
    if (str == NULL)
        return;
    my_putstr("\n\x1B[31m-------------------------------------------------\n");
    my_putstr("## ");
    my_putstr(str);
    my_putstr("\n-------------------------------------------------\n\x1B[0m");
}

void green_header(const char *str)
{
    if (str == NULL)
        return;
    my_putstr("\n\x1B[32m-------------------------------------------------\n");
    my_putstr("## ");
    my_putstr(str);
    my_putstr("\n-------------------------------------------------\n\x1B[0m");
}

void cyan_header(const char *str)
{
    if (str == NULL)
        return;
    my_putstr("\n\x1B[36m-------------------------------------------------\n");
    my_putstr("## ");
    my_putstr(str);
    my_putstr("\n-------------------------------------------------\n\x1B[0m");
}

void blue_header(const char *str)
{
    if (str == NULL)
        return;
    my_putstr("\n\x1B[34m-------------------------------------------------\n");
    my_putstr("## ");
    my_putstr(str);
    my_putstr("\n-------------------------------------------------\n\x1B[0m");
}

void white_header(const char *str)
{
    if (str == NULL)
        return;
    my_putstr("\n\x1B[37m-------------------------------------------------\n");
    my_putstr("## ");
    my_putstr(str);
    my_putstr("\n-------------------------------------------------\n\x1B[0m");
}
