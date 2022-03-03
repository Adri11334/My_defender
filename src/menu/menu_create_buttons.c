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
    button_dim = dimension_create(180, 100, posx, posy);
    button_text = text_create(text, ROBOTO_REGULAR, 20, button_dim);
    return button_create(button_dim, button_colors, button_text, NULL);
}

void init_menu_buttons(game_t *_gm)
{
    button_t *play = NULL;
    button_t *settings = NULL;
    button_t *how_to_play = NULL;
    button_t *quit =NULL;

    play = button_menu_create("PLAY", 870, 150, sfGreen);
    play->onClick = menu_play_clicked;
    settings = button_menu_create("SETTINGS", 870, 350, sfBlue);
    settings->onClick = menu_settings_clicked;
    how_to_play = button_menu_create("HOW TO PLAY", 870, 550, sfYellow);
    how_to_play->onClick = menu_ht_clicked;
    quit = button_menu_create("QUIT", 870, 750, sfRed);
    quit->onClick = menu_quit_clicked;
    _gm->current_buttons = init_list(play);
    push_node(&_gm->current_buttons, settings);
    push_node(&_gm->current_buttons, how_to_play);
    push_node(&_gm->current_buttons, quit);
}
