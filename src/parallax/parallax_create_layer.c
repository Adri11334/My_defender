/*
** EPITECH PROJECT, 2022
** parallax
** File description:
** init parallax
*/

#include "my_defender.h"

layer_t *layer_create(char *name, layer_type_t type, dimension_t *dim, \
int offset)
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
    layer->offset = offset;
    sfSprite_setTexture(layer->sprite, layer->texture, sfFalse);
    sfSprite_setTextureRect(layer->sprite, *layer->rect);
    sfSprite_setPosition(layer->sprite, *dim->position);
    return layer;
}
