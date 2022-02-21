/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** delete_mode
*/

#include <stdlib.h>

#include "linked_lists.h"

////////////////////////////////////////////////////////////
//
// delete a node in a double linked list
//
// @param node the pointer to the linked list
//
// @param to_delete the pointer to the node to delete
////////////////////////////////////////////////////////////
void delete_node(linked_list **node, linked_list *to_delete)
{
    if ((*node) == NULL || to_delete == NULL)
        return;
    if ((*node) == to_delete)
        (*node) = to_delete->next;
    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
    if (to_delete->next != NULL)
        to_delete->next->prev = to_delete->prev;
    free(to_delete);
}
