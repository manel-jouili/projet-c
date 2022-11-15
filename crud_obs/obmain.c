#include <stdio.h>
#include <string.h>
#include"obs.h"

int main()
{
    observateur obs1= {126985,"asma","malm","tunisienne","politique",01,"femme"},obs2= {127463,"jalel","mahmoud","tunisienne","presse",02,"homme"},obs3;
    int x=ajouter("fichier.txt", obs1);
   
    x=modifier("fichier.txt",1,obs2 );

    if(x==1)
        printf("\nModification de user avec succés");
    else printf("\nechec Modification");
    x=supprimer("fichier.txt",1 );
    if(x==1)
        printf("\nSuppression de user avec succés");
    else printf("\nechec Suppression");
    obs3=chercher("fichier.txt",3 );
    if(obs3.id ==-1)
        printf("introuvable");
    return 0;
}
