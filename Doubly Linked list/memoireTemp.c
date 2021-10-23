#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char *title;
    char *text ;
}Document;

typedef struct elem{

    Document *document;
    struct elem *next ; 
    struct elem *previous ;

}Element;

typedef struct{

    Element *first;
    Element *last ;

}Liste;

typedef struct tmptxt{

    char *text_in;
    struct tmptxt *next ;
    struct tmptxt *previous ;

}CHAR_Temp;

typedef struct mem{

    CHAR_Temp *first;
    CHAR_Temp *last;
    char *documentTitle;

}TempMemory;

Liste *initializeListe()
{
    Liste *L ;
    L =(Liste *) malloc(sizeof(Liste));
    L->first = NULL;
    L->last = NULL;
    return L;
}

TempMemory *initTempMemory()
{
    TempMemory *LT;
    LT=(TempMemory *)malloc(sizeof(TempMemory));
    LT->first=NULL;
    LT->last=NULL;
    LT->documentTitle=NULL;

    return LT;
}
//**************************************************************************************

Document *createDocument(char *title , char *txt)
{
    Document *doc ;
    doc = (Document *)malloc(sizeof(Document));
    doc->text=txt;
    doc->title=title;

    return doc;
}

Element *createElement(Document *doc)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->document = doc;
    newElement->next=NULL;
    newElement->previous=NULL;
    return newElement;
}

void addDocumenet(Liste *L , Document *doc)
{
    Element *newElement=NULL;
    newElement = createElement(doc);

    if (L->first==NULL)
    {
        L->first=newElement ;
        L->last=newElement;
        return ;
    }
    newElement->previous = L->last ;
    L->last->next=newElement ;
    L->last = newElement ;
}

void displayDoc(Liste *L)
{
    Element *e ;
    e = L->first;
    while (e!=NULL)
    {
        printf("\n\tTitle : %s\n\n%s\n\n",e->document->title,e->document->text);
        e = e->next;
    }
    
}
//*****************************************************************************************
void addTexte(TempMemory *LT , char *txt)
{
    CHAR_Temp *newTxtTemp ;
    newTxtTemp=(CHAR_Temp *)malloc(sizeof(CHAR_Temp));
    newTxtTemp->text_in= txt ;
    newTxtTemp->next =NULL;
    newTxtTemp->previous=NULL;
    if (LT->first ==NULL)
    {
        LT->first = newTxtTemp ;
        LT->last = newTxtTemp ;
        return ;
    }
    newTxtTemp->previous = LT->last ;
    LT->last->next=newTxtTemp;
    LT->last=newTxtTemp;
}

void displayMemory(TempMemory *LT)
{
    CHAR_Temp *tmp;
    tmp = LT->first ;
    while (tmp!=NULL)
    {
        printf("%s ",tmp->text_in);
        tmp = tmp->next;
    }
}

//***************************************************************************************


void splitTxtBySpace(TempMemory *LT ,char txt[] , char *title)
{
    char *setToMemory;
    setToMemory=(char *)calloc('\0',20);
    int i=0 ;
    int k=0 ;
    if(txt==NULL) return ;
    do
    {
        if (txt[i]!=' ')
        {
            strncat(setToMemory,&txt[i],1);
        }
        else
        {
            addTexte(LT,setToMemory);
            addTexte(LT," ");
            setToMemory=(char *)calloc('\0',10);
            k=0;
        }
        i++;
        k++ ;
    }while (txt[i]!='\0');
    addTexte(LT,setToMemory);
    LT->documentTitle=title;
}
CHAR_Temp *getLastChange(TempMemory *LT,CHAR_Temp *getLastChange , char action)
{
    if (getLastChange==NULL)
    {
        getLastChange = LT->last ;
    }
    
    if (action == 'y')
    {
        getLastChange = getLastChange->previous ;
    }
    if (action == 'z')
    {
        getLastChange = getLastChange->next ;
    }
    return getLastChange ;
}
void saveTexte(TempMemory *LT , Liste *L , CHAR_Temp *getLastChange )
{
    char *texte;
    texte=(char *)calloc('\0',100);
    Document *doc ;
    TempMemory *tmp ;
    tmp = LT ;
    if (getLastChange==NULL) getLastChange = LT->last;
    
    
    while (LT->first != getLastChange->next)
    {
        strcat(texte,tmp->first->text_in);
        tmp->first = tmp->first->next;
    }
    doc = createDocument(LT->documentTitle,texte);
    addDocumenet(L,doc);
    tmp = NULL;
}
//***************************************************************************************
int main(int argc, char const *argv[])
{
    Liste *LD; LD=initializeListe();
    TempMemory *LT; LT=initTempMemory();
    CHAR_Temp *getChange = NULL ;
    char title[20];
    char txt[1000];
    char action ;
    do
    {
        printf("\ncreate new Doc (N) , exit programe (X) , display Documents (D) => ");
        scanf("%c",&action);
        getchar();
        if (action=='x' || action=='X')break ;

        if (action=='n' || action=='N')
        {
            printf("Enter Title of document : ");
            gets(title);
            printf("Enter texte body document : \n => ");
            gets(txt);
            splitTxtBySpace(LT,txt,title);
            displayMemory(LT);
            do
            {
                printf("\nSave (s) , add other text (o) , Ctrl_Z (z) , Ctrl_Y (y) , exit (x)\n=> ");
                scanf("%c",&action);
                
                if (action =='x' || action =='X'){
                    LT=initTempMemory();
                    getChange =NULL;
                    break;
                }
                
                if (action =='s' || action =='S')
                {
                    saveTexte(LT,LD,getChange);
                    getChange=NULL;
                    LT=initTempMemory();
                    break;
                }
                else if (action =='o' || action =='O')
                {
                    printf("Enter texte body document : \n => ");
                    gets(txt);
                    splitTxtBySpace(LT,txt,title);
                    displayMemory(LT);
                }
                else if (action =='y' || action =='z')
                {
                    getChange = getLastChange(LT,getChange,action);

                }
                
                getchar(); 
            } while (1);            
            getchar();
        }   
        if (action=='d')
        {
            displayDoc(LD);
        }
    } while (1);
    
    
    return 0;
}
