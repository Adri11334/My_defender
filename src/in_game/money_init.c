/*
** EPITECH PROJECT, 2022
** defender
** File description:
** money_init
*/

#include "my_defender.h"

void set_money_text(game_t *_gm, txt_img_t *txt_img)
{
    sfFont *font = font_import(ROBOTO_REGULAR);
    sfVector2f text_position;

    text_position.x = txt_img->dims->position->x + txt_img->image_width;
    text_position.y = txt_img->dims->position->y + 10;
    txt_img->life_text = sfText_create();
    sfText_setPosition(txt_img->life_text, text_position);
    sfText_setCharacterSize(txt_img->life_text, 40);
    sfText_setFont(txt_img->life_text, font);
    sfText_setString(txt_img->life_text, my_to_str(_gm->money));
    sfSprite_setScale(txt_img->image, (sfVector2f){ .6, .6});
}

txt_img_t *create_money_goal(game_t *_gm)
{
    txt_img_t *txt_img = malloc(sizeof(txt_img_t));
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (_gm == NULL)
        return NULL;
    txt_img->image = sfSprite_create();
    rect->left = 0;
    rect->top = 840;
    rect->width = 120;
    txt_img->image_width = 80;
    txt_img->dims = dimension_create(70, 70, 1500, 300);
    sfSprite_setTexture(txt_img->image, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(txt_img->image, *rect);
    sfSprite_setPosition(txt_img->image, *txt_img->dims->position);
    set_money_text(_gm, txt_img);
    return txt_img;
}
