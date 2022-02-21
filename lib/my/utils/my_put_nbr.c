/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** affichage d'un int
*/

#include "my.h"

////////////////////////////////////////////////////////////
//
// display a number in the terminal
//
// @param nb the number to display
////////////////////////////////////////////////////////////
int my_put_nbr(int nb)
{
    int range = 1;
    int nb_buff = nb;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
        return 0;
    }
    while (nb_buff > 9) {
        nb_buff /= 10;
        range *= 10;
    }
    while (range >= 1) {
        my_putchar(((nb / range) % 10) + '0');
        range /= 10;
    }
    return (0);
}
