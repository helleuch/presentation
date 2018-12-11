#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "treeview_admin.h"



enum
{
	IDS,
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	VILLE,
	ZIP,
	ADRESSE,
	TEL,
	ROLE,
	COLUMNS
};

void personne(GtkWidget *liste)
{
user3 u;
perso p;
dat d;

GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


store=NULL;

FILE *f;
FILE *f1;



store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",IDS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" ville",renderer,"text",VILLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" postal",renderer,"text",ZIP,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",ADRESSE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",TEL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" role",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/haroun/Desktop/MyGym/src/data/id","r");
	f1=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");

	if(f==NULL)
	{

		return;
	}
	else
	{
 		f = fopen("/home/haroun/Desktop/MyGym/src/data/id", "a+");

              while((fscanf(f,"%s%s%s%s%s%s%s%s%s%s\n",p.id,p.nom,p.prenom,d.jour,d.mois,d.annee,p.ville,p.postal,p.adresse,p.tel)!=EOF)&&(fscanf(f1,"%s%s%s%s\n",u.id,u.login,u.password,u.role)!=EOF))
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,IDS,p.id,NOM,p.nom,PRENOM,p.prenom,JOUR,d.jour,MOIS,d.mois,ANNEE,d.annee,VILLE,p.ville,ZIP,p.postal,ADRESSE,p.adresse,TEL,p.tel,ROLE,u.role,-2);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}


}
