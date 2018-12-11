#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"

int check_login(char login[], char password[])
{
	int verif=-1;
	FILE *f;
	char r_login[30];char r_password[30];
	int r_role=-1,id ;
	f=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");
	if(f!=NULL)
	{

		while (fscanf(f,"%d %s %s %d\n",&id,r_login,r_password,&r_role) != EOF) //EOF = End Of File
		{
			if (strcmp(login,"")==0){
				verif = -2;
			}
			else  if (strcmp(password,"")==0){
				verif = -3;
			}
			else if (((strcmp(login,r_login)==0)&&(strcmp(password,r_password)==0)))
			{
			verif=r_role;
			}
		}
		fclose(f);
	}
	else{
		printf("ERROR : Could not open file users.\n");
		}

return verif;

}

int check_id(char to_test_id[]){

	int verif=-1;
	FILE *f;
	char r_login[30];char r_password[30];
	int r_role=-1;
	char id[5];
	f=fopen("/home/haroun/Desktop/MyGym/src/data/users","r");
	if(f!=NULL)
	{

		while (fscanf(f,"%s %s %s %d\n",id,r_login,r_password,&r_role) != EOF)
		{
			if (verif != 0){

				if (strcmp(id,to_test_id)==0){
					verif = 0;
		}
			}
		}
		fclose(f);
	}
	else{
		printf("ERROR : Could not open file users.\n");
		}

return verif;
}
