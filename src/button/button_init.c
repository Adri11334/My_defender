/*
** EPITECH PROJECT, 2022
** defender
** File description:
** init button
*/

#include <stdlib.h>

#include "my_project.h"

button_t *button_create(dimension_t *dimension, button_colors_t *color,
sfText *content, void *onClick)
{
    button_t *button = my_malloc(sizeof(button_t), NULL);

    if (button == NULL || content == NULL
    || dimension == NULL || color == NULL)
        return NULL;
    if ((button->rect = sfRectangleShape_create()) == NULL)
        return NULL;
    button->colors = color;
    button->onClick = onClick;
    button->status = ACTIVE;
    button->dimension = dimension;
    sfRectangleShape_setFillColor(button->rect, color->normal);
    sfRectangleShape_setPosition(button->rect, *dimension->position);
    sfRectangleShape_setSize(button->rect, *dimension->size);
    button->text = content;
    return button;
}
