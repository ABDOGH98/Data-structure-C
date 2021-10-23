#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{

    int id ;
    char *type;
    double montant ;
    int nbOperation ;

}Operation;

typedef struct{

    double number;
    double solde ;
    Operation *operation ;
    int nbrOperationMax ;

}Compte;

void setOperation(Compte *compte ,int id, char *type , double montant)
{
    int i = compte->operation->nbOperation;
    if (compte->operation->nbOperation<compte->nbrOperationMax && (strcmp("VERS",type)==0 || strcmp("RETR",type)==0) )
    {
        compte->operation[i].type = type ;
        compte->operation[i].montant = montant ;
        compte->operation[i].id = id ;
        compte->operation->nbOperation = i +1 ;
        
    }
    else if (compte->operation->nbOperation >= compte->nbrOperationMax)
    {
        printf("Error depassement\n");
    } 
}

Compte *getCompteByID(Compte *Compte , int SetNumber , int tailleTab)
{
    for (int i = 0; i < tailleTab; i++)
    {
        if (Compte[i].number == SetNumber)
        {
            return &Compte[i];
        }
        
    }
    return NULL;
}

void setNbrMaxOperation(Compte *compte , int nbrOpMax)
{
    compte->nbrOperationMax = nbrOpMax ;
}

void afficheDetaillCompte(Compte *compte)
{
    int j = compte->operation->nbOperation;
    double soldeFinal = compte->solde ;
    printf("-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("Compre N : %.2lf , Solde de depart : %.4lf\n",compte->number,compte->solde);
    printf("Operation N\tType\tMontatnt\n");

    for (int i = 0; i < j; i++)
    {
        printf("%d\t\t%s\t%.2lf\n",compte->operation[i].id,compte->operation[i].type,compte->operation[i].montant);
        if (strcmp("VERS",compte->operation[i].type)==0)
        {
            soldeFinal = compte->operation[i].montant + soldeFinal ;
        }
        else
        {
            soldeFinal = soldeFinal - compte->operation[i].montant  ;
        }
        
        
    }
    printf("\n\t\t\tSolde final : %.2lf \n\n",soldeFinal);
    
}

int main(int argc, char const *argv[])
{
    /*Compte compte1,compte2 ;
    Operation *op1 , *op2 ;
    op1 = (Operation *)malloc(sizeof(Operation));
    op2 = (Operation *)malloc(sizeof(Operation));
    op1->type = (char * )malloc(10);
    compte1.number = 123 ; compte1.solde = 5000;  compte1.operation = op1 ; compte1.operation->nbOperation=0 ;
    compte2.number = 456 ; compte1.solde = 10000; compte2.operation = op2 ; compte2.operation->nbOperation=0 ;

    setOperation(&compte1,1,"VERS",1000);
    setOperation(&compte1,2,"VERS",500);
    setOperation(&compte1,3,"RETR",500);

    afficheDetaillCompte(&compte1);*/

    Compte compte1,compte2,compt3,compte4,compte5 ;
    Operation *op1 , *op2 , *op3 , *op4 , *op5 ;
    
    op1 = (Operation *)malloc(sizeof(Operation)); op1->type = (char * )malloc(10); op1->nbOperation = 0 ;
    op2 = (Operation *)malloc(sizeof(Operation)); op2->type = (char * )malloc(10); op2->nbOperation = 0 ;
    op3 = (Operation *)malloc(sizeof(Operation)); op3->type = (char * )malloc(10); op3->nbOperation = 0 ;
    op4 = (Operation *)malloc(sizeof(Operation)); op4->type = (char * )malloc(10); op4->nbOperation = 0 ;
    op5 = (Operation *)malloc(sizeof(Operation)); op5->type = (char * )malloc(10); op5->nbOperation = 0 ;
    Operation tabOperation[]= {*op1 , *op2 , *op3 , *op4 , *op5} ;
    Compte tabCompte[] = {compte1,compte2,compt3,compte4,compte5};

    for (int i = 0; i < 5; i++)
    {
        (tabCompte+i)->operation =( tabOperation+i) ;
    }
    tabCompte[0].number = 1;
    setNbrMaxOperation(&tabCompte[0],2);
    int id ; char type[10];double montant ;
    for (int i = 0; i < 3; i++)
    {
        //printf("Entrer numero du compte %d : ",(i+1));scanf("%d",&tabCompte[i].number) ;
        
        printf("Entrer Solde du compte %d : ",(i+1));scanf("%lf",&tabCompte[0].solde) ;
        printf("Entrer id du operation du compte %d : ",(i+1));scanf("%d",&id) ;
        printf("Entrer type [VERS | RETR ] du compte %d : ",(i+1));scanf("%s",type) ;
        printf("Entrer montant d\'operation sur compte %d : ",(i+1));scanf("%lf",&montant) ;
        
        setOperation(&tabCompte[0],id,type,montant);
    }
    
    /*for (int i = 0; i < 2; i++)
    {
        afficheDetaillCompte(&tabCompte[i]);
    }*/
    int compteNumber = 0 ;
    printf("Entrer le numero de compte a rechercher : ");scanf("%d",&compteNumber);

    Compte *getCompte ;
    getCompte = getCompteByID(tabCompte,compteNumber,2);

    if (getCompte)
    {
        afficheDetaillCompte(getCompte);
    }
    else
    {
        printf("Acount Number NOT FOUND !!!!!!");
    }
    
    
    
    
    

    return 0;
}
