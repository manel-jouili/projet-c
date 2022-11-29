#include "election.h"
#include <stdio.h>
#include <gtk/gtk.h>
enum{
	ID,
	GOUV,
	MUNI,
	JOUR,
	MOIS,
	ANNEE,
	NBHABITONS,
	NBCONSEILLERS,
	DURE,
	COLUMNS
};
int ajouter(char *filename,election E)
{
FILE * f=fopen(filename,"a");
if(f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %d %d %d\n"
,E.identifiant,E.gouvernorat,E.municipalite,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.nombre_habitons,E.nombre_conseillers,E.dure);  
fclose(f);
return 1;
}
else return 0;
}
int modifier(char *filename,int identifiant,election nouv)
{
int tr=0;
election E;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("nouv.txt","w");
if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%d %s %s %d %d %d %d %d\n",&E.identifiant,E.gouvernorat,E.municipalite,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,&E.nombre_habitons,&E.nombre_conseillers)!=EOF)
{
if(E.identifiant==identifiant)
{ 
fprintf(f2,"%d %s %s %d %d %d %d %d\n",nouv.identifiant,nouv.gouvernorat,nouv.municipalite,nouv.date_election.jour,nouv.date_election.mois,nouv.date_election.annee,nouv.nombre_habitons,nouv.nombre_conseillers);
tr=1;
}
else
fprintf(f2,"%d %s %s %d %d %d %d %d\n",E.identifiant,E.gouvernorat,E.municipalite,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.nombre_habitons,E.nombre_conseillers);
}
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);
return tr;
}
int supprimer(char *filename,int identifiant)
{
	int tr=0;
	election E;
	FILE * f=fopen(filename,"r");
	FILE * f2=fopen("nouv.txt","a+");
	if((f!=NULL)&&(f2!=NULL))
	{
		while(fscanf(f,"%d %s %s %d %d %d %d %d %d\n",&E.identifiant,
								E.gouvernorat,
								E.municipalite,
								&E.date_election.jour,
								&E.date_election.mois,
								&E.date_election.annee,
								&E.nombre_habitons,
								&E.nombre_conseillers,
								&E.dure)!=EOF)
		{
			if(E.identifiant!=identifiant)
				fprintf(f2,"%d %s %s %d %d %d %d %d %d\n",E.identifiant,E.gouvernorat,E.municipalite,E.date_election.jour,E.date_election.mois,E.date_election.annee,E.nombre_habitons,E.nombre_conseillers,E.dure);
		}
		fclose(f);
		fclose(f2);
		remove(filename);
		rename("nouv.txt",filename);
	}
	
	return tr;
}
election chercher(char *filename,int identifiant)
{
election E;
int tr=0;
FILE *f=fopen(filename,"r");
if(f!=NULL)
{
while(tr==0 && fscanf(f,"%d %s %s %d %d %d %d %d\n",&E.identifiant,E.gouvernorat,E.municipalite,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,&E.nombre_habitons,&E.nombre_conseillers)!=EOF)
{
if(E.identifiant==identifiant)
tr=1;
}
}
fclose(f);
if(tr==0)
E.identifiant=-1;
return E;
}
void afficherElection(char *filename,GtkWidget *liste){
	election E;
	FILE *f;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Gouvernorat",renderer,"text",GOUV,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Municipalite",renderer,"text",MUNI,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nombre habitons",renderer,"text",NBHABITONS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nombre conseillers",renderer,"text",NBCONSEILLERS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Duree",renderer,"text",DURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen(filename,"r");
	if(f==NULL)
		return;
	else{
		while(fscanf(f,"%d %s %s %d %d %d %d %d %d\n",&E.identifiant,E.gouvernorat,E.municipalite,&E.date_election.jour,&E.date_election.mois,&E.date_election.annee,&E.nombre_habitons,&E.nombre_conseillers,&E.dure)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,E.identifiant,
								GOUV,E.gouvernorat,
								MUNI,E.municipalite,
								JOUR,E.date_election.jour,
								MOIS,E.date_election.mois,
								ANNEE,E.date_election.annee,
								NBHABITONS,E.nombre_habitons,
								NBCONSEILLERS,E.nombre_conseillers,
								DURE,E.dure,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}


