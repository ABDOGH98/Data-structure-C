#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int y ;

}Didi;

typedef struct{

    int x ;
    Didi *tabDidi;

}Dodo;

void createDodo1(Dodo *dodo , int x )
{
    dodo->x = x ;
    dodo->tabDidi = NULL;
}
void createDodo2(Dodo *dodo , int x , Didi *didi)
{
    dodo->x = x ;
    dodo->tabDidi = didi ;
}

void addDidiToDodo(Dodo *dodo , int size, Didi *tabDidi)
{
    for (int i = 0; i < size; i++)
    {
        dodo->tabDidi[i] = *(tabDidi+i);
    }
    
}

void createDidi(Didi *didi , int y)
{
    didi->y = y ;
}

void displayDidi(Didi *didi)
{
    printf("(%d)",didi->y);
}

void displayDodo(Dodo *dodo , int taille )
{
    printf("%d,tabDidi : [",dodo->x);
    for (int i = 0; i < taille; i++)
    {
        printf("%d,",(dodo)->tabDidi[i]);
    }
    printf("]");
    //printf("%d,tabDidi : [%d,%d,%d,%d]",dodo->x,(dodo)->tabDidi[i],(dodo)->tabDidi[1],(dodo)->tabDidi[2],(dodo)->tabDidi[3]);
    
}

int main(int argc, char const *argv[])
{

    Didi di1 ;
    createDidi(&di1,1);
    Didi di2 ;
    createDidi(&di2,2);
    Didi di3 ;
    createDidi(&di3,3);
    Didi di4 ;
    createDidi(&di4,4);

    Didi tabDidi[] ={di1,di2,di3,di4};

    Dodo do1 ;
    createDodo2(&do1,5,tabDidi);
    //displayDidi(&di1);
    displayDodo(&do1,4);
    
    return 0;
}
