/*
** EPITECH PROJECT, 2022
** defender
** File description:
** text_init
*/

#include "my_project.h"

sfFont *font_import(font_t font)
{
    switch (font) {
        case ROBOTO_LIGHT: break;
        case ROBOTO_ITALIC: break;
        case ROBOTO_THIN: break;
        case ROBOTO_REGULAR:
            return sfFont_createFromFile("assets/fonts/Roboto-Regular.ttf");
        case ROBOTO_NORMAL: break;
        case ROBOTO_MEDIUM: break;
        case ROBOTO_BOLD: break;
    }
    return NULL;
}

sfText *text_create(char *content, font_t font_wanted, int size, \
dimension_t *parent_dimensions)
{
    sfText *text = sfText_create();
    sfFont *font = font_import(font_wanted);
    sfVector2f text_position;

    if (text == NULL || font == NULL
    || content == NULL || parent_dimensions == NULL)
        return NULL;
    text_position.x = (((parent_dimensions->size->x) / 2)\
        + (parent_dimensions->position->x)) - \
        ((my_strlen(content) * (size / 2)) / 2);
    text_position.y = ((parent_dimensions->size->y / 2) \
        + (parent_dimensions->position->y)) - (size / 2);
    sfText_setPosition(text, text_position);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfText_setString(text, content);
    return text;
}