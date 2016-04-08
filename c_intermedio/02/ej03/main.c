#include <stdio.h>

enum gender {
    MALE,
    FEMALE
};
typedef enum gender gender;

struct person {
    char name[50];
    char surname[50];
    int age;
    gender gender;
};
typedef struct person person;

int main(int argc, char const *argv[]) {
    person me = {"Rafael", "Vindel", 23, MALE};
    person *me_pointer = &me;

    printf("name: %s\n", me.name);
    printf("surname: %s\n", me.surname);
    printf("age: %d\n", me.age);
    printf("gender: %d\n", me.gender);

    printf("pointer name: %s\n", (*me_pointer).name);
    printf("pointer surname: %s\n", me_pointer->surname);
    printf("pointer age: %d\n", me_pointer->age);
    printf("pointer gender: %d\n", me_pointer->gender);

    return 0;
}
