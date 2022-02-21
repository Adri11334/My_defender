/*
** EPITECH PROJECT, 2021
** square root
** File description:
** task05 day5: returns the square root of the number given
*/

#include <unistd.h>

int my_compute_square_root(int nb)
{
    for (int i = 0; i * i < nb && i * i != nb; i++) {
        if (i * i == nb) {
            return i;
        }
        return i * (i - 1);
    }
    return 0;
}
