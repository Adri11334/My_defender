/*
** EPITECH PROJECT, 2022
** parlalax
** File description:
** init layer
*/

#include "my_defender.h"

parallax_t *parallax_init_layer(void)
{
    dimension_t *dim = NULL;
    parallax_t *menu = NULL;

    dim = dimension_create(3840, 1080, 0, 0);
    menu = malloc(sizeof(parallax_t));
    if (!dim || !menu)
        return NULL;
    menu->ground = layer_create("./assets/parallax/1Ground.png", GROUND, dim);
    menu->trees = layer_create("./assets/parallax/2Trees.png", TREES, dim);
    menu->hillso = layer_create("./assets/parallax/3Hillso.png", HILLSO, dim);
    menu->hillst = layer_create("./assets/parallax/4Hillst.png", HILLST, dim);
    menu->clouds = layer_create("./assets/parallax/5Clouds.png", CLOUDS, dim);
    menu->rocks = layer_create("./assets/parallax/6Rocks.png", ROCKS, dim);
    menu->sky = layer_create("./assets/parallax/7Sky.png", SKY, dim);
    return menu;
}