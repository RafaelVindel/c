#include <time.h>
#include <stdio.h>

#define ITERATIONS 100
#define N 2000

char array[N][N];

void array_initializer() {

	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            array[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            array[i][j]++;
        }
    }
}

int main(int argc, char const *argv[]) {
	clock_t start, end;

	start = clock();

	for(int i = 0; i < ITERATIONS; i++) {
        array_initializer();
    }

	end = clock();

	printf("CPU = %f ms \n",  (float)(end - start)/CLOCKS_PER_SEC * 1000 / ITERATIONS);

    return 0;
}
