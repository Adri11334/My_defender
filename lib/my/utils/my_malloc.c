/*
** EPITECH PROJECT, 2021
** my malloc
** File description:
** malloc gestion
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"

////////////////////////////////////////////////////////////
//
// malloc an element at a precise size, and filled it with an existing string,
// or/and empty area, to avoid jumpimg condition
//
// @param size the size you want to allocate
// @param buf the string you want to fill in
////////////////////////////////////////////////////////////
void *my_malloc(int size, char *buf)
{
    char *str = malloc(size);
    int buf_len = -1;

    if (str == NULL)
        return NULL;
    if (buf != NULL)
        buf_len = my_strlen(buf);
    for (int i = 0; i < size; i++) {
        if (i < buf_len)
            str[i] = buf[i];
        else
            str[i] = 0;
    }
    return str;
}
