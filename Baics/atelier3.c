#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    char *designation;
    double price;
    int stockQuantity;
}Product;


int main(int argc, char const *argv[])
{


Product p1; /*ligne 3*/
p1.id=11;  /*ligne 4*/
//p1.designation=(char*)malloc(10); /*ligne 5*/
p1.designation="LED 32";  /*ligne 6*/
p1.price=3200;
p1.stockQuantity=10;
printf("--------------Product Detail---------------\n");
printf("Id: %d\n", p1.id); /*ligne 11*/
printf("Designation: %s\n", p1.designation);
printf("Price: %.2f\n", p1.price);
printf("Stock quantity: %d\n", p1.stockQuantity);
printf("Total: %.2f\n",( p1.stockQuantity* p1.price));

//

    //printf("%d",sizeof(p1));
    
    return 0;
}
