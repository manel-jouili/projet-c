#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "election.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


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

int dure=14;
void
on_radiobutton14heures_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		dure=14;
}


void
on_radiobutton12heures_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		dure=12;
}

int nbrhabitons=0;
int nbconseillers=0;
void
on_radiobutton05k_electeur_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=5000;
		nbconseillers=10;
	}
		
}


void
on_radiobutton10k25k_electeur_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=25000;
		nbconseillers=16;
	}
}


void
on_radiobutton5k10k_electeur_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=10000;
		nbconseillers=12;
	}
}


void
on_radiobutton25k50k_electeur_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=50000;
		nbconseillers=22;
	}
}


void
on_radiobutton50k100k_electeur_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=100000;
		nbconseillers=30;
	}
}


void
on_radiobutton100k500k_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=500000;
		nbconseillers=40;
	}
}


void
on_radiobutton501k_electeur_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		nbrhabitons=500005;
		nbconseillers=60;
	}
}


void
on_buttonajouter_electeur_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	election e;
	GtkWidget *id,*gouv,*munici,*jour,*mois,*annee;
	id=lookup_widget(objet,"entryid_electeur");
	gouv=lookup_widget(objet,"comboboxgouvernerat_electeur");
	munici=lookup_widget(objet,"comboboxmunicipalite_electeur");
	jour=lookup_widget(objet,"spinbuttonjour_electeur");
	mois=lookup_widget(objet,"spinbuttonmois_electeur");
	annee=lookup_widget(objet,"spinbuttonannee_electeur");
	e.identifiant=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
	e.date_election.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	e.date_election.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	e.date_election.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	strcpy(e.gouvernorat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
	strcpy(e.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munici)));
	e.dure=dure;
	e.nombre_habitons=nbrhabitons;
	e.nombre_conseillers=nbconseillers;
	ajouter("election.txt",e);
	
	
}


void
on_buttonrecherche_modifier_electeur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttongotomodifier_electeur_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonchercher_annuler_electeur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonrechercher_afficher_electeur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonafficher_electeur_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *GESTION_ELECTEUR,*treeviewafficher_electeur;
	GESTION_ELECTEUR=lookup_widget(objet,"GESTION_ELECTION");
	treeviewafficher_electeur=lookup_widget(GESTION_ELECTEUR,"treeviewafficher_electeur");
	afficherElection("election.txt",treeviewafficher_electeur);
}


void
on_MJbuttonLogin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ANbuttonGBV_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ANbuttonGU_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ANbuttonGL_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ANbuttonGE_clicked                  (GtkWidget       *object,
                                        gpointer         user_data)
{
	GtkWidget *GESTION_ELECTION,*GESTION,*treeviewafficher_electeur,*treeviewafficher_modifier_electeur,*treeviewafficher_annuler_electeur;
	GESTION=lookup_widget(object,"GESTION");
	GESTION_ELECTION=lookup_widget(object,"GESTION_ELECTION");
	gtk_widget_destroy(GESTION);
	GESTION_ELECTION = create_GESTION_ELECTION ();
	gtk_widget_show (GESTION_ELECTION);
	
	
	treeviewafficher_electeur=lookup_widget(GESTION_ELECTION,"treeviewafficher_electeur");
	treeviewafficher_modifier_electeur=lookup_widget(GESTION_ELECTION,"treeviewafficher_modifier_electeur");
	treeviewafficher_annuler_electeur=lookup_widget(GESTION_ELECTION,"treeviewafficher_annuler_electeur");
	afficherElection("election.txt",treeviewafficher_electeur);
	afficherElection("election.txt",treeviewafficher_modifier_electeur);
	afficherElection("election.txt",treeviewafficher_annuler_electeur);
}


void
on_ANbuttonGO_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_confAjoutManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Modifier1ManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_RechercheManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Recherche2ManelBV_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_DeleteManelBV_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_RecherchePManelBV_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_AfficherManelBV_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ConfmodifierManelBV_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsupprimer_electeur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeviewafficher_annuler_electeur,*GESTION_ELECTION;
	GtkTreeModel *model;
	GtkTreeSelection *selection;
	GtkTreeIter iter;
	gint id;
	GESTION_ELECTION=lookup_widget(objet,"GESTION_ELECTION");
	treeviewafficher_annuler_electeur=lookup_widget(GESTION_ELECTION,"treeviewafficher_annuler_electeur");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeviewafficher_annuler_electeur));
	if(gtk_tree_selection_get_selected(selection,&model,&iter)){
		gtk_tree_model_get(model,&iter,0,&id,-1);
		supprimer("election.txt",id);
		afficherElection("election.txt",treeviewafficher_annuler_electeur);
	}
}

