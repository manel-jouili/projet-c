#include <stdio.h>
#include <string.h>
#include"liste.h"

int main()
{
    liste l1= {001,11,"Droite",5,3,2022,12,13,14},l2= {002,21,"Centre",15,9,2021,22,23,24},l3;
    int x=ajouter("liste.txt", l1);
    if(x==1)
        printf("\najout de liste avec succés");
    else printf("\nechec ajout");
    x=modifier("liste.txt",002,l2 );
    if(x==1)
        printf("\nModification de liste avec succés");
    else printf("\nechec Modification");
    x=supprimer("liste.txt",002 );
    if(x==1)
        printf("\nSuppression de liste avec succés");
    else printf("\nechec Suppression");
    l3=chercher("liste.txt",003 );
    if(l3.idListe==-1)
        printf("introuvable");
    return 0;
}
