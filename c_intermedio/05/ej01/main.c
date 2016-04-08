#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "board.h"

Input * get_user_choice(void);

int main(int argc, char const *argv[]) {
    Board *board = create_board(argv[1], argv[2]);

    while(1) {
        print_board(board);
        Input *input = get_user_choice();
        insert_value(board, input);
    }

    return 0;
}

Input * get_user_choice(void) {
    Input *input = (Input *)calloc(1, sizeof(input[0]));

    printf("\nSelect row column & value: \n");
    scanf("%d %d %d", &(input->row), &(input->column), &(input->value));

    return input;
}
