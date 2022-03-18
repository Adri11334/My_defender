/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_enum
*/

#ifndef MY_ENUM_H_
#define MY_ENUM_H_

    typedef enum font_e {
        ROBOTO_LIGHT,
        ROBOTO_ITALIC,
        ROBOTO_THIN,
        ROBOTO_REGULAR,
        ROBOTO_NORMAL,
        ROBOTO_MEDIUM,
        ROBOTO_BOLD,
    } font_t;

    typedef enum tower_type_e {
        EARTH_TOWER,
        ICE_TOWER,
        SAND_TOWER,
        FIRE_TOWER,
    } tower_type_t;

    typedef enum block_type_e {
        BLOCK_BORDER_TOP,
        BLOCK_BORDER_BOTTOM,
        BLOCK_BORDER_LEFT,
        BLOCK_BORDER_RIGHT,
        BLOCK_BORDER_RT_CORNER,
        BLOCK_BORDER_RB_CORNER,
        BLOCK_BORDER_LT_CORNER,
        BLOCK_BORDER_LB_CORNER,
        BLOCK_SPAWNER,
        BLOCK_HOME,
        BLOCK_ROAD_VERT,
        BLOCK_ROAD_HORI,
        BLOCK_ROAD_TOP_LEFT_CORNER,
        BLOCK_ROAD_TOP_RIGHT_CORNER,
        BLOCK_ROAD_BOTTOM_LEFT_CORNER,
        BLOCK_ROAD_BOTTOM_RIGHT_CORNER,
        BLOCK_ROAD_X_CORNER,
        BLOCK_VIRGIN,
    } block_type_t;

    typedef enum button_status_e {
        ACTIVE,
        IDLE,
        HIGHLIGHT,
        CLICKED,
        DISABLED,
    } button_status_t;

    typedef enum game_status_e {
        LOADING,
        MENU,
        HOW_TO_PLAY,
        SETTINGS,
        GAME,
        PAUSE,
        ENDED,
    } game_status_t;

    typedef enum layer_type_e {
        GROUND,
        TREES,
        HILLSO,
        HILLST,
        CLOUDS,
        ROCKS,
        SKY,
    } layer_type_t;

#endif /* !MY_ENUM_H_ */
