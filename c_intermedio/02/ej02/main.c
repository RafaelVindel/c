#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i[5] = {1, 2, 3, 4, 5};
    int *i_pointer = i;

    printf("value position 0: %d\n", *(i_pointer + 0));
    printf("value position 1: %d\n", *(i_pointer + 1));
    printf("value position 2: %d\n", *(i_pointer + 2));
    printf("value position 3: %d\n", *(i_pointer + 3));
    printf("value position 4: %d\n", *(i_pointer + 4));

    return 0;
}
