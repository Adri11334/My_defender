/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene menu
*/

#include "my_defender.h"

void scene_menu_call(game_t *_gm)
{
    _gm->menu_scene->main_audio = create_audio("assets/audio/menu.wav", true);
    if (_gm->menu_scene->main_audio)
        sfMusic_play(_gm->menu_scene->main_audio);
    init_menu_buttons(_gm);
    parallax_init_layer(_gm);
    menu_title_create(_gm);
    while (sfRenderWindow_isOpen(_gm->window) \
    && _gm->status == MENU) {
        analyse_events(_gm);
        sfRenderWindow_clear(_gm->window, sfBlack);
        display_parallax(_gm);
        display_title(_gm);
        diplay_menu_buttons(_gm);
        sfRenderWindow_display(_gm->window);
    }
    destroy_audio(_gm->menu_scene->main_audio);
}
