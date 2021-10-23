#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct{

    char *nomFichier;
    int tailleFichier;
    char *texte;

}Document;

typedef struct{

    char *nomMachine;
    Document *doc;

}User;

typedef struct elem{

    User *user;
    char *dateLancement;
    struct elem *next;

}Element;

typedef struct{

    Element *first;
    Element *last;

}Spouleur;

Spouleur *createSpouleur()
{
    Spouleur *sp ;
    sp = (Spouleur *)malloc(sizeof(Spouleur));
    sp->first=NULL;
    sp->last=NULL;
    return sp;
}
User *createUser(char *nomMachi , Document *doc)
{
    User *u ;
    u =(User *)malloc(sizeof(User));
    u->doc=doc;
    u->nomMachine=nomMachi;

    return u ;
}
Document *createDocument(char *nomFichier ,int taille ,char *texte)
{
    Document *doc ;
    doc =(Document *)malloc(sizeof(Document));
    doc->nomFichier=nomFichier;
    doc->tailleFichier=taille;
    doc->texte=texte;

    return doc ;
}

void addToSpouler(Spouleur *sp , User *u)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char *date = asctime (timeinfo);
    free(timeinfo);
    Element *newElement ;
    newElement =(Element *)malloc(sizeof(Element));
    newElement->user=u;
    newElement->next=NULL;
    newElement->dateLancement = date;
    if (sp->first==NULL)
    {
        sp->first=newElement;
        sp->last=newElement;
        return;
    }
    sp->last->next=newElement;
    sp->last=newElement;
}
Element *getFirst(Spouleur *sp)
{
    if (sp->first==NULL)
    {
        printf("Empy , there is no doc !!!!!!!!");
        EXIT_SUCCESS;
    }
    return sp->first; 
}
void imprimer(Spouleur *sp)
{
    if (sp->first==NULL)
    {
        printf("Empy , there is no doc !!!!!!!!");
        return;
    }
    Element *tmp;
    tmp = sp->first;
    sp->first = sp->first->next;
    free(tmp);
    tmp=NULL;
}

int main(int argc, char const *argv[])
{
    Spouleur *sp;
    sp = createSpouleur();
    User *user1 ,*user2;
    Document *doc1 ,*doc2;
    doc1 = createDocument("langage C",15,"Le langagce C est un .....");
    user1 = createUser("abdo gh",doc1);
    doc2 = createDocument("Web Security",130,"HTTP adn HTPPS arte tow protocols .....");
    user2 = createUser("hatim",doc2);
    addToSpouler(sp,user1);
    addToSpouler(sp,user2);
    Element *e;
    e=getFirst(sp);
    printf("%s\n",e->user->nomMachine);
    printf("%s",e->dateLancement);
    imprimer(sp);
    e=getFirst(sp);
    printf("%s\n",e->user->nomMachine);
    printf("%s",e->dateLancement);
    
    return 0;
}
