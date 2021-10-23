#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    char *designation;
    double price;
    int stockQuantity;
}Product;

void displayProduct()
{
    
}


int main(int argc, char const *argv[])
{
    /*int *id; int *qteStock; double *prix; double *total;

    id = (int *)malloc(sizeof(int));
    qteStock = (int *)malloc(sizeof(int));
    prix = (double *)malloc(sizeof(double));
    total = (double *)malloc(sizeof(double));
    

    printf("Saisir ID:"); scanf("%d",id);
    printf("Saisir Qte stock:"); scanf("%d",qteStock);
    printf("Saisir PRIX:"); scanf("%lf",prix);

    *total = (*qteStock)*(*prix);
    printf("-------- Fiche du produit ----- \n");
    printf("ID produit: %d\n",*id);
    printf("Prix produit: %.2f\n",*total);
    printf("Qte en stock: %d\n",*qteStock);
    printf("Total en argent: %.2f\n",*total);*/

/*int sizeOF_Array=5; int Tab[]={1,2,3,4,5};

int i; int *ptrTab;

ptrTab=Tab; /*ligne5

for(i=0;i<sizeOF_Array;i++)
{
    printf("%p - %p ",&Tab[i],(Tab+i));
    printf(" *** ");
    printf("%p - %p ",&ptrTab[i],(ptrTab+i));
    printf(" *** ");
    printf("%d - %d - %d - %d ",Tab[i],*(Tab+i),ptrTab[i],*(ptrTab+i));
    printf("\n");
}
*(ptrTab+3)=33;
printf("%p - %p ",&Tab[3],(Tab+3));
printf(" *** ");
printf("%p - %p ",&ptrTab[3],(ptrTab+3));
printf(" *** ");
printf("%d - %d - %d - %d ",Tab[3],*(Tab+3),ptrTab[3],*(ptrTab+3));
printf("\n");*/

/*int sizeOF_STOCK=5; int i;
int id[]={1,2,3,4,5};
int qteStock[]={10,15,5,20,10};
double prix[]={90.5,60.5,70.5,65.0,75.0};

printf("ID \t QTE \t PRIX \t Sous Total\n");

for(i=0;i<sizeOF_STOCK;i++)
{
    printf("%d \t %d \t %.2f \t %.2f\n",id[i],qteStock[i],prix[i],(qteStock[i]*prix[i]));
}*/


Product p1; /*ligne 3*/

p1.id=11;  /*ligne 4*/
p1.designation=(char*)malloc(10); /*ligne 5*/
p1.designation="LED 32";  /*ligne 6*/
p1.price=3200;
p1.stockQuantity=10;


/*printf("--------------Product Detail---------------\n");
printf("Id: %d\n", p1.id); /*ligne 11
printf("Designation: %s\n", p1.designation);
printf("Price: %.2f\n", p1.price);
printf("Stock quantity: %d\n", p1.stockQuantity);
printf("Total: %.2f\n",( p1.stockQuantity* p1.price));*/

double *a;
printf("%d",sizeof(a));



return 0;

}
