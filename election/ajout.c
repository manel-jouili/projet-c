#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajout.h"
int verifier_ajout()
{E.dt_election=dt_elections
E.municipalite=municipalite
fprintf(f,"%s %d %d %d",E.municipalite,E.dt_elections.jour,E.dt_elections.mois,E.dt_elections.annee);

}
void confirmer_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget combobox1;
date dt_elections;
char municipalite[20];
jour=lookup_widget(objet_graphique,"jour");
mois=lookup_widget(objet_graphique,"mois");
annee=lookup_widget(objet_graphique,"annee");
combobox=lookup_widget(objet_graphique,combobox);
dt_elections.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
dt_elections.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
dt_elections.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX());
municipalite=municipalite[20];
