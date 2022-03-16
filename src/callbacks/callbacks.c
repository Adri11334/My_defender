/*
** EPITECH PROJECT, 2022
** defender
** File description:
** callbacks
*/

#include "my_defender.h"

void menu_play_clicked(game_t *_gm)
{
    _gm->status = GAME;
}

void menu_settings_clicked(game_t *_gm)
{
    _gm->status = SETTINGS;
}

void menu_ht_clicked(game_t *_gm)
{
    _gm->status = HOW_TO_PLAY;
}

void menu_quit_clicked(game_t *_gm)
{
    _gm->status = ENDED;
}
