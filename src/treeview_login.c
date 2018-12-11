#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "treeview_login.h"




enum
{
	ID,
	LOGIN,
	PASSWORD,
	ROLE,
	COLUMNS
};

void login(GtkWidget *liste)
{
log log;

GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


store=NULL;


FILE *f1;



store = gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" identifiant",renderer,"text",ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" login",renderer,"text",LOGIN,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" password",renderer,"text",PASSWORD,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" role",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);




	}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


	f1=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");

	if(f1==NULL)
	{

		return;
	}
	else
	{
 		f1 = fopen("/home/haroun/Desktop/MyGym/src/data/users", "a+");

              while(fscanf(f1,"%s%s%s%s\n",log.id3,log.login3,log.password3,log.role3)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,ID,log.id3,LOGIN,log.login3,PASSWORD,log.password3,ROLE,log.role3,-2);
		}
		fclose(f1);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    		g_object_unref (store);
	}


}
