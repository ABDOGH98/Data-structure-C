#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct elem{

    int data ;
    struct elem *next;

}Element;

typedef struct{

    Element *first;
    Element *last;
}Liste;

Liste *createListe()
{
    Liste *l ;
    l = (Liste *)malloc(sizeof(Liste));
    l->first=NULL;
    l->last=NULL;
    return l ;
}

Element *createElement(int d)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->data = d ;
    newElement->next =NULL;
    return newElement ;
}   

void addElement(Liste *L ,int data)
{
    Element *e=NULL;
    e=createElement(data);

    if (L->first == NULL || L->last==NULL)
    {
        L->first = e ;
        L->last = e ;
        return ;
    }
    L->last->next = e ;
    L->last = e;   
}

void displayALL(Liste *L)
{
    Element *p ;
    p=L->first;
    while (p !=NULL)
    {
        printf("First : %p -> %d\n",p->next,p->data);
        //printf("Last : %p -> %d\n",L->last->next,L->last->data);

        p = p->next ;
    }
    
}

int main(int argc, char const *argv[])
{
    Liste *L=NULL ;
    L = createListe();
    addElement(L,1);
    addElement(L,2);
    addElement(L,3);
    addElement(L,4);
    displayALL(L);

    //printf("First : %p -> %d\n",L->first->next,L->first->data);
    //printf("Last : %p -> %d\n",L->last->next,L->last->data);
    //displayALL(L);
    return 0;
}
