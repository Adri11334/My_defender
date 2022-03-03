/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps_objects
*/

#include <stdlib.h>

#include "my_defender.h"

map_block_t *map_block_create(dimension_t *dimension, block_type_t type, \
game_t *_gm)
{
    map_block_t *block = malloc(sizeof(map_block_t));
    sfIntRect block_rect = { 0, 0, dimension->size->x, dimension->size->y };

    if (block == NULL)
        return NULL;
    block->type = type;
    block->dimension = dimension;
    block->tower = NULL;
    block->sprite = sfSprite_create();
    switch (type) {
        case BLOCK_BORDER_TOP: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_BOTTOM: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_LEFT: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_RIGHT: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_RT_CORNER: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_RB_CORNER: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_LT_CORNER: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_BORDER_LB_CORNER: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_VIRGIN: block_rect.left = 600; block_rect.top = 0; break;
        case BLOCK_SPAWNER: block_rect.left = 480; block_rect.top = 0; break;
        case BLOCK_HOME: block_rect.left = 480; block_rect.top = 120; break;
        case BLOCK_ROAD_VERT: block_rect.left = 0; block_rect.top = 120; break;
        case BLOCK_ROAD_HORI: block_rect.left = 120; block_rect.top = 0; break;
        case BLOCK_ROAD_TOP_LEFT_CORNER: block_rect.left = 240; block_rect.top = 240; break;
        case BLOCK_ROAD_TOP_RIGHT_CORNER: block_rect.left = 0; block_rect.top = 240; break;
        case BLOCK_ROAD_BOTTOM_LEFT_CORNER: block_rect.left = 240; block_rect.top = 0; break;
        case BLOCK_ROAD_BOTTOM_RIGHT_CORNER: block_rect.left = 0; block_rect.top = 0; break;
        case BLOCK_ROAD_X_CORNER: block_rect.left = 120; block_rect.top = 120; break;
        default: block_rect.left = 360; block_rect.top = 360; break;
    }
    sfSprite_setTexture(block->sprite, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(block->sprite, block_rect);
    sfSprite_setPosition(block->sprite, *dimension->position);
    return block;
}
