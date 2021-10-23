#include <stdlib.h>
#include <stdio.h>

typedef struct elem{

    int data;
    struct elem *next;
    int status;
    
}Element;

typedef struct{

    Element *tabFirst;
    Element *tabLast;
}Tab;

typedef struct{

    Tab *T;
    Element *first;
    Element *last;
}Queue;

Tab *initializeTab(Element e[] , int N)
{
    Tab *T;
    T=(Tab *)malloc(sizeof(Tab));
    T->tabFirst =(Element *) (e+0);
    T->tabLast =(Element *) (e+N-1);
    for (int i = 0; i < N; i++)
    {
        e[i].next = (e+i+1);
        e[i].status=0;
    }
    e[N-1].next=T->tabFirst;
    return T;
}

Queue *initializQueue(Tab *T)
{
    Queue *Q;
    Q=(Queue *)malloc(sizeof(Queue));
    Q->first=T->tabFirst;
    Q->last=T->tabFirst;
    Q->T = T ;
    Q->first->status=0;
    Q->last->status=0;
    return Q;
}

void enqueue(Queue *Q,int data )
{
    
    if (Q->first->status==0)
    {
        Q->first = Q->T->tabFirst ;
        Q->first->data = data;  
        Q->last = Q->T->tabFirst ;
        Q->first->status = 1 ;
        return ; 
    }
    if (Q->last->next->status==0)
    {
        Q->last = Q->last->next ;
        Q->last->data = data ;
        Q->last->status = 1 ;
    }
    else
    {
        printf("Queue N/A to inser %d",data);
    }
}
void dequeue(Queue *Q)
{
    if (Q->first->status==0)
    {
        printf("Queue was empty !!!");
        return ;
    }
    
    Q->first->status = 0 ;
    Q->first = Q->first->next;
}
int getFirst(Queue *Q)
{
   if (Q->first->status==0)
    {
        printf("Queue was empty !!!");
        
    }
    else
    {
        return Q->first->data ;
    }
    
    
}
int main(int argc, char const *argv[])
{
    Element tabE[5];
    Tab *T = initializeTab(tabE,5);
    Queue *Q = initializQueue(T);
    
    enqueue(Q,1);
    printf("\n%d\n",getFirst(Q));
    dequeue(Q);
    enqueue(Q,2);
    enqueue(Q,3);
    enqueue(Q,4);
    enqueue(Q,5);
    enqueue(Q,6);
    printf("\n%d\n",getFirst(Q));
    dequeue(Q);
    printf("\n%d\n",getFirst(Q));
    dequeue(Q);
    printf("\n%d\n",getFirst(Q));
    dequeue(Q);
    printf("\n%d\n",getFirst(Q));
    dequeue(Q);
    printf("\n%d\n",getFirst(Q));
    dequeue(Q);
    dequeue(Q);
    

    return 0;
}
