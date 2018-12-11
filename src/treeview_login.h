#include <gtk/gtk.h>
struct log
{
char id3[30];
char login3[30];
char password3[30];
char role3[30];
};
typedef struct log log;
void login(GtkWidget *liste);
