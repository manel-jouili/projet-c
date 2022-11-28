#include <gtk/gtk.h>


void
on_ILradiobuttonhomme_group_changed    (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_ILradiobuttonfemme_group_changed    (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_ILButtonajoutera_clicked            (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_comboboxrolea_popdown               (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_ILbuttonmodifiera_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ILbuttonsupprimera_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton14heures_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12heures_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton05k_electeur_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton10k25k_electeur_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5k10k_electeur_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton25k50k_electeur_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton50k100k_electeur_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton100k500k_electeur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton501k_electeur_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonajouter_electeur_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonrecherche_modifier_electeur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttongotomodifier_electeur_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonchercher_annuler_electeur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrechercher_afficher_electeur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficher_electeur_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MJbuttonLogin_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ANbuttonGBV_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ANbuttonGU_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ANbuttonGL_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ANbuttonGE_clicked                  (GtkWidget       *object,
                                        gpointer         user_data);

void
on_ANbuttonGO_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_confAjoutManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier1ManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_RechercheManelBV_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Recherche2ManelBV_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_DeleteManelBV_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_RecherchePManelBV_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_AfficherManelBV_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ConfmodifierManelBV_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimer_electeur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);
