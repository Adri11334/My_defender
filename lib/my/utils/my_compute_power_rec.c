/*
** EPITECH PROJECT, 2021
** compute power rec
** File description:
** task04 day05: recursive function that returns the first
** argument raised to the power p, where p is the second argument
*/

#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 1;
    else
        nb *= my_compute_power_rec(nb, p - 1);
    return (nb);
}
