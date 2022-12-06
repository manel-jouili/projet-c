#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "bureaudevote.h"
#include "bureaudevote.c"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>

bureau bu;
char id_bv1[20];
char id_bv2[20];
char cap_obs1[20];
char id_agbv1[20];
int ca=0;
int ca1=0;
void
on_ILradiobuttonhomme_group_changed    (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_ILradiobuttonfemme_group_changed    (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_ILButtonajoutera_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


gboolean
on_comboboxrolea_popdown               (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_ILbuttonmodifiera_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ILbuttonsupprimera_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MJbuttonLogin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GESTION,*LOGINelecteur;

		gtk_widget_show(GESTION);
		gtk_widget_destroy(LOGINelecteur);
	
}


void
on_ANbuttonGBV_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_confAjoutManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id_bv;
GtkWidget *gouv;
GtkWidget *muni;
GtkWidget *cap_elec;
GtkWidget *cap_obs;

GtkWidget *nbrsalle;
GtkWidget *id_agbv;
GtkWidget *GESTION_BV;
bureau b;


int o=0;
id_bv = lookup_widget (GTK_WIDGET(button) ,"IDmanelBV");
gouv = lookup_widget (GTK_WIDGET(button),"GouvManelBV");
muni = lookup_widget (GTK_WIDGET(button),"muniManelBV");
cap_elec = lookup_widget (GTK_WIDGET(button),"capmanelBV");
cap_obs = lookup_widget (GTK_WIDGET(button),"capobsmanel1");
nbrsalle = lookup_widget (GTK_WIDGET(button),"nbrsallemanelBV");
id_agbv = lookup_widget (GTK_WIDGET(button),"idagentmanelBV");


/*GtkWidget *erreur_id_bv,*erreur_id_agbv;
GESTION_BV=lookup_widget(button,"GESTION_BV");
erreur_id_bv=lookup_widget(GESTION_BV,"erreur_id_bv");
erreur_id_agbv=lookup_widget(GESTION_BV,"erreur_id_agbv");
gtk_widget_hide(erreur_id_bv);  
gtk_widget_hide(erreur_id_agbv);  */


b.nbrsalle=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbrsalle));
b.cap_elec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap_elec));

strcpy(b.id_bv, gtk_entry_get_text(GTK_ENTRY(id_bv)));
strcpy(b.gouv, gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
strcpy(b.muni, gtk_combo_box_get_active_text(GTK_COMBO_BOX(muni)));
strcpy(id_agbv1, gtk_combo_box_get_active_text(GTK_COMBO_BOX(id_agbv)));
b.id_agbv = atoi(id_agbv1);
b.cap_obs = ca;










/*sprintf(id_bv2,"%d",b.id_bv);

if (strlen(id_bv2)!=8)
{o=1;
gtk_widget_show(erreur_id_bv);
}
else o=0;*/
 /*if (strcmp(p.nom,"")==0)
{o=1;
gtk_widget_show(erreur_nom1);
}
else o=0;

 if (x1==0)
{
gtk_widget_show(erreur_conf1);
}
if (strcmp(p.nature,"")==0)
{o=1;
gtk_widget_show(erreur_nature1);
}else o=0;
*/


 if(o==0){
ajouter(b);
GESTION_BV=lookup_widget(button,"GESTION_BV");
gtk_widget_destroy(GESTION_BV);
GtkWidget *GESTION_BV;
GESTION_BV = create_GESTION_BV ();
  gtk_widget_show (GESTION_BV);
}

}


void
on_RechercheManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Modifier1ManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GESTION_BV;
GESTION_BV=lookup_widget(button,"GESTION_BV");
gtk_widget_destroy(GESTION_BV);
bureau b;
FILE *f;
f=fopen("fileBureau.txt","r");
GtkWidget *modifier_Bv;
  modifier_Bv = create_ModifierBv ();
  gtk_widget_show (modifier_Bv);
GtkWidget *idManel;
idManel = lookup_widget (modifier_Bv ,"idManel");
while(fscanf(f,"%s %s  %s %d %d %d %d\n",b.id_bv,b.gouv,b.muni,&b.id_agbv,&b.cap_elec,&b.cap_obs,&b.nbrsalle)!=-1){
 if (strcmp(b.id_bv,bu.id_bv)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier_Bv,"idManel")),b.id_bv);
}}
}


void
on_DeleteManelBV_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GESTION_BV;
GESTION_BV=lookup_widget(button,"GESTION_BV");
supprimer_bu(bu.id_bv);
gtk_widget_destroy(GESTION_BV);
GESTION_BV = create_GESTION_BV ();
  gtk_widget_show (GESTION_BV);
}


void
on_Recherche2ManelBV_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AfficherManelBV_clicked             (GtkButton       *button,
                                        gpointer         user_data)

{
GtkWidget *treeview;
/*GtkWidget *AfficherManelBV;
AfficherManelBV=lookup_widget(GTK_WIDGET(button),"AfficherManelBV");*/

treeview=lookup_widget(GTK_WIDGET(button),"treeview11");
afficher_bureau(treeview);






}


void
on_RecherchePManelBV_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_capobsmanel1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca=1;
}


void
on_capobsmanel2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca=2;
}


void
on_capobsmanel3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca=3;
}


void
on_capobsmanel4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	
ca=4;
}


void
on_capobsmanel5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca=5;
}

void
on_treeview16_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id_bv;
	gchar* gouv;
	gchar* muni;
	gchar* var1;
	gchar* var2;
	gchar* var3;
	gchar* var4;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id_bv, 1 , &gouv, 2 , &muni, 3 , &var1, 4 , &var2, 5 , &var3, 6 , &var4,-1);
	strcpy(bu.id_bv,id_bv);
printf(bu.id_bv);
}
}


void
on_AccManel_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
/*GtkWidget *AfficherManelBV;
AfficherManelBV=lookup_widget(GTK_WIDGET(button),"AfficherManelBV");*/

treeview=lookup_widget(GTK_WIDGET(button),"treeview16");
afficher_bureau(treeview);




}


void
on_radiobutton103_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton104_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton105_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton106_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton107_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ModifierManel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id_bv;
GtkWidget *gouv;
GtkWidget *muni;
GtkWidget *cap_elec;
GtkWidget *cap_obs;

GtkWidget *nbrsalle;
GtkWidget *id_agbv;
GtkWidget *modifier_Bv;
bureau b;

int x=0;
int o=0;
modifier_Bv=lookup_widget(button,"modifier_Bv");
id_bv = lookup_widget (GTK_WIDGET(button) ,"idManel");
gouv = lookup_widget (GTK_WIDGET(button),"gouvManel");
muni = lookup_widget (GTK_WIDGET(button),"muniManel");
cap_elec = lookup_widget (GTK_WIDGET(button),"capeleManel");
cap_obs = lookup_widget (GTK_WIDGET(button),"capaciteobs1");
nbrsalle = lookup_widget (GTK_WIDGET(button),"NbrManel");
id_agbv = lookup_widget (GTK_WIDGET(button),"BureauManel");
/*
GtkWidget *erreur_nom2,*erreur_prod_id2,*erreur_conf2,*erreur_nature1;
erreur_nature1=lookup_widget(modifier_st,"erreur_catg2");
erreur_nom2=lookup_widget(modifier_st,"erreur_nom2");
erreur_prod_id2=lookup_widget(modifier_st,"erreur_prod_id2");
erreur_conf2=lookup_widget(modifier_st,"erreur_conf2");

 
gtk_widget_hide(erreur_nom2);  
gtk_widget_hide(erreur_prod_id2);  
gtk_widget_hide(erreur_conf2);
gtk_widget_hide(erreur_nature1);*/
b.nbrsalle=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbrsalle));
b.cap_elec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap_elec));

strcpy(b.id_bv, gtk_entry_get_text(GTK_ENTRY(id_bv)));

strcpy(b.gouv, gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
strcpy(b.muni, gtk_combo_box_get_active_text(GTK_COMBO_BOX(muni)));
strcpy(id_agbv1, gtk_combo_box_get_active_text(GTK_COMBO_BOX(id_agbv)));
b.id_agbv = atoi(id_agbv1);
b.cap_obs = ca1;
/*if (strcmp(p.prod_id,"")==0)
{x=1;
gtk_widget_show(erreur_prod_id2);
}else x=0;
 if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(erreur_nom2);
}else x=0;
if (strcmp(p.nature,"")==0)
{x=1;
gtk_widget_show(erreur_nature1);
}else x=0;

 if (x2==0)
{
gtk_widget_show(erreur_conf2);
}*/
if(x==0){
modifier(bu.id_bv,b);
gtk_widget_destroy(modifier_Bv);
GtkWidget *GESTION_BV;
GESTION_BV = create_GESTION_BV ();
gtk_widget_show (GESTION_BV);
x=0;
}
}


void
on_RetourrManell_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier_Bv;
modifier_Bv=lookup_widget(button,"modifier_Bv");
gtk_widget_destroy(modifier_Bv);
GtkWidget *GESTION_BV;
GESTION_BV = create_GESTION_BV ();
  gtk_widget_show (GESTION_BV);
}


void
on_capaciteobs1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca1=1;
}


void
on_capaciteobs2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca1=2;
}


void
on_capaciteobs3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca1=3;
}


void
on_capaciteobs4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca1=4;
}


void
on_capaciteobs5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
ca1=5;
}


void
on_treeview10_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id_bv;
	gchar* gouv;
	gchar* muni;
	gchar* var1;
	gchar* var2;
	gchar* var3;
	gchar* var4;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id_bv, 1 , &gouv, 2 , &muni, 3 , &var1, 4 , &var2, 5 , &var3, 6 , &var4,-1);
	strcpy(bu.id_bv,id_bv);
printf(bu.id_bv);
}
}


void
on_AccSupprimerManel_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
/*GtkWidget *AfficherManelBV;
AfficherManelBV=lookup_widget(GTK_WIDGET(button),"AfficherManelBV");*/

treeview=lookup_widget(GTK_WIDGET(button),"treeview10");
afficher_bureau(treeview);
}


void
on_rechercheMane_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview11;
GtkWidget *GESTION_BV;
GESTION_BV=lookup_widget(button,"treeview11");
treeview11=lookup_widget(GESTION_BV,"treeview11");
cherch = lookup_widget (button ,"entryrech");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 chercher_bu(treeview11,ch);
}

