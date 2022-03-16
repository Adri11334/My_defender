/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_map
*/

#include "my_defender.h"

void map_block_update_style(map_block_t *block)
{
    switch (block->status) {
        case ACTIVE:
            sfRectangleShape_setFillColor(block->rect, block->colors->normal);
            break;
        case IDLE:
            sfRectangleShape_setFillColor(block->rect, block->colors->idle);
            break;
        case HIGHLIGHT:
            sfRectangleShape_setFillColor(block->rect, \
            block->colors->highlight);
            break;
        case CLICKED:
            sfRectangleShape_setFillColor(block->rect, block->colors->clicked);
            break;
        case DISABLED:
            sfRectangleShape_setFillColor(block->rect, block->colors->disable);
            break;
    }
}

void diplay_map_blocks(game_t *_gm)
{
    linked_list *map_block = NULL;
    map_block_t *block = NULL;

    if (_gm == NULL)
        return;
    map_block = _gm->map_blocks;
    while (map_block != NULL) {
        if (!map_block->data)
            continue;
        block = map_block->data;
        if (block->type == BLOCK_VIRGIN)
            map_block_is_hover(_gm->window, &_gm->event, block, \
            &_gm->actual_clicked_button);
        map_block_update_style(block);
        sfRenderWindow_drawSprite(_gm->window, block->sprite, NULL);
        sfRenderWindow_drawRectangleShape(_gm->window, block->rect, NULL);
        if (block->tower != NULL && block->tower->sprite != NULL)
            sfRenderWindow_drawSprite(_gm->window, block->tower->sprite, NULL);
        map_block = map_block->next;
    }
}
