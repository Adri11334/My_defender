/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

    #ifndef MY_PROJECT_H_
        #include "my_project.h"
    #endif /* !MY_PROJECT_H_ */

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

    typedef struct button_s {
        button_status_t status;
        sfRectangleShape *rect;
        button_colors_t *colors;
        dimension_t *dimension;
        sfText *text;
        void (*onClick) (void);
    } button_t;

#endif /* !MY_STRUCT_H_ */
