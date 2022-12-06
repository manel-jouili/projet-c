#ifndef BUREAU_H_INCLUDED
#define BUREAU_H_INCLUDED

typedef struct{
   
    char id_bv[20];
    char gouv[20];
    char muni[50];
    int id_agbv;
    int cap_elec;
    int cap_obs;
    int nbrsalle;
    
    
}bureau; 

void ajouter(bureau b);
void modifier(char *id, bureau nouv);
//int supprimer(char id[], char * filename);
void afficher_bureau(GtkWidget *pListView);
bureau chercher(char id[], char * filename);
void supprimer_bu(char *id);
void chercher_bu(GtkWidget *liste, char ch[30]);


#endif // BUREAU_H_INCLUDED
