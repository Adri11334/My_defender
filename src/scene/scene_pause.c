/*
** EPITECH PROJECT, 2022
** scene pause
** File description:
** when pause
*/

#include "my_defender.h"

void scene_pause_call(game_t *game_manager)
{
    init_pause_buttons(game_manager);
    menu_pause_create(game_manager);
    while (sfRenderWindow_isOpen(game_manager->window) \
    && game_manager->status == PAUSE) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, sfBlack);
        display_parallax(game_manager);
        display_pause(game_manager);
        display_pause_buttons(game_manager);
        sfRenderWindow_display(game_manager->window);
    }
}
