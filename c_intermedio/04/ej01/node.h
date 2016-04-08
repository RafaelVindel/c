#ifndef _NODE_H_
#define _NODE_H_

#include <stdbool.h>

typedef struct _node {
    int value;
    struct _node* next;
} Node;

Node* create_node(int value);
void delete_node(Node** node);
bool is_equal(Node* node, int value);
void print_node(Node* node);

#endif
