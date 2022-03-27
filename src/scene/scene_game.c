/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene game
*/

#include "my_defender.h"

void scene_game_init(game_t *_gm)
{
    _gm->game_scene->annexe_audio = \
    create_audio("assets/audio/menu.wav", true);
    _gm->game_scene->main_audio = \
    create_audio("assets/audio/game.wav", true);
    _gm->money = 1000;
    _gm->money_clock = sfClock_create();
    _gm->money_gap = (float)700;
    _gm->money_by_gap = 50;
    init_ennemys(_gm);
    map_load_blocks(_gm);
    setup_ingame_menu(_gm);
    init_pause_buttons(_gm);
    menu_pause_create(_gm);
}

static void game_loop(game_t *_gm)
{
    if (_gm->game_scene->main_audio \
    && sfMusic_getStatus(_gm->game_scene->main_audio) != sfPlaying)
        sfMusic_play(_gm->game_scene->main_audio);
    if (_gm->game_scene->annexe_audio \
    && sfMusic_getStatus(_gm->game_scene->annexe_audio) == sfPlaying)
        sfMusic_pause(_gm->game_scene->annexe_audio);
    diplay_map_blocks(_gm);
    diplay_game_buttons(_gm);
    ennemy_display_manager(_gm);
    display_txt_imgs(_gm);
}

static void pause_loop(game_t *_gm)
{
    if (_gm->game_scene->annexe_audio \
    && sfMusic_getStatus(_gm->game_scene->annexe_audio) != sfPlaying)
        sfMusic_play(_gm->game_scene->annexe_audio);
    if (_gm->game_scene->main_audio \
    && sfMusic_getStatus(_gm->game_scene->main_audio) == sfPlaying)
        sfMusic_pause(_gm->game_scene->main_audio);
    display_parallax(_gm);
    display_pause(_gm);
    display_pause_buttons(_gm);
}

void scene_game_call(game_t *_gm)
{
    scene_game_init(_gm);
    while (sfRenderWindow_isOpen(_gm->window) \
    && (_gm->status == GAME || _gm->status == PAUSE)) {
        analyse_events(_gm);
        sfRenderWindow_clear(_gm->window, (sfColor){109, 90, 110,1.0});
        money_manager(_gm);
        if (_gm->status == GAME) {
            game_loop(_gm);
        } else {
            pause_loop(_gm);
        }
        sfRenderWindow_display(_gm->window);
    }
    sfClock_destroy(_gm->money_clock);
    destroy_audio(_gm->game_scene->annexe_audio);
    destroy_audio(_gm->game_scene->main_audio);
}
