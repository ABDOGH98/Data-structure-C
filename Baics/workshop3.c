#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
   int x ;
   char y ;
}Fofo;

typedef struct 
{
   double *x ;
   char *y ;
}Fifi;

void createFofo1(Fofo *f1)
{
    printf("x : ");
    scanf("%d",&f1->x);
    getchar();
    printf("\ny : ");
    scanf("%c",&f1->y);
}

void dispalyFofo(Fofo f)
{
    printf("Detail fofo\n");
    printf("(%d,%c)",f.x,f.y);

}

Fofo *createFofo2(int x , char y)
{
    Fofo *f2 ;
    f2 =(Fofo *) malloc(sizeof(Fofo));
    f2->x = x ;
    f2->y = y ;
    return f2;
}

void createFofo3(Fofo *f,int x , char y)
{
    f->x = x ;
    f->y = y ;
}

void createFifi1(Fifi *f)
{
    f->x=(double *)malloc(sizeof(double));
    f->y=(char *)malloc(10);
    printf("Entrer x :");
    scanf("%lf",f->x);
    printf("Entrer y :");
    scanf("%s",f->y);
}

void dispalyFifi(Fifi f)
{
    printf("Detail fifi\n");
    printf("(%d,%s)",*f.x,f.y);
}
//***************************************************************************************************************************
typedef struct 
{
   int x ;
   //Mimi *mimi ;
}Momo;

typedef struct 
{
   int x ;
   
}Mimi;

Momo *createMomo(int x , Mimi *mimi)
{
    Momo *momo ;
    momo = (Momo *)malloc(sizeof(Momo));

}


//***************************************************************************************************************************


int main(int argc, char const *argv[])
{
    /*Fofo f1 ;
    createFofo1(&f1);
    dispalyFofo(f1);*/

    //Fofo *f2 ;
    //f2 = createFofo2(3,'f');
    //dispalyFofo(*f2);

    Fifi f1 ;
    createFifi1(&f1);
    dispalyFifi(f1);


    return 0;
}
