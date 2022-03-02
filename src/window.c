/*
** EPITECH PROJECT, 2022
** defender
** File description:
** window
*/

#include <stddef.h>
#include <stdlib.h>

#include "my_project.h"


button_t *button_one_create(sfColor _color, dimension_t *button_dim)
{
    //dimension_t *button_dim = NULL;
    sfText *button_text = NULL;
    button_colors_t *button_colors = malloc(sizeof(button_colors_t));

    if (button_colors == NULL)
        return NULL;
    button_colors->normal = _color;
    button_colors->idle = sfBlack;
    button_colors->highlight = sfYellow;
    button_colors->clicked = sfCyan;
    button_colors->disable = sfBlue;
    //button_dim = dimension_create(150, 150, 150, 150);
    button_text = text_create("", ROBOTO_REGULAR, 20, button_dim);
    return button_create(button_dim, button_colors, button_text, &print_hello);
}

void made_map(char *map, sfRenderWindow *window, sfEvent *event) {
    dimension_t *button_dim = NULL;
    button_t *button = NULL;
    int x_element = 0;
    int y_element = 0;

    for (int map_i = 0; map[map_i] != 1; map_i++) {
        if (map[map_i] == '\n') {
            x_element = 0;
            y_element++;
            continue;
        }
        button_dim = dimension_create(150, 150, x_element * 150, y_element * 150);
        if (map[map_i] == ' ') {
            button = button_one_create(sfGreen, button_dim);
        } else if (map[map_i] == '-' || map[map_i] == '|' || map[map_i] == '/') {
            button = button_one_create(sfBlue, button_dim);
        }
        if (button != NULL) {
            button_is_hover(window, event, button);
            button_display(window, button);
        }
        x_element++;
        y_element++;
    }
}

int main_window(char **args)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    char *map = get_and_check_map(args[1]);
    //button_t *button = button_one_create(_sfRed);

    if (map == NULL) {
        write_red("wrong map\n");
        return 84;
    }
    window = sfRenderWindow_create(mode, "trop fort enfaite", sfFullscreen, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        //button_is_hover(window, &event, button);
        //button_display(window, button);
        made_map(map, window, &event);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    //button_destroy(button);
    return 0;
}
