/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** push
*/

#include <stdlib.h>

#include "linked_lists.h"

////////////////////////////////////////////////////////////
//
// Put a Data at the head of a double linked list
//
// @param node the node to insert the data
//
// @param data the pointer to the data we need to push
////////////////////////////////////////////////////////////
int push_node(linked_list **node, void *data)
{
    linked_list *new_node = malloc(sizeof(linked_list));

    if (new_node == NULL)
        return 84;
    new_node->data = data;
    new_node->next = *node;
    new_node->prev = NULL;
    if ((*node) != NULL)
        (*node)->prev = new_node;
    (*node) = new_node;
    return 0;
}
