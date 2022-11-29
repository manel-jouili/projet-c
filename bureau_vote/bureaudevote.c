#include "bureaudevote.h"
#include<stdio.h>
int ajouter(bureau b , char filename)
{
    FILE * f=fopen("filename.txt" ,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.ville,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id, bureau nouv, char * filename)
{
bureau b;
    FILE * f=fopen("filename.txt" , "r");
    FILE * f2=fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %s %d %d %d %d\n",&b.id_bv,b.gouv,b.ville,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF)
{
if(b.id_bv!=id)
        fprintf(f2,"%d %s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.ville,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);
else
  fprintf(f2,"%d %s %s %s %d %d %d %d\n",nouv.id_bv,nouv.gouv,nouv.ville,nouv.muni,nouv.id_agbv,nouv.cap_elec, nouv.cap_obs,nouv.nbrsalle);
  

}
        fclose(f);
        fclose(f2);
remove("filename.txt");
rename("aux.txt", "filename.txt");
        return 1;
    }
  
}






int supprimer(int id, char * filename)
{
bureau b;
    FILE * f=fopen("filename.txt", "r");
    FILE * f2=fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %s %d %d %d %d\n",&b.id_bv,b.gouv,b.ville,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF)
{
if(b.id_bv!=id)
       fprintf(f2,"%d %s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.ville,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);


}
        fclose(f);
        fclose(f2);
remove("filename.txt");
rename("aux.txt", "filename.txt");
        return 1;
    }
}



bureau chercher(int id, char * filename)
{
bureau b; int tr=0;
    FILE * f=fopen("filename.txt", "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %s %d %d %d %d\n",&b.id_bv,b.gouv,b.ville,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF && tr==0)
{if(id==b.id_bv)
tr=1;
}
}
if(tr==0)
b.id_bv=-1;
return b;

}
