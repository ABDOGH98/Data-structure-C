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

void addEtudiant(Element **L,char *nom , char *prenom , int age)
{

    Element *newE ;
    newE = (Element *)malloc(sizeof(Element));
    newE->etudiant = (Etudiant *)malloc(sizeof(Etudiant));

    if (*L == NULL)
    {
        *L =newE;
        (*L)->etudiant->age = age ;
        (*L)->etudiant->nom = nom ;
        (*L)->etudiant->prenom = prenom ;
        (*L)->next = NULL ;
        return;
    }

    Element *position ;
    position = *L;

    while (position->next != NULL)
    {
        position = position->next ;
    }

    newE->etudiant->age = age ;
    newE->etudiant->nom = nom;
    newE->etudiant->prenom = prenom ;
    position->next = newE ;
    newE->next = NULL ;
}

/*void addEtudiantToFiliere(Filiere *Tab , Element *L , char *filiere )
{

}*/

void displayEtudiant(Element *L)
{

    while(L != NULL)
    {
        printf("\n\n%s\t\t%s\t\t%d\n",L->etudiant->nom,L->etudiant->prenom,L->etudiant->age);
        L = L->next;
    }

}

/*void addEtudiant(Filiere **Tab  ,Element *L , Etudiant *etudiant, char *filier ,int N)
{
    for (int i = 0; i < N; i++)
    {
        if (Tab[i]!=NULL && strcmp(Tab[i]->nomFiliere,filier)==0)
        {
            L->etudiant = etudiant ;
            Tab[i]->etudiant_Liste = L ;
            L->next = NULL;
        }

    }
}*/



void displayAll(Filiere **Tab , int N)
{
    for (int i = 0; i < N; i++)
    {
        if (Tab[i]!=NULL)
        {
            printf("\n%d\t\t%s\t\t%p\n",Tab[i]->nbrEleve,Tab[i]->nomFiliere,Tab[i]->etudiant_Liste);
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

    Element *L = NULL ;

    addEtudiant(&L,"abdo","gh",22);
    addEtudiant(&L,"qasry","gh",21);
    addEtudiant(&L,"qasry","gh",30);

    displayEtudiant(L);


    //displayAll(Tab,3);


    //initTabFiliere(Filiere **Tab , int size )
    //filiere = createFiliere("GLSID")
    //displayAll(Filiere **Tab)

    //getSpace(e_filere , 3);




    return 0;
}
