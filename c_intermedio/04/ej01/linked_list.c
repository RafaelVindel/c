#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


Linked_List* create_linked_list() {
    Linked_List* linked_list = NULL;

    if(!(linked_list = (Linked_List*)malloc(1 * sizeof(linked_list[0])))) {
        return NULL;
    }

    linked_list->head = NULL;

    return linked_list;
}

void delete_linked_list(Linked_List** linked_list) {
    if((*linked_list)->head == NULL) {
        free(*linked_list);
        *linked_list = NULL;
    } else {
        Node* node = (*linked_list)->head;
        while(node->next != NULL) {
            Node* aux = node;
            delete_node(&node);
            node = aux->next;
        }

        delete_node(&node);
        free(*linked_list);
        *linked_list = NULL;
    }
}

void add_element(Linked_List* linked_list, int value) {
    if(linked_list->head == NULL) {
        linked_list->head = create_node(value);
    } else {
        Node* node = linked_list->head;
        while(node->next != NULL) {
            node = node->next;
        }
        node->next = create_node(value);
    }
}

void remove_element(Linked_List* linked_list, int value) {
    if(linked_list->head != NULL) {
        while(linked_list->head && is_equal(linked_list->head, value)) {
            Node* node = linked_list->head;
            linked_list->head = node->next;
            delete_node(&node);
        }

        if(linked_list->head != NULL) {
            Node* node = linked_list->head;
            while(node->next != NULL) {
                if(is_equal(node->next, value)) {
                    Node* node_aux = node->next->next;
                    delete_node(&node->next);
                    node->next = node_aux;
                } else {
                    node = node->next;
                }
            }
        }
    }
}

void print_linked_list(Linked_List* linked_list) {
    if(linked_list->head != NULL) {
        Node* node = linked_list->head;
        while(node != NULL) {
            print_node(node);
            node = node->next;
        }
    } else {
        printf("empty\n");
    }
}
