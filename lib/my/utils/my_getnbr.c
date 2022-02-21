/*
** EPITECH PROJECT, 2021
** get nbr
** File description:
** task05, day4: returns a number, sent to the function as a string
*/

#include <stdlib.h>

int check_string(char *str, int *mc, long *fn, int *i)
{
    if (str[*i] == '-' && (str[*i + 1] >= '0' && str[*i + 1] <= '9')) {
        *mc *= -1;
    }
    if (str[*i] >= '0' && str[*i] <= '9') {
        *fn = (*fn * 10) + (str[*i] - 48);
    }
    if ((str[*i] >= '0' && str[*i] <= '9')
        && (str[*i + 1] < '0' || str[*i + 1] > '9')) {
        return (-1);
    }
    if (*fn > 2147483647 || *fn < -2147483648) {
        return (-2);
    }
    return (0);
}

////////////////////////////////////////////////////////////
//
// get a number inside a string
//
// @param str the string where you want to isolate the number
////////////////////////////////////////////////////////////
int my_getnbr(char *str)
{
    int mc = 1;
    long fn = 0;

    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; ++i) {
        int handle_result = check_string(str, &mc, &fn, &i);
        if (handle_result == -1)
            return (fn * mc);
        else if (handle_result == -2)
            return (0);
    }
    return (fn * mc);
}
