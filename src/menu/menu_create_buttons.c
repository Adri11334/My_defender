/*
** EPITECH PROJECT, 2022
** button play
** File description:
** init a play button
*/

#include "my_defender.h"

button_t *button_menu_create(char *text, float posx, float posy, \
sfColor _color)
{
    dimension_t *button_dim = NULL;
    sfText *button_text = NULL;
    button_colors_t *button_colors = malloc(sizeof(button_colors_t));

    if (button_colors == NULL)
        return NULL;
    button_colors->normal = _color;
    button_colors->idle = (sfColor){ _color.r, _color.g, _color.b, 155 };
    button_colors->highlight = (sfColor){ _color.r, _color.g, _color.b, 155 };
    button_colors->clicked = (sfColor){ _color.r, _color.g, _color.b, 100 };
    button_colors->disable = (sfColor){ _color.r, _color.g, _color.b, 20 };
    button_dim = dimension_create(150, 100, posx, posy);
    button_text = text_create(text, ROBOTO_REGULAR, 20, button_dim);
    return button_create(button_dim, button_colors, button_text, &print_hello);
}

void init_menu_buttons(game_t *_gm)
{
    button_t *play = NULL;
    button_t *settings = NULL;
    button_t *how_to_play = NULL;
    button_t *quit =NULL;

    play = button_menu_create("PLAY", 895, 400, sfGreen);
    settings = button_menu_create("SETTINGS", 895, 700, sfBlue);
    how_to_play = button_menu_create("HOW TO PLAY", 895, 900, sfYellow);
    quit = button_menu_create("QUIT", 895, 1100, sfRed);
    _gm->current_buttons = init_list(play);
    push_node(&_gm->current_buttons, settings);
    push_node(&_gm->current_buttons, how_to_play);
    push_node(&_gm->current_buttons, quit);
}
