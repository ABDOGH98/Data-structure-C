#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int data;
    struct elem *leftChild;
    struct elem *rightChild;
} Element;

Element *createElement(int data)
{
    Element *e;
    e = (Element *)malloc(sizeof(Element));
    e->leftChild=NULL;
    e->rightChild=NULL;
    e->data=data;
    return e;
}
void displayPrefixe(Element *BT)
{
    
    if (BT!=NULL)
    {
        printf("%d | ",BT->data);
        displayPrefixe(BT->leftChild);
        displayPrefixe(BT->rightChild);
    }
}

void displayInfixe(Element *BT)
{
    if (BT!=NULL)
    {
        displayInfixe(BT->leftChild);
        printf("%d | ",BT->data);
        displayInfixe(BT->rightChild);
    }
}
void addElement(Element **BT ,int data)
{
    Element *newElement ;
    newElement = createElement(data);
    if ((*BT)==NULL)
    {
        (*BT) = newElement;
        return ;
    }
    Element *position = NULL ;
    position= *BT ;
    while (position->leftChild!=NULL && position->rightChild !=NULL)
    {
        if (data >= position->data)
        {
            position = position->rightChild ;
        }
        else if(data < position->leftChild)
        {
            position = position->leftChild ;
        }
    }
   if (data>=position->data)
   {
       position->rightChild = newElement ;
   }
   else
   {
        position->leftChild = newElement ;
   }
}
void insertRec(Element **BT ,int data )
{
    Element *newElement ;
    newElement = createElement(data);
    
    if ((*BT)==NULL)
    {
        (*BT) = newElement;
        return ;
    }
    if (data >= (*BT)->data)
    {
        insertRec(&(*BT)->rightChild,data);
    }
    else
    {
        insertRec(&(*BT)->leftChild,data);
    }

}



int main(int argc, char const *argv[])
{
    Element *BT = NULL;
    // e1=createElement(5);
    //e2=createElement(2);
    // e3=createElement(3);
    // e4=createElement(4);
    // e1->leftChild=e2;
    // e1->rightChild=e4;
    // e2->leftChild=e3;
 
    // addElement(&BT,5);
    // addElement(&BT,3);
    // addElement(&BT,7);
    // addElement(&BT,1);
    // addElement(&BT,4);
    // addElement(&BT,6);
    insertRec(&BT,5);
    insertRec(&BT,3);
    insertRec(&BT,7);
    insertRec(&BT,1);
    insertRec(&BT,4);
    insertRec(&BT,6);
    displayInfixe(BT);
    return 0;
}
