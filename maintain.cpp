#include <share.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <dos.h>

#define FALSE 0                            /* Boolean constant definitions */
#define TRUE !FALSE

int file_copy(char *oldname,char *newname);
int eopen(char *pszFileName);
FILE *fopenw(char *pszFileName,int wait);

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

//	extra data info
struct info2{
int trainpts;		//tells how much can train, not known to player
int i0,i1,i2,i3,i4,i5,i6;	//each stands for particular item, count
//i0 is fish, i1 is skins, i2 is meat, i3 is bread, i4 is horse,
//i5 is dragon scales, i6 is fur suit
char progress;		//progress to the king
int turns;		//number of turns the player has left
char hunger;		//A for stuff, B for fine, C for hungry, D for starving
int fish,forest,mountains,farm;	//how many turns for each
int pfight;		//how many for player fights
char inactivity;	//counts amount of days hasn't played
char prodeath;		//progress variable to death scythe
char proscor;		//progress variable to get Scorion's axe
char protiw;		//progress variable at Tiw
char well;		//whether or not visited well
char qf;			//if quick fight is engaged
char conv;		//whether or not conversed for the day
char jokesleft;	//jokes left for the day
char artype[12];	//name of armor type
char shtype;		//name of shield type
char undead;		//whether or not has undead scarab
char spe[10];		//10 slots of special attacks
char spec;		//special attacks left for the day
char spectotal;	//total number of special attacks
char compname[10];  //name of the companion
char compatt;		//attack strength of comp   0 if no companion
char compa[70];	//attack hit string of companion
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
};

int user, handle, to, from,playhandle;
struct player_info data[60];
struct settings setting[2];
struct info2 edata;


int main()
{
char pfile[12];
int phandle;
printf("\nChecking internal structure...\n");
struct tm *ptr;
time_t now;
char *tim;
time(&now);
ptr = localtime(&now);
tim = asctime(ptr);
if((playhandle=eopen("player.dat"))==-1){
	printf("7");
	printf("\n\rMissing data file : player.dat.\n\r");
	goto end;}
read(playhandle,data,(sizeof(struct player_info)*60));
close(playhandle);
if((handle=eopen("sett.ing"))==-1){
	printf("\n\rMissing data file : sett.ing.\n\r");
	goto end;}
read(handle,setting,sizeof(struct settings));
close(handle);
for(user=0;user<setting[0].num_users;user++)
{
if(data[user].online != -1)
	{fclose(fopen("maintain.!!!","w"));
	FILE *fp2;
	if((fp2=fopenw("chat.log",10))==NULL)
		{
		}
	else{
	fprintf(fp2,"~*");
	fclose(fp2);}
	printf("Users detected online! Kicking off... giving 30 seconds to comply...\n");
	sleep(30);
	break;
	}
}
sleep(5);
if((playhandle=eopen("player.dat"))==-1){
	printf("7");
	printf("\n\rMissing data file : player.dat.\n\r");
	goto end;}
read(playhandle,data,(sizeof(struct player_info)*60));
if((handle=eopen("sett.ing"))==-1){
	printf("\n\rMissing data file : sett.ing.\n\r");
	goto end;}
read(handle,setting,sizeof(struct settings));
if(setting[0].win != 100)
	{printf("Restarting game...\n");
	int hc;
	char buf23[10];
	for(hc=0;hc<setting[0].num_users;hc++)
		{
		sprintf(pfile,"%d.dat",data[hc].lognumber);
		remove(pfile);
		}
	for(hc = 0;hc < setting[0].num_users;hc++)
		{sprintf(buf23,"%d.asc",data[hc].lognumber);
		remove(buf23);
		}
	setting[0].num_users = 0;
	char buff[10];
	setting[0].win = 100;
	for(int cc = 0;cc<setting[0].num_log;cc++)
		{sprintf(buff,"%d.asc",data[cc].lognumber);
		remove(buff);
		}
	setting[0].num_log = 0;
	remove("announce.asc");
	FILE *fp;
	system("del day0.log");
	fp = fopen("day0.log","w+");
	char buf[80];
	strftime(buf, 80,"~9                             %A, %B %d.",ptr);
	fprintf(fp,"%s\n",buf);
	fprintf(fp,"~15                  Game started at~12 %s", tim);
	 fprintf(fp,"~9                                 = = =\n");
	fclose(fp);
	remove("day1.log");
	remove("day2.log");
	remove("day3.log");
	remove("day4.log");
	remove("day5.log");
	setting[0].death = TRUE;
	setting[0].gem = TRUE;}
printf("Healing wounds...\n");
for(user = 0;user<setting[0].num_users;user++)
	{
	if(data[user].online != -1)
		data[user].online = -1;
	if(data[user].hitpts == 0)
		{data[user].hitpts = data[user].totalhit-5;
		data[user].location = 'X';}
	else data[user].hitpts = data[user].totalhit;
	}
printf("Giving turns...\n");
for(user = 0;user<setting[0].num_users;user++)
	{
	sprintf(pfile,"%d.dat",data[user].lognumber);
	if((phandle=eopen(pfile))==-1) printf("error");
	read(phandle,&edata,sizeof(struct info2));
	edata.spec=edata.spectotal;
	edata.turns = setting[0].num_turns;
	edata.fish = setting[0].fish;
	edata.forest = setting[0].forest;
	edata.mountains = setting[0].mountains;
	edata.farm = setting[0].farm;
	edata.well = FALSE;
	edata.pfight = setting[0].pfight;
	edata.conv = FALSE;
	edata.jokesleft = setting[0].numjokes;
	lseek(phandle,0,SEEK_SET);
	write(phandle,&edata,sizeof(struct info2));
	close(phandle);
	}
printf("Updating hunger...\n");
for(user = 0;user<setting[0].num_users;user++)
	{
	sprintf(pfile,"%d.dat",data[user].lognumber);
	if((phandle=eopen(pfile))==-1) printf("error");
	read(phandle,&edata,sizeof(struct info2));
	if(edata.hunger == 'A')
		edata.hunger = 'B';
	else if(edata.hunger == 'B')
		edata.hunger = 'C';
	else if(edata.hunger == 'C')
		edata.hunger = 'D';
	else edata.hunger = 'D';
	lseek(phandle,0,SEEK_SET);
	write(phandle,&edata,sizeof(struct info2));
	close(phandle);
	}
printf("Checking for suicides and inactivity...\n");
for(user = 0;user<setting[0].num_users;user++)
	{sprintf(pfile,"%d.dat",data[user].lognumber);
	if((phandle=eopen(pfile))==-1) printf("error");
	read(phandle,&edata,sizeof(struct info2));

	if((stricmp(data[user].name, "suicide") == 0) || (edata.inactivity >= setting[0].days_delete))
		{printf("Deleting %s\n",data[user].alias);
		close(phandle);
		remove(pfile);
		sprintf(pfile,"%d.asc",data[user].lognumber);
		remove(pfile);
		to = user;
		from = (user + 1);
		setting[0].num_users--;
		for(;to < setting[0].num_users;to++,from++)
			{data[to] = data[from];
			}
		}
	else{edata.inactivity++;
		lseek(phandle,0,SEEK_SET);
		write(phandle,&edata,sizeof(struct info2));
		close(phandle);}
	}
setting[0].weather = 'F';
lseek(playhandle,0,SEEK_SET);
write(playhandle,data,(sizeof(struct player_info)*60));
close(playhandle);
lseek(handle,0,SEEK_SET);
write(handle,setting,sizeof(struct settings));
close(handle);
printf("Handling log files...\n");
file_copy("day4.log","day5.log");
file_copy("day3.log","day4.log");
file_copy("day2.log","day3.log");
file_copy("day1.log","day2.log");
file_copy("day0.log","day1.log");
FILE *fp;
system("del day0.log");
fp = fopen("day0.log","w+");
char buf[80];
strftime(buf, 80,"~9                          %A, %B %d.",ptr);
fprintf(fp,"%s\n",buf);
fprintf(fp,"~15             Maintanence ran at ~12%s",tim);
 fprintf(fp,"~9                                 = = =\n");
fclose(fp);
printf("All Done...\n");
remove("maintain.!!!");
remove("chat.log");
end:
return 0;
}


int file_copy(char *oldname,char *newname)
{
FILE *fold, *fnew;
int c;
if((fold = fopen(oldname,"rb"))==NULL)
	return -1;
if((fnew = fopen(newname,"wb"))==NULL)
	{fclose(fold);
	return -1;}
while(1)
{
c = fgetc(fold);
if(!feof(fold))
	fputc(c,fnew);
else break;
}
fclose(fnew);
fclose(fold);
return 0;
}

int eopen(char *pszFileName)
{
  int fpFile = -1;
   time_t StartTime = time(NULL);

   /* Attempt to open the file while there is still time remaining. */
   while(((fpFile = open(pszFileName,O_RDWR|O_BINARY)) == -1)
	 && (errno == EACCES)
	 && (difftime(time(NULL), StartTime) < 50))
   {
	 /* If we were unable to open the file, call od_kernal, so that    */
	 /* OpenDoors can continue to respond to sysop function keys, loss */
	 /* of connection, etc.                                            */
   }
   /* Return FILE pointer for opened file, if any. */
   return(fpFile);
}

FILE *fopenw(char *pszFileName,int wait)
{
   FILE *fpFile = NULL;
   time_t StartTime = time(NULL);


   /* Attempt to open the file while there is still time remaining. */
   while(((fpFile = _fsopen(pszFileName,"a",SH_DENYWR)) == NULL)
	 && (errno == EACCES)
	 && (difftime(time(NULL), StartTime) < wait))
   {
	 /* If we were unable to open the file, call od_kernal, so that    */
	 /* OpenDoors can continue to respond to sysop function keys, loss */
	 /* of connection, etc.                                            */
   }

   /* Return FILE pointer for opened file, if any. */
   return(fpFile);
}
