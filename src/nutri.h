#include <gtk/gtk.h>

typedef struct fiche fiche;
struct fiche {
  char ID_patient[50];
  int nb_seances;
  int jj;
  int mm;
  int aaaa;
  char tel[50];
  char obs[200];
};

int nutri_fiche_add();

void nutri_fiche_show(GtkWidget *liste);
void nutri_fiche_update(GtkWidget *edit);
void nutri_fiche_delete(char id[5]);
