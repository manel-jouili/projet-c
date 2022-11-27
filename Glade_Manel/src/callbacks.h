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
