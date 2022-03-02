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

int map_add_block(linked_list **map_blocks, map_block_t *c_block, \
dimension_t *dimensions, char current_char)
{
    switch (current_char) {
        case '\n': return -1;
        case '#': c_block = map_block_create(dimensions, BLOCK_BORDER); break;
        case '-': c_block = map_block_create(dimensions, BLOCK_ROAD); break;
        case '/': c_block = map_block_create(dimensions, BLOCK_ROAD); break;
        case '|': c_block = map_block_create(dimensions, BLOCK_ROAD); break;
        case ' ': c_block = map_block_create(dimensions, BLOCK_EMPTY); break;
        case 'o': c_block = map_block_create(dimensions, BLOCK_HOME); break;
        case 'x': c_block = map_block_create(dimensions, BLOCK_SPAWN); break;
        default: c_block = map_block_create(dimensions, BLOCK_EMPTY);
    }
    push_node(map_blocks, c_block);
    return 0;
}

void map_load_blocks(game_t *_gm)
{
    dimension_t *dimensions = NULL;
    map_block_t *c_block = NULL;

    dimensions = dimension_create(120, 120, 0, 0);
    if (dimensions == NULL)
        return;
    c_block = map_block_create(dimensions, BLOCK_BORDER);
    _gm->map_blocks = init_list(c_block);
    dimensions->position->x += 120;
    for (int i = 1; _gm->current_map[i] != '\0'; i++) {
        if (map_add_block(&_gm->map_blocks, c_block, dimensions, \
            _gm->current_map[i]) == -1) {
            dimensions->position->y += 120;
            dimensions->position->x = 0;
            continue;
        }
        dimensions->position->x += 120;
    }
}
