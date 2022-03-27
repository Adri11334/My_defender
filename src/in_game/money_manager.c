/*
** EPITECH PROJECT, 2022
** defender
** File description:
** money_manager
*/

#include "my_defender.h"

void display_txt_imgs(game_t *_gm)
{
    linked_list *txt_imgs = _gm->game_scene->title;
    txt_img_t *txt_img = NULL;

    for (; txt_imgs != NULL; txt_imgs = txt_imgs->next) {
        if (!txt_imgs->data)
            continue;
        txt_img = txt_imgs->data;
        sfRenderWindow_drawSprite(_gm->window, txt_img->image, NULL);
        sfText_setString(txt_img->life_text, my_to_str(_gm->money));
        sfRenderWindow_drawText(_gm->window, txt_img->life_text, NULL);
    }
    back_to_start(&txt_imgs);
}

void money_manager(game_t *_gm)
{
    float milli_seconds;
    sfTime time;

    if (!_gm)
        return;
    time = sfClock_getElapsedTime(_gm->money_clock);
    milli_seconds = time.microseconds / 1000;
    if (_gm->money < 0)
        _gm->money = 0;
    if (milli_seconds > _gm->money_gap) {
        _gm->money += _gm->money_by_gap;
        if (_gm->money_gap > 300)
            _gm->money_gap -= 10;
        sfClock_restart(_gm->money_clock);
    }
}
