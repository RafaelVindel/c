#include <stdio.h>
#include <stdlib.h>

#include "cell.h"

cell* create_cell(int dimension) {
    cell *new_cell = NULL;

    if(!(new_cell = (cell *)calloc(1, sizeof(new_cell[0])))) {
        return NULL;
    }

    new_cell->dimension = dimension;
    new_cell->size = dimension * dimension;
    if(!(new_cell->values = (char *)calloc(new_cell->size, sizeof(new_cell->values[0])))) {
        destroy_cell(&new_cell);
        return NULL;
    }

    return new_cell;
}

void destroy_cell(cell **cell) {
    if((*cell)->values != NULL) {
        free((*cell)->values);
        (*cell)->values = NULL;
    }

    free((*cell));
    cell = NULL;
}
