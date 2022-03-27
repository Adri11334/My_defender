/*
** EPITECH PROJECT, 2022
** defender
** File description:
** destroyer
*/

#include "my_defender.h"

void clear_previous_buttons(scene_t *scene)
{
    linked_list *buttons = scene->buttons;
    button_t *button = NULL;

    back_to_start(&scene->buttons);
    while (buttons != NULL) {
        button = buttons->data;
        button_destroy(button);
        buttons = buttons->next;
    }
    destroy_node(&scene->buttons);
}
