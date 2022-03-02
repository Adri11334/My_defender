/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps_objects
*/

#include <stdlib.h>

#include "my_defender.h"

map_block_t *map_block_create(dimension_t *dimension, block_type_t type)
{
    map_block_t *block = malloc(sizeof(map_block_t));
    sfIntRect block_rect = { 0, 0, dimension->size->x, dimension->size->y };

    sfColor color = sfBlack;
    if (block == NULL)
        return NULL;
    block->type = type;
    block->dimension = dimension;
    block->tower = NULL;

    block->rect = sfRectangleShape_create();
    switch (type) {
        case BLOCK_BORDER: color = sfMagenta; break;
        case BLOCK_ROAD:color = sfWhite; break;
        case BLOCK_EMPTY:color = sfGreen; break;
        case BLOCK_SPAWN:color = sfRed; break;
        case BLOCK_HOME:color = sfYellow; break;
        case BLOCK_WITH_TOWER:color = sfCyan; break;
    }
    sfRectangleShape_setFillColor(block->rect, color);
    sfRectangleShape_setPosition(block->rect, *dimension->position);
    sfRectangleShape_setSize(block->rect, *dimension->size);
    return block;
}
