/*
** EPITECH PROJECT, 2022
** defender
** File description:
** maps validity
*/

#include "my_defender.h"

char *get_and_check_map(char *filepath)
{
    char *map = get_file_content(filepath);
    int map_length = 0;

    if (map == NULL)
        return NULL;
    while (map[map_length] != '\0') {
        if (map[map_length] != '#' && map[map_length] != '-'
        && map[map_length] != '/' && map[map_length] != ' '
        && map[map_length] != '\\' && map[map_length] != '+'
        && map[map_length] != '|' && map[map_length] != '\n'
        && map[map_length] != 'x' && map[map_length] != 'o') {
            return NULL;
        }
        map_length++;
    }
    if (map_length != 116)
        return NULL;
    return map;
}
