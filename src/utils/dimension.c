/*
** EPITECH PROJECT, 2022
** defender
** File description:
** dimensions manager
*/

#include <stdlib.h>

#include "my_project.h"

dimension_t *dimension_create(float sizex, float sizey, \
float positionx, float positiony)
{
    dimension_t *dimension = malloc(sizeof(dimension_t));

    if (dimension == NULL)
        return NULL;
    dimension->size = malloc(sizeof(sfVector2f));
    if (dimension->size == NULL)
        return NULL;
    dimension->size->x = sizex;
    dimension->size->y = sizey;
    dimension->position = malloc(sizeof(sfVector2f));
    if (dimension->position == NULL)
        return NULL;
    dimension->position->x = positionx;
    dimension->position->y = positiony;
    return dimension;
}

void dimension_destroy(dimension_t *dimension)
{
    free(dimension->position);
    free(dimension->size);
    free(dimension);
}
