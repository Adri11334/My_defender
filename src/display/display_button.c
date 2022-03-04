/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_button
*/

#include <stdlib.h>

#include "my_defender.h"

void button_update_style(button_t *btn)
{
    switch (btn->status) {
        case ACTIVE:
            sfRectangleShape_setFillColor(btn->rect, btn->colors->normal);
            break;
        case IDLE:
            sfRectangleShape_setFillColor(btn->rect, btn->colors->idle);
            break;
        case HIGHLIGHT:
            sfRectangleShape_setFillColor(btn->rect, btn->colors->highlight);
            break;
        case CLICKED:
            sfRectangleShape_setFillColor(btn->rect, btn->colors->clicked);
            break;
        case DISABLED:
            sfRectangleShape_setFillColor(btn->rect, btn->colors->disable);
            break;
    }
}

void button_display(game_t *_gm, button_t *button)
{
    button_is_hover(_gm, button);
    button_update_style(button);
    sfRenderWindow_drawRectangleShape(_gm->window, button->rect, NULL);
    sfRenderWindow_drawText(_gm->window, button->text, NULL);
}
