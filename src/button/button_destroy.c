/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button_destroy
*/

#include <stdlib.h>

#include "my_defender.h"

void button_destroy(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    dimension_destroy(button->dimension);
    text_destroy(button->text);
    free(button->colors);
    free(button);
}
