#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int data;
}Node;

typedef struct LinkedList
{
    Node *head;
}LinkedList;

Node* createNode(int data);
LinkedList* listInit(LinkedList* l);
void prepend(LinkedList *l, int data);
void printll(LinkedList *l);
void destroy(LinkedList* l);

int main(void)
{
    LinkedList* l1 = listInit(l1);
    prepend(l1, 12);
    prepend(l1, 102);

    printll(l1);

    destroy(l1);

    return 0;
}

LinkedList* listInit(LinkedList* l)
{
    l = (LinkedList*) malloc(sizeof(LinkedList));
    l->head = NULL;
    return l;
}

Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}


void prepend(LinkedList *l, int data)
{
    Node *node = createNode(data);
    if(l->head == NULL)
    {
        l->head = node;
        return;
    }

    node->next = l->head;
    l->head = node;
}

void insertAt(LinkedList *l)
{

}

void append(LinkedList *l)
{
    
}

void printll(LinkedList *l)
{
    Node* cur = l->head;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void destroy(LinkedList* l)
{
    Node* cur = l->head;
    
    while (cur != NULL)
    {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(l);
}