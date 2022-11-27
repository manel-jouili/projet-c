#include <stdio.h>
#include <string.h>
#include"entite.h"

int main()
{
 float x,y;
x=TauxVB("filename1.txt","r");
y=Tauxobs("filename2.txt","r");
printf("taux de vote blanc %f",x);
printf("observateurs etrangers et nationaux:",y);
return 0;
}
