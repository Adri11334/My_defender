/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_map
*/

#include "my_defender.h"

void diplay_map_blocks(game_t *_gm)
{
    linked_list *map_block = _gm->map_blocks;
    map_block_t *block;

    while (map_block != NULL) {
        block = map_block->data;
        sfRenderWindow_drawRectangleShape(_gm->window, block->rect, NULL);
        map_block = map_block->next;
    }
}
