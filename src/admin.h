struct info
{
int id;
char login[30];
char password[30];
int role;
};
typedef struct info info;
//======================================
typedef struct
{
char id[100];
char nom[100];
char prenom[100];
char ville[100];
char postal[100];
char adresse[100];
char tel[100];
}user;
//======================================
struct date
{
int jour;
int mois;
int annee;
};
typedef struct date date;
//======================================
struct user2
{
char id1[100];
char nom1[100];
char prenom1[100];
char ville1[100];
char postal1[100];
char adresse1[100];
char tel1[100];
};
typedef struct user2 user2;
//======================================
struct date2
{
int jour1;
int mois1;
int annee1;
};
typedef struct date2 date2;
//======================================
struct info2
{
char id[30];
char login[30];
char password[30];
int role;
};
typedef struct info2 info2;
//======================================
struct info3
{
char id[30];
char login[30];
char password[30];
char role[30];
};
typedef struct info3 info3;
//=====================================



int add_user(info in);
int add_info(info in,user u,date d);
int mod_user(user u,date d);
int del_user(user u);
//======================================
void copier(user *u,date *d,char x[]);
void show(info2 *g,char y[]);
//======================================
int verif_password(info i);
