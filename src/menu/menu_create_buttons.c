/*
** EPITECH PROJECT, 2022
** button play
** File description:
** init a play button
*/

#include <stdlib.h>
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
    button_t *quit = NULL;

    play = button_menu_create("PLAY", 870, 375, (sfColor){160, 132, 157, 255});
    play->onClick = menu_play_clicked;
    settings = button_menu_create("SETTINGS", 870, 550, \
    (sfColor){148, 124, 176, 255});
    settings->onClick = menu_settings_clicked;
    how_to_play = button_menu_create("HOW TO PLAY", 870, 725, \
    (sfColor){1, 1, 122, 255});
    how_to_play->onClick = menu_ht_clicked;
    quit = button_menu_create("QUIT", 870, 900, (sfColor){101, 198, 187, 255});
    quit->onClick = menu_quit_clicked;
    _gm->menu_scene->buttons = init_list(play);
    push_node(&_gm->menu_scene->buttons, settings);
    push_node(&_gm->menu_scene->buttons, how_to_play);
    push_node(&_gm->menu_scene->buttons, quit);
}

void init_pause_buttons(game_t *_gm)
{
    button_t *resume = NULL;
    button_t *quit = NULL;
    button_t *menu = NULL;

    resume = button_menu_create("RESUME\n game", 870, 300, \
    (sfColor){174, 87, 0, 255});
    resume->onClick = menu_play_clicked;
    quit = button_menu_create("QUIT\ngame", 870, 500, \
    (sfColor){174, 87, 0, 255});
    quit->onClick = menu_quit_clicked;
    menu = button_menu_create("MENU", 870, 700, (sfColor){174, 87, 0, 255});
    menu->onClick = pause_menu_clicked;
    _gm->menu_scene->pause_buttons = init_list(resume);
    push_node(&_gm->menu_scene->pause_buttons, quit);
    push_node(&_gm->menu_scene->pause_buttons, menu);
}
