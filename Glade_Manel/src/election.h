#include <stdio.h>
#include <gtk/gtk.h>
#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
typedef struct{
int jour;
int mois;
int annee;
}date;
typedef struct{
int identifiant;
char gouvernorat[20];
char municipalite[30];
date date_election;
int dure;
int nombre_habitons;
int nombre_conseillers;
}election;
int ajouter (char *filename,election E);
int modifier(char *filename,int identifiant,election nouv);
int supprimer(char *filename,int identifiant);
election chercher(char *filename,int identifiant);
void afficherElection(char *filename,GtkWidget *liste);
#endif
