/*
** EPITECH PROJECT, 2022
** defender
** File description:
** towers_focus
*/

#include "my_defender.h"

void tower_manager(game_t *_gm, tower_t *tower)
{
    linked_list *enemies = _gm->game_scene->entitys;
    ennemy_t *ennemy = NULL;
    ennemy_t *stock_ennemy = NULL;
    int current_range = 0;
    int min_range = 0;

    cyan_header("New iteration");
    for (; enemies != NULL; enemies = enemies->next) {
        if (!enemies->data)
            continue;
        ennemy = enemies->data;
        current_range = (ennemy->stats->position->x - (ennemy->stats->size->x / 2)) - tower->dimension->size->x - (tower->dimension->size->x / 2);
        current_range -= (ennemy->stats->position->y - (ennemy->stats->size->y / 2)) - tower->dimension->size->y - (tower->dimension->size->y / 2);
        my_printf("%d / %d (%d)\n", ((int)ABSOLUTE(current_range)), min_range, tower->range);
        if ((int)ABSOLUTE(current_range) < tower->range)
            min_range = (int)ABSOLUTE(current_range);
        if ((int)ABSOLUTE(current_range) <= min_range) {
            stock_ennemy = ennemy;
            stock_ennemy->anim_speed = 1;
            min_range = (int)ABSOLUTE(current_range);
            write_purple("-> taked man\n\n");
        }
        if (ennemy != stock_ennemy) {
            ennemy->anim_speed = 500;
        }
    }
    back_to_start(&enemies);
    sfRenderWindow_drawSprite(_gm->window, tower->sprite, NULL);
}
