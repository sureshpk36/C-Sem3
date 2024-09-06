#include<stdio.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top=-1;

void push(){
    if(top==MAX_SIZE-1){
        printf("stack full\n");
    }
    else{
        int num;
        printf("enter num:\n");
        scanf("%d",&num);
        top++;
        stack[top]=num; 
    }
}

void pop(){
    if(top==-1){
        printf("stack empty\n");
        return;
    }
    printf("popped value: %d \n",stack[top]);
    top--;
}

void peek(){
    if(top==-1){
        printf("stack empty");
        return;
    }
    else{
        printf("peek value:%d \n",stack[top]);
    }

}

int main(){
    push();
    push();
    push();
    push();
    pop();
    pop();
    peek();
}