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
    #include  <stdlib.h>

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
    void button_display(game_t *_gm, button_t *button);
    void button_destroy(button_t *button);

    int button_hover_detection(sfVector2i mouse_position, button_t *button);
    int button_is_hover(game_t *_gm, button_t *button);

    sfText *text_create(char *content, font_t font_wanted, int size, \
    dimension_t *parent_dimensions);
    void text_destroy(sfText *text);

    void scene_menu_call(game_t *game_manager);
    void scene_game_call(game_t *game_manager);
    void scene_how_to_play_call(game_t *game_manager);
    void scene_settings_call(game_t *game_manager);
    void scene_pause_call(game_t *game_manager);

    void menu_play_clicked(game_t *_gm);
    void menu_settings_clicked(game_t *_gm);
    void menu_ht_clicked(game_t *_gm);
    void menu_quit_clicked(game_t *_gm);
    void game_pause_clicked(game_t *_gm);
    void pause_menu_clicked(game_t *_gm);

    void analyse_events(game_t *game_manager);
    void event_quit_game(game_t *game_manager);

    void init_menu_buttons(game_t *_gm);
    void diplay_menu_buttons(game_t *_gm);

    void init_pause_buttons(game_t *_gm);
    void display_pause_buttons(game_t *_gm);

    void menu_pause_create(game_t *_gm);
    layer_t *pause_create(char *name, game_status_t type, dimension_t *dim);
    void display_pause(game_t *_gm);
    void menu_title_create(game_t *_gm);
    void display_title(game_t *_gm);

    void setup_ingame_menu(game_t *_gm);

    char *get_and_check_map(char *filepath);

    map_block_t *map_block_create(dimension_t *dimension, block_type_t type, \
    game_t *game_manager);
    void map_load_blocks(game_t *_gm);

    void diplay_map_blocks(game_t *_gm);
    void diplay_game_buttons(game_t *_gm);
    map_block_t *map_check_road_type(game_t *_gm, dimension_t *dims, \
    int char_i);
    map_block_t *map_check_border_type(game_t *_gm, dimension_t *dims, \
    int char_i);
    int map_block_is_hover(sfRenderWindow *window, sfEvent *event, \
    map_block_t *block, dimension_t **actual_clicked);

    void init_ennemys(game_t *_gm);
    void spawn_new_ennemys(game_t *_gm);
    void display_ennemy(game_t *_gm, ennemy_t *ennemy);
    void ennemy_move(game_t *_gm, ennemy_t *ennemy);
    void ennemy_display_manager(game_t *_gm);
    sfVector2f *spawner_position(char *map);
    ennemy_t *ennemy_create(game_t *_gm, ennemy_type_t type);
    void destroy_ennemy(ennemy_t *ennemy);

    button_t *button_menu_create(char *text, float posx, float posy, \
    sfColor _color);

    int tower_set_range(tower_type_t type, int tower_level);
    int tower_set_damages(tower_type_t type, int tower_level);
    void *get_correct_tower_callback(tower_type_t type);
    tower_t *tower_create(dimension_t *dimension, tower_type_t type, \
    game_t *_gm);

    void add_update_earth_tower(game_t *_gm);
    void add_update_sand_tower(game_t *_gm);
    void add_update_ice_tower(game_t *_gm);
    void add_update_fire_tower(game_t *_gm);

    void tower_manager(game_t *_gm, tower_t *tower);

    void clear_previous_buttons(scene_t *scene);
    void print_hello(void);

    layer_t *layer_create(char *name, layer_type_t type, dimension_t *dim, \
    int offset);
    void parallax_init_layer(game_t *_gm);
    void display_parallax(game_t *_gm);
#endif /* !MY_DEFENDER_H_ */
