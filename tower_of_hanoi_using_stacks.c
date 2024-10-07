#include <stdio.h>

#define MAX 100

typedef struct Stack {
    int top;
    int arr[MAX];
} Stack;

void initStack(Stack* s) {
    s->top = -1; 
}

void push(Stack* s, int value) {
    s->top++;
    s->arr[s->top] = value; 
}

int pop(Stack* s) {
    int value = s->arr[s->top];
    s->top--;
    return value;
}

void move(Stack* src, Stack* dest) {
    int disk = pop(src); // Pop the top disk from source
    push(dest, disk); // Push it onto the destination stack

    printf("Move disk %d from rod S to rod D\n", disk);
}

void towerOfHanoi(int n, Stack* src, Stack* dest, Stack* aux) {
    if (n == 1) {
        move(src, dest); // Move disk from source to destination
        return;
    }
    towerOfHanoi(n - 1, src, aux, dest); // Move n-1 disks from src to aux
    move(src, dest); // Move the nth disk from src to dest
    towerOfHanoi(n - 1, aux, dest, src); // Move n-1 disks from aux to dest
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

    // Solve the Tower of Hanoi
    towerOfHanoi(num_of_disks, &src, &dest, &aux); // Move disks from src to dest using aux

    return 0;
}
