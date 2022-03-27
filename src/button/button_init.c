/*
** EPITECH PROJECT, 2022
** defender
** File description:
** init button
*/

#include <stdlib.h>

#include "my_defender.h"

button_t *button_test_create()
{
    dimension_t *button_dim = NULL;
    sfText *button_text = NULL;
    button_colors_t *button_colors = malloc(sizeof(button_colors_t));

    if (button_colors == NULL)
        return NULL;
    button_colors->normal = sfRed;
    button_colors->idle = sfBlack;
    button_colors->highlight = sfYellow;
    button_colors->clicked = sfCyan;
    button_colors->disable = sfBlue;
    button_dim = dimension_create(150, 150, 150, 150);
    button_text = text_create("My button", ROBOTO_REGULAR, 20, button_dim);
    return button_create(button_dim, button_colors, button_text, &print_hello);
}

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
    button->isSprite = false;
    sfRectangleShape_setFillColor(button->rect, color->normal);
    sfRectangleShape_setPosition(button->rect, *dimension->position);
    sfRectangleShape_setSize(button->rect, *dimension->size);
    button->text = content;
    return button;
}

button_t *button_sprite_create(dimension_t *dimension, game_t *_gm,
sfIntRect *rect, void *onClick)
{
    button_t *button = my_malloc(sizeof(button_t), NULL);

    if (_gm == NULL || rect == NULL
    || dimension == NULL)
        return NULL;
    if ((button->sprite = sfSprite_create()) == NULL)
        return NULL;
    button->onClick = onClick;
    button->status = ACTIVE;
    button->dimension = dimension;
    button->isSprite = true;
    sfSprite_setTexture(button->sprite, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(button->sprite, *rect);
    sfSprite_setPosition(button->sprite, *dimension->position);
    return button;
}
