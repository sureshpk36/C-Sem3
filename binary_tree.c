#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* create() {
    int x;
    struct node *newnode;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = x;

    printf("Enter left child of %d:\n", x);
    newnode->left = create();

    printf("Enter right child of %d:\n", x);
    newnode->right = create();

    return newnode;
}

// Preorder traversal
void Preorder(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

// Inorder traversal
void Inorder(struct node* root) {
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

// Postorder traversal
void Postorder(struct node* root) {
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node *root = NULL;
    root = create();

    printf("\nPreorder traversal: ");
    Preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    Inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    Postorder(root);
    printf("\n");

    return 0;
}













------------------------------------------------------------




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

    if (x == -1){
        return 0;
    };

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
