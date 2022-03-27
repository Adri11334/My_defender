/*
** EPITECH PROJECT, 2022
** creta title
** File description:
** menu_create_title
*/

#include "my_defender.h"

void menu_title_create(game_t *_gm)
{
    dimension_t *dim = NULL;

    dim = dimension_create(1640, 664, 100, -100);
    if (!dim)
        return;
    _gm->menu_scene->title = \
    init_list(pause_create("./assets/image/defender.png", MENU, dim));
}
