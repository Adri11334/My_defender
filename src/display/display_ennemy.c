/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_ennemy
*/

#include "my_defender.h"

void display_ennemy(game_t *_gm, ennemy_t *ennemy)
{
    if (!ennemy || !ennemy->sprite)
        return;
    sfRenderWindow_drawSprite(_gm->window, ennemy->sprite, NULL);
}

void ennemy_animation(ennemy_t *ennemy)
{
    sfVector2f pos;

    if (!ennemy)
        return;
    pos = *ennemy->stats->position;
    if (ennemy->rect.left + ennemy->gap < ennemy->gap * 12)
        ennemy->rect.left += ennemy->gap;
    else
        ennemy->rect.left = 0;
    sfSprite_setTextureRect(ennemy->sprite, ennemy->rect);
}

void ennemy_run(ennemy_t *ennemy)
{
    if (!ennemy)
        return;
    switch (ennemy->direction) {
        case TOP: ennemy->stats->position->y -= 10; break;
        case RIGHT: ennemy->stats->position->x += 10; break;
        case DOWN: ennemy->stats->position->y += 10; break;
        case LEFT: ennemy->stats->position->x -= 10; break;
        default: break;
    }
    sfSprite_setPosition(ennemy->sprite, *ennemy->stats->position);
}

void check_an_enemy(game_t *_gm, ennemy_t *ennemy)
{
    float milli_seconds;
    sfTime time;

    if (!ennemy)
        return;
    time = sfClock_getElapsedTime(ennemy->anim_clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > ennemy->anim_speed) {
        ennemy_animation(ennemy);
        sfClock_restart(ennemy->anim_clock);
    }
    time = sfClock_getElapsedTime(ennemy->move_clock);
    milli_seconds = time.microseconds / 1000;
    if (milli_seconds > ennemy->move_speed) {
        ennemy_run(ennemy);
        sfClock_restart(ennemy->move_clock);
    }
    display_ennemy(_gm, ennemy);
}

void ennemy_display_manager(game_t *_gm)
{
    linked_list *enemies = _gm->game_scene->entitys;
    ennemy_t *ennemy = NULL;
    sfTime time = sfClock_getElapsedTime(_gm->game_scene->scene_clock);
    float milli_seconds = time.microseconds / 1000;

    if (milli_seconds > _gm->game_scene->clock_rate) {
        spawn_new_ennemys(_gm);
        sfClock_restart(_gm->game_scene->scene_clock);
    }
    for (; enemies != NULL; enemies = enemies->next) {
        if (!enemies->data)
            continue;
        ennemy = enemies->data;
        if ((int)ennemy->stats->position->x % 120 == 0
        && (int)ennemy->stats->position->y % 120 == 0)
            ennemy_move(_gm, ennemy);
        if (ennemy->direction == FINISH || ennemy->life <= 0) {
            destroy_ennemy(ennemy);
            delete_node(&_gm->game_scene->entitys, enemies);
        } else {
            check_an_enemy(_gm, ennemy);
        }
    }
    back_to_start(&enemies);
}
