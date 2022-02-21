/*
** EPITECH PROJECT, 2021
** str copy
** File description:
** task 01
*/

#include <stdlib.h>

#include "my.h"

char *my_strcpy (char *dest, char const *src)
{
    int src_length = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    src_length = my_strlen(src);
    for (int i = 0; i < src_length; i++) {
        dest[i] = src[i];
    }
    return dest;
}
