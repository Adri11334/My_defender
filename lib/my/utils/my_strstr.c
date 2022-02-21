/*
** EPITECH PROJECT, 2021
** str str
** File description:
** task 05, day 6
*/

#include <stdlib.h>

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    if (str == NULL || to_find == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == to_find[0]
        && my_strncmp(&str[i], to_find, my_strlen(to_find)) == 0)
            return &str[i];
    return NULL;
}
