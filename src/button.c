/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button
*/

#include "my_project.h"

button_t *init_button(sfVector2f position, sfVector2f size, colors_t color,
char *content, void *onClick)
{
    button_t *button = my_malloc(sizeof(button_t), NULL);

    if (button == NULL)
        return NULL;
    if ((button->rect = sfRectangleShape_create()) == NULL)
        return NULL;
    button->colors = &color;
    sfRectangleShape_setFillColor(button->rect, color.normal);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    return button;
}
