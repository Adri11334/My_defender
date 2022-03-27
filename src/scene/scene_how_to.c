/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scene_how_to
*/

#include "my_defender.h"

void scene_how_to_play_call(game_t *game_manager)
{
/*     sfText *how_to_play = text_create(get_file_content("assets/help.txt"), \
    ROBOTO_REGULAR, 40, dimension_create(1920, 1080, 0, 0));
 */
    display_help();
    /* while (sfRenderWindow_isOpen(game_manager->window) \
    && game_manager->status == HOW_TO_PLAY) {
        analyse_events(game_manager);
        sfRenderWindow_clear(game_manager->window, \
        (sfColor){255, 73, 94, 255});
        sfRenderWindow_drawText(game_manager->window, how_to_play, NULL);
        sfRenderWindow_display(game_manager->window);
    } */
}
