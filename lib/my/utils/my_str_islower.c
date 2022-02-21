/*
** EPITECH PROJECT, 2021
** str is lower
** File description:
** task 14
*/

#include <stdlib.h>

int my_str_islower(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 122 && 97 <= str[i]) {
        } else
            return (0);
    }
    return (1);
}
