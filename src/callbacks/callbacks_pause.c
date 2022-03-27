/*
** EPITECH PROJECT, 2022
** callbacks pause
** File description:
** callbacks_pause
*/

#include "my_defender.h"

void pause_menu_clicked(game_t *_gm)
{
    _gm->status = MENU;
}

void game_pause_clicked(game_t *_gm)
{
    _gm->status = PAUSE;
}
