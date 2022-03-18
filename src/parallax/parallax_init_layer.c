/*
** EPITECH PROJECT, 2022
** parlalax
** File description:
** init layer
*/

#include "my_defender.h"

void parallax_init_layer(game_t *_gm)
{
    dimension_t *dim = NULL;

    dim = dimension_create(3840, 1080, 0, 0);
    if (!dim)
        return NULL;
    _gm->menu_scene->panels = \
    init_list(layer_create("./assets/parallax/1Ground.png", GROUND, dim, 14));
    push_node(&_gm->menu_scene->panels, \
    layer_create("./assets/parallax/2Trees.png", TREES, dim, 12));
    push_node(&_gm->menu_scene->panels, \
    layer_create("./assets/parallax/3Hillso.png", HILLSO, dim, 10));
    push_node(&_gm->menu_scene->panels, \
    layer_create("./assets/parallax/4Hillst.png", HILLST, dim, 8));
    push_node(&_gm->menu_scene->panels, \
    layer_create("./assets/parallax/5Clouds.png", CLOUDS, dim, 6));
    push_node(&_gm->menu_scene->panels, \
    layer_create("./assets/parallax/6Rocks.png", ROCKS, dim, 4));
    push_node(&_gm->menu_scene->panels, \
    layer_create("./assets/parallax/7Sky.png", SKY, dim, 2));
}
