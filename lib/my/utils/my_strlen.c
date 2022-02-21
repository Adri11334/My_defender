/*
** EPITECH PROJECT, 2021
** put str
** File description:
** task03 day4: return the number of characters in
** the string passed as parameter
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (i);
    while (str[i] != '\0')
        ++i;
    return (i);
}
