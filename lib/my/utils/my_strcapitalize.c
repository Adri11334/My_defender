/*
** EPITECH PROJECT, 2021
** capitalyse
** File description:
** task 10
*/

#include <stdlib.h>
#include "my.h"

char check_letter(char letter)
{
    if (letter >= 97 && letter <= 122) {
        return letter -= 32;
    }
    return letter;
}

char *my_strcapitalize(char *str)
{
    if (str == NULL)
        return NULL;
    if (my_strlowcase(str) == 84)
        return 84;
    for (int i = 0; str[i] != '\n'; i++) {
        if (i == 0 && str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
            continue;
        }
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+') {
            str[i + 1] = check_letter(str[i + 1]);
            continue;
        }
    }
    return str;
}
