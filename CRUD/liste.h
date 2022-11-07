#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include <stdio.h>
typedef struct
{
    int jour;
    int mois;
    int annee;
}date;

typedef struct
{
    int idListe;
    int idtete;
    char orientation[20];
    date date_depot;
    int id1,id2,id3;
    int nbvotes=0;
} liste;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non
//pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ajouter(char *, liste );
int modifier( char *, int, liste );
int supprimer(char *, int );
liste chercher(char *, int);

#endif // LISTE_H_INCLUDED
