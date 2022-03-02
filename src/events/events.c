/*
** EPITECH PROJECT, 2022
** defender
** File description:
** events manager
*/

#include "my_defender.h"

void analyse_events(game_t *game_manager)
{
    while (sfRenderWindow_pollEvent(game_manager->window,
    &game_manager->event)) {
        if (game_manager->event.type == sfEvtClosed) {
            sfRenderWindow_close(game_manager->window);
        }
        if (game_manager->event.type == sfEvtKeyPressed
        && game_manager->event.key.code == sfKeyQ) {
            event_quit_game(game_manager);
        }
    }
}