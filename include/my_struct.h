/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

    #ifndef MY_DEFENDER_H_
        #include "my_defender.h"
    #endif/* !MY_DEFENDER_H_ */

    #ifndef _STDBOOL_H
        #include <stdbool.h>
    #endif/* !_STDBOOL_H*/

    typedef struct button_colors_s {
        sfColor normal;
        sfColor idle;
        sfColor highlight;
        sfColor clicked;
        sfColor disable;
    } button_colors_t;

    typedef struct dimension_s {
        sfVector2f *size;
        sfVector2f *position;
    } dimension_t;

    typedef struct txt_img_s {
        sfSprite *image;
        sfIntRect *rect;
        sfText *life_text;
        dimension_t *dims;
        int image_width;
    } txt_img_t;

    typedef struct layer_s {
        int offset;
        float clock_rate;
        sfSprite *sprite;
        sfIntRect *rect;
        sfClock *clock;
        sfTexture *texture;
        layer_type_t type;
        dimension_t *dim;
    } layer_t;

    typedef struct scene_s {
        linked_list *blocks;
        linked_list *buttons;
        linked_list *pause_buttons;
        linked_list *entitys;
        linked_list *panels;
        linked_list *pause;
        linked_list *title;
        sfClock *scene_clock;
        float clock_rate;
    } scene_t;

    typedef struct ennemy_s {
        direction_t direction;
        sfClock *anim_clock;
        sfClock *move_clock;
        ennemy_type_t type;
        dimension_t *stats;
        float anim_speed;
        float move_speed;
        sfSprite *sprite;
        sfVector2f n_pos;
        sfIntRect rect;
        int gap;
        int life;
        sfText *life_text;
    } ennemy_t;

    typedef struct game_s {
        game_status_t status;
        sfRenderWindow *window;
        sfTexture *game_texture;
        scene_t *menu_scene;
        scene_t *game_scene;
        dimension_t *actual_clicked_button;
        char *current_map;
        sfEvent event;
        int money;
        sfClock *money_clock;
        float money_gap;
        int money_by_gap;
    } game_t;

    typedef struct button_s {
        button_status_t status;
        sfRectangleShape *rect;
        button_colors_t *colors;
        dimension_t *dimension;
        sfSprite *sprite;
        bool isSprite;
        sfText *text;
        void (*onClick) (game_t *_game_manager);
    } button_t;

    typedef struct tower_s {
        tower_type_t type;
        int range;
        int damage;
        sfSprite *sprite;
        sfIntRect *rect;
        sfClock *clock;
        float clock_rate;
        dimension_t *dimension;
        int max_frame;
        int current_frame;
        linked_list *shooting_ennemys;
    } tower_t;

    typedef struct map_block_s {
        block_type_t type;
        button_status_t status;
        sfRectangleShape *rect;
        button_colors_t *colors;
        tower_t *tower;
        dimension_t *dimension;
        sfSprite *sprite;
    } map_block_t;

#endif/* !MY_STRUCT_H_ */
