/*
** EPITECH PROJECT, 2022
** defender
** File description:
** in_game_display_buttons
*/

#include "my_defender.h"

void diplay_game_buttons(game_t *_gm)
{
    linked_list *buttons = _gm->game_scene->buttons;
    button_t *button = NULL;

    while (buttons != NULL) {
        button = buttons->data;
        button_display(_gm, button);
        buttons = buttons->next;
    }
}
