#include <stdio.h>
#include <string.h>

#define MAX 4

struct Queue {
    char tasks[MAX][20];
    int front, rear;
};

void Enqueue(struct Queue* q, const char* task) {
    if (q->rear < MAX - 1) {
        q->rear++; // Increment rear first
        strcpy(q->tasks[q->rear], task); // Copy the task
        if (q->front == -1){
             q->front = 0;}// Set front if it's the first task
    } else {
        printf("Queue is full\n");
    }
}

void Dequeue(struct Queue* q) {
    if (q->front != -1) {
        printf("Executing: %s\n", q->tasks[q->front++]); // Execute the task
        if (q->front > q->rear){
             q->front = q->rear = -1;} // Reset when queue is empty
    } else {
        printf("Queue is empty\n");
    }
}

int main() {
    struct Queue q = { .front = -1, .rear = -1 }; // Initialize queue
    Enqueue(&q, "Task 1");
    Enqueue(&q, "Task 2");
    Dequeue(&q); // Execute Task 1
    Dequeue(&q); // Execute Task 2
    Dequeue(&q); // Attempt to dequeue from an empty queue
    return 0;
}
