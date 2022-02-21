/*
** EPITECH PROJECT, 2021
** str is alpha
** File description:
** task 12
*/

#include <stdlib.h>

////////////////////////////////////////////////////////////
//
// check if a sting is only composed of alpha characters, return 1 if alpha
//
// @param str the string to analyse
////////////////////////////////////////////////////////////
int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] <= 122 && 97 <= str[i])
            || (str[i] <= 90 && 65 <= str[i])) {
        } else
            return (0);
    }
    return (1);
}
