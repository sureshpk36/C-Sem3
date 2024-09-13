#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *head = NULL, *last = NULL;  // Use both head and last pointers

void create();
void traverse();
void push();
void pop();

int main() {
    int choice;
    do {
        printf("\n1. Create Queue\n2. Traverse\n3. Push\n4. Pop\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: create(); break;
            case 2: traverse(); break;
            case 3: {
                int value;
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 4: pop(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void create() {
    int n, i, value;
    printf("How many nodes? ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        
        push(value);  // Use push to add nodes
    }
}

void traverse() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void push(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;

    if (head == NULL) {  // If list is empty
        head = last = newNode;
    } else {
        last->next = newNode;  // Attach newNode to the last node
        last = newNode;  // Update last to newNode
    }
}

void pop() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    struct Node *temp = head;
    head = head->next;

    // If the list becomes empty, reset last to NULL
    if (head == NULL) {
        last = NULL;
    }

    printf("Popped: %d\n", temp->info);
    free(temp);
}
