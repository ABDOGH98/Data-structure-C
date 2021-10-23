#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct elem
{
    int data;
    struct elem *next;
} Element;

Element *createElement(int c)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->data = c;
    newElement->next = NULL;
    return newElement;
}

void push(Element **pil, int c)
{
    Element *newElement;
    newElement = createElement(c);
    newElement->next = *pil;
    *pil = newElement;
}

void pop(Element **pil)
{
    if (*pil == NULL)
        return;

    Element *tmp;
    tmp = (*pil);
    (*pil) = (*pil)->next;

    free(tmp);
    tmp = NULL;
}

int peek(Element *pil)
{
    if (pil == NULL)
        return -1;
    return pil->data;
}

int calculeExpression(char *expression)
{
    int n = strlen(expression);
    int number = 0;
    int a, b, result = 0;
    Element *pil = NULL;
    char x ;
    for (int i = 0; i < n; i++)
    {
        x=expression[i];
        if (isdigit(expression[i]) != 0)
        {
            number = atoi(&x);
            push(&pil, number);
        }
        else
        {
            a = peek(pil);
            pop(&pil);
            b = peek(pil);
            pop(&pil);
            if (expression[i] == '+')
            {
                result = a + b;
                push(&pil, result);
            }
            else if (expression[i] == '*')
            {
                result =(int) a*b;
                push(&pil, result);
            }
            else if (expression[i] == '-')
            {
                result = b - a;
                push(&pil, result);
            }
            else if (expression[i] == '/')
            {

                result =(int) (b/a);
                push(&pil, result);
            }
        }
    }

    return peek(pil);
}

int verfier_si_postfixe(char exp[])
{
   
    if ( isdigit(exp[0]) != 0 && isdigit(exp[1]) != 0)
    {
        int nbr = 2 ;
        int sign = 0 ;
        
        for (int i = 2; i < strlen(exp); i++)
        {
            if (isdigit(exp[i]) != 0)
            {
                nbr++ ;
            }
            else
            {
                sign++ ;
            }
            
        }
        if (nbr-sign == 1 )
        {
            return 1 ;
        }
        
        
    }
    return -1 ;  
    
}

int est_bien_parantheses(char *exp)
{
    int openParenthesis=0 ;
    int closeParenthesis=0 ;
    int verif = 0 ;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
        {
            openParenthesis++;
            verif = 1 ;
        }
        else if (exp[i] == ')' && verif == 1)
        {
            closeParenthesis++;
            verif = 0 ;         
        } 
    }
    if (closeParenthesis==openParenthesis)
    {
        return 1 ;
    }
    return -1 ;
    
}

char **splitExpression(char exp[])
{
    char **numbers ;
    char operators;
    numbers = (char **)calloc(0,1);
    *numbers=(char *)calloc('\0',1);
    int c = 0;
    if (est_bien_parantheses(exp)==-1)
    {
        printf("Syntax Error!!!!!");
        EXIT_FAILURE;
    }
    for (int i = 0 , k=0; i < strlen(exp); i++)
    {
      if (exp[i]=='(')
      {
          numbers=(char **)realloc(numbers,k+1);
          *(numbers+k)=(char *)calloc('\0',1);
          do
          {
              i++;
              if (isdigit(exp[i])!=0)
              {     
                           
                strncat(*(numbers+k),&exp[i],1);
              }
              else if(exp[i]=='+' || exp[i]=='*' ||exp[i]=='-' ||exp[i]=='/')
              {
                
                strncat(*(numbers+k),&exp[i],1);
              }
              
          } while (exp[i]!=')');
      }
      else if (isdigit(exp[i])!=0)
      {
        numbers=(char **)realloc(numbers,k+1);
        *(numbers+k)=(char *)calloc('\0',1);
        strncat(*(numbers+k),&exp[i],1);
          
      }
      else if (exp[i]=='+' || exp[i]=='*' ||exp[i]=='-' ||exp[i]=='/')
      {
       
        numbers=(char **)realloc(numbers,k+1);
        *(numbers+k)=(char *)calloc('\0',1);
        strncat(*(numbers+k),&exp[i],1);
          
      }
      
      k++;
    }
     return numbers ;  
}

char *convert_infixe_postfixe(char *expression,int N)
{
    char **exp=splitExpression(expression);
    char *expressionFinal;
    expressionFinal=(char *)calloc('\0',1);
    char operatorInter;
    char *operatorExtern;
    operatorExtern=(char *)calloc('\0',1);
    int verify=0;
            
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < strlen(exp[i]); j++)
        {
            if (isdigit(exp[i][j] )!=0)
            {
                strncat(expressionFinal,&exp[i][j],1);
                if (strlen(exp[i])>1)
                {
                    verify = 1 ;
                }
                
            }
            else if(exp[i][j] == '+' || exp[i][j] == '-' || exp[i][j] == '*' || exp[i][j] == '/')
            {
                
                if (verify==1) operatorInter = exp[i][j] ;
                
                else strncat(operatorExtern,&exp[i][j],1);
            }     
        }
        if (verify==1)
        {
            strncat(expressionFinal,&operatorInter,1);
            verify = 0 ;
        }
    }
    Element *pil=NULL;
    char a ;
    for (int i = 0; i < strlen(operatorExtern); i++)
    {
        push(&pil,(int)operatorExtern[i]);
    }
    operatorExtern=(char *)calloc('\0',1);
    while (pil!=NULL)
    {
        a = (char)peek(pil);
        strncat(operatorExtern,&a,1);
        pil=pil->next;
    }
    
    strcat(expressionFinal,operatorExtern);
    
    return expressionFinal;
}
int main(int argc, char const *argv[])
{
    /*Format of Input function to use it  :
        -> set data with out pranthese at first
        -> to know the size of you String :
            (x+y) = 1
            sign = 1
            number out of parenthese = 1 
            exemple : "1+2*(5+3)/(4*3)" = 7
            [ 1 = 1 | + = 1 | 2 = 1 | * = 1 | (5+3) = 1 | / = 1 | (4*3) = 1 ] => 7
    */
    // char *r=convert_infixe_postfixe("(3+5)+(7*8)-4/2",5);
    // printf("\npostfix format => %s\n",r);
    // int result=0 ;
    // result = calculeExpression(r);
    // printf("\nresult => %d\n",result);
    int x = est_bien_parantheses("5+())(3");
    printf("%d",x);
    
    return 0;
}

