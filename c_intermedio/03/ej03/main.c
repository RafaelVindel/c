#include <stdio.h>

void sort_bubble_sort(int array[], int size);
void sort_bubble_sort_optimized(int array[], int size);

void swap(int *a, int *b);
void print_array(int array[], int size);

int main(int argc, char const *argv[]) {
    int array_a[10] = {1, 5, 7, 4, 3, 8, 9, 10, 2, 6};
    int array_b[10] = {1, 5, 7, 4, 3, 8, 9, 10, 2, 6};

    printf("sorting array with bubble sort...\n");
    sort_bubble_sort(array_a, 10);

    printf("sorting array with bubble sort optimized...\n");
    sort_bubble_sort_optimized(array_b, 10);

    return 0;
}

void sort_bubble_sort(int array[], int size) {
    for(int i = 0; i < size; i++) {
        print_array(array, 10);
        for(int j = 0; j < size - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void sort_bubble_sort_optimized(int array[], int size) {
    for(int i = 0, swapped = 1; i < size && swapped; i++) {
        swapped = 0;
        print_array(array, 10);
        for(int j = 0; j < size - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
    }
}

void swap(int *a, int *b) {
    int c = *b;
    *b = *a;
    *a = c;
}

void print_array(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
