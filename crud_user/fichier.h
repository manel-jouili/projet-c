#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <stdio.h>
typedef struct 
{int j;
int m;
int a;
}date;
typedef struct 
{char nom [20];
char prenom [20];
int login ;
char mdp [20];
int nbv;
char cin[20];
char sexe[20];
date d_u;
}user;
int ajouter(char * filename, user);
int modifier ( char * filename, int, user);
int supprimer(char * filename,int);
user chercher (char * filename,int);
float age_Moyen(char * filename);
int nbe( char * filename, int);
#endif


