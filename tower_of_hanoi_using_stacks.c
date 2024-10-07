#include <stdio.h>

#define MAX 100

typedef struct Stack {
    int top;
    int arr[MAX];
} Stack;

void initStack(Stack* s) {
    s->top = -1; // Initialize an empty stack
}

int isEmpty(Stack* s) {
    return s->top == -1; // Check if stack is empty
}

void push(Stack* s, int value) {
    s->arr[++(s->top)] = value; // Push a value onto the stack
}

int pop(Stack* s) {
    return s->arr[(s->top)--]; // Pop a value from the stack
}

void moveDisk(char fromRod, char toRod, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod); // Show disk movement
}

void move(Stack* src, Stack* dest, char s, char d) {
    int disk = pop(src);     // Pop the top disk from source
    push(dest, disk);        // Push it onto the destination stack
    moveDisk(s, d, disk);    // Print the move
}

int main() {
    Stack src, aux, dest;
    int num_of_disks;

    initStack(&src);   // Initialize all stacks
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
        move(&src, &dest, 'S', 'D'); // Move all disks from source to destination
    }

    return 0;
}
