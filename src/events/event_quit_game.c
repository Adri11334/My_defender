/*
** EPITECH PROJECT, 2022
** defender
** File description:
** event quit game
*/

#include "my_defender.h"

void event_quit_game(game_t *game_manager)
{
    game_manager->status = ENDED;
    sfRenderWindow_close(game_manager->window);
}
