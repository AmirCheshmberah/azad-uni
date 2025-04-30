#include <iostream>

using namespace std;

constexpr int DEFAULT_CAPACITY = 8;

class Stack
{
public:
    Stack() = default;

    Stack(const int CAPACITY)
    {
        capacity = CAPACITY;
        arrStack[capacity];
    }

    void push(int data)
    {
        if(isFull())
        {
            cout << "Stack OverFlow\n";
            return;
        }
        arrStack[++top] = data;
        size++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }
        top--;
        size--;
    }

    int peek()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arrStack[top];
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }
        for(int i = top; i >= 0; i--)
        {
            cout << arrStack[i] << '\n';
        }
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

private:
    int arrStack[DEFAULT_CAPACITY];
    int capacity = DEFAULT_CAPACITY;
    int size = 0;
    int top = -1;
};


int main(void)
{

    return 0;
}