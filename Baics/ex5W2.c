#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;     
    char *designation;
    double price;     
    int stockQuantity;
}Product;

Product *getProduct(Product *product,int id,int tailleTab)
{    
    for (int i = 0; i < tailleTab; i++)
    {
        if (product[i].id==id)
        {
            return (product+i) ;
        }
        
    }

    return NULL;
    
}

void setProduct(Product *product , int id , int prix , char *design,int tailleTab)
{
    Product *getP ;
    getP = (Product *)malloc(sizeof(Product));
    getP = getProduct(product,id,tailleTab);

    getP->designation = design ;
    getP->price = prix ;
}

void displayAll(Product *product , int tailleTab)
{
    printf("\nID\tDesignation\t\tPrix\t\tQTE\tS.Total\n");
    for (int i = 0; i < tailleTab; i++)
    {
        printf("%d\t%s\t\t       %.2f\t\t%d\t%.2lf\n",product[i].id,product[i].designation,product[i].price,product[i].stockQuantity, (product[i].price)*(product[i].stockQuantity) );
    }
    
}

int main(int argc, char const *argv[])
{
    Product p1 , p2 , *p3;
    int i; 
    int stockSize=5;

    p3=(Product*)malloc(sizeof(Product));

    p1.designation=(char*)malloc(10);  
    p2.designation=(char*)malloc(10);  
    p3->designation=(char*)malloc(10);

    p1.id=31;p1.designation="Led 31"; p1.price=3100;p1.stockQuantity=5;
    p2.id=32;p2.designation="Led 32"; p2.price=3200;p2.stockQuantity=10;
    p3->id=33;p3->designation="Led 33"; p3->price=3300;p3->stockQuantity=15;

    Product Tabl1[]={p1,p2,*p3};

    Product *getProductByid ;

    getProductByid = (Product *)malloc(sizeof(Product));

    getProductByid = getProduct(Tabl1,33,3);

    //displayAll(getProductByid,1);

    //displayAll(Tabl1,3);

    
    /*Product p4 , p5 , p6 , p7 , p8;

    p4.designation=(char *)malloc(15);
    p5.designation=(char *)malloc(15);
    p6.designation=(char *)malloc(15);
    p7.designation=(char *)malloc(15);
    p8.designation=(char *)malloc(15);
    Product Tabl2[] ={p4,p5,p6,p7,p8};

    for (int i = 0; i < 5; i++)
    {
        printf("Entrer ID :");scanf("%d",&Tabl2[i].id) ;
        printf("Entrer Designation :");scanf("%s",Tabl2[i].designation) ;
        printf("Entrer price :");scanf("%lf",&Tabl2[i].price) ;
        printf("Entrer stock QT :");scanf("%d",&Tabl2[i].stockQuantity) ;

    }
    displayAll(Tabl2,5);*/

    displayAll(Tabl1,3);
    setProduct(Tabl1,31,100,"GLSID1",3);
    displayAll(Tabl1,3);

    return 0;
}
