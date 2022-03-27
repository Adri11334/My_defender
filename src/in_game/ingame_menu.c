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

button_t *button_ingamemenu_create(sfIntRect btn_rect, float posx, float posy, \
game_t *_gm)
{
    dimension_t *button_dim = NULL;
    sfIntRect *def_rect = NULL;

    if (_gm == NULL)
        return NULL;
    def_rect = malloc_rect(btn_rect);
    button_dim = dimension_create(240, 120, posx, posy);
    return button_sprite_create(button_dim, _gm, def_rect, &print_hello);
}

txt_img_t *create_money_goal(game_t *_gm)
{
    txt_img_t *txt_img = malloc(sizeof(txt_img_t));
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    dimension_t *global_dms = malloc(sizeof(dimension_t));
    sfVector2f text_position;
    sfFont *font = font_import(ROBOTO_REGULAR);
    int image_width = 80;

    if (_gm == NULL)
        return;
    txt_img->image = sfSprite_create();
    rect->left = 0;
    rect->top = 840;
    rect->width = 120;
    global_dms = dimension_create(70, 70, 1500, 300);
    sfSprite_setTexture(txt_img->image, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(txt_img->image, *rect);
    sfSprite_setPosition(txt_img->image, *global_dms->position);
    image_width = global_dms->size->x;
    text_position.x = global_dms->position->x + image_width;
    text_position.y = global_dms->position->y + 10;
    txt_img->life_text = sfText_create();
    sfText_setPosition(txt_img->life_text, text_position);
    sfText_setCharacterSize(txt_img->life_text, 40);
    sfText_setFont(txt_img->life_text, font);
    sfText_setString(txt_img->life_text, my_to_str(_gm->money));
    sfSprite_setScale(txt_img->image, (sfVector2f){ .6, .6});
    return txt_img;
}

void setup_ingame_menu(game_t *_gm)
{
    button_t *pause = NULL;
    button_t *earth_tower = NULL;
    button_t *ice_tower = NULL;
    button_t *sand_tower = NULL;
    button_t *fire_tower = NULL;

//    clear_previous_buttons(_gm);
    pause = button_ingamemenu_create((sfIntRect){ 720, 840, 120, 120 }, 1710, 60, _gm);
    pause->onClick = &game_pause_clicked;
    earth_tower = button_ingamemenu_create((sfIntRect){ 120, 840, 120, 240 }, 1500, 490, _gm);
    earth_tower->onClick = &add_update_earth_tower;
    ice_tower = button_ingamemenu_create((sfIntRect){ 360, 840, 120, 240 }, 1710, 490, _gm);
    ice_tower->onClick = &add_update_ice_tower;
    sand_tower = button_ingamemenu_create((sfIntRect){ 240, 840, 120, 240 }, 1500, 810, _gm);
    sand_tower->onClick = &add_update_sand_tower;
    fire_tower = button_ingamemenu_create((sfIntRect){ 480, 840, 120, 240 }, 1710, 810, _gm);
    fire_tower->onClick = &add_update_fire_tower;
    _gm->game_scene->buttons = init_list(pause);
    _gm->game_scene->title = init_list(create_money_goal(_gm));
    push_node(&_gm->game_scene->buttons, earth_tower);
    push_node(&_gm->game_scene->buttons, ice_tower);
    push_node(&_gm->game_scene->buttons, sand_tower);
    push_node(&_gm->game_scene->buttons, fire_tower);
}
