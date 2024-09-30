#include <stdio.h>

#define MAX 15  // Maximum number of nodes in the tree

int tree[MAX];  // Global array to represent the tree

// Insert a node in the tree using pointers
void insert(int value, int index) {
    if (index != MAX - 1) {  // Change condition here
        tree[index] = value;
    } else {
        printf("Cannot insert at the last index\n");
    }
}

// Display the tree in an array format
void display(int size) {
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1) {
            printf("Node at index %d: %d\n", i, tree[i]);
        }
    }
}

int main() {
    // Initialize all elements to -1 (indicating an empty node)
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }

    // Insert nodes into the tree
    insert(10, 0);  // Root node
    insert(20, 1);  // Left child of root
    insert(30, 2);  // Right child of root
    insert(40, 3);  // Left child of node at index 1
    insert(50, 4);  // Right child of node at index 1
    
    // Display the tree
    display(MAX);

    return 0;
}
