/*
** EPITECH PROJECT, 2022
** display parallax
** File description:
** display_parallax
*/

#include "my_defender.h"

void move_parallax(layer_t *layer, int max)
{
    if (layer == NULL)
        return;
    if ((layer->rect->left + layer->offset) < max) {
        layer->rect->left = layer->rect->left + layer->offset;
    } else {
        layer->rect->left = 0;
    }
    sfSprite_setTextureRect(layer->sprite, *layer->rect);
}

void display_parallax(game_t *_gm)
{
    linked_list *layers = _gm->menu_scene->panels;
    layer_t *layer = NULL;

    for (; layers != NULL; layers = layers->next) {
        if (!layers->data)
            continue;
        layer = layers->data;
        move_parallax(layer, 1920);
        sfRenderWindow_drawSprite(_gm->window, layer->sprite, NULL);
    }
    back_to_start(&layers);
}
