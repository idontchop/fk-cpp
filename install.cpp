#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define FALSE 0                            /* Boolean constant definitions */
#define TRUE !FALSE

void fkp(char *j);

struct _nodes{
int com;		//10 if read from drop
int IRQ;		//10 if standard
char path[80]; //path to drop file
}; 	//0 for local
struct player_info{
char name[30];          //name taken from od.control
char alias[20];         //allias for player
char sex;               //M for male, F for female
char ANSI;              //player is asked, TRUE if available, FALSE if not
int strength;           //Strength value
int dex;                //Dexterity value
int skill;              //skill level value
unsigned int exp;      //experience
int hitpts;             //health of the player
int totalhit;           //total hit points possible
char town;              //What town player is in
char location;          //location within the town
unsigned int coins;             //Amount of gold
unsigned int bankcoins;	//amount of gold in the bank
char weaponshort;       //Indicates what type of short-range weapon held
char weaponlong;        //Indicates what type of long-range weapon held
int ammo;               //Amount of ammo for long-range weapons
char armor;             //Indicate what type of armor wearing
char shield;            //Indicates what type of shield held
int aim;                //Aim ability
int lognumber;          //number that personal logfile will be named
char newmessage;        //TRUE indicates new message in logfile, FALSE is none
char trueansi;          //contains whether the user wants ansi
int theif;     //Theiving skill, 1-22
char stype[14];	//name of short weapon
char ltype[10];
int online;		//holds node number -1 if not on
unsigned int kills;//number of kills made
int honor;		//The honor of the player can be negative
};

struct settings{
int num_log;            //next number to be used in log
int num_turns;          //number of total turns each player gets
int num_users;          //number of players
int days_delete;        //number of days before player is deleted
char registered[20];    //string sysop entered to register game
int fish,forest,mountains,farm; //keeps track of turns used to do each
//10 turns to fish, 10 to hunt, 10 to explore mountains,1 to steal from farm
//these numbers are default, sysop can change them.
int pfight;
//Turns for fighing players and for online fighting
char weather;
//Code for holding weather conditions for that day which effect fishing
//[S]torming, [R]aining, [F]air, sno[W]ing, [H]ot, [C]old
char death;	//if death has been found, FALSE.  Still available=TRUE
char gem;		//same as death
char win;
char registeredto[20];
long int regis;
char bbsname[30];
int numjokes;		//number of jokes available for a day
int num_spe;		//number of total special attacks there are
};


int handle;

struct player_info data[60];
struct settings setting[2];
struct _nodes node[2];

int main()
{
struct tm *ptr;
time_t now;
char *tim;
time(&now);
ptr = localtime(&now);
tim = asctime(ptr);
char jkl;
FILE *fp;
if((fp=fopen("player.dat","r")) != NULL)
	{fkp("\n\r~13Player.dat found.  Game in progress.  ~9Are you sure you want to restart?\n\r");
	do{
	jkl = toupper(getch());
	}while((jkl != 'N') && (jkl != 'Y'));
	if(jkl == 'N')
		{exit(1);}
	}
else{fkp("\n\r~13Player.dat not found, that must mean you are starting a new game.\n\r~9Thanks for playing!  Registration is only $14.\n\r");
	fkp("~13If you haven't already, you need to read ~15fksysop.doc ~13to see about the\n\rgame and learn how to set up the maintenance program.\n\r");
	}
fclose(fp);
remove("player.dat");
fp=fopen("player.dat","w");
fclose(fp);
if((handle=open("player.dat",O_WRONLY|O_BINARY))==-1){
	fkp("\n\r~15Error in creating player.dat.  Possibly out of space?\n\r");
	exit(0);}
write(handle,data,(sizeof(struct player_info)*60));
close(handle);
fkp("~13Starting game~9.~15.~13.\n\r");
if((fp=fopen("sett.ing","r")) != NULL)
{
if((handle=open("sett.ing",O_RDONLY|O_BINARY))==-1){
		printf("\n\rerror1\n\r");
		exit(0);}
read(handle,setting,sizeof(struct settings));
close(handle);
}
else{
	fp=fopen("sett.ing","w");
	fclose(fp);
	setting[0].num_turns = 50;
	setting[0].days_delete = 20;
	if(stricmp(setting[0].registered,"") == 0)
		strcpy(setting[0].registeredto,"[Unregistered]");
	setting[0].fish = 10;
	setting[0].mountains = 10;
	setting[0].forest = 10;
	setting[0].farm = 3;
	setting[0].pfight = 2;
	setting[0].weather = 'F';
	setting[0].num_spe = 13;
	setting[0].numjokes = 0;
	char fkpath[80],bat[80];
	fkp("\n\r~13Please enter your bbs name: ~15 ");
	gets(setting[0].bbsname);
	fkp("\n\r~13Please enter the drive and directory FK is installed in (this directory): \n\r>~15 ");
	gets(fkpath);
	fp=fopen("fk.bat","w");
	fprintf(fp,"cd %s\n",fkpath);
	fprintf(fp,"REM MAKE SURE CORRECT PATH IS USED!!!\n");
	fprintf(fp,"IF \"%1\" == \"\" GOTO LOCAL\n");
	fprintf(fp,"KING %1\n");
	fprintf(fp,"GOTO END\n");
	fprintf(fp,":LOCAL\n");
	fprintf(fp,"KING LOCAL\n");
	fprintf(fp,":END\n");
	fclose(fp);
	fkp("\n\r~15Fk.bat~13 is now being created to be used by your BBS.  Not for local play.\n\r");
	fkp("\n\rTo play Farmers and Kings locally, run king.exe with arguement \"-l.\"\n\r");
	fkp("You may want to check fk.bat to make sure it fits your BBS needs.\n\r");
	fkp("~8<Press any key>\n\r");
	getch();
	fkp("\n\n\r~9This version of Farmers and Kings has support for a multi-node system.\n\r");
	fkp("It also includes special features to take advantage of multi-nodes.\n\r");
	fkp("If you run a single-line system, answering the next questions will setup game.\n\r");
	fkp("If you run a multi-line system, be sure to setup your nodes with fkedit.exe.\n\r");
	char ab,cd;
	char in[2];
	fkp("~15NODE 1 setup:\n\r");
	fkp("\n\r~13Farmers and Kings runs on internal com routines...\n\r");
	fkp("~14Read comport from drop file? [Y/N] ~15");
	ab=toupper(getch());
	if(ab == 'Y')
		node[0].com = 10;
	else{fkp("\n\r~15Enter the com port (0 = COM1) (1 = COM2)... : ~13");
		gets(in);
		node[0].com=atoi(in);
		fkp("\n\r~15Standerd IRQ? [Y/N] ");
		cd=toupper(getch());
		if(cd == 'Y')
			{node[0].IRQ = 10;
			}
		else{fkp("~13Enter IRQ:  ~15 ");
			gets(in);
			node[0].IRQ=atoi(in);
			}
		}
	fkp("\n\r~15Enter ~9FULL~15 path to drop file (please add ~9\\~15 after path)\n\r> ");
	do{
	gets(node[0].path);
	}while(strcmp(node[0].path,"") == 0);
	fkp("\n\r~13Saving Node 1 setup...\n\r");
	fp=fopen("node1.dat","w");
	fclose(fp);
	int nodehandle;
	if((nodehandle=open("node1.dat",O_WRONLY|O_BINARY))==-1)
		{printf("Error opening file.  Possibly out of space?\n\r");
		printf("\n\rExiting setup...\n\r");
		exit(0);}
	write(nodehandle,node,(sizeof(struct _nodes)*2));
	close(nodehandle);
	fkp("~15Remember to add a parameter to fk.bat indicating the node. \n\rSingle-line systems add ~13\"1\"\n\r");
	}
char buff[10];
setting[0].win = 100;
for(int cc = 0;cc<setting[0].num_users;cc++)
	{sprintf(buff,"%d.asc",data[cc].lognumber);
	remove(buff);
	}
for(cc=0;cc<setting[0].num_users;cc++)
	{sprintf(buff,"%d.dat",data[cc].lognumber);
	remove(buff);
	}
setting[0].num_users = 0;
setting[0].num_log = 0;
remove("day0.log");
fp = fopen("day0.log","w+");
char buf[80];
strftime(buf, 80,"~9                          %A, %B %d.",ptr);
fprintf(fp,"%s\n",buf);
fprintf(fp,"~15              Game started at ~12%s",tim);
 fprintf(fp,"~9                                 = = =\n");
fclose(fp);
int hc;
char buf23[10];
for(hc = 0;hc < 51;hc++)
	{sprintf(buf23,"%d.asc",hc);
	remove(buf23);
	}
remove("hayward.con");
remove("den.con");
remove("pomdir.con");
remove("easttrim.con");
remove("sussenex.con");
remove("burkshir.con");
remove("tiw.con");
remove("hideout.con");
remove("day1.log");
remove("day2.log");
remove("day3.log");
remove("day4.log");
remove("day5.log");
remove("conver.asc");
setting[0].death = TRUE;
setting[0].gem = TRUE;
char filek[12];
for(int cio = 0;cio<51;cio++)
	{sprintf(filek,"%d.asc",cio);
	remove(filek);
	}
fp=fopen("conver.asc","w");
fprintf(fp,"~9Bartender~12:~15\nDo you think all the farmers out of work will help our business?\n");
fprintf(fp,"~9Velvet~12:~15\nIndeed!  All those slobbering men will come over and spend their last dime.\n");
fprintf(fp,"~9Oliver~12:\n~15I just hope their is some farm girls coming over.\n");
if((handle=open("sett.ing",O_WRONLY|O_BINARY))==-1){
		printf("\n\rerror2\n\r");
		exit(0);}
write(handle,setting,sizeof(struct settings));
close(handle);
fkp("\n\r~15Install.exe~9 is used only to restart.  Use ~15fkedit.exe~9 for setup.\n\r");
fkp("Game is now ready to be ran, use ~15fk.bat~9 to run from the bbs.\n\r");
fkp("~15Maintain.exe~9 needs to be ran at least once a day.\n\r~7 ");
return 0;
}

void fkp(char *j)
{
int cc = 0;
while(1)
{
if(j[cc] == '~')
{
cc++;
switch(j[cc])
{
	case '0':{textcolor(0);
			break;}
	case '2':{textcolor(2);
			break;}
	case '3':{textcolor(3);
			break;}
	case '4':{textcolor(4);
			break;}
	case '5':{textcolor(5);
			break;}
	case '6':{textcolor(6);
			break;}
	case '7':{textcolor(7);
			break;}
	case '8':{textcolor(8);
			break;}
	case '9':{textcolor(9);
			break;}
	case '1':{cc++;
			switch(j[cc])
			{
			case '1':{textcolor(11);
					break;}
			case '0':{textcolor(10);
					break;}
			case '2':{textcolor(12);
					break;}
			case '3':{textcolor(12);
					break;}
			case '4':{textcolor(14);
					break;}
			case '5':{textcolor(15);
					break;}
			default:{textcolor(1);
					putch(j[cc]);
					break;}
			}
			break;
			}
	}
	cc++;
	}
else if(j[cc] != '\0')
	{
	putch(j[cc]);
	cc++;
	}
else break;
}
}

