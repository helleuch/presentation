#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "admin.h"
#include <gtk/gtk.h>

int add_user(info in)
{

	info2 o;
	FILE *f;
	int test=-1;


	f=fopen("/home/haroun/Desktop/MyGym/src/data/users","a+");
	if (f!=NULL)
	{
	while (fscanf(f,"%d %s %s %d\n",&in.id,o.login,o.password,&o.role) != EOF)
		{
				in.id = in.id + 3;
		}
	if(strcmp(in.login,o.login)==0)
	{
	test=1;
	}
	else if(strcmp(in.login,"")==0)
	{
	test=2;
	}
	else if(strcmp(in.password,"")==0)
	{
	test=3;
	}
	else
	fprintf(f,"%d %s %s %d\n",in.id,in.login,in.password,in.role);
	fclose(f);
	}
	else printf("impossssible d'ouvrir\n");
	return(test);



}
//=============================================================================
int add_info(info in,user u,date d)
{
	date2 a;
	user2 o;
	int test=-1;


	FILE *info;


	info=fopen("/home/haroun/Desktop/MyGym/src/data/id","a+");
	if (info!=NULL)
	{
	while (fscanf(info,"%d %s %s %d %d %d %s %s %s %s\n",&in.id,o.nom1,o.prenom1,&a.jour1,&a.mois1,&a.annee1,o.ville1,o.postal1,o.adresse1,o.tel1) != EOF)
			{
				in.id = in.id + 3;
			}
	if(strcmp(u.nom,"")==0)
	{
	test=1;
	}
	else if(strcmp(u.prenom,"")==0)
	{
	test=2;
	}
	else if(strcmp(u.ville,"")==0)
	{
	test=3;
	}
	else if(strcmp(u.postal,"")==0)
	{
	test=4;
	}
	else if(strcmp(u.adresse,"")==0)
	{
	test=5;
	}
	else if(strcmp(u.tel,"")==0)
	{
	test=6;
	}

	else
	fprintf(info,"%d %s %s %d %d %d %s %s %s %s\n",in.id,u.nom,u.prenom,d.jour,d.mois,d.annee,u.ville,u.postal,u.adresse,u.tel);
	fclose(info);
	}
	else printf("impossssible d'ouvrir\n");
	return(test);

}
//============================================================================================================================================

int mod_user(user u,date d)
{
	int c=2;
	user2 us;
	date2 da;



	FILE *f1;
	FILE *f2;

	f1=fopen("/home/haroun/Desktop/MyGym/src/data/id","r");
	f2=fopen("/home/haroun/Desktop/MyGym/src/data/mod","a");

	if ( (f1!=NULL) || (f2!=NULL) )
	{

	while (fscanf(f1,"%s %s %s %d %d %d %s %s %s %s\n",us.id1,us.nom1,us.prenom1,&(da.jour1),&(da.mois1),&(da.annee1),us.ville1,us.postal1,us.adresse1,us.tel1) != EOF)
	{
		if(strcmp(u.id,"")==0)
		{
			c=1;
		}
		if(strcmp(u.id,us.id1)==0)
		{
			fprintf(f2,"%s %s %s %d %d %d %s %s %s %s\n",u.id,u.nom,u.prenom,d.jour,d.mois,d.annee,u.ville,u.postal,u.adresse,u.tel);
			c=-1;
		}
		else
		{
			fprintf(f2,"%s %s %s %d %d %d %s %s %s %s\n",us.id1,us.nom1,us.prenom1,da.jour1,da.mois1,da.annee1,us.ville1,us.postal1,us.adresse1,us.tel1);

		}
	}
	fclose(f1);
  	fclose(f2);
	}
	else printf("impossssible d'ouvrir\n");

  	remove("/home/haroun/Desktop/MyGym/src/data/id");
  	rename("/home/haroun/Desktop/MyGym/src/data/mod","/home/haroun/Desktop/MyGym/src/data/id");
	return(c);

}
//================================================================================================================================================
int del_user(user u)
{
	user2 us;
	date2 da;
	info2 inf;
	int v=-1;

	FILE *f1;
	FILE *f2;
	FILE *m1;
	FILE *m2;

	f1=fopen("/home/haroun/Desktop/MyGym/src/data/id","r");
	m1=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");
	f2=fopen("/home/haroun/Desktop/MyGym/src/data/del1","a");
	m2=fopen("/home/haroun/Desktop/MyGym/src/data/del2","a");

	if ( (f1!=NULL) || (f2!=NULL) )
	{

	while (fscanf(f1,"%s %s %s %d %d %d %s %s %s %s\n",us.id1,us.nom1,us.prenom1,&da.jour1,&da.mois1,&da.annee1,us.ville1,us.postal1,us.adresse1,us.tel1) != EOF)
	{
		if (strcmp(u.id,us.id1)!=0)
		{
			fprintf(f2,"%s %s %s %d %d %d %s %s %s %s\n",us.id1,us.nom1,us.prenom1,da.jour1,da.mois1,da.annee1,us.ville1,us.postal1,us.adresse1,us.tel1);


		}
		else
		{
		v=1;
		}
		if(strcmp(u.id,"")==0)
		{
		v=2;
		}
	}
	fclose(f1);
	fclose(f2);
	}
	if ( (m1!=NULL) || (m2!=NULL) )
	{

	while (fscanf(m1,"%s %s %s %d\n",inf.id,inf.login,inf.password,&inf.role) != EOF)
	{
		if (strcmp(u.id,inf.id)!=0)
		{
			fprintf(m2,"%s %s %s %d\n",inf.id,inf.login,inf.password,inf.role);


		}
		else
		{
		v=1;
		}
		if(strcmp(u.id,"")==0)
		{
		v=2;
		}
	}
	fclose(m1);
	fclose(m2);
	}


	remove("/home/haroun/Desktop/MyGym/src/data/id");
	rename("/home/haroun/Desktop/MyGym/src/data/del1","/home/haroun/Desktop/MyGym/src/data/id");
	remove("/home/haroun/Desktop/MyGym/src/data/users");
	rename("/home/haroun/Desktop/MyGym/src/data/del2","/home/haroun/Desktop/MyGym/src/data/users");
	return(v);


}
//============================================================================================================================================================================

void copier(user *u,date *d,char x[])
{
user2 us;
date da;
FILE *f;

f=fopen("/home/haroun/Desktop/MyGym/src/data/id","r");
	if (f!=NULL)
	while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s\n",us.id1,us.nom1,us.prenom1,&(da.jour),&(da.mois),&(da.annee),us.ville1,us.postal1,us.adresse1,us.tel1) !=EOF)
	{
		if(strcmp(x,us.id1)==0)
		{
			strcpy(u->nom,us.nom1);
			strcpy(u->prenom,us.prenom1);
			strcpy(u->ville,us.ville1);
			strcpy(u->postal,us.postal1);
			strcpy(u->adresse,us.adresse1);
			strcpy(u->tel,us.tel1);
			d->jour=da.jour;
			d->mois=da.mois;
			d->annee=da.annee;
		}
	}
	fclose(f);
}
//==============================================================================================================================================================================
int verif_password(info i)
{

int verif=-1;
	if(strcmp(i.password,"admin")==0)
	{
	verif=1;
	}

	return(verif);
}
//===============================================================================================================================================================================
void show(info2 *g,char y[])
{
info3 a;
FILE *f;
f=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");
	if (f!=NULL)
	while(fscanf(f,"%s %s %s %s\n",a.id,a.login,a.password,a.role) !=EOF)
	{
		if(strcmp(y,a.id)==0)
		{
			strcpy(g->login,a.login);
			strcpy(g->password,a.password);

		}
	}
	fclose(f);
}
//====================================================================================================================================================================================
int mod_login(info2 b)
{
	int c=2;
	info3 mo;



	FILE *f1;
	FILE *f2;

	f1=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");
	f2=fopen("/home/haroun/Desktop/MyGym/src/data/mad","a");

	if ( (f1!=NULL) || (f2!=NULL) )
	{

	while (fscanf(f1,"%s %s %s %s\n",mo.id,mo.login,mo.password,mo.role) != EOF)
	{
		if(strcmp(b.id,"")==0)
		{
			c=1;
		}
		if(strcmp(b.id,mo.id)==0)
		{
			fprintf(f2,"%s %s %s %d\n",b.id,b.login,b.password,b.role);
			c=-1;
		}
		else
		{
			fprintf(f2,"%s %s %s %s\n",mo.id,mo.login,mo.password,mo.role);

		}
	}
	fclose(f1);
  	fclose(f2);
	}
	else printf("impossssible d'ouvrir\n");

  	remove("/home/haroun/Desktop/MyGym/src/data/users");
  	rename("/home/haroun/Desktop/MyGym/src/data/mad","/home/haroun/Desktop/MyGym/src/data/users");
	return(c);
}
