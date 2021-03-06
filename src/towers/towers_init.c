/*
** EPITECH PROJECT, 2022
** defender
** File description:
** towers_init
*/

#include <stdlib.h>
#include "my_defender.h"

sfIntRect *tower_get_corect_rect(dimension_t *dimension, block_type_t type)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    if (rect == NULL || dimension == NULL)
        return NULL;
    rect->width = dimension->size->x;
    rect->height = dimension->size->y;
    switch (type) {
        case EARTH_TOWER: rect->left = 960; rect->top = 0; break;
        case ICE_TOWER: rect->left = 1440; rect->top = 120; break;
        case SAND_TOWER: rect->left = 960; rect->top = 120; break;
        case FIRE_TOWER: rect->left = 1440; rect->top = 0; break;
        default: rect->left = 120; rect->top = 120; break;
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
        case EARTH_TOWER: return (tower_level * 5);
        case ICE_TOWER: return (tower_level  * 10);
        case SAND_TOWER: return (tower_level * 12);
        case FIRE_TOWER: return (tower_level * 20);
        default: return 0;
    }
}

float set_tower_shoot_rate(tower_type_t type, int tower_level)
{
    switch (type) {
        case EARTH_TOWER: return (tower_level > 1 ? 400 : 550);
        case ICE_TOWER: return (tower_level > 1 ? 400 : 550);
        case SAND_TOWER: return (tower_level > 1 ? 550 : 700);
        case FIRE_TOWER: return (tower_level > 2 ? 600 : 750);
        default: return 0;
    }
}

tower_t *tower_create(dimension_t *dimension, tower_type_t type, \
game_t *_gm)
{
    tower_t *tower = malloc(sizeof(tower_t));
    dimension_t *tower_dims = NULL;

    if (tower == NULL || dimension == NULL || _gm == NULL)
        return NULL;
    tower_dims = dimension_create(dimension->size->x, dimension->size->y, \
    dimension->position->x, dimension->position->y);
    tower->rect = tower_get_corect_rect(tower_dims, type);
    tower->type = type;
    tower->range = tower_set_range(type, 1);
    tower->damage = tower_set_damages(type, 1);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(tower->sprite, *tower->rect);
    sfSprite_setPosition(tower->sprite, *tower_dims->position);
    tower->clock = sfClock_create();
    tower->clock_rate = (float)500;
    tower->dimension = tower_dims;
    tower->max_frame = (int)1;
    tower->current_frame = (int)1;
    return tower;
}
