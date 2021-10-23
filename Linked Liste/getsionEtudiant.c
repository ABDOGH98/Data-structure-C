#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{

    char *nom;
    char *prenom;
    int age ;

}Etudiant;

typedef struct Elem{

    Etudiant *etudiant;
    struct elem *next ;

}Element;

typedef struct{

    char *nomFiliere;
    int nbrEleve ;
    Element *etudiant_Liste ;

}Filiere;

void initFilier(Filiere **Tab , int N)
{
    for (int i = 0; i < N; i++)
    {
        Tab[i] = NULL;
    }

}

void createFiliere(Filiere **Tab,char *nomFil , int nbrEtudiant , int N)
{
    Filiere *filiere ;
    filiere = (Filiere *)malloc(sizeof(Filiere));
    filiere->nomFiliere = (char *) malloc(10);

    for (int i = 0 ; i < N ; i++)
    {
        if (Tab[i]==NULL)
        {
            Tab[i] = filiere ;
            Tab[i]->nomFiliere = nomFil ;
            Tab[i]->nbrEleve = nbrEtudiant ;
            Tab[i]->etudiant_Liste = NULL;
            return  ;
        }

    }
}

void createEtudiant(Etudiant **e ,char *nom ,char *prenom ,int age )
{
    (*e)=(Etudiant *) malloc(sizeof(Etudiant));
    (*e)->nom = (char *)malloc(15);
    (*e)->prenom =(char *)malloc(15);

    (*e)->nom = nom ;
    (*e)->prenom = prenom ;
    (*e)->age = age ;
}

void addEtudiant(Element **L,Etudiant *e)
{

    Element *newE ;
    newE = (Element *)malloc(sizeof(Element));
    newE->etudiant = (Etudiant *)malloc(sizeof(Etudiant));

    if (*L == NULL)
    {
        *L =newE;
        (*L)->etudiant = e ;
        (*L)->next = NULL ;
        return;
    }

    Element *position ;
    position = *L;

    while (position->next != NULL)
    {
        position = position->next ;
    }

    newE->etudiant=e;
    newE->next = NULL ;
    position->next = newE ;
}

void addEtudiantToFiliere(Filiere **Tab , Element *L , char *filiere , int N )
{
    for(int i=0 ; i<N ;i++)
    {
        if(strcmp(Tab[i]->nomFiliere,filiere)==0)
        {
            Tab[i]->etudiant_Liste = L ;
        }
    }
}

void displayEtudiant(Element *L)
{

    while(L != NULL)
    {
        printf("\n\n\t\t\t%s\t\t%s\t\t%d\n",L->etudiant->nom,L->etudiant->prenom,L->etudiant->age);
        L = L->next;
    }

}


void displayAll(Filiere **Tab , int N)
{
    for (int i = 0; i < N; i++)
    {
        if (Tab[i]!=NULL)
        {
            printf("\n%d\t\t%s\t\t%p\n",Tab[i]->nbrEleve,Tab[i]->nomFiliere,Tab[i]->etudiant_Liste);
            displayEtudiant(Tab[i]->etudiant_Liste);
        }

    }
}

int main(int argc, char const *argv[])
{

    Filiere *Tab[3];

    initFilier(Tab,3);

    createFiliere(Tab,"GLSID",35,3);
    createFiliere(Tab,"BDCC",30,3);
    createFiliere(Tab,"GIL",30,3);



    Element *glsid = NULL ;
    Element *bdcc = NULL ;

    Etudiant *e1 = NULL;
    Etudiant *e2 = NULL;
    Etudiant *e3 = NULL;
    Etudiant *e4 = NULL;

    createEtudiant(&e1,"abdo","gh",22);
    createEtudiant(&e2,"soso","toto",26);
    createEtudiant(&e3,"zozo","zizi",20);
    //createEtudiant(&e1,"abdo","gh",22);

    addEtudiant(&glsid,e1);
    addEtudiant(&glsid,e2);
    addEtudiant(&glsid,e3);

    addEtudiant(&bdcc,e1);
    addEtudiant(&bdcc,e2);
    addEtudiant(&bdcc,e3);

    addEtudiantToFiliere(Tab,glsid,"GLSID",3);
    addEtudiantToFiliere(Tab,bdcc,"BDCC",3);




    displayAll(Tab,3);


    //initTabFiliere(Filiere **Tab , int size )
    //filiere = createFiliere("GLSID")
    //displayAll(Filiere **Tab)

    //getSpace(e_filere , 3);




    return 0;
}
