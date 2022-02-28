/*
** EPITECH PROJECT, 2022
** defender
** File description:
** window
*/

#include <stddef.h>

#include "my_project.h"

int main_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    dimension_t *button_dim = create_dimension(150, 50, 100, 100);
    colors_t *button_colors = create_color_group(sfRed, sfBlue, sfGreen);
    char *my_button_text = my_malloc(10, "My button");
    button_t *button = init_button(button_dim, button_colors, my_button_text, NULL);

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
        display_button(window, button);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
