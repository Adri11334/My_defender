/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps_objects
*/

#include <stdlib.h>

#include "my_defender.h"

button_colors_t *map_block_create_colors(void)
{
    button_colors_t *colors = malloc(sizeof(button_colors_t));

    colors->normal = (sfColor){ 0, 0, 0, 0};
    colors->idle = (sfColor){ 0, 0, 0, 0};
    colors->highlight = (sfColor){ 255, 255, 255, 100};
    colors->clicked = (sfColor){ 0, 0, 0, 125};
    colors->disable = (sfColor){ 255, 0, 0, 125};
    return colors;
}

int block_is_border(sfIntRect *rect, block_type_t type)
{
    switch (type) {
        case BLOCK_BORDER_TOP: rect->left = 720; rect->top = 240; return 1;
        case BLOCK_BORDER_BOTTOM: rect->left = 720; rect->top = 240; return 1;
        case BLOCK_BORDER_LEFT: rect->left = 720; rect->top = 120; return 1;
        case BLOCK_BORDER_RIGHT: rect->left = 720; rect->top = 0; return 1;
        case BLOCK_BORDER_RT_CORNER:
        rect->left = 720; rect->top = 240; return 1;
        case BLOCK_BORDER_RB_CORNER:
        rect->left = 720; rect->top = 240; return 1;
        case BLOCK_BORDER_LT_CORNER:
        rect->left = 720; rect->top = 240; return 1;
        case BLOCK_BORDER_LB_CORNER:
        rect->left = 720; rect->top = 240; return 1;
        default: return 0;
    }
}

int block_is_road(sfIntRect *rect, block_type_t type)
{
    switch (type) {
        case BLOCK_ROAD_VERT: rect->left = 1560; rect->top = 840; return 1;
        case BLOCK_ROAD_HORI: rect->left = 1680; rect->top = 720; return 1;
        case BLOCK_ROAD_TOP_LEFT_CORNER:
            rect->left = 1800; rect->top = 960; return 1;
        case BLOCK_ROAD_TOP_RIGHT_CORNER:
            rect->left = 1560; rect->top = 960; return 1;
        case BLOCK_ROAD_BOTTOM_LEFT_CORNER:
            rect->left = 1800; rect->top = 720; return 1;
        case BLOCK_ROAD_BOTTOM_RIGHT_CORNER:
            rect->left = 1560; rect->top = 720; return 1;
        case BLOCK_ROAD_X_CORNER: rect->left = 120; rect->top = 120; return 1;
        default: return 0;
    }
}

int random_left()
{
    switch (rand() % 3) {
        case 0: return 1560;
        case 1: return 1680;
        case 2: return 1800;
    }
    return 0;
}

int random_top()
{
    switch (rand() % 3) {
        case 0: return 360;
        case 1: return 480;
        case 2: return 600;
    }
    return 0;
}

sfIntRect block_get_corect_rect(dimension_t *dimension, block_type_t type)
{
    sfIntRect block_rect = { 0, 0, dimension->size->x, dimension->size->y };

    if (block_is_border(&block_rect, type) == 1)
        return block_rect;
    if (block_is_road(&block_rect, type) == 1)
        return block_rect;
    switch (type) {
        case BLOCK_VIRGIN:
        block_rect.left = random_left(); block_rect.top = random_top(); break;
        case BLOCK_SPAWNER: block_rect.left = 480; block_rect.top = 0; break;
        case BLOCK_HOME: block_rect.left = 480; block_rect.top = 120; break;
        default: block_rect.left = 360; block_rect.top = 360; break;
    }
    return block_rect;
}

map_block_t *map_block_create(dimension_t *dimension, block_type_t type, \
game_t *_gm)
{
    map_block_t *block = malloc(sizeof(map_block_t));
    sfIntRect block_rect = block_get_corect_rect(dimension, type);

    if (block == NULL)
        return NULL;
    block->type = type;
    block->dimension = dimension;
    block->tower = NULL;
    block->status = ACTIVE;
    block->colors = map_block_create_colors();
    block->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(block->rect, block->colors->normal);
    sfRectangleShape_setPosition(block->rect, *dimension->position);
    sfRectangleShape_setSize(block->rect, *dimension->size);
    block->sprite = sfSprite_create();
    sfSprite_setTexture(block->sprite, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(block->sprite, block_rect);
    sfSprite_setPosition(block->sprite, *dimension->position);
    return block;
}
