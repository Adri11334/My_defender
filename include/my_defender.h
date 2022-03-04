/*
** EPITECH PROJECT, 2022
** project
** File description:
** my_project
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #ifndef MY_H_
        #include "my.h"
    #endif /* !MY_H_ */

    #ifndef LINKED_LISTS_H_
        #include "linked_lists.h"
    #endif /* !LINKED_LISTS_H_ */

    #ifndef MY_ENUM_H_
        #include "my_enum.h"
    #endif /* !MY_ENUM_H_ */

    #ifndef MY_STRUCT_H_
        #include "my_struct.h"
    #endif /* !MY_STRUCT_H_ */

    #define ABSOLUTE(nb) ((nb < 0) ? nb * -1 : nb)

    int main_window(char **args);

    dimension_t *dimension_create(float sizex, float sizey, \
    float positionx, float positiony);
    void dimension_destroy(dimension_t *dimension);

    button_t *button_create(dimension_t *dimension, button_colors_t *color, \
    sfText *content, void *onClick);
    void button_display(sfRenderWindow *window, button_t *button);
    void button_destroy(button_t *button);

    int button_hover_detection(sfVector2i mouse_position, button_t *button);
    int button_is_hover(sfRenderWindow *window, sfEvent *event, \
    button_t *button);

    sfText *text_create(char *content, font_t font_wanted, int size, \
    dimension_t *parent_dimensions);
    void text_destroy(sfText *text);

    void scene_menu_call(game_t *game_manager);
    void scene_game_call(game_t *game_manager);

    void analyse_events(game_t *game_manager);
    void event_quit_game(game_t *game_manager);

    void init_menu_buttons(game_t *_gm);
    void diplay_menu_buttons(game_t *_gm);

    char *get_and_check_map(char *filepath);

    map_block_t *map_block_create(dimension_t *dimension, block_type_t type, \
    game_t *game_manager);
    void map_load_blocks(game_t *_gm);

    void diplay_map_blocks(game_t *_gm);
    map_block_t *map_check_road_type(game_t *_gm, dimension_t *dims, \
    int char_i);
    map_block_t *map_check_border_type(game_t *_gm, dimension_t *dims, \
    int char_i);
    int map_block_is_hover(sfRenderWindow *window, sfEvent *event, \
    map_block_t *block, dimension_t **actual_clicked);

    button_t *button_menu_create(char *text, float posx, float posy, \
    sfColor _color);

    int tower_set_range(tower_type_t type, int tower_level);
    int tower_set_damages(tower_type_t type, int tower_level);
    tower_t *tower_create(dimension_t *dimension, tower_type_t type, \
    game_t *_gm);

    void clear_previous_buttons(game_t *_gm);
    void print_hello(void);
#endif /* !MY_DEFENDER_H_ */
