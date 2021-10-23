#include <stdlib.h>
#include <stdio.h>

typedef struct elem{

    int data;
    struct elem *leftChild;
    struct elem *rightChild;
    int level ; 
}Element;

typedef struct p{

    Element *e;
    struct p *next;

}Pile;

Element *createElement(int data)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));

    newElement->data=data;
    newElement->leftChild=NULL;
    newElement->rightChild=NULL;
    newElement ->level = 0 ;

    return newElement;
}

Pile *initialize()
{
    Pile *p;
    p=(Pile *)malloc(sizeof(Pile));
    p->next = NULL;
    p->e=NULL;
    
    return p ;
}
void push(Pile **p , Element *e)
{
    Pile *newElement;
    newElement = initialize();
    newElement->e =e ;
    newElement->next = (*p);
    (*p)=newElement ;
    
}
Element *getFirst(Pile *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    
    return p->e ;
}
void pop(Pile **p)
{
    if ((*p)->next == NULL)
    {
        return ;
    }
    
    Pile *tmp ;
    tmp = (*p);
    (*p) = (*p)->next;
    free(tmp);
    tmp = NULL ;
}

void displayPrefixe_Rec(Element *BT)
{
    if (BT !=NULL)
    {
        
        displayPrefixe_Rec(BT->leftChild);
        displayPrefixe_Rec(BT->rightChild);
        printf("%d | ",BT->data);
    }
    
}

void setHight(Element *BT)
{
    int left = 0  ;
    int right = 0 ;
    Pile *p , *leftVisited  ,*rightVisited;
    Element *leftE  , *rightE ;
    leftVisited = initialize();
    rightVisited = initialize();
    p = initialize();

    push(&p,BT);
    push(&leftVisited,BT);
    push(&rightVisited,BT);
    BT=getFirst(p);
    while (p->next!=NULL)
    {
        
        if (getFirst(leftVisited) != NULL && getFirst(leftVisited)->leftChild!=NULL   )
        {
            leftE = getFirst(leftVisited)->leftChild ;
            pop(&leftVisited);
            push(&leftVisited,leftE);
            left++;
        }
        else if (getFirst(leftVisited) != NULL && getFirst(leftVisited) != getFirst(p) && getFirst(leftVisited)->rightChild!=NULL)
        {    
            
            leftE = getFirst(leftVisited)->rightChild ;
            pop(&leftVisited);
            push(&leftVisited,leftE);
            left++;
        }
        else
        {
            pop(&leftVisited);
        }
        if (getFirst(rightVisited)!=NULL && getFirst(rightVisited)->rightChild!=NULL)
        {
            rightE = getFirst(rightVisited)->rightChild ;
            pop(&rightVisited);
            push(&rightVisited,rightE);
            right++;      
        } 
        else if (getFirst(rightVisited) != NULL && getFirst(rightVisited)->leftChild!=NULL && getFirst(rightVisited) != getFirst(p) )
        {
            rightE = getFirst(rightVisited)->leftChild ;
            pop(&rightVisited);
            push(&rightVisited,rightE);
            right++; 
        }    
        else
        {
            pop(&rightVisited);
            
        }
        if (getFirst(rightVisited)==NULL && getFirst(leftVisited) == NULL)
        {   
            BT->level = right - left ;
            pop(&p);
            
        }   
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
    Element *position ;
    position= *BT ;
    Element *ElementToAdd = NULL ;
    while (position != NULL)
    {
        ElementToAdd = position ;
        setHight(position);
        if (position->level>=2 && position->rightChild >= 0)
        {
            
        }
        
        if (data >= position->data )
        {
            position = position->rightChild ;
        }
        else
        {
            position = position->leftChild ;
        }
    }
   if (data>=ElementToAdd->data)
    {
       ElementToAdd->rightChild = newElement ; 
    }
   else
    {
        ElementToAdd->leftChild = newElement ;  
    }
}
Element *leftRotation(Element *BT)
{
    Pile *newHead , *oldHead , *otherToAdd ;
    newHead = initialize();
    oldHead = initialize();
    otherToAdd = initialize();
    push(&oldHead,BT);
    push(&newHead,BT->rightChild);
    push(&otherToAdd,BT->leftChild);
    Element *e ;
    getFirst(newHead)->leftChild = getFirst(oldHead);
    if ( otherToAdd->next!=NULL )
    {
        addElement(&newHead->e,otherToAdd->e->data);
    }
    return newHead->e ; 
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
    Element *e1 =NULL ;
    addElement(&e1,4);
    addElement(&e1,3);
    addElement(&e1,8);
    addElement(&e1,12);
    addElement(&e1,10);
    addElement(&e1,13);
    displayPrefixe_Rec(e1);
    printf("\n%d %d",e1->rightChild->level,e1->rightChild->data);
    printf("\n");
    displayPrefixe_Rec(e1);
    
    
    return 0;
}
