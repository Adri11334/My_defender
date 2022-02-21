/*
** EPITECH PROJECT, 2021
** my swap
** File description:
** task01 day4: swap content of 2 integers
*/

#include <unistd.h>

int my_swap(int *a, int *b)
{
    int c = 0;

    if (a == NULL || b == NULL)
        return 84;
    c = *a;
    *a = *b;
    *b = c;
    return 0;
}
