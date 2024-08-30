#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *rlink, *llink;
} *lfirst = NULL, *rfirst = NULL;

void create() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter info for first node: ");
    scanf("%d", &ptr->info);
    ptr->rlink = ptr->llink = NULL;
    lfirst = rfirst = ptr;

    for (int i = 1; i < N; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter info for node %d: ", i + 1);
        scanf("%d", &newNode->info);
        newNode->llink = rfirst;
        newNode->rlink = NULL;
        rfirst->rlink = newNode;
        rfirst = newNode;
    }
}

void Rtraverse() {
    for (struct Node *ptr = rfirst; ptr; ptr = ptr->llink)
        printf("%d\n", ptr->info);
}

void Ltraverse() {
    for (struct Node *ptr = lfirst; ptr; ptr = ptr->rlink)
        printf("%d\n", ptr->info);
}

void Insert_at_Left() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter info for new node: ");
    scanf("%d", &newNode->info);
    newNode->llink = NULL;
    newNode->rlink = lfirst;
    lfirst->llink = newNode;
    lfirst = newNode;
}

void Insert_at_Right() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter info for new node: ");
    scanf("%d", &newNode->info);
    newNode->rlink = NULL;
    newNode->llink = rfirst;
    rfirst->rlink = newNode;
    rfirst = newNode;
}

void Insert_after_a_node() {
    int item;
    printf("Enter the item after which to insert: ");
    scanf("%d", &item);
    struct Node *ptr = lfirst;
    while (ptr && ptr->info != item)
        ptr = ptr->rlink;
    if (!ptr) return;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter info for new node: ");
    scanf("%d", &newNode->info);
    newNode->rlink = ptr->rlink;
    if (ptr->rlink) ptr->rlink->llink = newNode;
    ptr->rlink = newNode;
    newNode->llink = ptr;
    if (!newNode->rlink) rfirst = newNode;
}

void Delete_at_Left() {
    struct Node *ptr = lfirst;
    if (!ptr) return;
    lfirst = lfirst->rlink;
    if (lfirst) lfirst->llink = NULL;
    free(ptr);
    if (!lfirst) rfirst = NULL;
}

void Delete_at_Right() {
    struct Node *ptr = rfirst;
    if (!ptr) return;
    rfirst = rfirst->llink;
    if (rfirst) rfirst->rlink = NULL;
    free(ptr);
    if (!rfirst) lfirst = NULL;
}

void Delete_after_a_Node() {
    int item;
    printf("Enter the item after which to delete: ");
    scanf("%d", &item);
    struct Node *ptr = lfirst;
    while (ptr && ptr->rlink && ptr->info != item)
        ptr = ptr->rlink;
    if (!ptr || !ptr->rlink) return;
    struct Node *save = ptr->rlink;
    ptr->rlink = save->rlink;
    if (save->rlink) save->rlink->llink = ptr;
    free(save);
    if (!ptr->rlink) rfirst = ptr;
}

int main() {
    int choice;
    do {
        printf("Enter your choice:\n1. Create\n2. Traverse Right\n3. Traverse Left\n4. Insert at Left\n5. Insert at Right\n6. Insert after Node\n7. Delete at Left\n8. Delete at Right\n9. Delete after Node\n10. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: Rtraverse(); break;
            case 3: Ltraverse(); break;
            case 4: Insert_at_Left(); break;
            case 5: Insert_at_Right(); break;
            case 6: Insert_after_a_node(); break;
            case 7: Delete_at_Left(); break;
            case 8: Delete_at_Right(); break;
            case 9: Delete_after_a_Node(); break;
            case 10: exit(0);
            default: printf("Wrong choice\n");
        }
    } while (choice != 10);
    return 0;
}
