/*
** EPITECH PROJECT, 2022
** display parallax
** File description:
** display_parallax
*/

#include "my_defender.h"

void display_parallax(game_t *_gm)
{
    sfRenderWindow_clear(_gm->window, sfTransparent);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->sky->sprite, NULL);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->rocks->sprite, NULL);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->clouds->sprite, NULL);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->hillst->sprite, NULL);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->hillso->sprite, NULL);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->trees->sprite, NULL);
    sfRenderWindow_drawSprite(_gm->window, _gm->parallax->ground->sprite, NULL);
}
