#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{

    int x ;
    int y;
    char *couleur;

}Rectangle;

typedef struct elem
{
    Rectangle *rectangle;
    struct elem *next;
}Element;

char *calculDistance(Element *L,int x , int y , int k ) //k plus proche
{
    char *color;
    double tmp = 0 ;
    int kb = 0;
    int kr = 0 ;

    double distance = 0 ;
    distance = (double) sqrt( pow( L->rectangle->x - x , 2 ) + pow( L->rectangle->y - y , 2 ) ) ;
    
    if (strcmp(L->rectangle->couleur,"red")==0)
    {
        kr++;
    }
    else
    {
        kb++;
    }
    
    
    double *TabNear;
    TabNear = (double *)calloc(0,k*sizeof(double));

    L=L->next ;

    while (L != NULL)
    {
       distance = (double) sqrt( pow( L->rectangle->x - x , 2 ) + pow( L->rectangle->y - y , 2 ) ) ;
       
        for (int i = 0; i < k; i++)
        {
            if (distance < TabNear[i] || TabNear[i]==0)
            {
                tmp = TabNear[i] ;
                TabNear[i]=distance;
                distance = tmp ;
                if (strcmp(L->rectangle->couleur,"red")==0)
                {
                    kr++; 
                    kb--;
                }
                else
                {
                    kb++;
                    kr--;
                }
            }     
        }
        tmp = 0 ;
        L = L->next ;
    }

    free(TabNear);
    TabNear=0;

    if (kb>kr)
    {
        return "blue";
    }
    else
    {
        return "red";
    }
    
    
}

void createRectangle(Rectangle **r,int x1 ,int y1 ,char *color)
{
    *r = (Rectangle *)malloc(sizeof(Rectangle));

    (*r)->x=x1;
    (*r)->y = y1 ;
    (*r)->couleur = color;
    
}

void addRectangle(Element **L,Rectangle *R)
{ 
    Element *newR ;
    newR = (Element *)malloc(sizeof(Element));
    newR->rectangle=(Rectangle *)malloc(sizeof(Rectangle));
    if (*L==NULL)
    {
        
        (*L)=newR;
        (*L)->rectangle = R ;
        (*L)->next=NULL;
        return ;
    }
    Element *position ;
    position = *L;

    while (position->next != NULL)
    {
        position = position->next ;
    }

    newR->rectangle=R;
    newR->next = NULL ;
    position->next = newR ;
    
}

void createRectangleNoColor(Element *L,int x1 ,int y1 ,int k)
{
    char *color ;
    Rectangle *r;
    
    color = calculDistance(L,x1,y1,k);  
    createRectangle(&r,x1,y1,color);
    addRectangle(&L,r);
}

void displayAll(Element *L)
{
    while (L != NULL)
    {
        printf("x = %d  y = %d  color = %s\n",L->rectangle->x,L->rectangle->y,L->rectangle->couleur);
        L=L->next;
    }
}

int main(int argc, char const *argv[])
{
    Element *L = NULL;  
    Rectangle *r1 , *r2 , *r3 , *r4 , *r5 , *r6; //Red
    Rectangle *b1 , *b2 , *b3 , *b4 , *b5 , *b6 , *b7;//Blue 

    createRectangle(&b1,1,9,"blue");
    createRectangle(&b2,9,1,"blue");
    createRectangle(&b3,5,8,"blue");
    createRectangle(&b4,4,4,"blue");
    createRectangle(&b5,9,2,"blue");
    createRectangle(&b6,3,5,"blue");
    createRectangle(&b7,2,9,"blue");

    createRectangle(&r1,15,13,"red");
    createRectangle(&r2,12,13,"red");
    createRectangle(&r3,14,17,"red");
    createRectangle(&r4,18,16,"red");
    createRectangle(&r5,11,14,"red");
    createRectangle(&r6,19,12,"red");

    Rectangle rTab[] = {*r1 , *r2 , *r3 , *r4 , *r5 , *r6};
    Rectangle bTab[] = {*b1 , *b2 , *b3 , *b4 , *b5 , *b6 , *b7};
    
    for (int i = 0; i < 6; i++)
    {
        addRectangle(&L,(rTab+i));
    }
    
    for (int i = 0; i < 6; i++)
    {
        addRectangle(&L,(bTab+i));
    }

    createRectangleNoColor(L,13,15,2);
    
    
    displayAll(L);
    
    return 0;
}
