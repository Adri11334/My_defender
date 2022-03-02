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

    if (map == NULL)
        return NULL;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '#' && map[i] != '-'
        && map[i] != '/' && map[i] != ' ' && map[i] != '|'
        && map[i] != '\n' && map[i] != '\0'
        && map[i] != 'x' && map[i] != 'o'
        && map[i] != '1' && map[i] != '2') {
            return NULL;
        }
    }
    return map;
}
