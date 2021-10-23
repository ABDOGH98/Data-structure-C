#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct elem
{
    char *balise;
    struct elem *next;
} Element;

Element *createElement(char *balise)
{
    Element *newElement ;
    newElement=(Element *)malloc(sizeof(Element));
    newElement->balise=balise;
    newElement->next=NULL;
    return newElement;
}

void push(Element **pil , char *balise)
{
    Element *newElement ;
    newElement = createElement(balise);
    newElement->next=(*pil);
    *pil=newElement;
}
char *peek(Element *pil)
{
    if (pil==NULL)
    {
        return NULL;
    }
    return pil->balise;
    
}
void pop(Element **pil)
{
    if (*pil==NULL)
    {
        return;
    }
    
    Element *tmp ;
    tmp = *pil ;
    *pil = (*pil)->next;
    free(tmp);
    tmp = NULL; 
}

char *openTags(char *strBalise)
{
    char *tag;
    tag = (char *)calloc('\0',1);
    
    for (int i = 0 , k=0; i < strlen(strBalise); i++)
    {
        if (strBalise[i]=='<' && strBalise[i+1]!='/')
        {
            i++;
            while (strBalise[i]!='>')
            {
                strncat(tag,&strBalise[i],1);
                i++;

            }
        }
    }
    return tag ;
}
char *closeTag(char *strBalise)
{
    Element *pil = NULL;
    char *tag;
    for (int i = 0; i < strlen(strBalise); i++)
    {
        if (strBalise[i]=='<' && strBalise[i+1]=='/')
        {
            tag = (char *)calloc('\0',1);
            i+=2;
            while (strBalise[i]!='>')
            {
                strncat(tag,&strBalise[i],1);
                i++;
            }
            push(&pil,tag);
            tag = NULL ;
        }
    }

    tag = (char *)calloc('\0',1);
    while (pil!=NULL)
    {
        strcat(tag,peek(pil));
        pop(&pil);
    }
    return tag ;
    
}

int verifyHTML(char *bodyFile)
{
    char *tagOpen = openTags(bodyFile);
    char *tagClose = closeTag(bodyFile);
    if (strcmp(tagClose,tagOpen)==0)
    {
        return 1;
    }
    return -1 ;
}

int main(int argc, char const *argv[])
{
    int verifyFile = verifyHTML("<html><body><p>hi</p></body></html>");
    if (verifyFile == 1)
    {
        printf("le fichier HTML est bien structure ");
    }
    else
    {
        printf("le fichier HTML n\'est pas bien structure ");
    }
    
    
    
    return 0;
}
