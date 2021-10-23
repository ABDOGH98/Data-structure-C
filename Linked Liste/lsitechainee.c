#include <stdlib.h>
#include <stdio.h>

typedef struct {

    int x ;
    Bed *next ;

}Bed;

int main(int argc, char const *argv[])
{
    Bed* L;

    Bed var1;
    L=&var1 ;
    var1.x = 1 ;
    var1.next = NULL;

    Bed var2;
    var2.x=2 ;
    var2.next = NULL;

    Bed var3;
    var3.x=3 ;
    var3.next = NULL;

    Bed var4;
    var4.x=4 ;
    var4.next = NULL;

    Bed var5;
    var5.x=5 ;
    var5.next = NULL;
    
    return 0;
}
