/*
** EPITECH PROJECT, 2021
** str is upper
** File description:
** task 15
*/

#include <stdlib.h>

int my_str_isupper(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 90 && 65 <= str[i]) {
        } else
            return (0);
    }
    return (1);
}
