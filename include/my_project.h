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

    #define ABSOLUTE(nb) ((nb < 0) ? nb * -1 : nb)

    typedef enum font_e {
        ROBOTO_LIGHT,
        ROBOTO_ITALIC,
        ROBOTO_THIN,
        ROBOTO_REGULAR,
        ROBOTO_NORMAL,
        ROBOTO_MEDIUM,
        ROBOTO_BOLD,
    } font_t;

    typedef struct colors_s {
        sfColor normal;
        sfColor highlight;
        sfColor disable;
    } colors_t;

    typedef struct dimension_s {
        sfVector2f *size;
        sfVector2f *position;
    } dimension_t;

    typedef struct button_s {
        sfRectangleShape *rect;
        colors_t *colors;
        dimension_t *dimension;
        sfText *text;
        void (*onClick);
    } button_t;

    int main_window(void);
    colors_t *color_group_create(sfColor normal, \
    sfColor highlight, sfColor disable);
    void color_group_destroy(colors_t *colors);

    dimension_t *dimension_create(float sizex, float sizey, \
    float positionx, float positiony);
    void dimension_destroy(dimension_t *dimension);

    button_t *button_create(dimension_t *dimension, colors_t *color, \
    sfText *content, void *onClick);
    void button_display(sfRenderWindow *window, button_t *button);
    void button_destroy(button_t *button);

    sfText *text_create(char *content, font_t font_wanted, int size, \
    dimension_t *parent_dimensions);
    void text_destroy(sfText *text);

    int mouse_click_detected(sfMouseButtonEvent event, button_t *button);
    int button_is_clicked(sfMouseButtonEvent event, button_t *button);

#endif /* !MY_PROJECT_H_ */
