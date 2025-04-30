#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
    int* arrStack;
    int capacity, size, top;
} Stack;

void push(Stack *stack, int data);
Stack* init(int const CAPACITY);
void display(Stack *stack);
void pop(Stack *stack);
int peek(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void destroy(Stack *stack);

int main(void)
{
    Stack *s1 = init(2);

    Stack *s2 = init(20);

    push(s2, 34);

    push(s1, 55);
    push(s1, 550);
    push(s1, 505);

    pop(s1);
    pop(s1);

    display(s2);

    destroy(s1);
    destroy(s2);
    return 0;
}

Stack* init(int const CAPACITY) //Create Stack
{
    Stack* stack = malloc(sizeof(Stack));
    stack->arrStack = malloc(sizeof(int) * CAPACITY);
    stack->capacity = CAPACITY;
    stack->size = 0;
    stack->top = -1;

    return stack;
}

void destroy(Stack *stack)
{
    free(stack->arrStack);
    free(stack);
}

void push(Stack *stack, int data)
{
    if(isFull(stack))
    {
        printf("Stack OverFlow\n");
        return;
    }
    stack->arrStack[++stack->top] = data;
    stack->size++;
}

void pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack UnderFlow\n");
        return;
    }
    stack->top--;
    stack->size--;
}

int peek(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack UnderFlow\n");
        return -1;
    }

    return stack->arrStack[stack->top];
}

void display(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack UnderFlow\n");
        return;
    }

    for(int i = stack->top; i >= 0; i--)
    {
        printf("%i\n", stack->arrStack[i]);
    }
}

bool isFull(Stack *stack)
{
    return stack->size == stack->capacity;
}

bool isEmpty(Stack *stack)
{
    return stack->size == 0;
}
