#include <stdio.h>
#include <string.h>
#include"entite.h"

int main()
{
float x;
float *taux_obse;
float *taux_obsn;
x=TauxVB("user.txt");
printf("taux de vote blanc %f",x);
Tauxobs("observateur.txt",&*taux_obse,&*taux_obsn);
printf("observateurs étrangers %f\n :",*taux_obse);
printf("observateurs tunisiens %f\n :",*taux_obsn);
return 0;
}
