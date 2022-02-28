/*
** EPITECH PROJECT, 2022
** defender
** File description:
** init button
*/

#include <stdlib.h>

#include "my_project.h"

colors_t *color_group_create(sfColor normal, \
sfColor highlight, sfColor disable)
{
    colors_t *colors = malloc(sizeof(colors_t));

    if (colors == NULL)
        return NULL;
    colors->normal = normal;
    colors->highlight = highlight;
    colors->disable = disable;
    return colors;
}

dimension_t *dimension_create(float sizex, float sizey, \
float positionx, float positiony)
{
    dimension_t *dimension = malloc(sizeof(dimension_t));

    if (dimension == NULL)
        return NULL;
    dimension->size = malloc(sizeof(sfVector2f));
    if (dimension->size == NULL)
        return NULL;
    dimension->size->x = sizex;
    dimension->size->y = sizey;
    dimension->position = malloc(sizeof(sfVector2f));
    if (dimension->position == NULL)
        return NULL;
    dimension->position->x = positionx;
    dimension->position->y = positiony;
    return dimension;
}

button_t *button_create(dimension_t *dimension, colors_t *color,
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
    button->dimension = dimension;
    sfRectangleShape_setFillColor(button->rect, color->normal);
    sfRectangleShape_setPosition(button->rect, *dimension->position);
    sfRectangleShape_setSize(button->rect, *dimension->size);
    button->text = content;
    return button;
}
