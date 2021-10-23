#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    /*int **a ;
    
    a = malloc (sizeof(int));
    *a = malloc(sizeof(int));
    **a = 15 ;

    /*int *b;

    int x = 5 ;

    b = &x ;

    a = &b ;
    
    //**a= 15 ;
    //printf("a = %p",*a);
    /*printf("%p\n",(a));

    printf("%p\n",&(*a));
    printf("%p\n",&(**a));*/
   // printf("%p",b);

  /* char x[3]  = {'x','y','z'};
    int i=0;
   int k ;
   char z ;
   z = x[i];
   k = 'z';
   if (k>100)
   {
       printf("hello");
   }
   
   printf("%d",z);*/

/*int M[4][10] = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 15},
                {10,11,12,13,14,15,16,17,18,19},
                {20,21,22,23,24,25,26,27,28,29},
                {30,31,32,33,34,35,36,37,38,39}};

    int *p;
    p=(int *)M;

    //printf("%p",(p));
    printf("\n%d",*M[0]);*/

    //char **x;
    //x=(char *)malloc(N*4);
    char *y[]={"abc","ziza","toto","koko"} ;
    //int x = sizeof(*y);
    char *x ;
    x=y[0];
    printf("%s",x);
    //x[0]=NULL;
    //x[0]=(char *)realloc(x[0],3);
    //strncat(y ,&x[0],1) ;
    //strcpy(x[0],"fff");
    //printf("%s",x[0]);

    return 0;
}


/*

char *calcilDistance(Element *L,int x , int y , int k ) //k plus proche
{
    char *color;
    double tmp = 0 ;
    int kb = 0;
    int kr = 0 ;

    double distance = 0 ;
    distance = (double) sqrt( pow( L->rectangle->x - x , 2 ) + pow( L->rectangle->y - y , 2 ) ) ;

    if (strcmp("red",L->rectangle->couleur)==0)
    {
        kr++;
    }
    else
    {
        kb++;
    }
    
    double *TabNear;
    TabNear = (double *)calloc(distance,k*sizeof(double));
    
    L=L->next ;

    while (L != NULL)
    {
       distance = (double) sqrt( pow( L->rectangle->x - x , 2 ) + pow( L->rectangle->y - y , 2 ) ) ;
        for (int i = 0; i < k; i++)
        {
            if (distance < TabNear[i])
            {
                tmp = TabNear[i] ;
                TabNear[i]=distance;
                distance = tmp ;
            }     
        }
        tmp = 0 ;
        L = L->next ;
    }

    free(TabNear);
    TabNear=0;
    return TabNear;
}

*/