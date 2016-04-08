#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"

Board* create_board(const char *filename, const char *game_type) {
    FILE *f = fopen(filename, "r");
    Board *board = (Board *)calloc(1, sizeof(board[0]));

    fscanf(f, "%d", &board->dimension);

    board->values = (int **)calloc(board->dimension, sizeof(board->values[0]));
    for(int i = 0; i < board->dimension; i++) {
        board->values[i] = (int *)calloc(board->dimension, sizeof(board->values[0][0]));
    }

    for(int i = 0; i < board->dimension; i++) {
        for(int j = 0; j < board->dimension; j++) {
            fscanf(f, "%d", &board->values[i][j]);
        }
    }

    if(!strcmp(game_type, "normal")) {
        board->number_of_assertions = 3;
        board->assertions = (int (**) (Board*, Input*))calloc(3, sizeof(board->assertions[0]));
        board->assertions[0] = &is_valid_value_for_row;
        board->assertions[1] = &is_valid_value_for_column;
        board->assertions[2] = &is_valid_value_for_cell;
    } else if(!strcmp(game_type, "diagonal")) {
        board->number_of_assertions = 3;
        board->assertions = (int (**) (Board*, Input*))calloc(3, sizeof(board->assertions[0]));
        board->assertions[0] = &is_valid_value_for_row;
        board->assertions[1] = &is_valid_value_for_column;
        board->assertions[2] = &is_valid_value_for_cell;
    }

    fclose(f);

    return board;
}

void print_board(Board *board) {
    for(int i = 0; i < board->dimension; i++) {
        if(i == 3 || i == 6) {
            printf("\n");
        }
        for(int j = 0; j < board->dimension; j++) {
            if(j == 3 || j == 6) {
                printf("|");
            }
            printf(" %d ", board->values[i][j]);
        }
        printf("\n");
    }
}

void destroy_board(Board **board) {
    for(int i = 0; i < (*board)->dimension; i++) {
        free((*board)->values[i]);
    }

    free((*board)->values);
    free(*board);
    *board = NULL;
}

int insert_value(Board *board, Input *input) {;
    for(int i = 0; i < board->number_of_assertions; i++) {
        if(!board->assertions[i](board, input)) {
            printf("Valor no válido\n");
            return 0;
        }
    }

    board->values[input->row][input->column] = input->value;

    return 1;
}

int is_valid_value_for_row(Board *board, Input *input) {
    for(int i = 0; i < board->dimension; i++) {
        if(board->values[input->row][i] == input->value) {
            return 0;
        }
    }
    return 1;
}

int is_valid_value_for_column(Board *board, Input *input) {
    for(int i = 0; i < board->dimension; i++) {
        if(board->values[i][input->column] == input->value) {
            return 0;
        }
    }
    return 1;
}

int is_valid_value_for_specific_cell(Board *board, Input *input, int begin_row, int end_row, int begin_column, int end_column) {
    for(int i = begin_row; i <= end_row; i++) {
        for(int j = begin_column; j <= end_column; j++) {
            if(board->values[i][j] == input->value) {
                return 0;
            }
        }
    }
    return 1;
}

int is_valid_value_for_cell(Board *board, Input *input) {
    if((CELLS_1_2_3_ROW_BEGIN <= input->row) && (input->row <= CELLS_1_2_3_ROW_END)) {
        if((CELLS_1_4_5_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_1_4_5_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_1_2_3_ROW_BEGIN, CELLS_1_2_3_ROW_END, CELLS_1_4_5_COLUMN_BEGIN, CELLS_1_4_5_COLUMN_END);
        } else if((CELLS_2_5_8_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_2_5_8_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_1_2_3_ROW_BEGIN, CELLS_1_2_3_ROW_END, CELLS_2_5_8_COLUMN_BEGIN, CELLS_2_5_8_COLUMN_END);
        } else if((CELLS_3_6_9_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_3_6_9_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_1_2_3_ROW_BEGIN, CELLS_1_2_3_ROW_END, CELLS_3_6_9_COLUMN_BEGIN, CELLS_3_6_9_COLUMN_END);
        }
    } else if((CELLS_4_5_6_ROW_BEGIN <= input->row) && (input->row <= CELLS_4_5_6_ROW_END)) {
        if((CELLS_1_4_5_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_1_4_5_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_4_5_6_ROW_BEGIN, CELLS_4_5_6_ROW_END, CELLS_1_4_5_COLUMN_BEGIN, CELLS_1_4_5_COLUMN_END);
        } else if((CELLS_2_5_8_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_2_5_8_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_4_5_6_ROW_BEGIN, CELLS_4_5_6_ROW_END, CELLS_2_5_8_COLUMN_BEGIN, CELLS_2_5_8_COLUMN_END);
        } else if((CELLS_3_6_9_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_3_6_9_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_4_5_6_ROW_BEGIN, CELLS_4_5_6_ROW_END, CELLS_3_6_9_COLUMN_BEGIN, CELLS_3_6_9_COLUMN_END);
        }
    } else if((CELLS_7_8_9_ROW_BEGIN <= input->row) && (input->row <= CELLS_7_8_9_ROW_END)) {
        if((CELLS_1_4_5_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_1_4_5_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_7_8_9_ROW_BEGIN, CELLS_7_8_9_ROW_END, CELLS_1_4_5_COLUMN_BEGIN, CELLS_1_4_5_COLUMN_END);
        } else if((CELLS_2_5_8_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_2_5_8_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_7_8_9_ROW_BEGIN, CELLS_7_8_9_ROW_END, CELLS_2_5_8_COLUMN_BEGIN, CELLS_2_5_8_COLUMN_END);
        } else if((CELLS_3_6_9_COLUMN_BEGIN <= input->column) && (input->column <= CELLS_3_6_9_COLUMN_END)) {
            return is_valid_value_for_specific_cell(board, input, CELLS_7_8_9_ROW_BEGIN, CELLS_7_8_9_ROW_END, CELLS_3_6_9_COLUMN_BEGIN, CELLS_3_6_9_COLUMN_END);
        }
    }

    return 0;
}
