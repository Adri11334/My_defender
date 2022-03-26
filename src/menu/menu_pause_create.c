/*
** EPITECH PROJECT, 2022
** menu pause
** File description:
** create /init menu pause
*/

#include "my_defender.h"

layer_t *pause_create(char *name, game_status_t type, dimension_t *dim)
{
    layer_t *layer = malloc(sizeof(layer_t));

    layer->rect = malloc(sizeof(sfIntRect));
    if (layer == NULL || layer->rect == NULL)
        return NULL;
    layer->rect->top = 0;
    layer->rect->left = 0;
    layer->rect->width = 3840;
    layer->rect->height = 1080;
    layer->sprite = sfSprite_create();
    layer->texture = sfTexture_createFromFile(name, NULL);
    layer->type = type;
    layer->clock = sfClock_create();
    layer->clock_rate = 1;
    layer->dim = dim;
    sfSprite_setTexture(layer->sprite, layer->texture, sfFalse);
    sfSprite_setTextureRect(layer->sprite, *layer->rect);
    sfSprite_setPosition(layer->sprite, *dim->position);
    return layer;
}

void menu_pause_create(game_t *_gm)
{
    dimension_t *dim = NULL;

    dim = dimension_create(1920, 1080, 0, 0);
    if (!dim)
        return;
    _gm->menu_scene->pause = \
    init_list(pause_create("./assets/image/menu_pause.png", PAUSE, dim));
    printf("the pause has been created\n");
}
