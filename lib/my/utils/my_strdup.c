/*
** EPITECH PROJECT, 2021
** my str duplicate
** File description:
** task 01
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *new_str;

    if (src == NULL)
        return NULL;
    if ((new_str = my_malloc(my_strlen(src) + 1, NULL)) == NULL)
        return NULL;
    while (src[i] != '\0') {
        new_str[i] = src[i];
        i++;
    }
    new_str[i + 1] = '\0';
    return (new_str);
}
