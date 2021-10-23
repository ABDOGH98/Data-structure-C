#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
    
typedef struct elem{

    char *nombre ;
    struct elem *next ;

}Element;


int isNumber(char myChar)
{
    if (myChar == '+' || myChar == '*' || myChar == '-')
    {
        
        return 0 ;
    }

    return 1 ;
    
}


char **splitExpression(char *expression)
{
    char **numberTab;
    int N = strlen(expression);
    int no = 0 ;

    numberTab = (char **)malloc(N*sizeof(int));

    for (int i = 0; i < N; i++)
    { 
        numberTab[i]=NULL;
    }

    for (int i = 0; i < N; i++)
    {

        if (isNumber(expression[i])==1)
        {
            if (no>0)
            {
                numberTab[i-no]=(char *)realloc(numberTab[i-no],no);
                strncpy(numberTab[i-no],&expression[i-no],no+1);
                no++;
            }
            else
            {
                
                numberTab[i]=(char *)calloc(0,1);
                strncpy(numberTab[i],&expression[i],1);
                no++ ;
            }
            
        }
        else
        {
            numberTab[i]=(char *)calloc(0,1);
            strncpy(numberTab[i],&expression[i],1);
            no=0;
        }
    }
    return numberTab ;
}

void addElement(Element **L ,char *exp)
{
    Element *position ;
    Element *newExp ;
   
    
    newExp = (Element *)malloc(sizeof(Element));

    if ((*L)==NULL)
    {
        (*L) = newExp ;
        (*L)->nombre = exp;
        (*L)->next = NULL;
    }
    else
    {
            position = *L;

        while (position->next != NULL)
        {
            position = position->next ;
        }
        newExp->nombre=exp;
        newExp->next=NULL;
        position->next=newExp;
    }
    
}

void transformExpession(Element **L ,char *exp)
{
    int N = strlen(exp);

    char **numberTab=NULL;

    numberTab = splitExpression(exp);

    for (int i = 0; i < N; i++)
    {
        if (numberTab[i]!=NULL)
        {
            addElement(L,numberTab[i]);
        }
        
    }
    free(*numberTab);
    free(numberTab);
}

void display(Element *L)
{
    while(L != NULL)
    {

        printf("%s -> ",L->nombre);
        L = L->next;
    }
}

int main(int argc, char const *argv[])
{
    
    Element *L = NULL;
    Element *G =NULL;

    char *exp = "0*15+24+5+10+80+15";
    transformExpession(&L ,exp);
    display(L);
    
    transformExpession(&G,"5+33-17+18");
    printf("\n");
    display(G);
    
    return 0;
}
