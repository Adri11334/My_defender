/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get_spawner
*/

#include "my_defender.h"

static void spawner_pt_two(int *founded, int index, char *map, sfVector2f *pos)
{
    if (*founded != 0)
        return;
    if (map[index] == '\n') {
        pos->x = 0;
        pos->y++;
    }
    if (map[index] == 'x') {
        *founded = 1;
        return;
    }
    pos->x++;
}

sfVector2f *spawner_position(char *map)
{
    sfVector2f *position = malloc(sizeof(sfVector2f));
    int index = 0;
    int founded = 0;

    if (position == NULL)
        return NULL;
    position->x = 0;
    position->y = 0;
    while (map[index] != '\0') {
        index++;
        spawner_pt_two(&founded, index, map, position);
    }
    return position;
}
