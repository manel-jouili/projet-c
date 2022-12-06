#include "bureaudevote.h"
#include<stdio.h>
#include <gtk/gtk.h>
#include <string.h>
void ajouter(bureau b)
{
    FILE * f= NULL;
f = fopen("fileBureau.txt" ,"a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);
        fclose(f);

    }

}

void modifier(char *id, bureau nouv)
{
bureau b;
FILE * f= NULL;
FILE * f2= NULL;
     f=fopen("fileBureau.txt" , "r");
   f2=fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s  %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF)
{
if(strcmp(b.id_bv,id)!=0)
        fprintf(f2,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);
else
  fprintf(f2,"%s %s %s %d %d %d %d\n",nouv.id_bv,nouv.gouv,nouv.muni,nouv.id_agbv,nouv.cap_elec, nouv.cap_obs,nouv.nbrsalle);
  

}
        fclose(f);
        fclose(f2);
remove("fileBureau.txt");
rename("aux.txt", "fileBureau.txt");
    }
  
}






/*int supprimer(char id[], char * fileBureau)
{
bureau b;

    FILE * f=fopen("fileBureau.txt", "r");
    FILE * f2=fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF)
{
if(strcmp(b.id_bv,id)!=0)
       fprintf(f2,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);


}
        fclose(f);
        fclose(f2);
remove("fileBureau.txt");
rename("aux.txt", "fileBureau.txt");
        return 1;
    }
}*/

void supprimer_bu(char *id){

FILE*f=NULL;
FILE*f1=NULL;
bureau b;
f=fopen("fileBureau.txt","r");
f1=fopen("aux.txt","w+");

while(fscanf(f,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=-1){
if(strcmp(b.id_bv,id)!=0)
    fprintf(f1,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,b.id_agbv,b.cap_elec,b.cap_obs,b.nbrsalle);
}
fclose(f);
fclose(f1);
remove("fileBureau.txt");
rename("aux.txt","fileBureau.txt");

}








bureau chercher(char id[], char * fileBureau)
{
bureau b; int tr=0;
    FILE * f=fopen("fileBureau.txt", "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF && tr==0)
{if(strcmp(id,b.id_bv)==0)
tr=1;
}
}
if(tr==0)
strcpy(b.id_bv,"-1");
return b;

}
enum {
ID_BV,
GOUV,
MUNI,
ID_AGBV,
CAP_ELEC,
CAP_OBS,
NBRSALLE,
N_COLUMN,

};


void afficher_bureau(GtkWidget *pListView)
{

 


GtkListStore *pListStore;

GtkTreeViewColumn *pColumn;

GtkCellRenderer *pCellRenderer;

GtkTreeIter pIter;


bureau b;

  char id_bv[20];
    char gouv[20];
    char muni[50];
    int id_agbv;
    int cap_elec;
    int cap_obs;
    int nbrsalle;
    
char var1[50],var2[50],var3[50],var4[50],var5[50];

pListStore=NULL;


FILE *f;

pListStore=gtk_tree_view_get_model(pListView);


if (pListStore== NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_bureau",pCellRenderer,"text", ID_BV,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("gouvernerat",pCellRenderer,"text",GOUV,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("municipalite",pCellRenderer,"text", MUNI,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_agent",pCellRenderer,"text", ID_AGBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("capacite_des_electeurs",pCellRenderer,"text", CAP_ELEC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("capacite_des_observateurs",pCellRenderer,"text", CAP_OBS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nombre_de_salles",pCellRenderer,"text", NBRSALLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);





pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("fileBureau.txt","r");
if (f==NULL){return;}
else{f=fopen("fileBureau.txt","a+");
while(fscanf(f,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF)
	{
sprintf(var1,"%d",b.id_agbv);
sprintf(var2,"%d",b.cap_elec);
sprintf(var3,"%d",b.cap_obs);
sprintf(var4,"%d",b.nbrsalle);
strcpy(id_bv,b.id_bv);
strcpy(gouv,b.gouv);
strcpy(muni,b.muni);

///

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,ID_BV,id_bv,GOUV,gouv,MUNI,muni,ID_AGBV,var1,CAP_ELEC,var2,CAP_OBS,var3,NBRSALLE,var4,-1);


}

fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);
       }
}
}



void chercher_bu(GtkWidget *pListView, char ch[30])
{
  
GtkListStore *pListStore;

GtkTreeViewColumn *pColumn;

GtkCellRenderer *pCellRenderer;

GtkTreeIter pIter;


bureau b;

  char id_bv[20];
    char gouv[20];
    char muni[50];
    int id_agbv;
    int cap_elec;
    int cap_obs;
    int nbrsalle;
    
char var1[50],var2[50],var3[50],var4[50],var5[50];

pListStore=NULL;


FILE *f;

pListStore=gtk_tree_view_get_model(pListView);


if (pListStore== NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_bureau",pCellRenderer,"text", ID_BV,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("gouvernerat",pCellRenderer,"text",GOUV,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("municipalite",pCellRenderer,"text", MUNI,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_agent",pCellRenderer,"text", ID_AGBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("capacite_des_electeurs",pCellRenderer,"text", CAP_ELEC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("capacite_des_observateurs",pCellRenderer,"text", CAP_OBS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nombre_de_salles",pCellRenderer,"text", NBRSALLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


}
pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	    f=fopen("fileBureau.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			//f=fopen("produit.txt","a+");
			while(fscanf(f,"%s %s %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=EOF)
sprintf(var1,"%d",b.id_agbv);
sprintf(var2,"%d",b.cap_elec);
sprintf(var3,"%d",b.cap_obs);
sprintf(var4,"%d",b.nbrsalle);
strcpy(id_bv,b.id_bv);
strcpy(gouv,b.gouv);
strcpy(muni,b.muni);
			{if (strcmp(b.id_bv,ch)==0){
                                       gtk_list_store_append(pListStore, &pIter);
                                       gtk_list_store_set(pListStore, &pIter,ID_BV,id_bv,GOUV,gouv,MUNI,muni,ID_AGBV,var1,CAP_ELEC,var2,CAP_OBS,var3,NBRSALLE,var4,-1);
			}}
			fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);
	    }
}

