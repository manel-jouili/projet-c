
#include "fichier.h"

int ajouter(char * filename, user u )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %s %d %s %d %d %d\n",u.nom,u.prenom,u.login,u.sexe,u.mdp,u.nbv,u.cin,u.d_u.j,u.d_u.m,u.d_u.a);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, user nouv )
{
    int tr=0;
    user u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %s %d %s %d %d %d\n",u.nom,u.prenom,	&u.login,u.sexe,u.mdp,&u.nbv,u.cin,&u.d_u.j,&u.d_u.m,&u.d_u.a)!=EOF)
        {
            if(u.login== id)
            {
                fprintf(f2,"%s %s %s %d %s %d %s %d %d %d\n",nouv.nom,nouv.prenom,nouv.sexe,nouv.login,nouv.mdp,nouv.nbv,nouv.cin,nouv.d_u.j,nouv.d_u.m,nouv.d_u.a);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %s %s %d %s %d %d %d\n",u.nom,u.prenom,u.login,u.sexe,u.mdp,u.nbv,u.cin,u.d_u.j,u.d_u.m,u.d_u.a);

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
    user u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %s %d %s %d %d %d\n",u.nom,u.prenom,&u.login,u.sexe,u.mdp,&u.nbv,u.cin,&u.d_u.j,&u.d_u.m,&u.d_u.a)!=EOF)
        {
            if(u.login== id)
                tr=1;
            else
                fprintf(f2,"%s %s %d %s %s %d %s %d %d %d \n",u.nom,u.prenom,u.login,u.sexe,u.mdp,u.nbv,u.cin,u.d_u.j,u.d_u.m,u.d_u.a);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
user chercher (char * filename, int id)
{
    user u;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %s %s %d %s %d %d %d \n",u.nom,u.prenom,&u.login,u.sexe,u.mdp,&u.nbv,u.cin,&u.d_u.j,&u.d_u.m,&u.d_u.a)!=EOF)
        {
            if(u.login== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.login=-1;
    return u;
}
float age_Moyen(char * filename)
{
int sum=0;
int num=0;
float age_m;
user u;
 FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %s %d %s %d %d %d \n",u.nom,u.prenom,&u.login,u.sexe,u.mdp,&u.nbv,u.cin,&u.d_u.j,&u.d_u.m,&u.d_u.a)!=EOF)
    {
sum+=2022-u.d_u.a;
num+=1;
}
}
 fclose(f);
age_m=sum/num;
return age_m;
}
int nbe( char * filename, int id )
{

int  n =0;
int tr =0;
user u;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %s %s %d %s %d %d %d\n",u.nom,u.prenom,&u.login,u.sexe,u.mdp,&u.nbv,u.cin,&u.d_u.j,&u.d_u.m,&u.d_u.a)!=EOF)
   
        {
           
              if(u.nbv==id){ 
                 tr =1;
                 n = n+1 ;
                

 
                    }
}
 }
   

    fclose(f);
if (tr==0){
u.nbv =-1;}
  

    
return n;

}
