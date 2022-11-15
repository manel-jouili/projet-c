#include "obs.h"

int ajouter(char * filename, observateur obs )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %d %d \n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,obs.id,obs.num_bv);
       fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, observateur nouv )
{
    int tr=0;
    observateur obs;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");s
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d \n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,&obs.id,&obs.num_bv)!=EOF)
        {
            if(obs.id== id)
            {
                fprintf(f2,"%s %s %s %s %s %d %d\n",nouv.nom,nouv.prenom,nouv.nationalite,nouv.appar,nouv.sexe,nouv.id,nouv.num_bv);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %d %d\n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,obs.id,obs.num_bv);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    observateur obs;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d\n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,&obs.id,&obs.num_bv)!=EOF)
        {
            if(obs.id== id)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %d %d\n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,obs.id,obs.num_bv);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
observateur chercher (char * filename, int id)
{
    observateur obs;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %d %d  %d %d\n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,&obs.id,&obs.num_bv)!=EOF)
        {
            if(obs.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        obs.id=-1;
    return obs;

}
