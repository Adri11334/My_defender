/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_ennemy
*/

#include "my_defender.h"

void display_ennemy(game_t *_gm, ennemy_t *ennemy)
{
    sfRenderWindow_drawSprite(_gm->window, ennemy->sprite, NULL);
}