#include "election.h"
#include <stdio.h>
int ajouter(char *filename,election E)
{
FILE * f=fopen(filename,"a");
if(f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %d %d\n"
,E.identifiant,E.gouvernorat,E.municipalite,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.nombre_habitons,E.nombre_conseillers);  
fclose(f);
return 1;
}
else return 0;
}
int modifier(char *filename,int identifiant,election nouv)
{
int tr=0;
election E;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("nouv.txt","w");
if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%d %s %s %d %d %d %d %d\n",&E.identifiant,E.gouvernorat,E.municipalite,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,&E.nombre_habitons,&E.nombre_conseillers)!=EOF)
{
if(E.identifiant==identifiant)
{ 
fprintf(f2,"%d %s %s %d %d %d %d %d\n",nouv.identifiant,nouv.gouvernorat,nouv.municipalite,nouv.date_election.jour,nouv.date_election.mois,nouv.date_election.annee,nouv.nombre_habitons,nouv.nombre_conseillers);
tr=1;
}
else
fprintf(f2,"%d %s %s %d %d %d %d %d\n",E.identifiant,E.gouvernorat,E.municipalite,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.nombre_habitons,E.nombre_conseillers);
}
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);
return tr;
}
int supprimer(char *filename,int identifiant)
{
int tr=0;
election E;
FILE * f=fopen(filename,"r");
FILE * f2=fopen("nouv.txt","w");
if((f!=NULL)&&(f2!=NULL))
{
while(fscanf(f,"%d %s %s %d %d %d %d %d\n",&E.identifiant,E.gouvernorat,E.municipalite,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,&E.nombre_habitons,&E.nombre_conseillers)!=EOF);
{
if(E.identifiant==identifiant)
tr=1;
else
fprintf(f2,"%d %s %s %d %d %d %d %d\n",E.identifiant,E.gouvernorat,E.municipalite,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.nombre_habitons,E.nombre_conseillers);
}
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);
return tr;
}
election chercher(char *filename,int identifiant)
{
election E;
int tr=0;
FILE *f=fopen(filename,"r");
if(f!=NULL)
{
while(tr==0 && fscanf(f,"%d %s %s %d %d %d %d %d\n",&E.identifiant,E.gouvernorat,E.municipalite,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,&E.nombre_habitons,&E.nombre_conseillers)!=EOF)
{
if(E.identifiant==identifiant)
tr=1;
}
}
fclose(f);
if(tr==0)
E.identifiant=-1;
return E;
}
