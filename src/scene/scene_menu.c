/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene menu
*/

#include "my_defender.h"

void scene_menu_call(game_t *game_manager)
{
    init_menu_buttons(game_manager);
    while (sfRenderWindow_isOpen(game_manager->window)) {
        analyse_events(game_manager);
        diplay_menu_buttons(game_manager);
        sfRenderWindow_clear(game_manager->window, sfRed);
        sfRenderWindow_display(game_manager->window);
    }
}
