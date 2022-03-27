/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemy_move
*/

#include "my_defender.h"

void ennemy_move(game_t *_gm, ennemy_t *ennemy)
{
    sfVector2f *e_pos = ennemy->stats->position;
    char **n_map = my_str_to_words_array(_gm->current_map, (char[]){ '\n' });
    int ac_x = e_pos->x / 120;
    int ac_y = e_pos->y / 120;

    if (n_map[ac_y][ac_x] == 'o')
        ennemy->direction = FINISH;
    switch (ennemy->direction) {
        case TOP: if (n_map[ac_y - 1][ac_x] != ' ') return; break;
        case RIGHT: if (n_map[ac_y][ac_x + 1] != ' ') return; break;
        case DOWN: if (n_map[ac_y + 1][ac_x] != ' ') return; break;
        case LEFT: if (n_map[ac_y][ac_x - 1] != ' ') return; break;
        case FINISH: return;
    }
    if (n_map[ac_y][ac_x - 1] != ' ' && ennemy->direction != RIGHT) {
        ennemy->direction = LEFT;
        return;
    }
    if (n_map[ac_y - 1][ac_x] != ' ' && ennemy->direction != DOWN) {
        ennemy->direction = TOP;
        return;
    }
    if (n_map[ac_y][ac_x + 1] != ' ' && ennemy->direction != LEFT) {
        ennemy->direction = RIGHT;
        return;
    }
    if (n_map[ac_y + 1][ac_x] != ' ' && ennemy->direction != TOP) {
        ennemy->direction = DOWN;
        return;
    }
}
