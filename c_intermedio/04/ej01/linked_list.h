#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "node.h"

typedef struct _linked_list {
    Node* head;
} Linked_List;

Linked_List* create_linked_list();
void delete_linked_list(Linked_List** linked_list);
void add_element(Linked_List* linked_list, int value);
void remove_element(Linked_List* linked_list, int value);
void print_linked_list(Linked_List* linked_list);

#endif
