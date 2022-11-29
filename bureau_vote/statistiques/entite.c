#include "entite.h"






float TauxVB(char filename1[])
{
 float taux;
 liste l;
 int nbr_v;
 int nbr_vb=0;
 FILE *f=fopen(filename1,"r");
 if (f!=NULL)
 {
     while(fscanf(f,"%d %d %s %d %d  %d %d %d %d %d %s \n ",&l.idListe,&l.idtete,l.orientation,&l.id1,&l.id2,&l.id3,&l.date_depot.j,&l.date_depot.m,&l.date_depot.a,&l.vote,l.role)!=EOF)
      {  if((strcmp(l.role,"élécteur")==0)&&(l.vote!=-1))
            { nbr_v++;}
         if (l.vote==0)
            {nbr_vb++;}
      }
 }
 taux=(float)(nbr_vb/nbr_v)*100;
 fclose(f);
 return taux;
}









float Tauxobs(char filename2[],float *taux_obse, float *taux_obsn)
{
    observateur obs;
    int nbr_obsn=0;
    int nbr_obse=0;
    int nbr_obs=0;
    FILE *f=fopen(filename2,"r");
 if (f!=NULL)
  {
     while(fscanf(f,"%s %s %s %s %s %d %d\n",obs.nom,obs.prenom,obs.nationalite,obs.appar,obs.sexe,&obs.id,&obs.num_bv)!=EOF)
      {
         nbr_obs++;   
         if(strcmp(obs.nationalite,"tunisienne")==0)
          
            nbr_obsn++;
        
         else 
            nbr_obse++;
      }}
  

*taux_obse=(float)(nbr_obse/nbr_obs)*100;
*taux_obsn=(float)(nbr_obsn/nbr_obs)*100;
fclose(f);
return 0;}
