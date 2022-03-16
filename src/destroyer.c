/*
** EPITECH PROJECT, 2022
** defender
** File description:
** destroyer
*/

#include "my_defender.h"

void clear_previous_buttons(game_t *_gm)
{
    linked_list *buttons = _gm->current_buttons;
    button_t *button = NULL;

    back_to_start(&_gm->current_buttons);
    while (buttons != NULL) {
        button = buttons->data;
        button_destroy(button);
        buttons = buttons->next;
    }
    destroy_node(&_gm->current_buttons);
}
