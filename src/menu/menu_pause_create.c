/*
** EPITECH PROJECT, 2022
** menu pause
** File description:
** create /init menu pause
*/

#include "my_defender.h"

void menu_pause_create(game_t *_gm)
{
    dimension_t *dim = NULL;

    dim = dimension_create(1920, 1080, 0, 0);
    if (!dim)
        return NULL;
    _gm->menu_scene->pause = \
    init_list(layer_create("./assets/image/menu_pause.png", PAUSE, dim, 1));
}
