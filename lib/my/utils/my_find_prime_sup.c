/*
** EPITECH PROJECT, 2021
** find prime sup
** File description:
** task 07
*/

#include <unistd.h>

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (; my_is_prime(nb) == 0; nb++);
    return nb;
}
