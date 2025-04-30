#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

int queue[CAPACITY];

int size = 0, front = 0, rear = -1;

bool isEmpty();
bool isFull();
void display_array();
void display();
void deQueue();
void enQueue(int data);
int getFront();
int getRear();
int getSize();

int main(void)
{
    enQueue(56);
    enQueue(5132);
    enQueue(729);
    enQueue(21);

    deQueue();

    enQueue(75);
    enQueue(955);
    enQueue(12);
    enQueue(52);

    enQueue(527);
    enQueue(123);
    enQueue(46);

    deQueue();
    deQueue();

    enQueue(77);
    enQueue(799);
    
    deQueue();
    deQueue();
    deQueue();
    deQueue();

    enQueue(23);
    enQueue(237);
    enQueue(2037);
    
    printf("front: %i\n", getFront());
    printf("rear: %i\n", getRear());
    printf("size: %i\n", getSize());

    printf("display:\n");
    display();
    printf("\ndisplay_array:\n");
    display_array();
    return 0;
}

void enQueue(int data)
{
    if(isFull())
    {
        printf("Queue is full\n");
        return;
    }
    rear = (rear+1) % CAPACITY;
    queue[rear] = data;
    size++;
}

void deQueue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    front = (front+1) % CAPACITY;
    size--;
}

int getFront()
{
    if(isEmpty())
    {
        return -1;
    }
    return queue[front];
}

int getRear()
{
    if(isEmpty())
    {
        return -1;
    }
    return queue[rear];
}

int getSize()
{
    return size;
}

void display()
{
    int i = 0;
    int cur = front;
    while(i < size)
    {
        printf("%i ",queue[cur]);
        cur = (cur+1) % CAPACITY;
        i++;
    }
}

void display_array()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    for(int i = 0; i < CAPACITY; i++)
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