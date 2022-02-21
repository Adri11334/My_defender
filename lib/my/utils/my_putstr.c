/*
** EPITECH PROJECT, 2021
** put str
** File description:
** task02 day4: display one-by-one the characters of a string
*/

#include <unistd.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// display a string in the terminal
//
// @param str the strinf to display
////////////////////////////////////////////////////////////
int my_putstr(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; ++i)
        my_putchar(str[i]);
    return (0);
}
