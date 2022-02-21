/*
** EPITECH PROJECT, 2021
** printf
** File description:
** utils function
*/

void my_putchar(char c);

int print_unisgned_number(unsigned int nb)
{
    unsigned int range = 1;
    unsigned int nb_buff = nb;

    while (nb_buff > 9) {
        nb_buff /= 10;
        range *= 10;
    }
    while (range >= 1) {
        my_putchar(((nb / range) % 10) + '0');
        range /= 10;
    }
    return 0;
}
