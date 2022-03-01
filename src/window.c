/*
** EPITECH PROJECT, 2022
** defender
** File description:
** window
*/

#include <stddef.h>

#include "my_project.h"

button_t *button_one_create()
{
    dimension_t *button_dim = dimension_create(150, 50, 100, 100);
    sfText *button_text = text_create("My button", ROBOTO_REGULAR, 20, button_dim);
    colors_t *button_colors = color_group_create(sfRed, sfBlue, sfGreen);
    return button_create(button_dim, button_colors, button_text, &print_hello);
}

int main_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    button_t *button = button_one_create();

    window = sfRenderWindow_create(mode, "trop fort enfaite", sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                button_is_clicked(event.mouseButton, button);
        }
        sfRenderWindow_clear(window, sfBlack);
        button_display(window, button);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    button_destroy(button);
    return 0;
}
