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
    button_t *button = init_button((dimension_t){ (sfVector2f){ 150, 50 }, (sfVector2f){ 100, 100 } }, (colors_t){ sfCyan, sfBlue, sfGreen }, "My button", NULL);

    window = sfRenderWindow_create(mode, "adrien la grosse pute qui n aime pas le nouvel album de vald", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        sfRenderWindow_drawText(window, button->text, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
