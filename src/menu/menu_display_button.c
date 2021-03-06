/*
** EPITECH PROJECT, 2022
** button display
** File description:
** display all of the menu's button
*/

#include "my_defender.h"

void diplay_menu_buttons(game_t *_gm)
{
    linked_list *buttons = _gm->menu_scene->buttons;
    button_t *button = NULL;

    while (buttons != NULL) {
        button = buttons->data;
        button_display(_gm, button);
        buttons = buttons->next;
    }
}
