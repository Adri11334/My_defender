/*
** EPITECH PROJECT, 2021
** upcase
** File description:
** str upcase
*/

#include <stdlib.h>

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return NULL;
    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
