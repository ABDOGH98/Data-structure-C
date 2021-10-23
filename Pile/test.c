#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    
    char *x[] = {"his","hola"};

    int z = sizeof(x)/sizeof(*x);
    printf("%d",z);
     
    return 0;
}
