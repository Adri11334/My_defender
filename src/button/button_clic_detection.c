/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button_detection
*/

#include "my_defender.h"

int button_hover_detection(sfVector2i m_pos, button_t *button)
{
    float clic_from_right_border_x = m_pos.x - \
    (button->dimension->position->x + button->dimension->size->x);
    float clic_from_top_border_y = m_pos.y - \
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

int button_hovered(game_t *_gm, button_t *button)
{
    sfEvent *event = NULL;

    if (_gm == NULL || button == NULL)
        return 84;
    if ((event = &_gm->event) == NULL)
        return 84;
    if (event->type == sfEvtMouseButtonPressed) {
        if (button->status != CLICKED && button->onClick != NULL) {
            button->status = CLICKED;
            button->onClick(_gm);
        }
    } else {
        button->status = HIGHLIGHT;
    }
    return 1;
}

int button_is_hover(game_t *_gm, button_t *button)
{
    sfVector2i mouse_pos;

    if (_gm == NULL || button == NULL)
        return 84;
    mouse_pos = sfMouse_getPositionRenderWindow(_gm->window);
    if (button_hover_detection(mouse_pos, button) == 1) {
        return button_hovered(_gm, button);
    } else {
        if (button->status != DISABLED && button->status != IDLE) {
            button->status = ACTIVE;
        }
        return 0;
    }
}
