/*
** EPITECH PROJECT, 2022
** defender
** File description:
** towers_focus
*/

#include <stdbool.h>

#include "my_defender.h"

dimension_t *get_tower_range(tower_t *tower)
{
    float sizex = 0;
    float sizey = 0;
    float posx = 0;
    float posy = 0;

    if (tower == NULL || tower->dimension == NULL)
        return NULL;
    sizex = tower->dimension->size->x + ((tower->range * 120) * 2);
    sizey = tower->dimension->size->y + ((tower->range * 120) * 2);
    posx = tower->dimension->position->x - (tower->range * 120);
    posy = tower->dimension->position->y - (tower->range * 120);
    return dimension_create(sizex, sizey, posx, posy);
}

bool ennemy_in_tower_range(dimension_t *ennemy, dimension_t *tower)
{
    if (ennemy->position->x <= tower->position->x + tower->size->x
        && ennemy->position->x >= tower->position->x)
        if (ennemy->position->y <= tower->position->y + tower->size->y
            && ennemy->position->y >= tower->position->y)
            return true;
    return false;
}

void shoot_ennemy(ennemy_t *ennemy, tower_t *tower)
{
    dimension_t *range_dim = NULL;
    sfTime time = sfClock_getElapsedTime(tower->clock);
    float milli_seconds = time.microseconds / 1000;

    if ((range_dim = get_tower_range(tower)) == NULL)
        return;
    if (ennemy_in_tower_range(ennemy->stats, range_dim)) {
        if (milli_seconds > tower->clock_rate) {
            ennemy->life -= tower->damage;
            sfClock_restart(tower->clock);
        }
    }
    dimension_destroy(range_dim);
}

void tower_manager(game_t *_gm, tower_t *tower)
{
    linked_list *enemies = _gm->game_scene->entitys;

    for (; enemies != NULL; enemies = enemies->next) {
        if (!enemies->data)
            continue;
        shoot_ennemy(enemies->data, tower);
    }
    back_to_start(&enemies);
    sfRenderWindow_drawSprite(_gm->window, tower->sprite, NULL);
}
