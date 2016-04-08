#ifndef _CELL_H_
#define _CELL_H_

struct Cell {
    int dimension;
    int size;
    char *values;
};
typedef struct Cell cell;

cell* create_cell(int dimension);
void destroy_cell(cell **cell);

#endif
