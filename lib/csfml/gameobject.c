/*
** EPITECH PROJECT, 2022
** project
** File description:
** gameobject
*/

#include "my_runner.h"

gameobject *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, enum gameobject_type type)
{
    gameobject *object = malloc(sizeof(gameobject));

    if (object == NULL)
        return NULL;
    object->type = type;
    object->texture = sfTexture_createFromFile(path_to_spritesheet, &rect);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    object->rect = rect;
    sfSprite_setTextureRect(object->sprite, rect);
    object->pos = pos;
    sfSprite_setPosition(object->sprite, pos);
    object->clock = sfClock_create();
    return object;
}

void destroy_object(gameobject *obj)
{
    if (!obj)
        error_manager(NOT_REQUIRED_PARAMETER);
    sfClock_destroy(obj->clock);
    sfTexture_destroy((*obj).texture);
    sfSprite_destroy(obj->sprite);
    free(obj);
}
