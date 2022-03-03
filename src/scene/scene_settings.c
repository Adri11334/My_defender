/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene_settings
*/

#include "my_defender.h"

void scene_settings_call(game_t *game_manager)
{
    while (sfRenderWindow_isOpen(game_manager->window) \
    && game_manager->status == SETTINGS) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, (sfColor){255, 73, 255, 255});
        sfRenderWindow_display(game_manager->window);
    }
}
