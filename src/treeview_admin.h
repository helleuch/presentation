#include <gtk/gtk.h>

struct perso
{
char id[30];
char nom[30];
char prenom[30];
char adresse[30];
char ville[30];
char postal[30];
char tel[30];
};
typedef struct perso perso;
//=======================================
struct dat
{
char jour[30];
char mois[30];
char annee[30];
};
typedef struct dat dat;

//=======================================
struct user3
{
char id[30];
char login[30];
char password[30];
char role[30];
};
typedef struct user3 user3;
//=======================================






void personne(GtkWidget *liste);
