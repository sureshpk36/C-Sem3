#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 30

struct stack {
    int data;
    struct stack *next;  
};

struct stack *top =NULL;


void push(){
    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    int num;
    printf("enter num:\n");
    scanf("%d",&num);
    p->data=num;
    p->next=top;
    top=p;
}

void pop(){
    if(top==NULL){
        printf("stack is empty");
        return;
    
    }
    struct stack *temp=top;
    printf("poped value %d \n",top->data);
    top=top->next;
    free(temp);
}

void peek(){
        if(top==NULL){
        printf("stack is empty");
        return;
    
    }

    printf("peek value: %d",top->data);
}

int main(){
    push();
    push();
    push();
    pop();
    pop();
    peek();

}

