/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button
*/

#include "my_project.h"

button_t *init_button(dimension_t dimension, colors_t color,
char *content, void *onClick)
{
    button_t *button = my_malloc(sizeof(button_t), NULL);
    sfText *text = sfText_create();

    if (button == NULL)
        return NULL;
    if ((button->rect = sfRectangleShape_create()) == NULL)
        return NULL;
    button->colors = &color;
    button->onClick = onClick;
    button->text = text;
    sfRectangleShape_setFillColor(button->rect, color.normal);
    sfRectangleShape_setPosition(button->rect, dimension.position);
    sfRectangleShape_setSize(button->rect, dimension.size);
    sfText_setPosition(text, dimension.position);
    sfText_setString(text, content);
    return button;
}

void print_hello(void)
{
    my_printf("Hello\n");
}

float absolutes(float nb)
{
    if (nb < 0)
        nb = nb * -1;
    return nb;
}

int mouse_click_detected(sfMouseButtonEvent event, button_t *button)
{
    if (absolutes(event.x - button->dimension->position.x) < 100) {
        if (absolutes(event.y - button->dimension->position.y) < 100) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int button_is_clicked(sfMouseButtonEvent event, button_t *button, \
dimension_t dimension)
{
    if (mouse_click_detected(event, button) == 1) {
        print_hello();
        return 1;
    } else
        return 0;
}
