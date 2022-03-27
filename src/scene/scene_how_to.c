/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene_how_to
*/

#include "my_defender.h"

void scene_how_to_play_call(game_t *game_manager)
{
    while (sfRenderWindow_isOpen(game_manager->window) \
     && game_manager->status == HOW_TO_PLAY) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, \
        (sfColor){255, 73, 94, 255});
        sfRenderWindow_display(game_manager->window);
    }
}
