#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------DATA STRUCTURES*/
typedef struct
{
    char *adress;
    char *title;
    char *content;
} Page;

typedef struct Elem
{
    Page *page;
    struct Elem *next;
    struct Elem *previous;
} Element;

typedef struct
{
    Element *First;
    Element *Last;
    int size;
} List;

typedef struct
{
    Element *courant;
    List *DL;
} Memory;
/*-------------------------------create page*/
Page *createPage(char *adress, char *title, char *content)
{
    Page *page;
    page = (Page *)malloc(sizeof(Page));
    page->adress = adress;
    page->title = title;
    page->content = content;

    return page;
}

/*-------------------------------display page*/
void displayPage(Page *page)
{
    if (page == NULL)
    {
        printf("ERROR");
        return;
    }
    printf("\n----------- %s -----------", page->title);
    printf("\n%s\n--------------- -----------", page->content);
}
/*-----------------------------------------------CREATE DOUBLY LINKED LIST*/

List *createList()
{
    List *list;
    list = (List *)malloc(sizeof(List));
    list->First = NULL;
    list->Last = NULL;
    list->size = 0;
    return list;
}

/*-----------------------------------------------CREATE ELEMENT*/

Element *createElemnt(Page *page)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->page = page;
    newElement->next = NULL;
    newElement->previous = NULL;
    return newElement;
}

/*-------------------------------------------------------------ADD AT END*/
void add(Page *page, Memory *mem)
{
    Element *newElement;
    newElement = createElemnt(page);
    mem->courant = newElement;
    if (mem->DL->First == NULL)
    {
        mem->DL->First = newElement;
        mem->DL->Last = newElement;
        mem->DL->size++;
        return;
    }
    mem->DL->Last->next = newElement;
    newElement->previous = mem->DL->Last;
    mem->DL->Last = newElement;
    mem->DL->size++;
}

/*-------------------------------------------------------------DISPLAY FROM FIRST*/
void displayFromFirst(List *L)
{
    Element *crt;
    crt = L->First;
    while (crt)
    {
        printf("%d - ", crt->page->title);
        crt = crt->next;
    }
}

/*-------------------------------------------------------------DISPLAY FROM LAST*/
void displayFromLast(List *L)
{
    Element *crt;
    crt = L->Last;
    while (crt)
    {
        printf("%d - ", crt->page->title);
        crt = crt->previous;
    }
}

/*-------------------------------INIT TABL*/
void initTabl(Page *Tab[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        Tab[i] = NULL;
    }

    /*pour simplifier */

    Tab[0] = createPage("www.enset-media.ac.ma", "home", "news + top elements");
    Tab[1] = createPage("nous", "qui somme nous", "le texte de la presentation de enset");
    Tab[2] = createPage("fi", "formation initiale", "glisid et bdcc premiere annee");
    Tab[3] = createPage("fc", "formation continue", "developpement web et moble et bdcc");
    Tab[4] = createPage("rd", "recherche", "recherche + environnement...");
}
/*----------------------------------------------getPage*/
Page *getPage(char *adress, Page *Tab[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (Tab[i] == NULL)
        {
            printf("ERROR 404\n");
            return NULL;
        }
        if (strcmp(Tab[i]->adress, adress) == 0)
            return Tab[i];
    }
    return NULL;
}
/*-------------------------------------------------------------MAIN*/
Memory *createMemory()
{
    Memory *mem;
    mem = (Memory *)malloc(sizeof(Memory));
    mem->courant = NULL;
    mem->DL = createList();
    return mem;
}
void gotoNext(Memory *mem)
{
    if (mem->DL->First != NULL && mem->courant->next != NULL)
    {

        mem->courant = mem->courant->next;
        displayPage(mem->courant->page);
    }
}

void gotoPrevious(Memory *mem)
{
    if (mem->DL->First != NULL && mem->courant->previous != NULL)
    {
        mem->courant = mem->courant->previous;
        displayPage(mem->courant->page);
    }
}

int main()
{
    /*
1.cr�er un tableau de pages web et l'intialiser
*/

    int N = 10;
    Page *Tab[10];
    initTabl(Tab, N);
    Memory *cach;
    cach = createMemory();
    char adress[50];
    char c;
    do
    {
        printf("entrer une action:");
        scanf(" %c", &c); /* w n p x*/
        if (c == 'x')
            break;
        if (c == 'w')
        {
            printf("adresse web:");
            scanf("%s", adress);
            Page *page = getPage(adress, Tab, N);
            if (page != NULL)
            {
                add(page, cach);
            }
        }
        if (c == 'p')
        {
            gotoPrevious(cach);
        }
        if (c == 'n')
        {
            gotoNext(cach);
        }

    } while (1);

    return 0;
}
