/*
** EPITECH PROJECT, 2021
** rev str
** File description:
** task 03
*/

#include <stdlib.h>

#include "my.h"

char *my_revstr_pt2(int length, char *str)
{
    char new_char[length + 1];

    if (str == NULL)
        return NULL;
    for (int i = 0; i < length; i++)
        new_char[length - 1 - i] = str[i];
    for (int i = length - 1; i >= 0; i--)
        str[i] = new_char[i];
    return str;
}

////////////////////////////////////////////////////////////
//
// reverse a string
//
// @param str the string to reverse
////////////////////////////////////////////////////////////
char *my_revstr(char *str)
{
    if (str == NULL)
        return NULL;
    return my_revstr_pt2(my_strlen(str), str);
}
