/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps_road_type
*/

#include "my_defender.h"

map_block_t *map_check_road_type(game_t *_gm, dimension_t *dims, int char_i)
{
    switch (_gm->current_map[char_i]) {
        case '-': return map_block_create(dims, BLOCK_ROAD_HORI, _gm);
        case '/':
            if (_gm->current_map[char_i + 1] != '-' \
            && _gm->current_map[char_i + 1] != '\\') {
                return map_block_create(dims, BLOCK_ROAD_TOP_LEFT_CORNER, _gm);
            }
            return map_block_create(dims, BLOCK_ROAD_BOTTOM_RIGHT_CORNER, _gm);
        case '\\':
            if (_gm->current_map[char_i + 1] == '-' \
            || _gm->current_map[char_i + 1] == '/') {
                return map_block_create(dims, BLOCK_ROAD_TOP_RIGHT_CORNER, \
                _gm);
            }
            return map_block_create(dims, BLOCK_ROAD_BOTTOM_LEFT_CORNER, _gm);
        case '|': return map_block_create(dims, BLOCK_ROAD_VERT, _gm);
        case '+': return map_block_create(dims, BLOCK_ROAD_X_CORNER, _gm);
        default: return map_block_create(dims, BLOCK_VIRGIN, _gm);
    }
    return NULL;
}

map_block_t *map_check_border_type(game_t *_gm, dimension_t *dims, int char_i)
{
    if (dims->position->x == 0)
        if (dims->position->y == 0)
            return map_block_create(dims, BLOCK_BORDER_LT_CORNER, _gm);
        else if (dims->position->y == 960)
            return map_block_create(dims, BLOCK_BORDER_LB_CORNER, _gm);
        else
            return map_block_create(dims, BLOCK_BORDER_LEFT, _gm);
    if (dims->position->y == 0)
        if (dims->position->x == 1320)
            return map_block_create(dims, BLOCK_BORDER_RT_CORNER, _gm);
        else
            return map_block_create(dims, BLOCK_BORDER_TOP, _gm);
    if (dims->position->y == 960)
        if (dims->position->x == 1320)
            return map_block_create(dims, BLOCK_BORDER_RB_CORNER, _gm);
        else
            return map_block_create(dims, BLOCK_BORDER_BOTTOM, _gm);
    if (dims->position->x == 1320)
        return map_block_create(dims, BLOCK_BORDER_RIGHT, _gm);
    return map_block_create(dims, BLOCK_VIRGIN, _gm);
}
