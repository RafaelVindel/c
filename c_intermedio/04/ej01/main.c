#include <stdio.h>

#include "linked_list.h"

int main(int argc, char const *argv[]) {
    Linked_List* linked_list = NULL;

    linked_list = create_linked_list();

    add_element(linked_list, 5);
    print_linked_list(linked_list);

    remove_element(linked_list, 5);
    print_linked_list(linked_list);

    add_element(linked_list, 4);
    print_linked_list(linked_list);

    add_element(linked_list, 3);
    print_linked_list(linked_list);

    add_element(linked_list, 2);
    print_linked_list(linked_list);

    remove_element(linked_list, 4);
    print_linked_list(linked_list);

    remove_element(linked_list, 3);
    print_linked_list(linked_list);

    remove_element(linked_list, 2);
    print_linked_list(linked_list);

    add_element(linked_list, 5);
    add_element(linked_list, 4);
    add_element(linked_list, 3);
    add_element(linked_list, 2);
    print_linked_list(linked_list);

    remove_element(linked_list, 3);
    print_linked_list(linked_list);

    remove_element(linked_list, 4);
    print_linked_list(linked_list);

    remove_element(linked_list, 2);
    print_linked_list(linked_list);

    remove_element(linked_list, 5);
    print_linked_list(linked_list);

    add_element(linked_list, 5);
    add_element(linked_list, 4);
    add_element(linked_list, 3);
    add_element(linked_list, 2);

    delete_linked_list(&linked_list);

    return 0;
}
