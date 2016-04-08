#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i = 7;
    int *i_pointer = &i;

    printf("memory address: %x\n", i_pointer);
    printf("value: %d\n", *i_pointer);

    return 0;
}
