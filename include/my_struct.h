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
    #endif /* !MY_DEFENDER_H_ */


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

    typedef struct scene_s {
        linked_list *blocks;
        linked_list *buttons;
        linked_list *entitys;
        linked_list *panels;
    } scene_t;

    typedef struct ennemy_s {
        ennemy_type_t type;
        dimension_t *stats;
        sfSprite *sprite;
        float clock_rate;
        sfVector2f pos;
        sfIntRect rect;
        sfClock *clock;
        int speed;
        int life;
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
    } game_t;

    typedef struct button_s {
        button_status_t status;
        sfRectangleShape *rect;
        button_colors_t *colors;
        dimension_t *dimension;
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

#endif /* !MY_STRUCT_H_ */
