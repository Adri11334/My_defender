/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** print
*/

#include <stdlib.h>

#include "linked_lists.h"

////////////////////////////////////////////////////////////
//
// Get the size of a double linked list
//
// @param node the pointer to the linked list
////////////////////////////////////////////////////////////
int node_length(linked_list *node)
{
    int length = 0;

    for (; node != NULL; length++)
        node = node->next;
    return length;
}
