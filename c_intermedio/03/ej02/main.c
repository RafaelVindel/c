#include <stdio.h>

int get_bit_at_position(int number, int position);

int main(int argc, char const *argv[]) {
    for(int i = 0; i < 16; i++) {
        int bit_0 = get_bit_at_position(i, 0);
        int bit_1 = get_bit_at_position(i, 1);;
        int bit_2 = get_bit_at_position(i, 2);
        int bit_3 = get_bit_at_position(i, 3);

        printf("%d%d%d%d\n", bit_3, bit_2, bit_1, bit_0);
    }

    return 0;
}

int get_bit_at_position(int number, int position) {
    return (number >> position) & 1;
}
