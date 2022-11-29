#ifndef BUREAU_H_INCLUDED
#define BUREAU_H_INCLUDED

typedef struct{
   
    int id_bv;
    char gouv[20];
    char ville[20];
    char muni[50];
    int id_agbv;
    int cap_elec;
    int cap_obs;
    int nbrsalle;
    
    
}bureau; 

int ajouter(bureau b , char filename);
int modifier(int id, bureau nouv , char * filename);
int supprimer(int id, char * filename);
bureau chercher(int id, char * filename);

#endif // BUREAU_H_INCLUDED
