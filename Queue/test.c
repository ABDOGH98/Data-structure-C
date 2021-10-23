#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct elem{

    int data;
    
}Element;
int main ()
{
  // time_t rawtime;
  // struct tm * timeinfo;
  // time ( &rawtime );
  // timeinfo = localtime ( &rawtime );
  // char *date = asctime (timeinfo);

  // printf ( "Current local time and date: %s", date );

Element e[3];
e[0].data=0;
e[1].data=1;
e[2].data=2;

for (int i = 0; i < 3; i++)
{
  
}


  return 0;
}