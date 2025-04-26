#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int* arrQueue;
    int capacity, size, front, rear;
} Queue;

Queue* init(int const capacity);
void enQueue(Queue *queue, int data);
void deQueue(Queue *queue);
int getFront(Queue *queue);
int getRear(Queue *queue);
void display(Queue *queue);
bool isFull(Queue *queue);
bool isEmpty(Queue *queue);
void destroy(Queue *queue);

int main(void)
{
    Queue *q1 = init(5);
    enQueue(q1, 16);
    enQueue(q1, 106);
    enQueue(q1, 160);
    enQueue(q1, 45);
    enQueue(q1, 405);

    deQueue(q1);
    deQueue(q1);
    deQueue(q1);

    enQueue(q1, 62);
    enQueue(q1, 69);
    enQueue(q1, 690);

    deQueue(q1);
    deQueue(q1);
    deQueue(q1);

    enQueue(q1, 23);
    enQueue(q1, 230);
    enQueue(q1, 203);


    display(q1);

    destroy(q1);
    return 0;
}

Queue* init(int const capacity)
{
    Queue* queue = malloc(sizeof(Queue));
    queue->arrQueue = malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;

    return queue;
}

void destroy(Queue *queue)
{
    free(queue->arrQueue);
    free(queue);
}

void enQueue(Queue *queue, int data)
{
    if(isFull(queue))
    {
        printf("Queue is Full\n");
        return;
    }
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->arrQueue[queue->rear] = data;
    queue->size++;
}

void deQueue(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return;
    }

    queue->front = (queue->front+1) % queue->capacity;
    queue->size--;
}

int getFront(Queue *queue)
{
    if(isEmpty(queue))
    {
        return -1;
    }
    return queue->arrQueue[queue->front];
}


int getRear(Queue *queue)
{
    if(isEmpty(queue))
    {
        return -1;
    }
    return queue->arrQueue[queue->rear];
}

void display(Queue *queue)
{
    int i = 0;
    int cur = queue->front;
    while(i < queue->size)
    {
        printf("%i ", queue->arrQueue[cur]);
        cur = (cur+1) % queue->capacity;
        i++;
    }
    printf("\n");
}

bool isFull(Queue *queue)
{
    return queue->size == queue->capacity;
}


bool isEmpty(Queue *queue)
{
    return queue->size == 0;
}