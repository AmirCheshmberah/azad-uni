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
    int size;
}LinkedList;

Node* createNode(int data);
LinkedList* listInit(LinkedList* l);
void prepend(LinkedList *l, int data);
void printll(LinkedList *l);
void destroy(LinkedList* l);
void append(LinkedList *l, int data);
void insertAt(LinkedList *l, int data, int loc);
int main(void)
{
    LinkedList* l1 = listInit(l1);
    prepend(l1, 12);
    prepend(l1, 102);
    prepend(l1, 1020);

    printf("%d\n", l1->size);

    append(l1, 45);
    append(l1, 405);
    append(l1, 425);

    insertAt(l1, 20, 3);
    insertAt(l1, 23, 5);
    printll(l1);

    destroy(l1);

    return 0;
}

LinkedList* listInit(LinkedList* l)
{
    l = (LinkedList*) malloc(sizeof(LinkedList));
    l->head = NULL;
    l->size = 0;
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
        l->size++;
        return;
    }

    node->next = l->head;
    l->head = node;
    l->size++;
}

void insertAt(LinkedList *l, int data, int loc)
{
    
    if(loc == 1)
    {
        prepend(l, data);
        return;
    }

    if(loc == l->size+1)
    {
        append(l, data);
        return;
    }

    if(loc < 1 || loc > l->size)
    {
        return;
    }

    Node *node = createNode(data);
    if(l->head == NULL)
    {
        l->head = node;
        l->size++;
        return;
    }

    Node* cur = l->head;
    for (int i = 0; i < loc - 2; i++)
    {
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;
    l->size++;
}

void append(LinkedList *l, int data)
{
    Node *node = createNode(data);
    if(l->head == NULL)
    {
        l->head = node;
        l->size++;
        return;
    }

    Node* cur = l->head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = node;
    l->size++;
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