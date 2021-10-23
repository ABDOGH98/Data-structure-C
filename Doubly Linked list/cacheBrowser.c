#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char *addrWeb;
    char *titre;
    char *contenue;
} Page;

typedef struct elem
{
    Page *page;
    struct elem *next;
    struct elem *previous;
} Element;

typedef struct
{
    Element *first;
    Element *Last;
} Liste;

Page *createPage(char *addr, char *title, char *content)
{
    Page *page ;
    page = (Page *)malloc(sizeof(Page));
    page->addrWeb = addr;
    page->titre = title;
    page->contenue = content;

    return page;
}

void initialiseTabPage(Page **pages, int N)
{
    
    for (int i = 0; i < N; i++)
    {
        *(pages + i) = NULL;
    }
    pages[0] = createPage("www.azize.com","HOME","Landing Page");
    pages[1] = createPage("www.azize.com/about-us","Ecole ing","depratement math");
    pages[2] = createPage("www.azize.com/technology","our  technology","react,PHP,UIKIT,WEB security,W3C");
    pages[3] = createPage("www.azize.com/footer","footer","privacy policy");
}

Element *creaetElement(Page *page)
{
    Element *newElement ;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->next=NULL;
    newElement->previous=NULL;
    newElement->page=page;

    return newElement ;
}

Liste *createListe()
{
    Liste *L ;
    L=(Liste *)malloc(sizeof(Liste));

    L->first=NULL;
    L->Last=NULL;

    return L ;
}
void addPage(Liste *L , Page *page)
{
    Element *newElement ;
    newElement = creaetElement(page);

    if (L->first == NULL)
    {
        L->first=newElement ;
        L->Last=newElement ; 

        return ;
    }
    L->Last->next = newElement ;
    newElement->previous = L->Last ;
    L->Last = newElement ; 
}

void displayFromFirst(Liste *L)
{
    while (L->first != NULL)
    {
        printf("%s\n",L->first->page->addrWeb);
        L->first = L->first->next;
    }
}

void displayPage(Element *e)
{
    printf("\n-------------------------------------------------------------------------------------------\n");
    printf("address : %s\ntitre : %s\ncontent : %s\n",e->page->addrWeb,e->page->titre,e->page->contenue);
    printf("\n-------------------------------------------------------------------------------------------\n");
}
Element *getPgaeByAddr(Liste *L , char *address)
{
    printf("\nLoading...");
    while (L->first != NULL)
    {
        if (strcmp(L->first->page->addrWeb,address)==0)
        {
            return L->first ;
        }
        printf("...");
        L->first = L->first->next;
    }
    return NULL;
}

Element *nextPage(Element *e)
{
    Element *elem ;
    elem = e ;
    elem = elem->next;
    if (elem!=NULL)
    {
        
        displayPage(elem);
        return elem ;
    }
    displayPage(e);
    return e ;
    
}

Element *previousPage(Element *e)
{
    Element *elem ;
    elem = e ;
    elem = elem->previous;
    if (elem!=NULL)
    {
        
        displayPage(elem);
        return elem ;
    }
    displayPage(e);
    return e ;
    
}

int main(int argc, char const *argv[])
{
    Page *page[10];
    initialiseTabPage(page, 10);
    Liste *L = createListe();
    
    addPage(L,page[0]);
    addPage(L,page[1]);
    addPage(L,page[2]);
    addPage(L,page[3]);
    char action ;
    char adresse[50] ;
    char title[20] ;
    char content[100] ;
    Element *getPgae;
    int firstSearch = 0 ;
    do
    {
        printf("Entrer votre choix : ");
        scanf("%c",&action);
        if('x'==action || 'X'==action) break ;
        if (action == 'w' || action == 'W'){

            printf("Entrer l'adresse du site web : ");
            scanf("%s",adresse);                
            getPgae=getPgaeByAddr(L,adresse);
            if (getPgae !=NULL){

                displayPage(getPgae);
                firstSearch=1 ;
            }
            else{
                printf("\n-------------------------------------------------------------------------------------------\n");
                printf("ERROR 404 ");
                printf("\n-------------------------------------------------------------------------------------------\n");
            }            
        }
        if ((action == 'n' || action == 'N')&&(firstSearch==1)){

            getPgae = nextPage(getPgae);
        }
        if ((action == 'p' || action == 'P')&&(firstSearch==1)){

            getPgae = previousPage(getPgae);
        }
        
        
    getchar();
    } while (1);
    

    displayFromFirst(L);
    return 0;
}
