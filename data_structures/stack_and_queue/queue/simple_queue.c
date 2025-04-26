#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

int queue[CAPACITY];

int size = 0, front = 0, rear = -1;

bool isEmpty();
bool isFull();
void display();
void deQueue();
void enQueue(int data);
int getFront();
int getRear();

int main(void)
{
    enQueue(56);
    enQueue(5132);
    enQueue(729);
    enQueue(21);

    deQueue();

    enQueue(75);
    enQueue(955);

    deQueue();
    deQueue();
    
    printf("front: %i\n", getFront());
    printf("rear: %i\n", getRear());

    display();
    return 0;
}

void enQueue(int data)
{
    if(isFull())
    {
        printf("Queue is full\n");
        return;
    }

    queue[++rear] = data;
    size++;
}

void deQueue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    front++;
    size--;
}

int getFront()
{
    return queue[front];
}

int getRear()
{
    return queue[rear];
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%i ", queue[i]);
    }
    printf("\n");
}

bool isFull()
{
    return size == CAPACITY;
}

bool isEmpty()
{
    return size == 0;
}