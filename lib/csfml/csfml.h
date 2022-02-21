/*
** EPITECH PROJECT, 2022
** CSFML lib
** File description:
** csfml
*/

#ifndef CSFML_H_
#define CSFML_H_
    #include <SFML/Graphics.h>

    enum gameobject_type {
        NONE,
        PLAYER,
        ENNEMY,
    };

    enum gamestatus {
        MENU,
        PAUSE,
        PLAYING,
        DEAD,
        VICTORY,
    };

    typedef struct gameobject_s {
        enum gameobject_type type;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        sfIntRect rect;
        sfClock *clock;
        float clock_rate;
        int speed;
    } gameobject;

#endif /* !CSFML_H_ */
