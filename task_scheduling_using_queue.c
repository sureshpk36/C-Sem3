#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

typedef struct {
    char name[20];
} Task;

typedef struct {
    Task tasks[MAX];
    int front;
    int rear;
} Queue;

void Enqueue(Queue *q, Task task) {
    if (q->rear < MAX - 1) {
        q->tasks[++q->rear] = task;
        if (q->front == -1) {
            q->front = 0;
        }
    } else {
        printf("Queue is full\n");
    }
}

Task Dequeue(Queue *q) {
    Task task = {"Empty"};
    if (q->front != -1) {
        task = q->tasks[q->front++];
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset queue when empty
        }
    } else {
        printf("Queue is empty\n");
    }
    return task;
}

int main() {
    Queue q = {.front = -1, .rear = -1};

    Enqueue(&q, (Task){"Task 1"});
    Enqueue(&q, (Task){"Task 2"});

    for (int i = 0; i < 2; i++) {
        Task task = Dequeue(&q);
        printf("Executing: %s\n", task.name);
    }

    return 0;
}
