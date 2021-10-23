#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{

    int data;
    struct elem *leftChild;
    struct elem *rightChild;
} Element;

typedef struct p
{

    Element *e;
    struct p *next;

} Pile;

Element *createElement(int data)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));

    newElement->data = data;
    newElement->leftChild = NULL;
    newElement->rightChild = NULL;

    return newElement;
}
Pile *initialize()
{
    Pile *p;
    p = (Pile *)malloc(sizeof(Pile));
    p->next = NULL;
    p->e = NULL;
    return p;
}
void push(Pile **p, Element *e)
{
    Pile *newElement;
    newElement = initialize();
    newElement->e = e;
    newElement->next = (*p);
    (*p) = newElement;
}
Element *getFirst(Pile *p)
{
    if (p == NULL)
    {
        return NULL;
    }

    return p->e;
}
void pop(Pile **p)
{
    Pile *tmp;
    tmp = (*p);
    (*p) = (*p)->next;
    free(tmp);
    tmp = 0;
}
void displayPrefixe_Rec(Element *BT)
{
    if (BT != NULL)
    {
        printf("%d | ", BT->data);
        displayPrefixe_Rec(BT->leftChild);
        displayPrefixe_Rec(BT->rightChild);
    }
}

void displayPrefixe_Iterative(Element *BT)
{
    Pile *p;
    p = initialize();
    push(&p, BT);

    while (p->next != NULL)
    {
        BT = getFirst(p);
        printf("%d | ", BT->data);
        pop(&p);
        if (BT->rightChild != NULL)
        {
            push(&p, BT->rightChild);
        }
        if (BT->leftChild != NULL)
        {
            push(&p, BT->leftChild);
        }
    }
}
int main(int argc, char const *argv[])
{
    Element *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8, *e9, *e10;
    e1 = createElement(1);
    e2 = createElement(2);
    e3 = createElement(3);
    e4 = createElement(4);
    e5 = createElement(5);
    e6 = createElement(6);
    e7 = createElement(7);
    e8 = createElement(8);
    e9 = createElement(9);
    e10 = createElement(10);

    e1->leftChild = e2;
    e1->rightChild = e3;

    e2->leftChild = e4;
    e2->rightChild = e5;

    e5->leftChild = e8;

    e3->leftChild = e6;
    e3->rightChild = e7;

    e7->leftChild = e9;
    e7->rightChild = e10;

    displayPrefixe_Rec(e1);
    printf("\n");
    displayPrefixe_Iterative(e1);

    return 0;
}
