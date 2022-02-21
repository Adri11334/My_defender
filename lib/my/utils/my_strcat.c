/*
** EPITECH PROJECT, 2021
** is printable
** File description:
** str cat
*/

#include <stdlib.h>

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int index_dest = 0;
    int index_src = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    if (my_strlen(src) == 0)
        return (dest);
    while (dest[index_dest] != '\0') {
        index_dest++;
    }
    while (src[index_src] != '\0') {
        dest[index_dest] = src[index_src];
        index_dest++;
        index_src++;
    }
    return (dest);
}
