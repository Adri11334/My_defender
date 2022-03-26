/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** main file
*/

#include <stddef.h>
#include "my_defender.h"

int main(int argc, char **argv, char **env)
{
    if (*env == NULL)
        return 84;
    return main_window(argv);
}

// ! F4./src/towers/towers_init.c:74 ./src/maps/maps_load_blocks.c:33