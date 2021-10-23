#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int y ;
}Mimi;

typedef struct{
    int x ;
    Mimi *mimi ;
}Momo;

void crateMomo1(Momo *momo ,int x , Mimi *mimi)
{
    momo->x = x ;
    momo->mimi = mimi ;
}

void crateMomo2(Momo *momo ,int x , Mimi *mimi)
{
    momo->x = x ;
    momo->mimi = mimi ;
    mimi->y = 0 ;
}

void setMimoOfMomo(Momo *momo , Mimi *mimi)
{
    momo->mimi = mimi ;
}

void createMimi(Mimi *mimi , int y)
{
    mimi->y = y ;
}

void displayMimi(Mimi mimi)
{
    printf("Detail Mimi : (%d)",mimi.y);
}

void displayMomo (Momo momo)
{
    printf("Detaill Momo : (%d , (%d))",momo.x,momo.mimi->y);
    
}

int main(int argc, char const *argv[])
{
    /*Mimi *m1 ;
    m1 = (Mimi *)malloc(sizeof(Momo));
    createMimi(m1,5);
    displayMimi(*m1);

    Momo m2 ;
    crateMomo1(&m2 ,1,m1);
    displayMomo(m2);*/

    Mimi mi1;
    createMimi(&mi1,5);
    Mimi mi2;
    createMimi(&mi2,2);
    Mimi mi3;
    createMimi(&mi3,3);
    Mimi mi4;
    createMimi(&mi4,1);

    Momo mo1;
    crateMomo1(&mo1,1,&mi1);
    Momo mo2;
    crateMomo1(&mo2,2,&mi2);
    Momo mo3;
    crateMomo1(&mo3,3,&mi3);
    Momo mo4;
    crateMomo1(&mo4,4,&mi4);
    
    Momo tabMomo[] = {mo1,mo2,mo3,mo4};
    int min = 0 ;
    Momo result ;
    //result = (Momo *)malloc(sizeof(Momo));
    min = tabMomo[0].mimi->y ;
    result = tabMomo[0];
    
    for (int i = 0; i < 4; i++)
    {
        if (tabMomo[i].mimi->y < min)
        {
            min = tabMomo[i].mimi->y ;
            result = tabMomo[i];
        }
        
    }
    
    displayMomo(result);
    
    return 0;
}
