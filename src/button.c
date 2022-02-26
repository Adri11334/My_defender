/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button
*/

#include "my_project.h"
#include <stdio.h>

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
    button->dimension = &dimension;
    printf("GOT %.0f / %.0f\n", button->dimension->position.x, button->dimension->size.x);
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
    printf("%.0f\n", button->dimension->size.x);
    if (absolutes(event.x - button->dimension->position.x) < button->dimension->size.x) {
        if (absolutes(event.y - button->dimension->position.y) < button->dimension->size.y) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int button_is_clicked(sfMouseButtonEvent event, button_t *button)
{
    printf("> %.0f\n", button->dimension->size.x);
    if (mouse_click_detected(event, button) == 1) {
        print_hello();
        return 1;
    } else
        return 0;
}
