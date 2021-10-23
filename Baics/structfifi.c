#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {

    int x ;
    char y ;
}Fofo ;
typedef struct {

    double *x;
    char *y ;
}Fifi ;

void createFofo1(Fofo *fofo)
{
    printf("x = ");
    scanf("%d",&(*fofo).x);
    getchar();
    printf("y = ");
    scanf("%c",&(*fofo).y);

}

Fofo *createFofo2(int x , char y)
{
    Fofo *fofo ;
    fofo =(Fofo *) malloc(sizeof(Fofo));
    fofo->x = x ;
    fofo->y = y ;

    return fofo ;
}

void createFofo3(Fofo *fofo , int x , char y)
{
    fofo->x = x ;
    fofo->y = y ;
}

void createFifi(Fifi *fifi)
{
    printf("Entrer x : ");
    fifi->x =(double *) malloc(sizeof(double));
    scanf("%lf",fifi->x);
    printf("Entrer y : ");
    fifi->y = (char *)malloc(20);
    scanf("%s",fifi->y);
}

Fofo getFofo(Fofo *fofo,int x , int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if ((fofo+i)->x == x)
        {
            return *(fofo+i) ;
        }
        
    }

}

void displayFofo(Fofo fofo)
{
    printf("(%d,%c)",fofo.x,fofo.y);
}
void displayFifi(Fifi fifi)
{
    printf("(%.2lf,%s)",*(fifi).x,fifi.y);
}

int main(int argc, char const *argv[])
{
    //Fofo f1 ;
    //Fofo *f2 ;
    //Fofo f3 ;
    

    //createFofo1(&f1);
    //f2 = createFofo2(5,'h');
    //createFofo3(&f3,9,'m');
    //displayFofo(f3);

    //Fifi f1 ;
    //createFifi(&f1);
    //displayFifi(f1);
    Fofo *f1 ;
    Fofo *f2 ;
    Fofo f3 ;

    f1 = createFofo2(1,'a');
    f2 = createFofo2(2,'b');
    createFofo3(&f3,3,'c');

    
    /*f1 = (Fofo *)malloc(sizeof(Fofo));
    f2 = (Fofo *)malloc(sizeof(Fofo));
    f3 = (Fofo *)malloc(sizeof(Fofo));*/

    Fofo fofo[3] = {*f1,*f2,f3};
    int x = 0 ;
    Fofo result ;
    printf("Entrer le nombre a rechercher : ");scanf("%d",&x);
    //result =(Fofo *) malloc(sizeof(Fofo));
    result = getFofo(fofo,x,3);

    displayFofo(result);

    return 0;
}
