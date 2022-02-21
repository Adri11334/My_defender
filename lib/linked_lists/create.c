/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** create
*/

#include <stdlib.h>

#include "linked_lists.h"

////////////////////////////////////////////////////////////
//
// Init a new double linked list with a start of Data
//
// @param data the pointer to the data we need to push
////////////////////////////////////////////////////////////
linked_list *init_list(void *data)
{
    linked_list *list = malloc(sizeof(linked_list));

    if (list == NULL)
        return NULL;
    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}
