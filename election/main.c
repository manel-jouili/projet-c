#include <stdio.h>
#include <string.h>
#include "election.h"

int main()
{
   election E1={111254,"sfax","gremda",13,10,2023,12,15000},E2={111253,"sfax","Ain",13,10,2024,16,20000},E3;
   int x=ajouter("election.txt",E1);
   //int y=ajouter("election.txt",E2);

   if(x==1)
     printf("\najout de election avec succes");
   else printf("\nechec ajout");

   /*int x=modifier("election.txt",111254,E2);
   if(x==1)
     printf("\nmodification d'election avec succes");
   else printf("\nechec modification");
   int x=supprimer("election.txt",111253);
   if(x==1)
     printf("\nsuppression d'election avec succes");
   else printf("\nechec suppression");*/
   E3=chercher("election.txt",3);
   if(E3.identifiant==-1)
     printf("introuvable");
  return 0;
}
