/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_button
*/

#include <stdlib.h>

#include "my_project.h"

void button_display(sfRenderWindow *window, button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}
