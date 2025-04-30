#include <stdio.h>

#define CAPACITY 10

int Stack[CAPACITY];
int size = 0, top = -1;

void push(int data);
void display();
void pop();
int peek();

int main(void)
{

    pop();

    printf("peek: %i\n", peek());
    display();
    return 0;
}

void push(int data)
{
    if(size == CAPACITY)
    {
        printf("Stack OverFlow\n");
        return;
    }
    Stack[++top] = data;
    size++;
}

void pop()
{
    if(size == 0)
    {
        printf("Stack UnderFlow\n");
        return;
    }
    top--;
    size--;
}

int peek()
{
    if(size == 0)
    {
        printf("Stack UnderFlow\n");
        return -9999;
    }
    return Stack[top];
}

void display()
{
    if(size == 0)
    {
        printf("Stack UnderFlow\n");
        return;
    }
    for(int i = top; i >= 0; i--)
    {
        printf("%i\n", Stack[i]);
    }
}