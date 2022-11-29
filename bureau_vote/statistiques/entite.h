#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include <stdio.h>
#include <string.h>



typedef struct
{

char nom[20];
char prenom[20];
char nationalite[20];
char appar[20];
char sexe[20];
int id;
int num_bv;

}observateur;

typedef struct 
{int j;
int m;
int a;
}date;

typedef struct
{
    int idListe;
    int idtete;
    char orientation[20];
    date date_depot;
    int id1,id2,id3;
    int nbvotes;
    int vote;
    char role[30];
} liste;
float TauxVB(char *filename1);
float Tauxobs(char filename2[],float *taux_obse,float *taux_obsn);



#endif

