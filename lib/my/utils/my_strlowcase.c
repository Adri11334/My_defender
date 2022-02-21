/*
** EPITECH PROJECT, 2021
** low case
** File description:
** task 09
*/

#include <stdlib.h>

char *my_strlowcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return NULL;
    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}
