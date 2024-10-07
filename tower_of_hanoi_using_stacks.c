#include <stdio.h>

#define MAX 100

typedef struct Stack {
    int top;
    int arr[MAX];
} Stack;

void initStack(Stack* s) {
    s->top = -1; // Initialize an empty stack
}

void push(Stack* s, int value) {
    s->top++; // Increment top first
    s->arr[s->top] = value; // Then assign the value to the array
}

int pop(Stack* s) {
    // Retrieve the value at the top of the stack
    int value = s->arr[s->top];
    s->top--;
    return value;
}

void move(Stack* src, Stack* dest) {
    int disk = pop(src); // Pop the top disk from source
    push(dest, disk); // Push it onto the destination stack

    // Print the move directly in the move function
    printf("Move disk %d from rod S to rod D\n", disk); // Adjust according to your desired output
}

int main() {
    Stack src, aux, dest;
    int num_of_disks;

    initStack(&src); // Initialize all stacks
    initStack(&aux);
    initStack(&dest);

    printf("Enter the number of disks: ");
    scanf("%d", &num_of_disks);

    // Push disks onto source stack
    for (int i = num_of_disks; i >= 1; i--) {
        push(&src, i); // Push disk 1, 2, ..., num_of_disks
    }

    // Move disks from src to dest
    for (int i = num_of_disks; i > 0; i--) {
        move(&src, &dest); // Move all disks from source to destination
    }

    return 0;
}
