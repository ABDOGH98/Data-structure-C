#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elem
{

    int data;
    struct elem *next;
    struct elem *previous;

} Element;

typedef struct
{

    Element *first;
    Element *last;
} Liste;

Liste *createListe()
{
    Liste *l;
    l = (Liste *)malloc(sizeof(Liste));
    l->first = NULL;
    l->last = NULL;
    return l;
}

Element *createElement(int d)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->data = d;
    newElement->next = NULL;
    newElement->previous = NULL;
    return newElement;
}

void addElement(Liste *L, int data)
{
    Element *newElement;
    newElement = createElement(data);
    if (L->first == NULL)
    {
        L->first = newElement;
        L->last = newElement;
        return;
    }
    L->last->next = newElement;
    newElement->previous = L->last;
    L->last = newElement;
}

void displayALL(Liste *L)
{
    Element *p;
    p = L->first;
    while (p != NULL)
    {
        printf("%p <- %p -> %p\t\t=> %d\n", p->previous, p, p->next, p->data);
        p = p->next;
    }
}

void displayLast(Liste *L)
{
    Element *p;
    p = L->last;
    while (p != NULL)
    {
        printf("%p <- %p -> %p\t\t=> %d\n", p->previous, p, p->next, p->data);
        p = p->previous;
    }
}
int main(int argc, char const *argv[])
{
    Liste *L;
    L = createListe();

    addElement(L, 1);
    addElement(L, 2);
    addElement(L, 3);
    addElement(L, 4);
    addElement(L, 5);
    addElement(L, 6);
    displayALL(L);
    printf("------------------------------------\n");
    displayLast(L);

    return 0;
}
