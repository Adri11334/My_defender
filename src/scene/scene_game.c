/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene game
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

void scene_game_call(game_t *game_manager)
{
    game_manager->money = 1000;
    game_manager->money_clock = sfClock_create();
    game_manager->money_gap = (float)700;
    game_manager->money_by_gap = 50;
    init_ennemys(game_manager);
    map_load_blocks(game_manager);
    setup_ingame_menu(game_manager);
    init_pause_buttons(game_manager);
    menu_pause_create(game_manager);
    while (sfRenderWindow_isOpen(game_manager->window) \
    && (game_manager->status == GAME || game_manager->status == PAUSE)) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, (sfColor){52, 73, 94,1.0});
        money_manager(game_manager);
        if (game_manager->status == GAME) {
            diplay_map_blocks(game_manager);
            diplay_game_buttons(game_manager);
            ennemy_display_manager(game_manager);
            display_txt_imgs(game_manager);
        } else {
            display_parallax(game_manager);
            display_pause(game_manager);
            display_pause_buttons(game_manager);
        }
        sfRenderWindow_display(game_manager->window);
    }
    sfClock_destroy(game_manager->money_clock);
}
