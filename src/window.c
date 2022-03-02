/*
** EPITECH PROJECT, 2022
** defender
** File description:
** window
*/

#include <stddef.h>
#include <stdlib.h>

#include "my_defender.h"

game_t *init_game(void)
{
    sfVideoMode mode = { 1920, 1080, 32 };
    game_t *game_manager = malloc(sizeof(game_t));

    if (game_manager == NULL)
        return NULL;
    game_manager->status = MENU;
    game_manager->window = sfRenderWindow_create(mode, "OUR defender !", \
    sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game_manager->window, 60);
    if (!game_manager->window) {
        free(game_manager);
        return NULL;
    }
    return game_manager;
}

int main_window(char **args)
{
    game_t *game_manager = init_game();

    if (args[1] == NULL)
        return -1;
    game_manager->current_map = get_and_check_map(args[1]);
    if (game_manager->current_map == NULL)
        return 84;
    if (game_manager == NULL)
        return 84;
    switch (game_manager->status) {
        case LOADING: break;
        case MENU: scene_menu_call(game_manager); break;
        case GAME: scene_game_call(game_manager); break;
        case PAUSE: break;
        case ENDED: sfRenderWindow_destroy(game_manager->window); break;
    }
    return 0;
}
