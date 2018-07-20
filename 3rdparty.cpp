#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//program call
//3rdparty.exe mod_name town_location path_to_mod path_to_fk

struct _3rdparty{
char name[70];  //name of module
char location;  //town name
char path[80];  //path to module
} module[20];



int handle,nummod;
void main(int argc, char *argv[])
{
FILE *fp;
if(argc <= 1)
	{printf("Please read 3rdparty.txt to use this program.\n");
	}
else if(argc != 5)
	{printf("Improper use:  module not loaded.");
	}
else{char comline[80];
	sprintf(comline,"cd %s",argv[4]);
	system(comline);
	if((fp=fopen("3rdparty.num","r"))==NULL)
		{printf("\"3rdparty.num\" not found.  Creating one.  Make sure correct path was used.\n");
		nummod=0;}
	fscanf(fp,"%d",nummod);
	fclose(fp);
	strcpy(module[nummod].name,argv[1]);
	if(stricmp(argv[2],"hayward") == 0)
		module[nummod].location = 'H';
	else if(stricmp(argv[2],"den") == 0)
		module[nummod].location = 'D';
	else if(stricmp(argv[2],"pomdirgunua") == 0)
		module[nummod].location = 'P';
	else if(stricmp(argv[2],"burkshire") == 0)
		module[nummod].location = 'B';
	else if(stricmp(argv[2],"tiw") == 0)
		module[nummod].location = 'T';
	else{printf("Error in town name\n");
		exit(0);}
	strcpy(module[nummod].path,argv[3]);
	nummod++;
	remove("3rdparty.num");
	if((fp=fopen("3rdparty.num","w"))==NULL)
		{printf("Program error");
		exit(0);}
	fprintf(fp,"%d",nummod);
	int handle2;
	if((handle2=open("3rdparty.dat",O_WRONLY|O_BINARY))==-1){
		again:
		printf("3rdparty.dat not found. Creating one, make sure correct directory was used.\n");
		FILE *fp;
		fp=fopen("3rdparty.dat","w");
		fclose(fp);
		if((handle2=open("3rdparty.dat",O_WRONLY|O_BINARY))==-1){
			printf("Error in 3rdparty.exe, program not loaded.");
			exit(0);}
		}
	write(handle2,module,(sizeof(struct _3rdparty)*20));
	close(handle2);
}

}

