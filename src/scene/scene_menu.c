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
    parallax_init_layer(game_manager);
    menu_title_create(game_manager);
    while (sfRenderWindow_isOpen(game_manager->window) \
     && game_manager->status == MENU) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, sfBlack);
        display_parallax(game_manager);
        display_title(game_manager);
        diplay_menu_buttons(game_manager);
        sfRenderWindow_display(game_manager->window);
    }
}
