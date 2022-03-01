/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button_destroy
*/

#include <stdlib.h>

#include "my_project.h"

void button_destroy(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    color_group_destroy(button->colors);
    dimension_destroy(button->dimension);
    text_destroy(button->text);
    free(button);
}
