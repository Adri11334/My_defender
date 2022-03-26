/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene game
*/

#include "my_defender.h"

void scene_game_call(game_t *game_manager)
{
    init_ennemys(game_manager);
    map_load_blocks(game_manager);
    setup_ingame_menu(game_manager);
    init_pause_buttons(game_manager);
    menu_pause_create(game_manager);
    while (sfRenderWindow_isOpen(game_manager->window) \
     && (game_manager->status == GAME || game_manager->status == PAUSE)) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, (sfColor){52, 73, 94,1.0});
        if (game_manager->status == GAME) {
            diplay_map_blocks(game_manager);
            diplay_game_buttons(game_manager);
            ennemy_display_manager(game_manager);
        } else {
            display_parallax(game_manager);
            display_pause(game_manager);
            display_pause_buttons(game_manager);
        }
        sfRenderWindow_display(game_manager->window);
    }
}
