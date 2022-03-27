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
    game_t *_gm = malloc(sizeof(game_t));
    sfIntRect rect = { 0, 0, 1920, 1080 };

    if (_gm == NULL)
        return NULL;
    _gm->status = MENU;
    _gm->window = sfRenderWindow_create(mode, "OUR defender !", \
    sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(_gm->window, 60);
    _gm->game_texture = \
    sfTexture_createFromFile("assets/image/tilesheet.png", &rect);
    _gm->menu_scene = malloc(sizeof(scene_t));
    _gm->game_scene = malloc(sizeof(scene_t));
    _gm->actual_clicked_button = NULL;
    if (!_gm->window) {
        free(_gm);
        return NULL;
    }
    return _gm;
}

int main_window(char **args)
{
    game_t *_gm = init_game();

    if (args[1] == NULL)
        return -1;
    _gm->current_map = get_and_check_map(args[1]);
    if (_gm->current_map == NULL || _gm == NULL)
        return 84;
    while (_gm->status != ENDED) {
        switch (_gm->status) {
            case LOADING: break;
            case MENU: scene_menu_call(_gm); break;
            case HOW_TO_PLAY: display_help(); _gm->status = ENDED; break;
            case SETTINGS: scene_settings_call(_gm); break;
            case GAME: scene_game_call(_gm); break;
            case PAUSE: scene_game_call(_gm); break;
            default: _gm->status = ENDED; break;
        }
    }
    sfRenderWindow_destroy(_gm->window);
    return 0;
}
