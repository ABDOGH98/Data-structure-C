#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{

    int x;
    int y;

} Points;

typedef struct elem
{
    Points *points;
    struct elem *next;
    struct elem *previous;
} Elements;

typedef struct
{

    Elements *first;
    Elements *last;
    int size;

} Liste;

void createListe(Liste **L)
{
    *L = (Liste *)malloc(sizeof(Liste));
    (*L)->first = NULL;
    (*L)->last = NULL;
    (*L)->size = 0;
}

void createPoints(Points **p, int x, int y)
{
    *p = (Points *)malloc(sizeof(Points));
    (*p)->x = x;
    (*p)->y = y;
}

void addPoints(Liste *L, Points *p)
{
    Elements *newElement;
    newElement = (Elements *)malloc(sizeof(Elements));
    //newElement->points = (Points *)malloc(sizeof(Points));
    if (L->first == NULL)
    {
        newElement->points = p;
        newElement->next = NULL;
        newElement->previous = NULL;
        L->first = newElement;
        L->last = newElement;
        L->size++;
        return;
    }

    newElement->points = p;
    newElement->next = NULL;
    newElement->previous = L->last;

    L->last->next = newElement;
    L->last = newElement;
    L->size++;
}

void removeElement(Liste **L, Points *p)
{
    Elements *e;
    e = (*L)->first;
    while (e != NULL)
    {
        if (e->points == p)
        {
            Elements *tmp;
            tmp = e;
        }

        e = e->next;
    }
}

void displayAll(Liste *L)
{

    //Elements *e ;
    while (L->last != NULL)
    {
        printf("x = %d et y = %d\n", L->last->points->x, L->last->points->y);
        L->last = L->last->previous;
    }
    printf("size = %d", L->size);
}

int main(int argc, char const *argv[])
{
    Liste *L;
    createListe(&L);

    Points *p1, *p2, *p3;

    createPoints(&p1, 1, 1);
    createPoints(&p2, 2, 2);
    createPoints(&p3, 3, 3);

    addPoints(L, p1);
    addPoints(L, p2);
    addPoints(L, p3);
    displayAll(L);
    return 0;
}
