#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rdv.h"
#include "kine.h"
#include <gtk/gtk.h>
#include <support.h>


enum
{
  ID_RDV,
  DATE,
	ID_ADH,
  DESC,
  COLUMNS
};


int rdv_add(GtkWidget *validate){
  int r = -2;
  GtkWidget *entry_kine_rdv;
  GtkWidget *entry_kine_rdv_2;
  GtkWidget *button_kine_rdv_validate;
  GtkWidget *spinbutton_kine_rdv_j;
  GtkWidget *spinbutton_kine_rdv_m;
  GtkWidget *spinbutton_kine_rdv_a;
  GtkWidget *window_kine_rdv;
//  GtkWidget *spinbutton_kine_rdv_h;
//  GtkWidget *spinbutton_kine_rdv_min;

  rdv new_rdv;

  window_kine_rdv = lookup_widget(validate,"window_kine_rdv");
  entry_kine_rdv = lookup_widget(window_kine_rdv,"entry_kine_rdv");
  entry_kine_rdv_2 = lookup_widget(window_kine_rdv,"entry_kine_rdv_2");
  spinbutton_kine_rdv_j = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_j");
  spinbutton_kine_rdv_m = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_m");
  spinbutton_kine_rdv_a = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_a");
//  spinbutton_kine_rdv_h = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_h");
//  spinbutton_kine_rdv_min = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_min");

  char formatedDesc[150];
  strcpy(formatedDesc,gtk_entry_get_text(GTK_ENTRY(entry_kine_rdv_2)));
  replaceSpace(formatedDesc);
  strcpy(new_rdv.ID_rdv,"default");
  sprintf(new_rdv.ID_rdv, "%d", rdv_generateID());
  new_rdv.jj = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_kine_rdv_j));
  new_rdv.mm = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_kine_rdv_m));
  new_rdv.aaaa = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_kine_rdv_a));
  strcpy(new_rdv.ID_adh,gtk_entry_get_text(GTK_ENTRY(entry_kine_rdv)));
  new_rdv.role_staff = 3; //CURRENT_USER.ROLE
  strcpy(new_rdv.desc,formatedDesc);

  if (isPatient(new_rdv.ID_adh) == 0){
    FILE* frdv;
    frdv = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat","a");
    if (frdv != NULL){
      fprintf(frdv,"%s %d/%d/%d %s %d %s\n", new_rdv.ID_rdv,new_rdv.jj, new_rdv.mm, new_rdv.aaaa, new_rdv.ID_adh, new_rdv.role_staff, new_rdv.desc);
      fclose(frdv);
      r=0;
    }
    else
    {
      printf("ERROR : Failed to open file rdv.dat !");
    }
  }else{
    r = -1;
  }
    return r;
  };

void rdv_show(GtkWidget *liste){
  GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkTreeIter    iter;
  	GtkListStore *store;

  	char id_rdv [15];
  	char date [25];
  	char id_adh [15];
    int role_staff;
    char desc[60];
    store=NULL;

    FILE *f;

  	store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
  	if (store==NULL)
  	{

      renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("ID rdv", renderer, "text",ID_RDV, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("ID patient", renderer, "text",ID_ADH, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text",DESC, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

  	}


  	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  	f = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat", "r");

  	if(f==NULL)
  	{

  		return;
  	}
  	else

  	{ f = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat", "a+");
                while(fscanf(f,"%s %s %s %d %s \n",id_rdv, date, id_adh, &role_staff, desc)!=EOF)
  		{
  	gtk_list_store_append (store, &iter);
  	gtk_list_store_set (store, &iter, ID_RDV, id_rdv, DATE, date, ID_ADH, id_adh,DESC,desc, -1);
  		}
  		fclose(f);
    	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
      g_object_unref (store);
  	}
};


void rdv_update(GtkWidget *validate){
FILE  *old, *new;
rdv to_keep;
rdv update;

GtkWidget *entry_kine_rdv;
GtkWidget *entry_kine_rdv_2;
GtkWidget *entry_kine_rdv_3;
GtkWidget *button_kine_rdv_validate;
GtkWidget *spinbutton_kine_rdv_j;
GtkWidget *spinbutton_kine_rdv_m;
GtkWidget *spinbutton_kine_rdv_a;
GtkWidget *window_kine_rdv;

window_kine_rdv = lookup_widget(validate,"window_kine_rdv");
entry_kine_rdv = lookup_widget(window_kine_rdv,"entry_kine_rdv");
entry_kine_rdv_2 = lookup_widget(window_kine_rdv,"entry_kine_rdv_2");
entry_kine_rdv_3 = lookup_widget(window_kine_rdv,"entry_kine_rdv_3");
spinbutton_kine_rdv_j = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_j");
spinbutton_kine_rdv_m = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_m");
spinbutton_kine_rdv_a = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_a");

char formatedDesc[150];
strcpy(formatedDesc,gtk_entry_get_text(GTK_ENTRY(entry_kine_rdv_2)));
replaceSpace(formatedDesc);

strcpy(update.ID_rdv,gtk_entry_get_text(GTK_ENTRY(entry_kine_rdv_3)));

update.jj = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_kine_rdv_j));
update.mm = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_kine_rdv_m));
update.aaaa = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_kine_rdv_a));
strcpy(update.ID_adh,gtk_entry_get_text(GTK_ENTRY(entry_kine_rdv)));
update.role_staff = 3; //CURRENT_USER.ROLE
strcpy(update.desc,formatedDesc);

old = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat","a+");
new = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.temp","a+");
if(old != NULL){
  while(fscanf(old,"%s %d/%d/%d %s %d %s\n", to_keep.ID_rdv, &to_keep.jj, &to_keep.mm, &to_keep.aaaa, to_keep.ID_adh, &to_keep.role_staff, to_keep.desc)!=EOF){
    if (strcmp(to_keep.ID_rdv,update.ID_rdv)!=0)
      fprintf(new,"%s %d/%d/%d %s %d %s\n", to_keep.ID_rdv, to_keep.jj, to_keep.mm, to_keep.aaaa, to_keep.ID_adh, to_keep.role_staff, to_keep.desc);
    else
      fprintf(new,"%s %d/%d/%d %s %d %s\n", update.ID_rdv, update.jj, update.mm, update.aaaa, update.ID_adh, update.role_staff, update.desc);

  }
  fclose(old);
  fclose(new);
  remove("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat");
  rename("/home/haroun/Desktop/MyGym/src/data/rdv_kine.temp","/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat");
}
else{
  printf("ERROR : Could not open file kine_rdv.dat !");
    }
};



void rdv_delete(char id[5]) {
  FILE  *old, *new;
  rdv to_keep;
  old = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat","a+");
  new = fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.temp","a+");
  if(old != NULL){
    while(fscanf(old,"%s %d/%d/%d %s %d %s\n", to_keep.ID_rdv, &to_keep.jj, &to_keep.mm, &to_keep.aaaa, to_keep.ID_adh, &to_keep.role_staff, to_keep.desc)!=EOF){
      if (strcmp(to_keep.ID_rdv,id)!=0)
        fprintf(new,"%s %d/%d/%d %s %d %s\n", to_keep.ID_rdv, to_keep.jj, to_keep.mm, to_keep.aaaa, to_keep.ID_adh, to_keep.role_staff, to_keep.desc);
    }
    fclose(old);
    fclose(new);
    remove("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat");
    rename("/home/haroun/Desktop/MyGym/src/data/rdv_kine.temp","/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat");
  }
  else{
    printf("ERROR : Could not open file kine_rdv.dat !");
  }
};


int rdv_generateID(){
  int id = 111;
  int id_rdv;
  char date [15];
  char id_adh [10];
  int role_staff;
  char desc[150];

	FILE* f;
	f=fopen("/home/haroun/Desktop/MyGym/src/data/rdv_kine.dat", "r");
	if(f!=NULL)
	{

		  while(fscanf(f,"%d %s %s %d %s\n",&id_rdv,date,id_adh,&role_staff,desc)!=EOF)
		{
				id = id_rdv + 13;
		}
	}else{
		printf("ERROR : Could not open file rdv_kine.dat !\n");
	}
  return id;
}

void replaceSpace(char str[]){
  int n = strlen(str);
  int i;
  for(i=0; i<n; i++){
    if (str[i]==' ')
      str[i]='_';
  }
}

void rdv_widget_add_show(GtkWidget *window_kine_rdv){

  GtkWidget *label_kine_rdv_2;
  GtkWidget *label_kine_rdv_3;
  GtkWidget *label_kine_rdv_4;
  GtkWidget *label_kine_rdv_5;
  GtkWidget *entry_kine_rdv;
  GtkWidget *entry_kine_rdv_2;
  GtkWidget *button_kine_rdv_validate;
  GtkWidget *button_kine_rdv_cancel;
  GtkWidget *spinbutton_kine_rdv_j;
  GtkWidget *spinbutton_kine_rdv_m;
  GtkWidget *spinbutton_kine_rdv_a;
  GtkWidget *spinbutton_kine_rdv_h;
  GtkWidget *spinbutton_kine_rdv_min;
  GtkWidget *treeview_kine_rdv_patients;

  label_kine_rdv_2 = lookup_widget(window_kine_rdv,"label_kine_rdv_2");
  label_kine_rdv_3 = lookup_widget(window_kine_rdv,"label_kine_rdv_3");
  label_kine_rdv_4 = lookup_widget(window_kine_rdv,"label_kine_rdv_4");
  label_kine_rdv_5 = lookup_widget(window_kine_rdv,"label_kine_rdv_5");
  entry_kine_rdv = lookup_widget(window_kine_rdv,"entry_kine_rdv");
  entry_kine_rdv_2 = lookup_widget(window_kine_rdv,"entry_kine_rdv_2");
  button_kine_rdv_validate = lookup_widget(window_kine_rdv,"button_kine_rdv_validate");
  button_kine_rdv_cancel = lookup_widget(window_kine_rdv,"button_kine_rdv_cancel");
  spinbutton_kine_rdv_j = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_j");
  spinbutton_kine_rdv_m = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_m");
  spinbutton_kine_rdv_a = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_a");
  spinbutton_kine_rdv_h = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_h");
  spinbutton_kine_rdv_min = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_min");
  treeview_kine_rdv_patients = lookup_widget(window_kine_rdv,"treeview_kine_rdv_patients");

  gtk_widget_show(label_kine_rdv_2);
  gtk_widget_show(label_kine_rdv_3);
  gtk_widget_show(label_kine_rdv_4);
  gtk_widget_show(label_kine_rdv_5);
  gtk_widget_show(entry_kine_rdv);
  gtk_widget_show(entry_kine_rdv_2);
  gtk_widget_show(button_kine_rdv_validate);
  gtk_widget_show(button_kine_rdv_cancel);
  gtk_widget_show(spinbutton_kine_rdv_j);
  gtk_widget_show(spinbutton_kine_rdv_m);
  gtk_widget_show(spinbutton_kine_rdv_a);
  gtk_widget_show(spinbutton_kine_rdv_h);
  gtk_widget_show(spinbutton_kine_rdv_min);
  gtk_widget_show(treeview_kine_rdv_patients);
}

void rdv_widget_delete_show(GtkWidget *window_kine_rdv){

  GtkWidget *label_kine_rdv_6;
  GtkWidget *entry_kine_rdv_3;
  GtkWidget *button_kine_rdv_validate_delete;
  GtkWidget *button_kine_rdv_cancel;

  label_kine_rdv_6 = lookup_widget(window_kine_rdv,"label_kine_rdv_6");
  entry_kine_rdv_3 = lookup_widget(window_kine_rdv,"entry_kine_rdv_3");
  button_kine_rdv_validate_delete = lookup_widget(window_kine_rdv,"button_kine_rdv_validate_delete");
  button_kine_rdv_cancel = lookup_widget(window_kine_rdv,"button_kine_rdv_cancel");

  gtk_widget_show(label_kine_rdv_6);
  gtk_widget_show(entry_kine_rdv_3);
  gtk_widget_show(button_kine_rdv_validate_delete);
  gtk_widget_show(button_kine_rdv_cancel);
}

void rdv_widget_edit_show(GtkWidget *window_kine_rdv){

  GtkWidget *button_kine_rdv_validate_edit;

  button_kine_rdv_validate_edit = lookup_widget(window_kine_rdv,"button_kine_rdv_validate_edit");

  gtk_widget_show(button_kine_rdv_validate_edit);

  GtkWidget *label_kine_rdv_2;
  GtkWidget *label_kine_rdv_3;
  GtkWidget *label_kine_rdv_4;
  GtkWidget *label_kine_rdv_5;
  GtkWidget *label_kine_rdv_6;
  GtkWidget *entry_kine_rdv;
  GtkWidget *entry_kine_rdv_2;
  GtkWidget *entry_kine_rdv_3;
  GtkWidget *spinbutton_kine_rdv_j;
  GtkWidget *spinbutton_kine_rdv_m;
  GtkWidget *spinbutton_kine_rdv_a;
  GtkWidget *spinbutton_kine_rdv_h;
  GtkWidget *spinbutton_kine_rdv_min;
  GtkWidget *treeview_kine_rdv_patients;
  GtkWidget *button_kine_rdv_cancel;

  label_kine_rdv_2 = lookup_widget(window_kine_rdv,"label_kine_rdv_2");
  label_kine_rdv_3 = lookup_widget(window_kine_rdv,"label_kine_rdv_3");
  label_kine_rdv_4 = lookup_widget(window_kine_rdv,"label_kine_rdv_4");
  label_kine_rdv_5 = lookup_widget(window_kine_rdv,"label_kine_rdv_5");
  label_kine_rdv_6 = lookup_widget(window_kine_rdv,"label_kine_rdv_6");
  entry_kine_rdv = lookup_widget(window_kine_rdv,"entry_kine_rdv");
  entry_kine_rdv_2 = lookup_widget(window_kine_rdv,"entry_kine_rdv_2");
  entry_kine_rdv_3 = lookup_widget(window_kine_rdv,"entry_kine_rdv_3");
  spinbutton_kine_rdv_j = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_j");
  spinbutton_kine_rdv_m = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_m");
  spinbutton_kine_rdv_a = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_a");
  spinbutton_kine_rdv_h = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_h");
  spinbutton_kine_rdv_min = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_min");
  treeview_kine_rdv_patients = lookup_widget(window_kine_rdv,"treeview_kine_rdv_patients");
  button_kine_rdv_cancel = lookup_widget(window_kine_rdv,"button_kine_rdv_cancel");

  gtk_widget_show(label_kine_rdv_2);
  gtk_widget_show(label_kine_rdv_3);
  gtk_widget_show(label_kine_rdv_4);
  gtk_widget_show(label_kine_rdv_5);
  gtk_widget_show(label_kine_rdv_6);
  gtk_widget_show(entry_kine_rdv);
  gtk_widget_show(entry_kine_rdv_2);
  gtk_widget_show(entry_kine_rdv_3);
  gtk_widget_show(spinbutton_kine_rdv_j);
  gtk_widget_show(spinbutton_kine_rdv_m);
  gtk_widget_show(spinbutton_kine_rdv_a);
  gtk_widget_show(spinbutton_kine_rdv_h);
  gtk_widget_show(spinbutton_kine_rdv_min);
  gtk_widget_show(treeview_kine_rdv_patients);
  gtk_widget_show(button_kine_rdv_cancel);
}

void rdv_widget_hide_all(GtkWidget *window_kine_rdv){

  GtkWidget *label_kine_rdv_2;
  GtkWidget *label_kine_rdv_3;
  GtkWidget *label_kine_rdv_4;
  GtkWidget *label_kine_rdv_5;
  GtkWidget *label_kine_rdv_6;

  GtkWidget *spinbutton_kine_rdv_j;
  GtkWidget *spinbutton_kine_rdv_m;
  GtkWidget *spinbutton_kine_rdv_a;
  GtkWidget *spinbutton_kine_rdv_h;
  GtkWidget *spinbutton_kine_rdv_min;

  GtkWidget *entry_kine_rdv;
  GtkWidget *entry_kine_rdv_2;
  GtkWidget *entry_kine_rdv_3;

  GtkWidget *button_kine_rdv_validate;
  GtkWidget *button_kine_rdv_cancel;
  GtkWidget *button_kine_rdv_validate_delete;
  GtkWidget *button_kine_rdv_validate_edit;


  label_kine_rdv_2 = lookup_widget(window_kine_rdv,"label_kine_rdv_2");
  label_kine_rdv_3 = lookup_widget(window_kine_rdv,"label_kine_rdv_3");
  label_kine_rdv_4 = lookup_widget(window_kine_rdv,"label_kine_rdv_4");
  label_kine_rdv_5 = lookup_widget(window_kine_rdv,"label_kine_rdv_5");
  label_kine_rdv_6 = lookup_widget(window_kine_rdv,"label_kine_rdv_6");

  spinbutton_kine_rdv_j = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_j");
  spinbutton_kine_rdv_m = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_m");
  spinbutton_kine_rdv_a = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_a");
  spinbutton_kine_rdv_h = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_h");
  spinbutton_kine_rdv_min = lookup_widget(window_kine_rdv,"spinbutton_kine_rdv_min");

  entry_kine_rdv = lookup_widget(window_kine_rdv,"entry_kine_rdv");
  entry_kine_rdv_2 = lookup_widget(window_kine_rdv,"entry_kine_rdv_2");
  entry_kine_rdv_3 = lookup_widget(window_kine_rdv,"entry_kine_rdv_3");

  button_kine_rdv_validate = lookup_widget(window_kine_rdv,"button_kine_rdv_validate");
  button_kine_rdv_cancel = lookup_widget(window_kine_rdv,"button_kine_rdv_cancel");
  button_kine_rdv_validate_delete = lookup_widget(window_kine_rdv,"button_kine_rdv_validate_delete");
  button_kine_rdv_validate_edit = lookup_widget(window_kine_rdv,"button_kine_rdv_validate_edit");


  gtk_widget_hide(label_kine_rdv_2);
  gtk_widget_hide(label_kine_rdv_3);
  gtk_widget_hide(label_kine_rdv_4);
  gtk_widget_hide(label_kine_rdv_5);
  gtk_widget_hide(label_kine_rdv_6);

  gtk_widget_hide(spinbutton_kine_rdv_j);
  gtk_widget_hide(spinbutton_kine_rdv_m);
  gtk_widget_hide(spinbutton_kine_rdv_a);
  gtk_widget_hide(spinbutton_kine_rdv_h);
  gtk_widget_hide(spinbutton_kine_rdv_min);

  gtk_widget_hide(entry_kine_rdv);
  gtk_widget_hide(entry_kine_rdv_2);
  gtk_widget_hide(entry_kine_rdv_3);

  gtk_widget_hide(button_kine_rdv_validate);
  gtk_widget_hide(button_kine_rdv_cancel);
  gtk_widget_hide(button_kine_rdv_validate_delete);
  gtk_widget_hide(button_kine_rdv_validate_edit);
}

void set_mode(GtkWidget *window, int mode){
  GtkWidget *label;
  label = lookup_widget(window,"label_kine_rdv_mode");
  char text[80];
  switch (mode){
    case 0:
      strcpy(text,"Que voulez-vous faire ?");
      break;

    case 1:
      strcpy(text,"Ajouter un rendez-vous :");
      break;

    case 2:
      strcpy(text,"Modifier un rendez-vous :");
      break;

    case 3:
      strcpy(text,"Supprimer un rendez-vous :");
      break;

    default:
      printf("ERROR while setting mode !");
      strcpy(text,"ERROR");
    }
    gtk_label_set_text(label,text);
  }
