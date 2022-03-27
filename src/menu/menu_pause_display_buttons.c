/*
** EPITECH PROJECT, 2022
** pause display buttons
** File description:
** menu_pause_display_buttons
*/

#include "my_defender.h"

void display_pause_buttons(game_t *_gm)
{
    linked_list *pause_buttons = _gm->menu_scene->pause_buttons;
    button_t *button = NULL;

    while (pause_buttons != NULL) {
        button = pause_buttons->data;
        button_display(_gm, button);
        pause_buttons = pause_buttons->next;
    }
}
