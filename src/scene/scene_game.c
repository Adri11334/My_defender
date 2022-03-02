/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene game
*/

#include "my_defender.h"

void scene_game_call(game_t *game_manager)
{
    map_load_blocks(game_manager);
    while (sfRenderWindow_isOpen(game_manager->window)) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, sfBlack);
        diplay_map_blocks(game_manager);
        sfRenderWindow_display(game_manager->window);
    }
}
