/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ingame_menu
*/

#include <stdlib.h>
#include "my_defender.h"

sfIntRect *malloc_rect(sfIntRect rect_base)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (rect == NULL)
        return NULL;
    rect->left = rect_base.left;
    rect->top = rect_base.top;
    rect->width = rect_base.width;
    rect->height = rect_base.height;
    return rect;
}

button_t *btn_ig_create(sfIntRect btn_rect, float posx, \
float posy, game_t *_gm)
{
    dimension_t *button_dim = NULL;
    sfIntRect *def_rect = NULL;

    if (_gm == NULL)
        return NULL;
    def_rect = malloc_rect(btn_rect);
    button_dim = dimension_create(240, 120, posx, posy);
    return button_sprite_create(button_dim, _gm, def_rect, &print_hello);
}

button_t *create_pause_init_list(game_t *_gm)
{
    button_t *pause = NULL;

    pause = btn_ig_create((sfIntRect){ 720, 840, 120, 120 }, \
    1710, 60, _gm);
    pause->onClick = &game_pause_clicked;
    return pause;
}

void setup_ingame_menu(game_t *_gm)
{
    button_t *pause = create_pause_init_list(_gm);
    button_t *e_tower = NULL;
    button_t *i_tower = NULL;
    button_t *s_tower = NULL;
    button_t *f_tower = NULL;

    e_tower = btn_ig_create((sfIntRect){ 120, 840, 120, 240 }, 1500, 490, _gm);
    e_tower->onClick = &add_update_earth_tower;
    i_tower = btn_ig_create((sfIntRect){ 360, 840, 120, 240 }, 1710, 490, _gm);
    i_tower->onClick = &add_update_ice_tower;
    s_tower = btn_ig_create((sfIntRect){ 240, 840, 120, 240 }, 1500, 810, _gm);
    s_tower->onClick = &add_update_sand_tower;
    f_tower = btn_ig_create((sfIntRect){ 480, 840, 120, 240 }, 1710, 810, _gm);
    f_tower->onClick = &add_update_fire_tower;
    _gm->game_scene->buttons = init_list(pause);
    _gm->game_scene->title = init_list(create_money_goal(_gm));
    push_node(&_gm->game_scene->buttons, e_tower);
    push_node(&_gm->game_scene->buttons, i_tower);
    push_node(&_gm->game_scene->buttons, s_tower);
    push_node(&_gm->game_scene->buttons, f_tower);
}
