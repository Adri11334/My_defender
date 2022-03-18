/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_ennemy
*/

#include "my_defender.h"

void display_ennemy(game_t *_gm, ennemy_t *ennemy)
{
    sfRenderWindow_drawSprite(_gm->window, ennemy->sprite, NULL);
}

void ennemy_animation(ennemy_t *ennemy)
{
    sfVector2f pos = *ennemy->stats->position;

    if (ennemy->rect.left + ennemy->gap < ennemy->gap * 12)
        ennemy->rect.left += ennemy->gap;
    else
        ennemy->rect.left = 0;
    sfSprite_setTextureRect(ennemy->sprite, ennemy->rect);
}

void ennemy_run(ennemy_t *ennemy)
{
    switch (ennemy->direction) {
        case TOP: ennemy->stats->position->y -= 10; break;
        case RIGHT: ennemy->stats->position->x += 10; break;
        case DOWN: ennemy->stats->position->y += 10; break;
        case LEFT: ennemy->stats->position->x -= 10; break;
        default: break;
    }
    sfSprite_setPosition(ennemy->sprite, *ennemy->stats->position);
}

void check_an_enemy(game_t *_gm, ennemy_t *enemy)
{
    float milli_seconds;
    sfTime time;

    time = sfClock_getElapsedTime(enemy->anim_clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > enemy->anim_speed) {
        ennemy_animation(enemy);
        sfClock_restart(enemy->anim_clock);
    }
    time = sfClock_getElapsedTime(enemy->move_clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > enemy->move_speed) {
        ennemy_run(enemy);
        sfClock_restart(enemy->move_clock);
    }
    display_ennemy(_gm, enemy);
}

void ennemy_display_manager(game_t *_gm)
{
    linked_list *enemies = _gm->game_scene->entitys;
    ennemy_t *enemy = NULL;

    for (; enemies != NULL; enemies = enemies->next) {
        if (!enemies->data)
            continue;
        enemy = enemies->data;
        if ((int)enemy->stats->position->x % 120 == 0
        && (int)enemy->stats->position->y % 120 == 0)
            ennemy_move(_gm, enemy);
        enemy = enemies->data;
        check_an_enemy(_gm, enemy);
    }
    back_to_start(&enemies);
}
