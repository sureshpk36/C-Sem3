#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create() {
    int x;
    struct node *newnode;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = x;

    printf("Enter left child of %d:\n", x);
    newnode->left = create();

    printf("Enter right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

int main() {
    struct node *root = NULL;
    root = create();

    // You can add a function to display or further manipulate the tree here

    return 0;
}
