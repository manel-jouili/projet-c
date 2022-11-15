#ifndef obs_H_INCLUDED
#define obs_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{

char nom[20];
char prenom[20];
char nationalite[20];
char appar[20];
char sexe;
int id;
int num_bv;

}observateur;
int ajouter(char *, observateur );
int modifier( char *, int, observateur );
int supprimer(char *, int );
observateur chercher (char *, int);

#endif
