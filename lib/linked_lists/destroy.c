/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** destroy
*/

#include <stdlib.h>

#include "linked_lists.h"

////////////////////////////////////////////////////////////
//
// Destroy a linked list (will not destroy his content)
//
// @param node the pointeur to the linked list
////////////////////////////////////////////////////////////
void destroy_node(linked_list **node)
{
    linked_list *current = *node;

    back_to_start(node);
    while (current != NULL) {
        linked_list *next = current->next;
        free(current);
        current = next;
    }
}
