typedef struct msg msg;
struct msg {
  int id_destinataire;
  int id_envoyeur;
  char texte[200];
}
