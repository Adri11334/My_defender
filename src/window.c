/*
** EPITECH PROJECT, 2022
** defender
** File description:
** window
*/

#include <stddef.h>
#include "my_project.h"
#include <stdio.h>

int main_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    button_t *button = init_button((dimension_t){ .size = (sfVector2f){ .x = 150, .y = 50 }, .position = (sfVector2f){ .x = 100, .y = 100 } }, (colors_t){ sfCyan, sfBlue, sfGreen }, "My button", NULL);

    window = sfRenderWindow_create(mode, "nique zebi", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        sfRenderWindow_drawText(window, button->text, NULL);
        printf("--> %.0f\n", button->dimension->size.x);
        button_is_clicked(event.mouseButton, button);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
