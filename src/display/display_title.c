/*
** EPITECH PROJECT, 2022
** display title
** File description:
** display_title
*/

#include "my_defender.h"

void display_title(game_t *_gm)
{
    linked_list *title = _gm->menu_scene->title;
    layer_t *layer_ti = NULL;

    for (; title != NULL; title = title->next) {
        if (!title->data)
            continue;
        layer_ti = title->data;
        sfRenderWindow_drawSprite(_gm->window, layer_ti->sprite, NULL);
    }
    back_to_start(&title);
}
