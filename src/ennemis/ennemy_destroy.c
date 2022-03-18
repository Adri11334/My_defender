/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemy_destroy
*/

#include "my_defender.h"

void destroy_ennemy(ennemy_t *ennemy)
{
    sfClock_destroy(ennemy->anim_clock);
    sfClock_destroy(ennemy->move_clock);
    dimension_destroy(ennemy->stats);
    sfSprite_destroy(ennemy->sprite);
    free(ennemy);
}
