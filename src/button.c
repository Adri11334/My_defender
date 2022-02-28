/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button
*/

#include <stdlib.h>

#include "my_project.h"

colors_t *create_color_group(sfColor normal, \
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

dimension_t *create_dimension(float sizex, float sizey, \
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

button_t *init_button(dimension_t *dimension, colors_t *color,
char *content, void *onClick)
{
    button_t *button = my_malloc(sizeof(button_t), NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/Roboto-Regular.ttf");
    sfVector2f text_position;

    if (button == NULL || text == NULL || font == NULL
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
    if (content != NULL) {
        text_position.x = (((dimension->size->x) / 2) + (dimension->position->x)) - ((my_strlen(content) * 10) / 2);
        text_position.y = ((dimension->size->y / 2) + (dimension->position->y)) - 10;
        sfText_setPosition(text, text_position);
        sfText_setCharacterSize(text, 20);
        sfText_setFont(text, font);
        sfText_setString(text, content);
    }
    button->text = text;
    return button;
}

void display_button(sfRenderWindow *window, button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}

float absolutes(float nb)
{
    if (nb < 0)
        nb = nb * -1;
    return nb;
}

int mouse_click_detected(sfMouseButtonEvent event, button_t *button)
{
    float clic_from_right_border_x = event.x - \
    (button->dimension->position->x + button->dimension->size->x);
    float clic_from_top_border_y = event.y - \
    (button->dimension->position->y + button->dimension->size->y);

    if (clic_from_right_border_x < 0 \
    && absolutes(clic_from_right_border_x) < button->dimension->size->x) {
        if (clic_from_top_border_y < 0 \
        && absolutes(clic_from_top_border_y) < button->dimension->size->y) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int button_is_clicked(sfMouseButtonEvent event, button_t *button)
{
    if (mouse_click_detected(event, button) == 1) {
        write_green("Button is clicked\n");
        return 1;
    } else
        return 0;
}
