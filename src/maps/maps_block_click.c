/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps block click
*/

#include "my_defender.h"

int map_block_hover_detection(sfVector2i m_pos, map_block_t *block)
{
    float clic_from_right_border_x = m_pos.x - \
    (block->dimension->position->x + block->dimension->size->x);
    float clic_from_top_border_y = m_pos.y - \
    (block->dimension->position->y + block->dimension->size->y);

    if (clic_from_right_border_x < 0 \
    && ABSOLUTE(clic_from_right_border_x) < block->dimension->size->x) {
        if (clic_from_top_border_y < 0 \
        && ABSOLUTE(clic_from_top_border_y) < block->dimension->size->y) {
            return 1;
        }
    }
    return 0;
}

int map_block_hovered(sfEvent *event, map_block_t *block)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (block->status != CLICKED) {
            block->status = CLICKED;
        }
        return 1;
    }
    block->status = HIGHLIGHT;
    return 1;
}

int map_block_is_hover(sfRenderWindow *window, sfEvent *event, \
map_block_t *block, dimension_t **actual_clicked)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (map_block_hover_detection(mouse_pos, block) == 1) {
        map_block_hovered(event, block);
        if (block->status != CLICKED && *actual_clicked == block->dimension) {
            block->status = CLICKED;
        } else if (block->status == CLICKED && *actual_clicked != block->dimension) {
            *actual_clicked = block->dimension;
        }
        return 1;
    }
    if (block->status == CLICKED && *actual_clicked != block->dimension)
        block->status = ACTIVE;
    if (block->status == HIGHLIGHT)
        block->status = ACTIVE;
    return 0;
}
