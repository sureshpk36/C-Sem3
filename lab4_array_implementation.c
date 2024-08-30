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
