/*
** EPITECH PROJECT, 2022
** project
** File description:
** my_project
*/

#ifndef MY_PROJECT_H_
#define MY_PROJECT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my.h"

    typedef struct colors_s {
        sfColor normal;
        sfColor hightlight;
        sfColor disable;
    } colors_t;

    typedef struct dimension_s {
        sfVector2f size;
        sfVector2f position;
    } dimension_t;

    typedef struct button_s {
        sfRectangleShape *rect;
        colors_t *colors;
        dimension_t *dimension;
    } button_t;

    int main_window(void);
    button_t *init_button(sfVector2f position, \
    sfVector2f size, colors_t color);

#endif /* !MY_PROJECT_H_ */
