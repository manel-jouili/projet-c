#include <stdio.h>
#include <string.h>
#include "fichier.h"


int main()
{
    user u1= {"Mohamed","Hssin",123596,"20mli89",01,"1498726","homme",01,11,2022},u2= {"nora","hezzi",126947,"50mli97",02,"14369614","femme",02,11,2022},u3;
    int x=ajouter("fichier.txt", u1);
   
    x=modifier("fichier.txt",1,u2 );

    if(x==1)
        printf("\nModification de user avec succés");
    else printf("\nechec Modification");
    x=supprimer("fichier.txt",1 );
    if(x==1)
        printf("\nSuppression de user avec succés");
    else printf("\nechec Suppression");
    u3=chercher("fichier.txt",3 );
    if(u3.login ==-1)
        printf("introuvable");
    return 0;
}
