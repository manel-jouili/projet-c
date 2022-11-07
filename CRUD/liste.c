#include "liste.h"

int ajouter(char * filename, liste l )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %s %d %d %d %d %d %d \n",l.idListe,l.idtete,l.orientation,l.date_depot.jour,l.date_depot.mois,l.date_depot.annee,l.id1,l.id2,l.id3);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, liste nouv )
{
    int tr=0;
    liste l;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %d %d %d %d %d %d \n",&l.idListe,&l.idtete,l.orientation,&l.date_depot.jour,&l.date_depot.mois,&l.date_depot.annee,&l.id1,&l.id2,&l.id3)!=EOF)
        {
            if(l.idListe== id)
            {
                fprintf(f2,"%d %d %s %d %d %d %d %d %d \n",nouv.idListe,nouv.idtete,nouv.orientation,nouv.date_depot.jour,nouv.date_depot.mois,nouv.date_depot.annee,nouv.id1,nouv.id2,nouv.id3);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %s %d %d %d %d %d %d \n",l.idListe,l.idtete,l.orientation,l.date_depot.jour,l.date_depot.mois,l.date_depot.annee,l.id1,l.id2,l.id3);

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
    liste l;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %d %d %d %d %d %d \n",&l.idListe,&l.idtete,l.orientation,&l.date_depot.jour,&l.date_depot.mois,&l.date_depot.annee,&l.id1,&l.id2,&l.id3)!=EOF)
        {
            if(l.idListe== id)
                tr=1;
            else
                fprintf(f2,"%d %d %s %d %d %d %d %d %d \n",l.idListe,l.idtete,l.orientation,l.date_depot.jour,l.date_depot.mois,l.date_depot.annee,l.id1,l.id2,l.id3);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
liste chercher(char * filename, int id)
{
    liste l;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %s %d %d %d %d %d %d \n",&l.idListe,&l.idtete,l.orientation,&l.date_depot.jour,&l.date_depot.mois,&l.date_depot.annee,&l.id1,&l.id2,&l.id3)!=EOF)
        {
            if(l.idListe== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        l.idListe=-1;
    return l;

}
