#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node* create_node(int value) {
    Node* node = NULL;

    if(!(node = (Node*)calloc(1, sizeof(node[0])))) {
        return NULL;
    }

    node->value = value;
    node->next = NULL;

    return node;
}

void delete_node(Node** node) {
    free(*node);
    *node = NULL;
}

bool is_equal(Node* node, int value) {
    return node->value == value;
}

void print_node(Node* node) {
    printf("Nodo[%x]. valor: %d, next: %x\n", node, node->value, node->next);
}
