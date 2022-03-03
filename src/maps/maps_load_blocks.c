/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps_load_blocks
*/

/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene game
*/

#include "my_defender.h"

int map_add_block(game_t *_gm, map_block_t *c_block, \
dimension_t *dims, int current_char_index)
{
    switch (_gm->current_map[current_char_index]) {
        case '\n': return -1;
        case '#': c_block = map_check_border_type(_gm, dims, current_char_index); break;
        case '-': c_block = map_check_road_type(_gm, dims, current_char_index); break;
        case '/': c_block = map_check_road_type(_gm, dims, current_char_index); break;
        case '|': c_block = map_check_road_type(_gm, dims, current_char_index); break;
        case '\\': c_block = map_check_road_type(_gm, dims, current_char_index); break;
        case '+': c_block = map_check_road_type(_gm, dims, current_char_index); break;
        case ' ': c_block = map_block_create(dims, BLOCK_VIRGIN, _gm); break;
        case 'o': c_block = map_block_create(dims, BLOCK_HOME, _gm); break;
        case 'x': c_block = map_block_create(dims, BLOCK_SPAWNER, _gm); break;
        default: c_block = map_block_create(dims, BLOCK_VIRGIN, _gm);
    }
    push_node(&_gm->map_blocks, c_block);
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
    _gm->map_blocks = init_list(c_block);
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
