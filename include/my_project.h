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

    typedef struct button_colors_s {
        sfColor normal;
        sfColor idle;
        sfColor highlight;
        sfColor clicked;
        sfColor disable;
    } button_colors_t;

    typedef enum button_status_e {
        ACTIVE,
        IDLE,
        HIGHLIGHT,
        CLICKED,
        DISABLED,
    } button_status_t;

    typedef struct dimension_s {
        sfVector2f *size;
        sfVector2f *position;
    } dimension_t;

    typedef struct button_s {
        button_status_t status;
        sfRectangleShape *rect;
        button_colors_t *colors;
        dimension_t *dimension;
        sfText *text;
        void (*onClick) (void);
    } button_t;

    int main_window(void);

    dimension_t *dimension_create(float sizex, float sizey, \
    float positionx, float positiony);
    void dimension_destroy(dimension_t *dimension);

    button_t *button_create(dimension_t *dimension, button_colors_t *color, \
    sfText *content, void *onClick);
    void button_display(sfRenderWindow *window, button_t *button);
    void button_destroy(button_t *button);

    sfText *text_create(char *content, font_t font_wanted, int size, \
    dimension_t *parent_dimensions);
    void text_destroy(sfText *text);

    int button_hover_detection(sfVector2i mouse_position, button_t *button);
    int button_is_hover(sfRenderWindow *window, sfEvent *event, \
    button_t *button);


    void print_hello();
#endif /* !MY_PROJECT_H_ */
