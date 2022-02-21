/*
** EPITECH PROJECT, 2021
** isneg
** File description:
** task04, day 3: display N if negatif, else P for positiv or null
*/

#include <unistd.h>

////////////////////////////////////////////////////////////
//
// know if a number is positive or negative, 1 for positive, -1 for negative
//
// @param n the number to analyse
////////////////////////////////////////////////////////////
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        return -1;
    else
        return 0;
    return (0);
}
