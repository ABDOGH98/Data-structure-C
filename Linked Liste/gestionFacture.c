#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{

    int number_product ;
    char *designation;
    double price_U;

}Product;

typedef struct{

    int quantity ;
    double sous_total ;
    Product *product ;

}LigneCommands;

typedef struct Elem{

    LigneCommands *commands;
    struct Elem *next ;

}Element;

typedef struct{

    char *date;
    int number_Facture ;
    double total;
    Element *facture_liste;

}Facture;

void initialisationTabFacture(Facture **facture , int N)
{
    for (int i = 0; i < N; i++)
    {
        facture[i]=NULL;
    }

}

void createFacture(Facture **TabFacture ,Element *factureListe , char *date ,int number ,int N)
{
    for (int i = 0; i < N; i++)
    {
        if (TabFacture[i]==NULL)
        {
            TabFacture[i]=(Facture *)malloc(sizeof(Facture));
            TabFacture[i]->date=(char *)malloc(15);
            TabFacture[i]->date = date;
            TabFacture[i]->number_Facture = number ;
            TabFacture[i]->facture_liste = factureListe;
            TabFacture[i]->total = 0;
            while (factureListe != NULL)
            {
                TabFacture[i]->total += factureListe->commands->sous_total ;
                factureListe=factureListe->next;
            }
            return ;
        }
    }

}

void createCommandsLinge(Element **L ,Product *p ,int quantity)
{
    Element *newF ;
    newF = (Element *)malloc(sizeof(Element));
    newF->commands = (LigneCommands *)malloc(sizeof(LigneCommands));

    if (*L==NULL)
    {
        *L = newF ;
        (*L)->commands->product = p ;
        (*L)->commands->quantity = quantity ;
        (*L)->commands->sous_total = (quantity) * (p->price_U);
        (*L)->next = NULL;
        return ;
    }

    Element *position ; position = *L ;

    while (position->next != NULL)
    {
        position = position->next ;
    }

    newF->commands->product = p;
    newF->commands->quantity = quantity ;
    newF->commands->sous_total = (quantity) * (p->price_U) ;
    newF->next = NULL;
    position->next = newF;

}

void dispalyCammands(Element *L)
{
    while (L!= NULL)
    {
        printf("\n%d\t%.2lf\t%s\n",L->commands->quantity,L->commands->product->price_U,L->commands->product->designation);
        L=L->next;
    }

}



void createPoruct(Product **p ,int number ,char *designation ,double prixU)
{
    (*p) = (Product *)malloc(sizeof(Product));
    (*p)->designation = (char *)malloc(20);

    (*p)->number_product = number ;
    (*p)->designation = designation ;
    (*p)->price_U = prixU ;
}

void displayProduct(Product *p)
{
    printf("%d\t%s\t%.2lf",p->number_product,p->designation,p->price_U);
}


void displayAll(Facture **TabFacture , int N )
{
    for (int i = 0; i < N; i++)
    {
        if (TabFacture[i]!=NULL)
        {
            printf("\n****************************************************************************************************************\n");
            printf("\n****************************************************************************************************************\n");
            printf("Date : %s\nFacture n : %d\n",TabFacture[i]->date,TabFacture[i]->number_Facture);
            printf("Produit N\tQuantity\tDesignation\tprix/unite\ttotal:prix*quantity");
            printf("\n---------------------------------------------------------------------------------------------");

            while (TabFacture[i]->facture_liste != NULL)
            {
                printf("\n%d\t\t%d\t\t%s\t\t%.2lf\t\t%.2lf\n",TabFacture[i]->facture_liste->commands->product->number_product,TabFacture[i]->facture_liste->commands->quantity,TabFacture[i]->facture_liste->commands->product->designation,TabFacture[i]->facture_liste->commands->product->price_U,TabFacture[i]->facture_liste->commands->sous_total);
                TabFacture[i]->facture_liste=TabFacture[i]->facture_liste->next ;
            }
            
            printf("\n\t\t\t\t\t\t\tTotal : %.2lf",TabFacture[i]->total);
        }

    }

}

int main(int argc, char const *argv[])
{
    int N = 3;

    Facture *TabFactures[3] ;
    initialisationTabFacture(TabFactures,N);

    Element *L =NULL ;

    Element *G = NULL ;

    Product *p=NULL  ;
    Product *pp=NULL ;
    Product *kk = NULL;
    

    createPoruct(&p,123,"milk",15.30);
    createPoruct(&pp,124,"momo",15.00);
    createPoruct(&kk,124,"koko",30);
    //displayProduct(pp);

    createCommandsLinge(&L,p,15);
    createCommandsLinge(&L,pp,4);
    createCommandsLinge(&L,kk,4);
    //dispalyCammands(L);

    createCommandsLinge(&G,p,15);
    createCommandsLinge(&G,pp,4);
    createCommandsLinge(&G,kk,4);

    createFacture(TabFactures,L,"24/02/1998",1998,N);
    createFacture(TabFactures,G,"24/02/2020",100,N);
    displayAll(TabFactures,N);

    printf("\n");

    return 0;
}
