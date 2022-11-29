#include <stdio.h>
#include <string.h>
#include "bureaudevote.h"

int main()
{
    bureau b1= {1,"Ariena","ArienaEssoghra","Enkhilette",101,150,2,10},b2= {2,"Ariena","ArienaEssoghra","Raoued",201,200,4,16},b3;
    int x=ajouter(b1,"bureau.txt");
    
    
    if(x==1)
        printf("\najout de bureau avec succés");
    else printf("\nechec ajout");
    x=ajouter(b2,"bureau.txt");
    if(x==1)
        printf("\najout de bureau avec succés");
    else printf("\nechec ajout");
        
    x=modifier(1,b2,"bureau.txt" );

    if(x==1)
        printf("\nModification de bureau avec succés");
    else printf("\nechec Modification");
    x=supprimer(1,"bureau.txt" );
    if(x==1)
        printf("\nSuppression de bureau avec succés\n");
    else printf("\nechec Suppression");
    b3=chercher(3,"bureau.txt" );
    if(b3.id_bv==-1)
        printf("introuvable\n");
    return 0;
}


