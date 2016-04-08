#include <stdio.h>
#include <string.h>

#define STACK_SIZE 50

struct stack {
    int values[STACK_SIZE];
    int* top;
};

void init_stack(struct stack *stack) {
    for(int i = 0; i < STACK_SIZE; i++) {
        stack->values[i] = 0;
    }
    stack->top = stack->values;
}

int push(struct stack *stack, int value) {
    if(stack->top == (stack->values + STACK_SIZE)) {
        return -1;
    }

    *(stack->top) = value;
    ++(stack->top);

    return 0;
}

int pop(struct stack *stack) {
    if(stack->top == stack->values) {
        return -1;
    }

    --(stack->top);
    int value = *(stack->top);
    *(stack->top) = 0;

    return value;
}

void print_stack(struct stack *stack) {
    for(int i = 0; i < STACK_SIZE; i++) {
        printf("%d ", stack->values[i]);
    }
    printf("\n");
}

int get_int_value_from_char(char c);

#define NUMBER_OF_PARAMS 2

int main(int argc, char const *argv[]) {

    if(argc != NUMBER_OF_PARAMS) {
        printf("El número de parámetros no es el correcto.\n");
        return -1;
    }

    struct stack my_stack;
    init_stack(&my_stack);

    for(int i = 0; i < strlen(argv[1]); i++) {
        switch(argv[1][i]) {
            case '+': {
                int b = pop(&my_stack);
                int a = pop(&my_stack);
                push(&my_stack, a + b);
                break;
            }
            case '-': {
                int b = pop(&my_stack);
                int a = pop(&my_stack);
                push(&my_stack, a - b);
                break;
            }
            case '*': {
                int b = pop(&my_stack);
                int a = pop(&my_stack);
                push(&my_stack, a * b);
                break;
            }
            case '/': {
                int b = pop(&my_stack);
                int a = pop(&my_stack);
                push(&my_stack, a / b);
                break;
            }
            default: {
                int value = get_int_value_from_char(argv[1][i]);
                push(&my_stack, value);
                break;
            }
        }

        print_stack(&my_stack);
    }

    printf("El resultado es: %d\n", pop(&my_stack));

    return 0;
}

int get_int_value_from_char(char c) {
    return (int)(c - '0');
}
