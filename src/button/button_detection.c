/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button_detection
*/

#include "my_project.h"

int button_clicked_detection(sfMouseButtonEvent event, button_t *button)
{
    float clic_from_right_border_x = event.x - \
    (button->dimension->position->x + button->dimension->size->x);
    float clic_from_top_border_y = event.y - \
    (button->dimension->position->y + button->dimension->size->y);

    if (clic_from_right_border_x < 0 \
    && ABSOLUTE(clic_from_right_border_x) < button->dimension->size->x) {
        if (clic_from_top_border_y < 0 \
        && ABSOLUTE(clic_from_top_border_y) < button->dimension->size->y) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int button_is_clicked(sfMouseButtonEvent event, button_t *button)
{
    if (button_clicked_detection(event, button) == 1) {
        write_green("Button is clicked\n");
        return 1;
    } else
        return 0;
}
