/*
** EPITECH PROJECT, 2022
** display pause
** File description:
** pause screen
*/

#include "my_defender.h"

void display_pause(game_t *_gm)
{
    linked_list *pause = _gm->menu_scene->pause;
    layer_t *layer_p = NULL;

    for (; pause != NULL; pause = pause->next) {
        if (!pause->data)
            continue;
        layer_p = pause->data;
        sfRenderWindow_drawSprite(_gm->window, layer_p->sprite, NULL);
    }
    back_to_start(&pause);
}
