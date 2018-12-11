#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "coach.h"


void coach_ajout_client(int id){
FILE *f;
f = fopen("/home/Desktop/project1/src/data/coach_clients.dat","a"); 
if (f!=NULL)
{
fprintf(f,"%d\n", id);
fclose(f);
}
else
{
printf("File coach_client.dat not found !");
}
}


