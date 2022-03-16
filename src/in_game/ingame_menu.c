/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ingame_menu
*/

#include <stdlib.h>
#include "my_defender.h"

button_t *button_ingamemenu_create(char *text, float posx, float posy, \
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
    button_dim = dimension_create(120, 120, posx, posy);
    button_text = text_create(text, ROBOTO_REGULAR, 20, button_dim);
    return button_create(button_dim, button_colors, button_text, &print_hello);
}

void setup_ingame_menu(game_t *_gm)
{
    button_t *pause = NULL;
    button_t *earth_tower = NULL;
    button_t *ice_tower = NULL;
    button_t *sand_tower = NULL;
    button_t *fire_tower = NULL;

    clear_previous_buttons(_gm);
    pause = button_ingamemenu_create("PAUSE", 1710, 60, sfWhite);
    earth_tower = button_ingamemenu_create("ET", 1500, 690, sfMagenta);
    earth_tower->onClick = &add_update_earth_tower;
    ice_tower = button_ingamemenu_create("IT", 1710, 690, sfCyan);
    sand_tower = button_ingamemenu_create("ST", 1500, 900, sfYellow);
    fire_tower = button_ingamemenu_create("FT", 1710, 900, sfRed);
    _gm->current_buttons = init_list(pause);
    push_node(&_gm->current_buttons, earth_tower);
    push_node(&_gm->current_buttons, ice_tower);
    push_node(&_gm->current_buttons, sand_tower);
    push_node(&_gm->current_buttons, fire_tower);
}
