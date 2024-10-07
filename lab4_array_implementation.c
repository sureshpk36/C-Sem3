#include <stdio.h>
#define MAX_SIZE 50

int arr[MAX_SIZE];
int size = -1;  // Initialize as -1 to indicate the array is empty

void display() {
    if (size == -1) {  // Array is empty when size is -1
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i <= size; i++) // Loop from 0 to size
        printf("%d\t", arr[i]);
    printf("\n");
}

void insertAtPos(int pos, int val) {
    if (size == MAX_SIZE - 1) {  // Adjust condition for MAX_SIZE
        printf("Array is full\n");
        return;
    }
    if (pos < 0 || pos > size + 1) {  // Adjust position check
        printf("Invalid position\n");
        return;
    }

    for (int i = size; i >= pos; i--) {  // Adjust loop range
        arr[i + 1] = arr[i];
    }

    arr[pos] = val;
    size++;  // Increment size after insertion
    printf("Inserted %d at pos %d\n", val, pos);
}

void deleteFromPos(int pos) {
    if (size == -1) {  // Array is empty when size is -1
        printf("Array is empty\n");
        return;
    }
    if (pos < 0 || pos > size) {
        printf("Invalid position\n");
        return;
    }

    int del = arr[pos];
    for (int i = pos; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    size--;  // Decrement size after deletion
    printf("Deleted %d at pos %d\n", del, pos);
}

void searchElement(int val) {
    for (int i = 0; i <= size; i++) {  // Adjust loop range
        if (arr[i] == val) {
            printf("Element %d found at position %d\n", val, i);
            return;
        }
    }
    printf("Element %d not found\n", val);
}

int main() {
    insertAtPos(0, 10);
    insertAtPos(1, 20);
    insertAtPos(2, 30);
    display();

    deleteFromPos(1);
    display();

    searchElement(30);
    searchElement(50);

    return 0;
}









--------------------------------------------------------------------------------------------------------------------------------------------


    




#include <stdio.h>

int main()
{
    int a[10] = {5,6,4,8,23,51,420}, pos,item,i, j;

    printf("Enter item and position ");
    scanf("%d%d", &item, &pos);

    for (i = 6; i >= pos; i--)
        a[i+1] = a[i];
    
    a[pos] = item;

    printf("\nAfter addition\n");
    for (j = 0; j <= 7; j++)
        printf("%d\n", a[j]);

    printf("\nEnter position ");
    scanf("%d", &pos);

    for (i = pos; i <= 8; i++)
        a[i] = a[i+1];
    printf("\nArray after deletion \n");
    for (j = 0; j <= 6; j++)
        printf("%d\n", a[j]);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; } *head = NULL;

void delete_at_position(int pos) {
    if (!head) return;
    struct Node *temp = head, *prev = NULL;
    if (pos == 0) { head = temp->next; free(temp); return; }
    for (int i = 0; i < pos && temp; i++) { prev = temp; temp = temp->next; }
    if (temp) { prev->next = temp->next; free(temp); }
}

int main() {
    head = malloc(sizeof(struct Node)); head->data = 1;
    head->next = malloc(sizeof(struct Node)); head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node)); head->next->next->data = 3;
    head->next->next->next = NULL;

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    delete_at_position(pos);

    for (struct Node *temp = head; temp; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL\n");

    return 0;
}
