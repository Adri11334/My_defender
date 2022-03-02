/*
** EPITECH PROJECT, 2022
** Linked List lib
** File description:
** linked lists header
*/

#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_
    #include <stddef.h>

    typedef struct node_s {
        void *data;
        struct node_s *prev;
        struct node_s *next;
    } linked_list;

    linked_list *init_list(void *data);
    void delete_node(linked_list **node, linked_list *to_delete);
    void destroy_node(linked_list **node);
    int node_length(linked_list *node);
    int push_node(linked_list **node, void *data);
    int back_to_start(linked_list **node);
    int go_to_last(linked_list **node);
#endif /* !LINKED_LISTS_H_ */
