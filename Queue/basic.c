#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elem
{
    int data;
    struct elem *netx;
}Element;

typedef struct
{
    Element *first;
    Element *last;
}Queue;

Element *createElement(int data)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->data=data;
    newElement->netx=NULL;

    return newElement;
}

Queue *createQueue()
{
    Queue *Q ;
    Q = (Queue *)malloc(sizeof(Queue));
    Q->first=NULL;
    Q->last=NULL;
    return Q ;
}

void enqueue(Queue *Q , int data)
{
    Element *newElement ;
    newElement=createElement(data);
    if (Q->first==NULL)
    {
        Q->first=newElement;
        Q->last=newElement;
        return;
    }
    Q->last->netx=newElement;
    Q->last=newElement;
}

void getFirst(Queue *Q)
{
    printf("%d",Q->first->data);
}

void dequeue(Queue *Q)
{
    if (Q->first==NULL)
    {
        return;
    }
    Element *tmp;
    tmp = Q->first ;
    Q->first = Q->first->netx ;
    free(tmp);
    tmp=NULL;
    
}
int main(int argc, char const *argv[])
{
    Queue *queue;
    queue=createQueue();
    enqueue(queue,1);
    enqueue(queue,2);
    getFirst(queue);
    dequeue(queue);
    getFirst(queue);
    dequeue(queue);
    enqueue(queue,1);
    getFirst(queue);
    
    return 0;
}
