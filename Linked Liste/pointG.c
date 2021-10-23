#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {

    int x ;
    int y ;

}Cordonnee;

void displayCordonnee(Cordonnee cordonnee)
{
    printf("cordonnee : (%d,%d)",cordonnee.x,cordonnee.y);
}

float calculeDistance(Cordonnee c1 , Cordonnee c2)
{
    float resultat = 0 ;
    resultat = sqrt(pow((c2.x-c1.x),2)+pow((c2.y-c1.y),2));
    return resultat ;
}

int main(int argc, char const *argv[])
{
    Cordonnee *c1 , *c2 ;
    c1 = (Cordonnee *)malloc(sizeof(Cordonnee));
    c2 = (Cordonnee *)malloc(sizeof(Cordonnee));

    c1->x = 1; c1->y = 1 ;
    c2->x = 2; c2->y = 2 ;

    /*displayCordonnee(c1);
    printf("\n");
    displayCordonnee(c2);*/

    float distance = 0 ;

    distance = calculeDistance(*c1 , *c2 );
    printf("Distance : %.2f",distance);
    
    return 0;
}
