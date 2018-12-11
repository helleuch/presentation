#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"

#include "support.h"
#include "login.h"
#include "admin.h"
#include "kine.h"
#include "rdv.h"
#include "nutri.h"
#include "treeview_admin.h"
#include "treeview_login.h"


void
on_button_home_quit_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_main_quit();
}


void
on_button_home_login_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  char login[30];char password[30]; int role;int x;

	GtkWidget *input1=lookup_widget(objet_graphique,"entry_login");
	GtkWidget *input2=lookup_widget(objet_graphique,"entry_pwd");
	GtkWidget *output=lookup_widget(objet_graphique,"label_home_error");
	GtkWidget *window_home;
  	GtkWidget *window_admin;
  	GtkWidget *window_kine;
  	GtkWidget *window_nutri;
	GtkWidget *treeview_admin;
	GtkWidget *liste;



	window_home=lookup_widget(objet_graphique,"window_home");



	strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

	x=check_login(login,password);

	switch(x){
    case 1 : {
        window_admin = create_window_admin();
        gtk_widget_destroy(window_home);
        gtk_widget_show(window_admin);
	treeview_admin = lookup_widget(window_admin,"treeview_admin");
	personne(treeview_admin);
      }break;

    case 4 : {
        window_kine = create_window_kine();
        gtk_widget_destroy(window_home);
        gtk_widget_show(window_kine);
      }break;

    case 5 : {
        window_nutri = create_window_nutri();
        gtk_widget_destroy(window_home);
        gtk_widget_show(window_nutri);
      }break;

    case -1 : {
      	gtk_label_set_text(GTK_LABEL(output),"Nom d'utilisateur ou mot de passe incorrect !");
      }break;

      case -2 : {
        	gtk_label_set_text(GTK_LABEL(output),"Veuillez saisir un nom d'utilisateur !");
        }break;

      case -3 : {
          gtk_label_set_text(GTK_LABEL(output),"Veuillez saisir un mot de passe !");
        }break;


		default : printf("Error : unindentified role.\n");
		}

	}

void
on_button_admin_logout_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_home;
  GtkWidget *window_admin;
	window_admin=lookup_widget(objet_graphique,"window_admin");

  window_home = create_window_home();
  gtk_widget_destroy(window_admin);
  gtk_widget_show(window_home);
}


void
on_button_admin_refresh_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
 perso p;

	GtkWidget *window_admin;
	window_admin=lookup_widget(objet_graphique,"window_admin");
	GtkWidget *treeview_admin;
	treeview_admin = lookup_widget(window_admin,"treeview_admin");
  	personne(treeview_admin);
}


void
on_button_admin_del_clicked  (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_del_user;
	window_admin_del_user = create_window_admin_del_user();
	gtk_widget_show(window_admin_del_user);
}


void
on_button_admin_edit_clicked  (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_mod_user;
	window_admin_mod_user = create_window_admin_mod_user();
	gtk_widget_show(window_admin_mod_user);
}


void
on_button_admin_add_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_admin_add_user;
  window_admin_add_user = create_window_admin_add_user();
  gtk_widget_show(window_admin_add_user);
}

void
on_button_kine_patients_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine;
  GtkWidget *window_kine_patients;
  window_kine = lookup_widget(objet_graphique,"window_kine");
  window_kine_patients = create_window_kine_patients();

  GtkWidget *label_kine_add_patient_1;
  GtkWidget *entry_kine_add_patient;
  GtkWidget *button_kine_add_patient_validate;
  GtkWidget *button_kine_add_patient_end;
  GtkWidget *treeview_kine_patients;

  label_kine_add_patient_1 = lookup_widget(window_kine_patients,"label_kine_add_patient_1");
  entry_kine_add_patient = lookup_widget(window_kine_patients,"entry_kine_add_patient");
  button_kine_add_patient_validate = lookup_widget(window_kine_patients,"button_kine_add_patient_validate");
  button_kine_add_patient_end = lookup_widget(window_kine_patients,"button_kine_add_patient_end");
  treeview_kine_patients = lookup_widget(window_kine_patients,"treeview_kine_patients");
  kine_show_patients(treeview_kine_patients);

  gtk_widget_show(window_kine_patients);
  gtk_widget_hide(label_kine_add_patient_1);
  gtk_widget_hide(entry_kine_add_patient);
  gtk_widget_hide(button_kine_add_patient_validate);
  gtk_widget_hide(button_kine_add_patient_end);
  gtk_widget_destroy(window_kine);

}


void
on_button_kine_logout_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_home;
  GtkWidget *window_kine;
  window_kine = lookup_widget(objet_graphique,"window_kine");
  gtk_widget_destroy(window_kine);
  window_home = create_window_home();
  gtk_widget_show(window_home);
}


void
on_button_kine_quit_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void
on_button_kine_rdv_clicked (GtkWidget *objet_graphique, gpointer user_data)
{

  GtkWidget *window_kine;
  GtkWidget *window_kine_rdv;
  window_kine = lookup_widget(objet_graphique,"window_kine");
  window_kine_rdv = create_window_kine_rdv();

  GtkWidget *treeview_kine_rdv;
  treeview_kine_rdv = lookup_widget(window_kine_rdv,"treeview_kine_rdv");
  rdv_show(treeview_kine_rdv);
  rdv_widget_hide_all(window_kine_rdv);
  gtk_widget_show(window_kine_rdv);
  gtk_widget_destroy(window_kine);
}

void
on_button_kine_patient_back_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_patients;
  GtkWidget *window_kine;
  window_kine_patients = lookup_widget(objet_graphique,"window_kine_patients");
  gtk_widget_destroy(window_kine_patients);
  window_kine = create_window_kine();
  gtk_widget_show(window_kine);
}


void
on_button_kine_patients_refresh_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_patients;
  GtkWidget *treeview_kine_patients;
  window_kine_patients = lookup_widget(objet_graphique,"window_kine_patients");
  treeview_kine_patients = lookup_widget(window_kine_patients,"treeview_kine_patients");
  kine_show_patients(treeview_kine_patients);
}

void
on_button_kine_patients_add_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *window_kine_patients;
GtkWidget *label_kine_add_patient_1;
GtkWidget *entry_kine_add_patient;
GtkWidget *button_kine_add_patient_validate;
GtkWidget *button_kine_add_patient_end;

window_kine_patients = lookup_widget(objet_graphique,"window_kine_patients");
label_kine_add_patient_1 = lookup_widget(objet_graphique,"label_kine_add_patient_1");
entry_kine_add_patient = lookup_widget(objet_graphique,"entry_kine_add_patient");
button_kine_add_patient_validate = lookup_widget(objet_graphique,"button_kine_add_patient_validate");
button_kine_add_patient_end = lookup_widget(objet_graphique,"button_kine_add_patient_end");

gtk_widget_show(label_kine_add_patient_1);
gtk_widget_show(entry_kine_add_patient);
gtk_widget_show(button_kine_add_patient_validate);
gtk_widget_show(button_kine_add_patient_end);

}


void
on_button_kine_add_patient_validate_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  char id_str[5], success_str[100];
  int failed;
  GtkWidget *dialog_kine_add_patient;
  GtkWidget *entry_kine_add_patient;
  GtkWidget *label_dialog_kine_add_patient;

  dialog_kine_add_patient = create_dialog_kine_add_patient();
  label_dialog_kine_add_patient = lookup_widget(dialog_kine_add_patient,"label_dialog_kine_add_patient");
  entry_kine_add_patient = lookup_widget(objet_graphique,"entry_kine_add_patient");

  strcpy(id_str,(gtk_entry_get_text(GTK_ENTRY(entry_kine_add_patient))));

  strcpy(success_str,"Succès de l'ajout du patient : ");

  failed = kine_add_patient(id_str);

  if(failed == 0){
    strcat(success_str,id_str);
    gtk_label_set_text(GTK_LABEL(label_dialog_kine_add_patient),success_str);
  }
  else if(failed == -1){
    gtk_label_set_text(GTK_LABEL(label_dialog_kine_add_patient),"Erreur : Cet ID n'existe pas dans la base de données !");
  }
  else{
    printf("ERROR: could not add patient.");
    gtk_label_set_text(GTK_LABEL(label_dialog_kine_add_patient),"INTERNAL ERROR : Please retry operation.");
  }

  gtk_widget_show(dialog_kine_add_patient);
}

void
on_button_dialog_kine_add_patient_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *dialog;
  dialog = lookup_widget(objet_graphique,"dialog_kine_add_patient");
  gtk_widget_destroy(dialog);
}



void
on_button_kine_add_patient_end_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_patients;
  GtkWidget *label_kine_add_patient_1;
  GtkWidget *entry_kine_add_patient;
  GtkWidget *button_kine_add_patient_validate;
  GtkWidget *button_kine_add_patient_end;

  window_kine_patients = lookup_widget(objet_graphique,"window_kine_patients");
  label_kine_add_patient_1 = lookup_widget(window_kine_patients,"label_kine_add_patient_1");
  entry_kine_add_patient = lookup_widget(window_kine_patients,"entry_kine_add_patient");
  button_kine_add_patient_validate = lookup_widget(window_kine_patients,"button_kine_add_patient_validate");
  button_kine_add_patient_end = lookup_widget(window_kine_patients,"button_kine_add_patient_end");

  gtk_widget_hide(label_kine_add_patient_1);
  gtk_widget_hide(entry_kine_add_patient);
  gtk_widget_hide(button_kine_add_patient_validate);
  gtk_widget_hide(button_kine_add_patient_end);
}

void
on_button_nutri_quit_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  gtk_main_quit();
}


void
on_button_nutri_logout_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_home;
  GtkWidget *window_nutri;

  window_home = create_window_home();
  window_nutri = lookup_widget(objet_graphique, "window_nutri");

  gtk_widget_destroy(window_nutri);
  gtk_widget_show(window_home);
}

void
on_button_nutri_msg_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_nutri;
  GtkWidget *window_nutri_msg;

  window_nutri = lookup_widget(objet_graphique,"window_nutri");
  window_nutri_msg = create_window_nutri_msg();

  gtk_widget_destroy(window_nutri);
  gtk_widget_show(window_nutri_msg);
}


void
on_button_nutri_msg_back_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_nutri;
  GtkWidget *window_nutri_msg;

  window_nutri_msg = lookup_widget(objet_graphique,"window_nutri_msg");
  window_nutri = create_window_nutri();

  gtk_widget_destroy(window_nutri_msg);
  gtk_widget_show(window_nutri);
}

void
on_button_kine_rdv_add_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_rdv;
  GtkWidget *treeview_kine_rdv_patients;
  window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");
  treeview_kine_rdv_patients = lookup_widget(objet_graphique,"treeview_kine_rdv_patients");
  kine_show_patients(treeview_kine_rdv_patients);

  set_mode(window_kine_rdv, 1);
  rdv_widget_hide_all(window_kine_rdv);
  rdv_widget_add_show(window_kine_rdv);
}

void
on_button_rdv_back_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine;
  GtkWidget *window_kine_rdv;

  window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");
  window_kine = create_window_kine();

  gtk_widget_destroy(window_kine_rdv);
  gtk_widget_show(window_kine);
}

void
on_button_kine_rdv_cancel_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_rdv;
  window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");
  rdv_widget_hide_all(window_kine_rdv);
  set_mode(window_kine_rdv, 0);
}

void
on_button_kine_rdv_refresh_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_rdv;
  GtkWidget *treeview_kine_rdv;
  window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");
  treeview_kine_rdv = lookup_widget(window_kine_rdv,"treeview_kine_rdv");
  rdv_show(treeview_kine_rdv);
}

void
on_button_kine_rdv_validate_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  int success;
  char msg[60];
  success = rdv_add(objet_graphique);
  if(success == 0)
    strcpy(msg,"Succès de la création du rendez-vous !");
  else if (success == -1)
    strcpy(msg,"Erreur : Veuillez entrer une ID présente dans la liste !");
  else
    strcpy(msg,"INTERNAL ERROR : please try again");

  GtkWidget *dialog_kine_add_rdv;
  GtkWidget *window_kine_rdv;
  GtkWidget *treeview_kine_rdv;
  GtkWidget *label_dialog_kine_add_rdv;
  dialog_kine_add_rdv =create_dialog_kine_add_rdv();
  label_dialog_kine_add_rdv = lookup_widget(dialog_kine_add_rdv,"label_dialog_kine_add_rdv");
  gtk_label_set_text(GTK_LABEL(label_dialog_kine_add_rdv),msg);
  gtk_widget_show(dialog_kine_add_rdv);
  window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");
  treeview_kine_rdv = lookup_widget(objet_graphique,"treeview_kine_rdv");
  rdv_show(treeview_kine_rdv);

}

void
on_okbutton_dialog_kine_add_rdv_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *dialog_kine_add_rdv;
    dialog_kine_add_rdv = lookup_widget(objet_graphique,"dialog_kine_add_rdv");
    gtk_widget_destroy(dialog_kine_add_rdv);
}

void
on_button_kine_rdv_edit_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_kine_rdv;
  GtkWidget *treeview_kine_rdv_patients;
  treeview_kine_rdv_patients = lookup_widget(objet_graphique,"treeview_kine_rdv_patients");
  window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");
  kine_show_patients(treeview_kine_rdv_patients);

  set_mode(window_kine_rdv, 2);
  rdv_widget_hide_all(window_kine_rdv);
  rdv_widget_edit_show(window_kine_rdv);

}


void
on_button_kine_rdv_delete_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *window_kine_rdv;
 window_kine_rdv = lookup_widget(objet_graphique,"window_kine_rdv");

 set_mode(window_kine_rdv, 3);
 rdv_widget_hide_all(window_kine_rdv);
 rdv_widget_delete_show(window_kine_rdv);
}


void
on_button_kine_validate_delete_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *entry;
  GtkWidget *treeview;
  entry = lookup_widget(objet_graphique,"entry_kine_rdv_3");
  char input_id[5];
  strcpy(input_id,gtk_entry_get_text(GTK_ENTRY(entry)));
  rdv_delete(input_id);
  treeview = lookup_widget(objet_graphique,"treeview_kine_rdv");

  GtkWidget *dialog;
  dialog = create_dialog_kine_add_rdv();
  GtkWidget *label;
  label = lookup_widget(dialog,"label_dialog_kine_add_rdv");
  gtk_label_set_text(GTK_LABEL(label),"Succès de la suppression du rendez-vous séléctionné !");
  gtk_widget_show(dialog);
  rdv_show(treeview);

}


void
on_button_kine_rdv_validate_edit_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *label;
  GtkWidget *entry;
  GtkWidget *treeview;
  GtkWidget *dialog;

  entry = lookup_widget(objet_graphique,"entry_kine_rdv_3");

  treeview = lookup_widget(objet_graphique,"treeview_kine_rdv");

  rdv_update(objet_graphique);

  dialog = create_dialog_kine_add_rdv();
  label = lookup_widget(dialog,"label_dialog_kine_add_rdv");
  gtk_label_set_text(GTK_LABEL(label),"Succès de la modification du rendez-vous séléctionné !");
  gtk_widget_show(dialog);

  rdv_show(treeview);
}

void
on_button_modusr_modifier_clicked      (GtkWidget *object_graphique, gpointer user_data)
{
user u;
date d;
int x;

GtkWidget *output=lookup_widget(object_graphique,"label_modusr");
GtkWidget *input1=lookup_widget(object_graphique,"entry_modusr_id");
GtkWidget *input2=lookup_widget(object_graphique,"entry_modusr_nom");
GtkWidget *input3=lookup_widget(object_graphique,"entry_modusr_prenom");
GtkWidget *input4=lookup_widget(object_graphique,"entry_modusr_ville");
GtkWidget *input5=lookup_widget(object_graphique,"entry_modusr_zip");
GtkWidget *input6=lookup_widget(object_graphique,"entry_modusr_adresse");
GtkWidget *input7=lookup_widget(object_graphique,"entry_modusr_tel");
GtkWidget *j=lookup_widget(object_graphique, "spinbutton_modusr1");
GtkWidget *m=lookup_widget(object_graphique, "spinbutton_modusr2");
GtkWidget *a=lookup_widget(object_graphique, "spinbutton_modusr3");

  strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(u.ville,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(u.postal,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(u.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(u.tel,gtk_entry_get_text(GTK_ENTRY(input7)));

  d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (j));
  d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (m));
  d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (a));

x=mod_user(u,d);
	if (x==1)
	{
	gtk_label_set_text(GTK_LABEL(output),"Veuillez entrer un ID !");
	}
	else if(x==2)
	{
	gtk_label_set_text(GTK_LABEL(output),"L'utilisateur n'est pas trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"L'utilisateur est modifié !");
	}
}


void
on_button_modusr_show_clicked          (GtkWidget *object_graphique, gpointer user_data)
{
user u;
date d;
char x[30];

  GtkWidget *input1=lookup_widget(object_graphique,"entry_modusr_nom");
  GtkWidget *input2=lookup_widget(object_graphique,"entry_modusr_prenom");
  GtkWidget *input3=lookup_widget(object_graphique,"entry_modusr_ville");
  GtkWidget *input4=lookup_widget(object_graphique,"entry_modusr_zip");
  GtkWidget *input5=lookup_widget(object_graphique,"entry_modusr_adresse");
  GtkWidget *input6=lookup_widget(object_graphique,"entry_modusr_tel");
  GtkWidget *input7=lookup_widget(object_graphique,"entry_modusr_id");

  GtkWidget *j=lookup_widget(object_graphique, "spinbutton_modusr1");
  GtkWidget *m=lookup_widget(object_graphique, "spinbutton_modusr2");
  GtkWidget *a=lookup_widget(object_graphique, "spinbutton_modusr3");

  strcpy(x,gtk_entry_get_text(GTK_ENTRY(input7)));

  copier(&u,&d,x);

  gtk_entry_set_text(GTK_ENTRY(input1),u.nom);
  gtk_entry_set_text(GTK_ENTRY(input2),u.prenom);
  gtk_entry_set_text(GTK_ENTRY(input3),u.ville);
  gtk_entry_set_text(GTK_ENTRY(input4),u.postal);
  gtk_entry_set_text(GTK_ENTRY(input5),u.adresse);
  gtk_entry_set_text(GTK_ENTRY(input6),u.tel);
  gtk_spin_button_set_value(j,d.jour);
  gtk_spin_button_set_value(m,d.mois);
  gtk_spin_button_set_value(a,d.annee);
}


void
on_button_modusr_quit_clicked          (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_mod_user;
	window_admin_mod_user=lookup_widget(object_graphique,"window_admin_mod_user");
	gtk_widget_hide(window_admin_mod_user);
}


void
on_button_delusr_del_clicked           (GtkWidget *object_graphique, gpointer user_data)
{
user u;
int x;

GtkWidget *input1=lookup_widget(object_graphique,"entry_delusr_id");
GtkWidget *output=lookup_widget(object_graphique,"label_delusr_mssg");

strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(input1)));

x=del_user(u);

	if(x==1)
	{
	gtk_label_set_text(GTK_LABEL(output),"Veuillez entrez un ID !");
	}
	if(x==2)
	{
	gtk_label_set_text(GTK_LABEL(output),"L'utilisateur n'est pas trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"L'utilisateur est modifié !");
	}
}


void
on_button_delusr_quit_clicked          (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_del_user;
	window_admin_del_user=lookup_widget(object_graphique,"window_admin_del_user");
	gtk_widget_hide(window_admin_del_user);
}


void
on_button_addusr_confirm_clicked       (GtkWidget *object_graphique, gpointer user_data)
{
info in;
 date d;
 user u;
 int x;
 int y;



  GtkWidget *output1=lookup_widget(object_graphique,"label_addusr1");
  GtkWidget *output2=lookup_widget(object_graphique,"label_addusr2");
  GtkWidget *input1=lookup_widget(object_graphique,"entry_addusr_login");
  GtkWidget *input2=lookup_widget(object_graphique,"entry_addusr_pwd");
  GtkWidget *input3=lookup_widget(object_graphique,"entry_addusr_nom");
  GtkWidget *input4=lookup_widget(object_graphique,"entry_addusr_prenom");
  GtkWidget *input5=lookup_widget(object_graphique,"entry_addusr_ville");
  GtkWidget *input6=lookup_widget(object_graphique,"entry_addusr_zip");
  GtkWidget *input7=lookup_widget(object_graphique,"entry_addusr_adress");
  GtkWidget *input8=lookup_widget(object_graphique,"entry_addusr_tel");
  GtkWidget *combobox1=lookup_widget(object_graphique,"combobox_addusr_role");
  GtkWidget *j=lookup_widget(object_graphique, "spinbutton1");
  GtkWidget *m=lookup_widget(object_graphique, "spinbutton2");
  GtkWidget *a=lookup_widget(object_graphique, "spinbutton3");

  strcpy(in.login,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(in.password,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(u.ville,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(u.postal,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(u.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(u.tel,gtk_entry_get_text(GTK_ENTRY(input8)));


  d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (j));
  d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (m));
  d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (a));


    if(strcmp("adherent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
        {
          in.role=2;
        }
    else if(strcmp("coach",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
        {
          in.role=3;
        }
    else if(strcmp("kinesitherapeute",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
        {
          in.role=4;
        }
    else if(strcmp("dieteticien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
        {
          in.role=5;
        }
      else
        {
          in.role=6;
        }


	x=add_user(in);
	if(x==1)
	{
	gtk_label_set_text(GTK_LABEL(output1),"Le login existe deja !");
	}
	else if(x==2)
	{
	gtk_label_set_text(GTK_LABEL(output1),"Veuillez entrer un login !");
	}
	else if(x==3)
	{
	gtk_label_set_text(GTK_LABEL(output1),"Veuillez entrer un password !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output1),"Success pour login");
		y=add_info(in,u,d);
		if (y==1)
		{
		x=2;
		gtk_label_set_text(GTK_LABEL(output2),"Veuillez entrer un nom !");
		}
		else if (y==2)
		{
		x=2;
		gtk_label_set_text(GTK_LABEL(output2),"Veuillez entrer un prenom !");
		}
		else if (y==3)
		{
		x=2;
		gtk_label_set_text(GTK_LABEL(output2),"Veuillez entrer une vile !");
		}
		else if (y==4)
		{
		x=2;
		gtk_label_set_text(GTK_LABEL(output2),"Veuillez entrer un code postal !");
		}
		else if (y==5)
		{
		x=2;
		gtk_label_set_text(GTK_LABEL(output2),"Veuillez entrer une adresse !");
		}
		else if (y==6)
		{
		x=2;
		gtk_label_set_text(GTK_LABEL(output2),"Veuillez entrer un telephone !");
		}
		else
		gtk_label_set_text(GTK_LABEL(output2),"Success pour informations");

	}

}



void
on_button_admin_login_clicked          (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_login;
	window_admin_login = create_window_admin_login();
	gtk_widget_show(window_admin_login);
}


void
on_button_login_ok_clicked             (GtkWidget *object_graphique, gpointer user_data)
{
info i;
int x;

	GtkWidget *window_admin_login;
	window_admin_login=lookup_widget(object_graphique,"window_admin_login");



	GtkWidget *window_admin_login_show;
	GtkWidget *output=lookup_widget(object_graphique,"label_login2");
	GtkWidget *input;
	input = lookup_widget(object_graphique,"entry_admin_login");
	strcpy(i.password,gtk_entry_get_text(GTK_ENTRY(input)));

x=verif_password(i);

	if (x==1)
	{

	window_admin_login_show = create_window_admin_login_show();
	gtk_widget_destroy(window_admin_login);
	gtk_widget_show(window_admin_login_show);
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"Mot de passe incorrect !");
	}


}


void
on_button_admin_login_refresh_clicked  (GtkWidget *object_graphique, gpointer user_data)
{


	GtkWidget *window_admin_login_show;
	window_admin_login_show=lookup_widget(object_graphique,"window_admin_login_show");
	GtkWidget *treeview_login;
	treeview_login = lookup_widget(window_admin_login_show,"treeview_login");
  	login(treeview_login);
}


void
on_button_admin_login_edit_ok_clicked  (GtkWidget *object_graphique, gpointer user_data)
{
info2 b;
int x;

GtkWidget *output=lookup_widget(object_graphique,"label_admin_login_edit5");
GtkWidget *input1=lookup_widget(object_graphique,"entry_admin_login_edit1");
GtkWidget *input2=lookup_widget(object_graphique,"entry_admin_login_edit2");
GtkWidget *input3=lookup_widget(object_graphique,"entry_admin_login_edit3");
GtkWidget *role=lookup_widget(object_graphique, "spinbutton_admin_login_edit");

  strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(b.login,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(b.password,gtk_entry_get_text(GTK_ENTRY(input3)));
  b.role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (role));



x=mod_login(b);
	if (x==1)
	{
	gtk_label_set_text(GTK_LABEL(output),"Veuillez entrer un ID !");
	}
	else if(x==2)
	{
	gtk_label_set_text(GTK_LABEL(output),"L'utilisateur n'est pas trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"L'utilisateur est modifié !");
	}
}


void
on_button_admin_login_edit_show_clicked (GtkWidget *object_graphique, gpointer user_data)
{
info2 g;
char y[30];
  GtkWidget *input1=lookup_widget(object_graphique,"entry_admin_login_edit2");
  GtkWidget *input2=lookup_widget(object_graphique,"entry_admin_login_edit3");
  GtkWidget *input3=lookup_widget(object_graphique,"entry_admin_login_edit1");
  strcpy(y,gtk_entry_get_text(GTK_ENTRY(input3)));

  show(&g,y);

  gtk_entry_set_text(GTK_ENTRY(input1),g.login);
  gtk_entry_set_text(GTK_ENTRY(input2),g.password);

}


void
on_button_admin_login_edit_clicked     (GtkWidget *object_graphique, gpointer user_data)
{

	GtkWidget *window_admin_login_edit;
	window_admin_login_edit = create_window_admin_login_edit();
	gtk_widget_show(window_admin_login_edit);
}


void
on_button_addusr_quit_clicked          (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_add_user;
	window_admin_add_user=lookup_widget(object_graphique,"window_admin_add_user");
	gtk_widget_hide(window_admin_add_user);
}


void
on_button_login_quit_clicked           (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_login;
	window_admin_login=lookup_widget(object_graphique,"window_admin_login");
	gtk_widget_hide(window_admin_login);
}


void
on_button_admin_login_quit_clicked     (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_login_show;
	window_admin_login_show=lookup_widget(object_graphique,"window_admin_login_show");
	gtk_widget_hide(window_admin_login_show);
}


void
on_button_admin_login_edit_quit_clicked (GtkWidget *object_graphique, gpointer user_data)
{
	GtkWidget *window_admin_login_edit;
	window_admin_login_edit=lookup_widget(object_graphique,"window_admin_login_edit");
	gtk_widget_hide(window_admin_login_edit);
}

void
on_button_nutri_fiche_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *window_nutri;
    GtkWidget *window_nutri_fiche;
    window_nutri = lookup_widget(objet_graphique,"window_nutri");
    window_nutri_fiche=create_window_nutri_fiche();
    gtk_widget_destroy(window_nutri);
    gtk_widget_show(window_nutri_fiche);

}


void
on_button_nutri_fiche_back_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_nutri;
  GtkWidget *window_nutri_fiche;
  window_nutri_fiche = lookup_widget(objet_graphique,"window_nutri_fiche");
  window_nutri=create_window_nutri();
  gtk_widget_destroy(window_nutri_fiche);
  gtk_widget_show(window_nutri);
}


void
on_button_nutri_fiche_delete_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
 char id[5];
 GtkWidget *window;
 window = lookup_widget(objet_graphique,"window_nutri_fiche");
 GtkWidget *input;
 input = lookup_widget(window,"entry_nutri_fiche_select");
 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
 nutri_fiche_delete(id);
}

void
on_button_nutri_fiche_addmod_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget *window_nutri_fiche_add;
  window_nutri_fiche_add=create_window_nutri_fiche_add();
  gtk_widget_show(window_nutri_fiche_add);

  GtkWidget *window_nutri_fiche;
  GtkWidget *entry_nutri_fiche_select;
  window_nutri_fiche = lookup_widget(objet_graphique,"window_nutri_fiche");
  entry_nutri_fiche_select = lookup_widget(window_nutri_fiche,"entry_nutri_fiche_select");
  char test[5];
  strcpy(test,gtk_entry_get_text(GTK_ENTRY(entry_nutri_fiche_select)));
  if (strcmp(test,"")!=0){
    GtkWidget *entry_nutri_fiche_add_id;
    entry_nutri_fiche_add_id = lookup_widget(window_nutri_fiche_add,"entry_nutri_fiche_add_id");
    gtk_entry_set_text(GTK_ENTRY(entry_nutri_fiche_add_id),test);
  }
}

void
on_button_nutri_fiche_add_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  int success;
  success = nutri_fiche_add(objet_graphique);

}

void
on_button_nutri_fiche_update_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  nutri_fiche_update(objet_graphique);
}

void
on_button_nutri_fiche_refresh_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget* window_nutri_fiche;
  window_nutri_fiche = lookup_widget(objet_graphique,"window_nutri_fiche");
  GtkWidget* treeview_nutri_fiche;
  treeview_nutri_fiche= lookup_widget(objet_graphique,"treeview_nutri_fiche");

  nutri_fiche_show(treeview_nutri_fiche);
}

void
on_button_home_mdp_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget* dialog_home_mdp;
    dialog_home_mdp = create_dialog_home_mdp();
    gtk_widget_show(dialog_home_mdp);

}

void
on_okbutton_mdp_clicked  (GtkWidget *objet_graphique, gpointer user_data)
{
  GtkWidget* dialog_home_mdp;
  dialog_home_mdp = lookup_widget(objet_graphique,"dialog_home_mdp");
  gtk_widget_destroy(dialog_home_mdp);
}
