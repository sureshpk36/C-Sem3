#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head =NULL;
struct node *tail =NULL;

void insert_at_beg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int num;

    printf("Enter num:\n");
    scanf("%d", &num);
    
    newnode->data = num;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {  // If the list is empty
        head = tail = newnode;
    } else {  // If the list already has elements
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void displayF(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void displayR(){
    struct node *temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    } 
    printf("\n");
}

void insert_at_pos(){
    int pos,num;
    printf("enter pos - starts with 0:");
    scanf("%d",&pos);
    printf("enter num:");
    scanf("%d",&num);
    if (pos==0){
        insert_at_beg();
    }
    else{
        struct node *temp=head;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
                if(temp==NULL){
                    return;
                }
        }
        newnode->data=num;
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
    

    }
}

void insert_at_end(){
    int num;
    printf("enter num:");
    scanf("%d",&num);
    struct node *temp=head;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->data=num;
    newnode->next=NULL;
    newnode->prev=temp;
    temp->next=newnode;
    tail=newnode; 
}

void delete_at_beg(){

    struct node *temp=head;

    if (head == NULL) {  // Check if the list is empty
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {  // If there's only one node
        head = tail = NULL;
        free(temp);
        return;
    }

    temp->next->prev=NULL;
    head=temp->next;
    free(temp);

}

void delete_at_pos(){
    int pos;
        printf("enter pos:");
        scanf("%d",&pos);

    struct node *temp=head;
    struct node *prev=NULL;
    for(int i=0;i<pos-1;i++){
        prev=temp;
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid \n");
            return;
        }
    }
    prev->next=temp->next;
    temp->next->prev=prev;
    free(temp);
}

void delete_at_end(){
    struct node *temp=head;
    struct node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    tail=prev;
}

int main(){
    insert_at_beg();
    insert_at_beg();
    insert_at_beg();
    insert_at_beg();
    displayF();
    displayR();
    insert_at_pos();
    displayF();
    insert_at_end();
    displayF();
    delete_at_beg();
    displayF();
    delete_at_pos();
    displayF();
    delete_at_end();
    displayF();


}
