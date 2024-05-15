#include <stdio.h>
#define MAX_SIZE 15

//implementation of stack in c
struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int value) {
    s->top++;
    s->items[s->top] = value;
}

int pop(struct Stack *s) {
    int popped = s->items[s->top];
    s->top--;
    return popped;
}

void display(struct Stack *s) {
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    for (int i = 1; i <= 15; i++) {
        //pushing an element
        push(&stack, i);
    }
    display(&stack);

    // removing an element
    int removed = pop(&stack);
    printf("Popped element: %d\n", removed);

    display(&stack);

    return 0;
}
