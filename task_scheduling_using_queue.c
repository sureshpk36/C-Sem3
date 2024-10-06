#include <stdio.h>
#include <string.h>

#define MAX 4

struct Task {
    char name[20];
};

struct Queue {
    struct Task tasks[MAX];
    int front, rear;
};

void Enqueue(struct Queue *q, struct Task task) {
    if (q->rear < MAX - 1) {
        q->tasks[++q->rear] = task;
        if (q->front == -1) q->front = 0;
    } else {
        printf("Queue is full\n");
    }
}

struct Task Dequeue(struct Queue *q) {
    struct Task task = {"Empty"};
    if (q->front != -1) {
        task = q->tasks[q->front++];
        if (q->front > q->rear) q->front = q->rear = -1;
    } else {
        printf("Queue is empty\n");
    }
    return task;
}

int main() {
    struct Queue q = {-1, -1};
    
    Enqueue(&q, (struct Task){"Task 1"});
    Enqueue(&q, (struct Task){"Task 2"});

    for (int i = 0; i < 2; i++) {
        struct Task task = Dequeue(&q);
        printf("Executing: %s\n", task.name);
    }

    return 0;
}
