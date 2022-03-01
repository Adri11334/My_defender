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
    button_dim = dimension_create(150, 50, 100, 100);
    button_text = text_create("My button", ROBOTO_REGULAR, 20, button_dim);
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
        }
        sfRenderWindow_clear(window, sfBlack);
        button_is_hover(window, &event, button);
        button_display(window, button);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    button_destroy(button);
    return 0;
}
