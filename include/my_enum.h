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
        TOWER_1,
        TOWER_2,
        TOWER_3,
    } tower_type_t;

    typedef enum block_type_e {
        BLOCK_BORDER,
        BLOCK_SPAWN,
        BLOCK_HOME,
        BLOCK_ROAD,
        BLOCK_EMPTY,
        BLOCK_WITH_TOWER,
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
        GAME,
        PAUSE,
        ENDED,
    } game_status_t;

#endif /* !MY_ENUM_H_ */
