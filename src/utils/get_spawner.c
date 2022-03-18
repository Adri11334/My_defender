/*
** EPITECH PROJECT, 2022
** defender
** File description:
** get_spawner
*/

#include "my_defender.h"

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
        if (founded != 0)
            continue;
        if (map[index] == '\n') {
            position->x = 0;
            position->y++;
        }
        if (map[index] == 'x') {
            founded = 1;
            continue;
        }
        position->x++;
    }
    return position;
}
