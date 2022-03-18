/*
** EPITECH PROJECT, 2022
** defender
** File description:
** callbacks_tower
*/

#include <stdbool.h>
#include "my_defender.h"

void add_update_earth_tower(game_t *_gm)
{
    bool block_founded = false;
    linked_list *map_block = _gm->game_scene->blocks;
    map_block_t **block = NULL;

    if (map_block == NULL)
        return;
    my_printf("Adding an earth tower\n");
    while (map_block != NULL && !block_founded) {
        block = &map_block->data;
        if ((*block)->dimension == _gm->actual_clicked_button)
            block_founded = true;
        map_block = map_block->next;
    }
    if ((*block)->tower == NULL)
        (*block)->tower = tower_create(_gm->actual_clicked_button, \
        EARTH_TOWER, _gm);
    my_printf("-> earth tower is created\n");
}

void add_update_sand_tower(game_t *_gm)
{
    bool block_founded = false;
    linked_list *map_block = _gm->game_scene->blocks;
    map_block_t **block = NULL;

    if (map_block == NULL)
        return;
    my_printf("Adding a sand tower\n");
    while (map_block != NULL && !block_founded) {
        block = &map_block->data;
        if ((*block)->dimension == _gm->actual_clicked_button)
            block_founded = true;
        map_block = map_block->next;
    }
    if ((*block)->tower == NULL)
        (*block)->tower = tower_create(_gm->actual_clicked_button, \
        SAND_TOWER, _gm);
    my_printf("-> sand tower is created\n");
}

void add_update_ice_tower(game_t *_gm)
{
    bool block_founded = false;
    linked_list *map_block = _gm->game_scene->blocks;
    map_block_t **block = NULL;

    if (map_block == NULL)
        return;
    my_printf("Adding an ice tower\n");
    while (map_block != NULL && !block_founded) {
        block = &map_block->data;
        if ((*block)->dimension == _gm->actual_clicked_button)
            block_founded = true;
        map_block = map_block->next;
    }
    if ((*block)->tower == NULL)
        (*block)->tower = tower_create(_gm->actual_clicked_button, \
        ICE_TOWER, _gm);
    my_printf("-> ice tower is created\n");
}

void add_update_fire_tower(game_t *_gm)
{
    bool block_founded = false;
    linked_list *map_block = _gm->game_scene->blocks;
    map_block_t **block = NULL;

    if (map_block == NULL)
        return;
    my_printf("Adding a fire tower\n");
    while (map_block != NULL && !block_founded) {
        block = &map_block->data;
        if ((*block)->dimension == _gm->actual_clicked_button)
            block_founded = true;
        map_block = map_block->next;
    }
    if ((*block)->tower == NULL)
        (*block)->tower = tower_create(_gm->actual_clicked_button, \
        FIRE_TOWER, _gm);
    my_printf("-> fire tower is created\n");
}
