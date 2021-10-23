#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int data;
    struct elem *next;
} Element;

Element *createElement(int c)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->data = c;
    newElement->next = NULL;
    return newElement;
}
int isEmpty(Element *pil)
{
    if (pil == NULL)
        return 1;
    else
        return 0;
}

void push(Element **pil, int c)
{
    Element *newElement;
    newElement = createElement(c);
    newElement->next = *pil;
    *pil = newElement;
}

void pop(Element **pil)
{
    if (*pil == NULL)
        return;

    Element *tmp;
    tmp = (*pil);
    (*pil) = (*pil)->next;

    free(tmp);
    tmp = 0;
}

int peek(Element *pil)
{
    if (pil == NULL)
        return -1;
    return pil->data;
}

int main(int argc, char const *argv[])
{
    Element *pil;
    pil = NULL;
    int a;
    push(&pil, 1);
    push(&pil, 2);
    a = peek(pil);
    printf("%d", a);
    push(&pil, 3);
    a = peek(pil);
    printf("%d", a);
    pop(&pil);
    a = peek(pil);
    printf("%d", a);
    return 0;
}
