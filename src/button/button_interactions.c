/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button interactions
*/

#include "my_project.h"

void button_change_status(button_t *button, button_status_t status)
{
    switch (status) {
        case ACTIVE: button->status = ACTIVE; break;
        case IDLE: button->status = IDLE; break;
        case HIGHLIGHT: button->status = HIGHLIGHT; break;
        case CLICKED: button->status = CLICKED; break;
        case DISABLED: button->status = DISABLED; break;
    }
}