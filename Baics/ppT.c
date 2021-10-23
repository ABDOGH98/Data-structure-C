#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int *T[9];

    for (int i = 0; i < 9; i++)
    {
        T[i] = (int *)malloc(sizeof(int)*(i+1));

    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < i+1 ; j++)
        {
            T[i][j] = j+1;
            printf("%d  ",T[i][j]);
        }
        printf("\n");
        
    }
    
    /*for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("%d  ",T[i][j]);
        }
        printf("\n");
    }*/
    

    return 0;
}
