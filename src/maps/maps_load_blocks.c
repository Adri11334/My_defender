/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps_load_blocks
*/

#include "my_defender.h"

int map_add_block(game_t *_gm, map_block_t *c_block, \
dimension_t *dimensions, int char_i)
{
    dimension_t *dims = NULL;

    dims = dimension_create(dimensions->size->x, dimensions->size->x, \
    dimensions->position->x, dimensions->position->y);
    if (dims == NULL)
        return 84;
    switch (_gm->current_map[char_i]) {
        case '\n': return -1;
        case '#': c_block = map_check_border_type(_gm, dims, char_i); break;
        case '-': c_block = map_check_road_type(_gm, dims, char_i); break;
        case '/': c_block = map_check_road_type(_gm, dims, char_i); break;
        case '|': c_block = map_check_road_type(_gm, dims, char_i); break;
        case '\\': c_block = map_check_road_type(_gm, dims, char_i); break;
        case '+': c_block = map_check_road_type(_gm, dims, char_i); break;
        case ' ': c_block = map_block_create(dims, BLOCK_VIRGIN, _gm); break;
        case 'o': c_block = map_block_create(dims, BLOCK_HOME, _gm); break;
        case 'x': c_block = map_block_create(dims, BLOCK_SPAWNER, _gm); break;
        default: c_block = map_block_create(dims, BLOCK_VIRGIN, _gm);
    }
    push_node(&_gm->game_scene->blocks, c_block);
    return 0;
}

void map_load_blocks(game_t *_gm)
{
    dimension_t *dimensions = NULL;
    map_block_t *c_block = NULL;

    dimensions = dimension_create(120, 120, 0, 0);
    if (dimensions == NULL)
        return;
    c_block = map_block_create(dimensions, BLOCK_BORDER_TOP, _gm);
    _gm->game_scene->blocks = init_list(c_block);
    dimensions->position->x += 120;
    for (int i = 1; _gm->current_map[i] != '\0'; i++) {
        if (map_add_block(_gm, c_block, dimensions, i) == -1) {
            dimensions->position->y += 120;
            dimensions->position->x = 0;
            continue;
        }
        dimensions->position->x += 120;
    }
}
