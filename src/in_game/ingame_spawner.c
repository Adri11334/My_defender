/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ingame_spawner
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "my_defender.h"

void init_ennemys(game_t *_gm)
{
    srand(time(NULL));
    _gm->game_scene->scene_clock = sfClock_create();
    _gm->game_scene->clock_rate = 1000;
    switch (rand() % 3) {
        case 0:
        _gm->game_scene->entitys = init_list(ennemy_create(_gm, ICE_GOLEM));
        break;
        case 1:
        _gm->game_scene->entitys = init_list(ennemy_create(_gm, EARTH_GOLEM));
        break;
        case 2:
        _gm->game_scene->entitys = init_list(ennemy_create(_gm, FIRE_GOLEM));
        break;
    }
}

void spawn_new_ennemys(game_t *_gm)
{
    srand(time(NULL));
    switch (rand() % 3) {
        case 0:
        push_node(&_gm->game_scene->entitys, ennemy_create(_gm, ICE_GOLEM));
        break;
        case 1:
        push_node(&_gm->game_scene->entitys, ennemy_create(_gm, EARTH_GOLEM));
        break;
        case 2:
        push_node(&_gm->game_scene->entitys, ennemy_create(_gm, FIRE_GOLEM));
        break;
    }
}
