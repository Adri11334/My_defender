/*
** EPITECH PROJECT, 2022
** defender
** File description:
** towers_init
*/

#include "my_defender.h"

sfIntRect *tower_get_corect_rect(dimension_t *dimension, block_type_t type)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->width = dimension->size->x;
    rect->height = dimension->size->y;
    switch (type) {
        case EARTH_TOWER: rect->left = 600; rect->top = 0; break;
        case ICE_TOWER: rect->left = 480; rect->top = 0; break;
        case SAND_TOWER: rect->left = 480; rect->top = 120; break;
        case FIRE_TOWER: rect->left = 480; rect->top = 120; break;
        default: rect->left = 360; rect->top = 360; break;
    }
    return rect;
}

int tower_set_range(tower_type_t type, int tower_level)
{
    switch (type) {
        case EARTH_TOWER: return (tower_level > 2 ? 3 : 1);
        case ICE_TOWER: return (tower_level > 2 ? 4 : 2);
        case SAND_TOWER: return (tower_level > 2 ? 4 : 2);
        case FIRE_TOWER: return (tower_level > 1 ? 2 : 1);
        default: return 0;
    }
}

int tower_set_damages(tower_type_t type, int tower_level)
{
    switch (type) {
        case EARTH_TOWER: return (tower_level * 15);
        case ICE_TOWER: return (tower_level  * 5);
        case SAND_TOWER: return (tower_level * 5);
        case FIRE_TOWER: return (tower_level * 20);
        default: return 0;
    }
}

tower_t *tower_create(dimension_t *dimension, tower_type_t type, \
game_t *_gm)
{
    tower_t *tower = malloc(sizeof(map_block_t));
    tower->rect = tower_get_corect_rect(dimension, type);

    tower->type = type;
    tower->range = tower_set_range(type, 1);
    tower->range = tower_set_damages(type, 1);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(tower->sprite, *tower->rect);
    sfSprite_setPosition(tower->sprite, *dimension->position);
    tower->clock = sfClock_create();
    tower->clock_rate = 1;
    tower->dimension = dimension;
    tower->max_frame = 1;
    tower->current_frame = 1;
    return tower;
}
