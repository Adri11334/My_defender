/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemis_gen
*/

#include "my_defender.h"

sfIntRect ennemy_correct_rect(ennemy_type_t type)
{
    switch (type) {
        case ICE_GOLEM: return (sfIntRect){ 0, 480, 120, 120 }; break;
        case EARTH_GOLEM: return (sfIntRect){ 0, 600, 120, 120 }; break;
        case FIRE_GOLEM: return (sfIntRect){ 0, 720, 120, 120 }; break;
    }
}

dimension_t *ennemy_correct_dims(game_t *_gm, ennemy_type_t type)
{
    dimension_t *dims = malloc(sizeof(dimension_t));
    sfVector2f *size = malloc(sizeof(sfVector2f));
    sfVector2f *sp_pos = spawner_position(_gm->current_map);

    size->x = 120;
    size->y = 120;
    dims->size = size;
    dims->position = malloc(sizeof(sfVector2f));
    if (sp_pos != NULL) {
        dims->position->x = (sp_pos->x - 1) * 120;
        dims->position->y = sp_pos->y * 120;
    } else {
        dims->position->x = 0;
        dims->position->y = 0;
    }
    return dims;
}

ennemy_t *ennemy_create(game_t *_gm, ennemy_type_t type)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    ennemy->direction = RIGHT;
    ennemy->type = type;
    ennemy->stats = ennemy_correct_dims(_gm, type);
    ennemy->sprite = sfSprite_create();
    sfSprite_setTexture(ennemy->sprite, _gm->game_texture, sfFalse);
    ennemy->rect = ennemy_correct_rect(type);
    ennemy->anim_clock = sfClock_create();
    ennemy->move_clock = sfClock_create();
    switch (type) {
        case ICE_GOLEM: ennemy->life = 100; break;
        case EARTH_GOLEM: ennemy->life = 100; break;
        case FIRE_GOLEM: ennemy->life = 100; break;
    }
    ennemy->anim_speed = 70;
    ennemy->gap = 120;
    ennemy->move_speed = 40;
    sfSprite_setTexture(ennemy->sprite, _gm->game_texture, sfFalse);
    sfSprite_setTextureRect(ennemy->sprite, ennemy->rect);
    sfSprite_setPosition(ennemy->sprite, *ennemy->stats->position);
    return ennemy;
}
