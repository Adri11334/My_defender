/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** restart
*/

#include <stdlib.h>

#include "linked_lists.h"

////////////////////////////////////////////////////////////
//
// Get back to the first pos of a linked list
//
// @param node the pointer to the linked list
////////////////////////////////////////////////////////////
int back_to_start(linked_list **node)
{
    if ((*node) == NULL)
        return 84;
    while ((*node)->prev != NULL)
        *node = (*node)->prev;
    return 0;
}

////////////////////////////////////////////////////////////
//
// Get back to the first pos of a linked list
//
// @param node the pointer to the linked list
////////////////////////////////////////////////////////////
int go_to_last(linked_list **node)
{
    if ((*node) == NULL)
        return 84;
    while ((*node)->next != NULL)
        *node = (*node)->next;
    return 0;
}
