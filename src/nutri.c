#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rdv.h"
#include "kine.h"
#include "nutri.h"
#include <gtk/gtk.h>
#include <support.h>


enum
{
  ID_PAT,
  NB_SEANCES,
	RDV,
  TEL,
  OBSERVATIONS,
  COLUMNS_FICHE
};


int nutri_fiche_add(GtkWidget *validate){
  int r = -2;
  GtkWidget *window_nutri_fiche_add;

  GtkWidget *entry_nutri_fiche_add_id;
  GtkWidget *entry_nutri_fiche_add_tel;
  GtkWidget *entry_nutri_fiche_add_observations;
  GtkWidget *spinbutton_nb_seances;
  GtkWidget *spinbutton_j;
  GtkWidget *spinbutton_m;
  GtkWidget *spinbutton_a;

  window_nutri_fiche_add=lookup_widget(validate,"window_nutri_fiche_add");

  entry_nutri_fiche_add_id = lookup_widget(window_nutri_fiche_add,"entry_nutri_fiche_add_id");
  entry_nutri_fiche_add_tel = lookup_widget(window_nutri_fiche_add,"entry_nutri_fiche_add_tel");
  entry_nutri_fiche_add_observations = lookup_widget(window_nutri_fiche_add,"entry_nutri_fiche_add_observations");
  spinbutton_nb_seances = lookup_widget(window_nutri_fiche_add,"spinbutton_nutri_fiche_add_seances");
  spinbutton_j = lookup_widget(window_nutri_fiche_add,"spinbutton_nutri_fiche_add_j");
  spinbutton_m = lookup_widget(window_nutri_fiche_add,"spinbutton_nutri_fiche_add_m");
  spinbutton_a = lookup_widget(window_nutri_fiche_add,"spinbutton_nutri_fiche_add_a");

  fiche new_fiche;
  char formatedObs[150];

  strcpy(new_fiche.ID_patient,gtk_entry_get_text(GTK_ENTRY(entry_nutri_fiche_add_id)));


  new_fiche.nb_seances = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_nb_seances));
  new_fiche.jj = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_j));
  new_fiche.mm = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_m));
  new_fiche.aaaa = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_a));

  strcpy(new_fiche.tel,gtk_entry_get_text(GTK_ENTRY(entry_nutri_fiche_add_tel)));

  strcpy(formatedObs,gtk_entry_get_text(GTK_ENTRY(entry_nutri_fiche_add_observations)));
  replaceSpace(formatedObs);
  strcpy(new_fiche.obs,formatedObs);
  // strcpy(new_fiche.obs,gtk_entry_get_text(GTK_ENTRY(entry_nutri_fiche_add_observations)));

  FILE* fiche;
  fiche = fopen("/home/haroun/Desktop/MyGym/src/data/nutri.dat","a");
  if (fiche != NULL){
    fprintf(fiche,"%s %d %d-%d-%d %s %s\n", new_fiche.ID_patient, new_fiche.nb_seances, new_fiche.jj, new_fiche.mm, new_fiche.aaaa, new_fiche.tel, new_fiche.obs);

    r=0;
  }
  else
  {
    printf("ERROR : Failed to open file nutri.dat !");
  }
  fclose(fiche);
  gtk_widget_destroy(window_nutri_fiche_add);
  return r;
};

void nutri_fiche_show(GtkWidget *liste){
    GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkTreeIter iter;
  	GtkListStore *store;

  	char id_pat [5];
    int nb_seances;
    char date [11];
    char tel[9];
    char obs[150];
    store=NULL;

    FILE *f;

  	store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
  	if (store==NULL)
  	{

      renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("ID patient", renderer, "text",ID_PAT, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("Nb. séances", renderer, "text",NB_SEANCES, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("Dernière viste", renderer, "text",RDV, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("Tél.", renderer, "text",TEL, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

      renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("Observations.", renderer, "text",OBSERVATIONS, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

  	}


  	store=gtk_list_store_new (COLUMNS_FICHE, G_TYPE_STRING,G_TYPE_INT,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  	f = fopen("/home/haroun/Desktop/MyGym/src/data/nutri.dat", "r");

  	if(f==NULL)
  	{

  		return;
  	}
  	else

  	{ f = fopen("/home/haroun/Desktop/MyGym/src/data/nutri.dat", "a+");
                while(fscanf(f,"%s %d %s %s %s\n",id_pat, &nb_seances, date, tel, obs)!=EOF)
  		{
  	gtk_list_store_append (store, &iter);
  	gtk_list_store_set (store, &iter, ID_PAT, id_pat, NB_SEANCES, nb_seances, RDV, date,TEL,tel,OBSERVATIONS,obs, -1);
  		}
  		fclose(f);
    	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
      g_object_unref (store);
  	}
};


void nutri_fiche_update(GtkWidget *edit){

  GtkWidget *entry_nutri_fiche_add_id;
  GtkWidget *window_nutri_fiche_add;
  window_nutri_fiche_add = lookup_widget(edit,"window_nutri_fiche_add");
  entry_nutri_fiche_add_id = lookup_widget(window_nutri_fiche_add,"entry_nutri_fiche_add_id");

  char id[5];  strcpy(id,"0000");
  strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry_nutri_fiche_add_id)));
  nutri_fiche_delete(id);
  nutri_fiche_add(edit);

};



void nutri_fiche_delete(char id[5]) {
  FILE  *old, *new;
  fiche to_keep;
  old = fopen("/home/haroun/Desktop/MyGym/src/data/nutri.dat","r");
  new = fopen("/home/haroun/Desktop/MyGym/src/data/nutri.temp","a+");
  if(old != NULL){
    while(fscanf(old,"%s %d %d-%d-%d %s %s\n", to_keep.ID_patient, &to_keep.nb_seances, &to_keep.jj, &to_keep.mm, &to_keep.aaaa, to_keep.tel, to_keep.obs)!=EOF){
      if (strcmp(to_keep.ID_patient,id)!=0)
        fprintf(new,"%s %d %d-%d-%d %s %s\n", to_keep.ID_patient, to_keep.nb_seances, to_keep.jj, to_keep.mm, to_keep.aaaa, to_keep.tel, to_keep.obs);
    }
    fclose(old);
    fclose(new);
    remove("/home/haroun/Desktop/MyGym/src/data/nutri.dat");
    rename("/home/haroun/Desktop/MyGym/src/data/nutri.temp","/home/haroun/Desktop/MyGym/src/data/nutri.dat");
  }
  else{
    printf("ERROR : Could not open file nutri.dat !");
  }
};
