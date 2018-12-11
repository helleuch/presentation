#include <gtk/gtk.h>

typedef struct rdv rdv;
struct rdv {
  char ID_rdv[10];
  int jj;
  int mm;
  int aaaa;
  char ID_adh[10];
  int role_staff;
  char desc[200];
};

int rdv_add(GtkWidget *validate);
void rdv_show(GtkWidget *liste);
void rdv_update(GtkWidget *validate);
void rdv_delete(char id[5]);

void rdv_widget_hide_all(GtkWidget *window_kine_rdv);
void rdv_widget_add_show(GtkWidget *window_kine_rdv);
void rdv_widget_delete_show(GtkWidget *window_kine_rdv);
void rdv_widget_edit_show(GtkWidget *window_kine_rdv);

int rdv_generateID();
void replaceSpace(char str[]);
void set_mode(GtkWidget *window, int mode);
