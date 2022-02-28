/*
** EPITECH PROJECT, 2022
** defender
** File description:
** colors manager
*/

#include <stdlib.h>

#include "my_project.h"

colors_t *color_group_create(sfColor normal, \
sfColor highlight, sfColor disable)
{
    colors_t *colors = malloc(sizeof(colors_t));

    if (colors == NULL)
        return NULL;
    colors->normal = normal;
    colors->highlight = highlight;
    colors->disable = disable;
    return colors;
}

void color_group_destroy(colors_t *colors)
{
    free (colors);
}
