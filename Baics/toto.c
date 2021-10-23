#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int z;

}Tata;

typedef struct{

    int y ;
    Tata *tata;

}Titi;

typedef struct{

    int x ;
    Titi titi ;

}Toto;

void createTata(Tata *tata , int z)
{
    tata->z = z ;
}

void createTiti(Titi *titi , int y , Tata *tata)
{
    titi->y = y ;
    titi->tata = tata ;
}

void createToto(Toto *toto , int x , Titi *titi)
{
    toto->x = x ;
    toto->titi = *titi ;
}

void displayToto(Toto *toto , int tailleTitiTab)
{
    printf("x = %d et y = %d et tabTiti = [",toto->x,toto->titi.y);
    for (int i = 0; i < tailleTitiTab; i++)
    {
        printf("%d,",toto->titi.tata[i].z);
    }
    printf("]");
}

int main(int argc, char const *argv[])
{
    Tata tataTab[] = {1,2,3,4,5}  ;
    //t1.z = 1 ; t2.z = 2 ; t3.z = 3 ; t4.z = 4 ; t5.z = 5 ; 
    Titi *titi ;
    titi = (Titi *)malloc(sizeof(Titi));
    createTiti(titi , 2 ,tataTab);

    Toto *toto ;
    toto = (Toto *)malloc(sizeof(Toto));
    createToto(toto,1,titi);

    displayToto(toto,5);


    return 0;
}
