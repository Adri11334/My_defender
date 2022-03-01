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
    #include "my_enum.h"
    #include "my_struct.h"

    #define ABSOLUTE(nb) ((nb < 0) ? nb * -1 : nb)

    int main_window(void);

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

    void print_hello();
#endif /* !MY_PROJECT_H_ */
