#ifndef _BOARD_H_
#define _BOARD_H_

#define CELLS_1_2_3_ROW_BEGIN 0
#define CELLS_1_2_3_ROW_END 2
#define CELLS_4_5_6_ROW_BEGIN 3
#define CELLS_4_5_6_ROW_END 5
#define CELLS_7_8_9_ROW_BEGIN 6
#define CELLS_7_8_9_ROW_END 8

#define CELLS_1_4_5_COLUMN_BEGIN 0
#define CELLS_1_4_5_COLUMN_END 2
#define CELLS_2_5_8_COLUMN_BEGIN 3
#define CELLS_2_5_8_COLUMN_END 5
#define CELLS_3_6_9_COLUMN_BEGIN 6
#define CELLS_3_6_9_COLUMN_END 8

typedef struct _input {
    int row;
    int column;
    int value;
} Input;

typedef struct _board {
    int dimension;
    int **values;
    int number_of_assertions;
    int (**assertions)(struct _board*, Input*);
} Board;

Board* create_board(const char *filename, const char *game_type);
void print_board(Board *board);
void destroy_board(Board **board);

int insert_value(Board *board, Input *input);
int is_valid_value_for_row(Board *board, Input *input);
int is_valid_value_for_column(Board *board, Input *input);
int is_valid_value_for_cell(Board *board, Input *input);

#endif
