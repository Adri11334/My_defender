/*
** EPITECH PROJECT, 2021
** str is alpha
** File description:
** task 12
*/

#include <stdlib.h>

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 57 && 48 <= str[i]) {
        } else
            return (0);
    }
    return (1);
}
