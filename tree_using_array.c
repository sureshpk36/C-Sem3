#include <stdio.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int size = 0;

void add(int value) {
    if (size < MAX_SIZE) {
        tree[size] = value;
        size++;
    } else {
        printf("Tree is full\n");
    }
}

int getLeftChild(int i) {
    int leftChildIndex = 2 * i + 1;
    if (leftChildIndex < size) {
        return tree[leftChildIndex];
    }
    return -1;
}

int getRightChild(int i) {
    int rightChildIndex = 2 * i + 2;
    if (rightChildIndex < size) {
        return tree[rightChildIndex];
    }
    return -1;
}

int getParent(int i) {
    if (i == 0) {
        return -1;
    }
    int parentIndex = (i - 1) / 2;
    return tree[parentIndex];
}

void printTree() {
    for (int i = 0; i < size; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int main() {
    add(10);
    add(20);
    add(30);
    add(40);
    add(50);
    add(60);

    printf("Binary Tree: ");
    printTree();

    printf("Left child of node 0: %d\n", getLeftChild(0));
    printf("Right child of node 0: %d\n", getRightChild(0));
    printf("Parent of node 2: %d\n", getParent(2));

    return 0;
}
