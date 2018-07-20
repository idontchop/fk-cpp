#include <time.h>
#include <iostream.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <errno.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0                            /* Boolean constant definitions */
#define TRUE !FALSE

int eopen(char *pszFileName);

void pedit(void);
void setup(void);
void regis(void);
void save(void);
void nodesetup(void);
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
long regis;
char bbsname[30];
int numjokes;		//number of jokes available for a day
};


unsigned char com;
int user;
struct player_info data[60];
struct info2 edata;
struct settings setting[2];
struct _nodes node[2];

int main()
{
int handle;
if((handle=eopen("player.dat"))==-1){
	printf("\n\rMissing data file : player.dat.\n\r");
	exit(0);}
read(handle,data,(sizeof(struct player_info)*60));
close(handle);
int sethandle;
if((sethandle=eopen("sett.ing"))==-1){
	printf("\n\rMissing data file : sett.ing.\n\r");
	exit(0);}
read(sethandle,setting,sizeof(struct settings));
close(sethandle);
int on;
do{
clrscr();
for(on=0;on<setting[0].num_users;on++)
	{
	if(data[on].online != -1)
		{
		fkp("~12Warning:~15  Users detected online!  Careful who you edit.\n\r");
		fkp("Only changes made to offline users will stick.\n\r");
		}
	}
fkp("~15Player Editor and Setup\n\r");
fkp("~31.~13  Player editor\n\r");
fkp("~32.~13  Setup\n\r");
fkp("~33.~13  Node setup\n\r");
fkp("~34.~13  Register\n\r");
fkp("~35.~13  Quit\n\r");
com = getch();
switch(com)
{
case '1':{if(setting[0].num_users == 0)
			{printf("\nNo players to edit.\n");
			sleep(2);
			}
	    else{
	    pedit();}
	    break;}
case '2':{setup();
	    break;}
case '3':{nodesetup();
		break;}
case '4':{regis();
	    break;}
}
}while(com != '5');
save();
return 0;
}

void pedit(void)
{
char ansi[4], jkl[4];
long change;
user = 0;
char file[12];
int fhandle;
do{
sprintf(file,"%d.dat",data[user].lognumber);
if((fhandle=eopen(file))==-1)
	{
	fkp("~15File not found.\n\r");
	}
read(fhandle,&edata,sizeof(struct info2));
close(fhandle);
if(data[user].trueansi == TRUE)
	strcpy(ansi,"Yes");
	else strcpy(ansi,"No");
if(data[user].ANSI == TRUE)
	strcpy(jkl,"Yes");
	else strcpy(jkl,"No");
clrscr();
fkp("~9Press ~13<~9 and ~13>~9 to change player\n\r");
fkp("~9Name:  ~15");  fkp(data[user].name);
fkp("\n\n\r~13A.~9  Alias:~15  "); fkp(data[user].alias);
fkp("\n\r~13B.~9  Sex: ~15 ");  putch(data[user].sex);
fkp("\n\r~13C.~9  Strength:~15  ");  cprintf("%d",data[user].strength);
fkp("\n\r~13D.~9  Dexterity:~15  "); cprintf("%d",data[user].dex);
fkp("\n\r~13E.~9  Skill level:~15  "); cprintf("%d",data[user].skill);
fkp("\n\r~13F.~9  Experience:~15  "); cprintf("%u",data[user].exp);
fkp("\n\r~13G.~9  Total hitpoints: ~15 "); cprintf("%d",data[user].totalhit);
fkp("\n\r~13H.~9  Hitpoints:~15  "); cprintf("%d",data[user].hitpts);
fkp("\n\r~13I.~9  Aim:~15  "); cprintf("%d",data[user].aim);
fkp("\n\r~13J.~9  Coins:~15  "); cprintf("%u",data[user].coins);
fkp("\n\r~13K.~9  Ammo:~15  "); cprintf("%d",data[user].ammo);
fkp("\n\r~13L.~9  Turns left:~15  "); cprintf("%d",edata.turns);
fkp("\n\r~13M.~9  ANSI: ~15 "); fkp(ansi);
fkp("\n\r~13N.~9  ANSI graphics: ~15 "); fkp(jkl);
fkp("\n\r~13Q.~9  Quit\n\n\r");
fkp("~13!.~9  Run maintanence for this user\n\r");
fkp("~13Z. ~9 Nuke user\n\n\r");
com = toupper(getch());
switch(com)
{
case '!':{edata.spec=edata.spectotal;
	edata.turns = setting[0].num_turns;
	edata.fish = setting[0].fish;
	edata.forest = setting[0].forest;
	edata.mountains = setting[0].mountains;
	edata.farm = setting[0].farm;
	edata.well = FALSE;
	edata.pfight = setting[0].pfight;
	edata.conv = FALSE;
	edata.jokesleft = setting[0].numjokes;
	if(data[user].hitpts == 0)
		{data[user].hitpts = data[user].totalhit-5;
		data[user].location = 'X';}
	else data[user].hitpts = data[user].totalhit;
		break;
		}
case 'M':{if(data[user].trueansi == TRUE)
			data[user].trueansi = FALSE;
		else data[user].trueansi = TRUE;
		break;
		}
case 'N':{if(data[user].ANSI == TRUE)
			data[user].ANSI = FALSE;
		else data[user].ANSI = TRUE;
		break;
		}
case 'A':{cout << "Change Alias to what?  ";
		gets(data[user].alias);
		break;
		}
case 'B':{cout << "Change sex? [Y/N]";
		char ui;
		ui = toupper(getch());
		if(ui == 'Y')
			{if(data[user].sex == 'M')
				data[user].sex = 'F';
				else data[user].sex = 'M';
			}
		break;
		}
case 'C':{zagain:
		cout << "Change strength attribute to what?  1-22  ";
		cin >> change;
		if((change < 1) || (change > 22))
			goto zagain;
		else data[user].strength = change;
		break;
		}
case 'D':{yagain:
		cout << "Change Dexterity attribute to what?  1-22  ";
		cin >> change;
		if((change < 1) || (change > 22))
			goto yagain;
		else data[user].dex = change;
		break;
		}
case 'E':{xagain:
		cout << "Change Skill level to what?  1-25  ";
		cin >> change;
		if((change < 1) || (change > 25))
			goto xagain;
		else data[user].skill = change;
		break;
		}
case 'F':{ragain:
		cout << "Change experience to what? 1-60000  ";
		cin >> change;
		if((change < 1) || (change > 60000))
			goto ragain;
		else data[user].exp = change;
		break;
		}
case 'G':{sagain:
		cout << "Change total hitpoints to what? 1-220  ";
		cin >> change;
		if((change < 1) || (change > 220))
			goto sagain;
		else data[user].totalhit = change;
		break;
		}
case 'H':{tagain:
		cout << "Change hitpoints to what? 0-" << data[user].totalhit << " ";
		cin >> change;
		if((change < 0) || (change > data[user].totalhit))
			goto tagain;
		else data[user].hitpts = change;
		break;
		}
case 'I':{uagain:
		cout << "Change aim to what? 1-20  ";
		cin >> change;
		if((change < 1) || (change > 20))
			goto tagain;
		else data[user].aim = change;
		break;
		}
case 'J':{wagain:
		cout << "Change coins to what? 1-60000  ";
		cin >> change;
		if((change < 1) || (change > 60000))
			goto wagain;
		else data[user].coins = change;
		break;
		}
case 'K':{magain:
		cout << "Change ammo to what? 1-30  ";
		cin >> change;
		if((change < 1) || (change > 30))
			goto tagain;
		else data[user].ammo = change;
		break;
		}
case 'L':{jagain:
		cout << "Change number of turns left to what? 1-" << setting[0].num_turns << " ";
		cin >> change;
		if((change < 1) || (change > setting[0].num_turns))
			goto jagain;
		else edata.turns = change;
		break;
		}
case '.':
case '>':{user++;
		if(user == setting[0].num_users)
			user--;
		break;
		}
case ',':
case '<':{user--;
		if(user == -1)
			user++;
		break;
		}
case 'Z':{int to;
		int from;
		printf("\nAre you sure!?\n");
		char you;
		you = toupper(getch());
		if(you == 'Y')
			{char buf[80];
			sprintf(buf,"%d.asc",data[user].lognumber);
			remove(buf);
			sprintf(buf,"%d.dat",data[user].lognumber);
			remove(buf);
			to = user;
			from = (user + 1);
			setting[0].num_users -= 1;
			for(;to < setting[0].num_users;to++,from++)
			{data[to] = data[from];
			}
			user -= 1;
			if(user == -1)
				user++;
			if(setting[0].num_users == 0)
				com = 'Q';
			}
		break;
		}
case 'Q':{break;}
}
if((fhandle=eopen(file))==-1)
	{
	fkp("~15File not found.\n\r");
	}
write(fhandle,&edata,sizeof(struct info2));
close(fhandle);
}while(com != 'Q');
}

void setup(void)
{
int ccount;
int change;
do{
clrscr();
fkp("\n\n\r~13A.~9  Max number of turns: ~15"); cprintf("%d",setting[0].num_turns);
fkp("~13\n\rB.~9  Days before deleted from game: ~15"); cprintf("%d",setting[0].days_delete);
fkp("~13\n\rC.~9  Max turns for fishing: ~15"); cprintf("%d",setting[0].fish);
fkp("~13\n\rD.~9  Max turns for forest: ~15"); cprintf("%d",setting[0].forest);
fkp("~13\n\rE.~9  Max turns for mountains: ~15"); cprintf("%d",setting[0].mountains);
fkp("~13\n\rF.~9  Max turns for farms: ~15"); cprintf("%d",setting[0].farm);
fkp("~13\n\rG.~9  Max turns for player fights: ~15"); cprintf("%d",setting[0].pfight);
fkp("~13\n\rH.~9  Max turns for Jokes:  ~15");  cprintf("%d",setting[0].numjokes);
fkp("~13\n\rI.~9  BBS name:  ~15"); fkp(setting[0].bbsname);
fkp("\n\r\r~13J.~9  Fix nodes.~15  (Use if it reports a user on who is not)\n\r");
fkp("                (or if it reports someone in chat who is not)\n\r");
fkp("~13K.~9  Allow/Disallow rude getures in chat\n\r");
fkp("~13Q.~9  Quit\n\r");
com = toupper(getch());
switch(com)
{
case 'K':{if(fopen("rude.no","r")==NULL)
			{
			fclose(fopen("rude.no","w"));
			printf("Disallowing rude gestures.");
			sleep(4);
			break;}
		remove("rude.no");
		printf("Allowing rude gestures in chat.");
		sleep(4);
		break;}
case 'G':{gagain:
		cout << "Change number of player fights to what? 2-100 ";
		cin >> change;
		if((change < 2) || (change > 100))
			goto gagain;
		else setting[0].pfight = change;
		break;
		}
case 'I':{printf("\n\nEnter your bbs name:  ");
		gets(setting[0].bbsname);
		break;}
case 'J':{for(ccount=0;ccount<setting[0].num_users;ccount++)
			{if(data[ccount].online != -1)
				{
				data[ccount].online = -1;
				printf("Logging user %s off.\n",data[ccount].alias);
				}
			}
		for(ccount=0;ccount<60;ccount++)
			{if((data[ccount].location == '$') || (data[ccount].location == '@'))
				data[ccount].location = 'F';
			}
		break;
	    }
case 'A':{aagain:
		cout << "Change number of turns to what? 2-1000 ";
		cin >> change;
		if((change < 2) || (change > 1000))
			goto aagain;
		else{setting[0].num_turns = change;
		}
		break;
		}
case 'H':{Tagain:
		cout << "Change number of jokes turns to what? 1-10 ";
		cin >> change;
		if((change <1)||(change>10))
			goto Tagain;
		else{setting[0].numjokes = change;}
		break;
		}
case 'B':{bagain:
		cout << "Change number of days till deleted from game to what? 2-100 ";
		cin >> change;
		if((change < 2) || (change > 100))
			goto bagain;
		else{setting[0].days_delete = change;
		}
		break;
		}
case 'C':{cagain:
		cout << "Change fishing turns to what? 2-100 ";
		cin >> change;
		if((change < 2) || (change > 100))
			goto cagain;
		else setting[0].fish = change;
		break;
		}
case 'D':{dagain:
		cout << "Change forest turns to what? 2-100 ";
		cin >> change;
		if((change < 2) || (change > 100))
			goto dagain;
		else setting[0].forest = change;
		break;
		}
case 'E':{eagain:
		cout << "Change mountain turns to what? 2-100 ";
		cin >> change;
		if((change < 2) || (change > 100))
			goto eagain;
		else setting[0].mountains = change;
		break;
		}
case 'F':{fagain:
		cout << "Change farm turns to what? 1-10 ";
		cin >> change;
		if((change < 1) || (change > 10))
			goto fagain;
		else setting[0].farm = change;
		break;
		}
case 'Q':{break;}
}
}while(com != 'Q');
}

void regis(void)
{
long regist(void);
if((strcmp(setting[0].registered,"GLSKDMTEPDOGKFS") == 0)&&(setting[0].regis==regist()))
	{cout << "\nGame is already registered\n";}
else{
cout << "\nEnter registration code (letters):  ";
gets(setting[0].registered);
if(strcmp(setting[0].registered,"GLSKDMTEPDOGKFS") != 0)
	{cout << "\nWrong code entered.\n";
	}
else{cout << "\nEnter registration code (numbers):  ";
	cin >> setting[0].regis;
	if(setting[0].regis == regist())
		cout << "\nThank you for registering\n";
	else cout << "\bWrong Code entered.\n";
	}
}
if((strcmp(setting[0].registered,"GLSKDMTEPDOGKFS") == 0)&&(setting[0].regis==regist()))
{
cout << "Enter the name to appear to the players:  ";
gets(setting[0].registeredto);
cout << "Press any key\n";
}
getch();
}

long regist(void)
{
long j=0;
int cc;
for(cc=0;cc<30;cc++)
	{
	if(setting[0].bbsname[cc]=='\0')
		break;
	j += toupper(setting[0].bbsname[cc]);
	}
j = j+50000;
j = j/5;
j = j+2;
return j;
}

void nodesetup(void)
{
char patht[80];
char in[3];
struct _nodes node1[2];
char cnode;
int snode;
snode=1;
FILE *nodefp;
char filename[12];
if((nodefp=fopen("node1.dat","r"))==NULL)
	{printf("\nNode1.dat not found.  Has install.exe been run?\n");
	getch();
	goto nodeend;}
fclose(nodefp);
int nodehandle;
nodehandle=open("node1.dat",O_RDONLY|O_BINARY);
read(nodehandle,node1,(sizeof(struct _nodes)));
close(nodehandle);
do{
if((snode>999) || (snode<1))
	snode=1;
sprintf(filename,"node%d.dat",snode);
if((nodehandle=open(filename,O_RDONLY|O_BINARY))==-1)
	{printf("Creating file for node %d.\n",snode);
	printf("Creating node %d with node 1's attributes.\n",snode);
	printf("Press any key.");
	getch();
	fclose(fopen(filename,"w"));
	strcpy(node[0].path,node1[0].path);
	node[0].com = node1[0].com;
	node[0].IRQ = node1[0].IRQ;
	nodehandle=open(filename,O_RDONLY|O_BINARY);
	}
else read(nodehandle,node,(sizeof(struct _nodes)*2));
close(nodehandle);
clrscr();
printf("NODE %d SETUP\n\n",snode);
printf("< and > to change nodes\n\n");
printf("J.  Jump to another node\n\n");
printf("A.  Comport.............");
if(node[0].com == 10)
	printf("Read from drop file\n");
else printf("%d\n",node[0].com);
printf("B.  IRQ.................");
if((node[0].IRQ == 10) || (node[0].com == 10))
	printf("Standard\n");
else printf("%d\n",node[0].IRQ);
printf("C.  Path to Drop File...%s\n",node[0].path);
printf("Q.  Quit\n\n");
cnode=toupper(getch());
switch(cnode)
{
case 'A':{printf("Enter new comport (10 to read from drop file):  ");
	  gets(in);
	  node[0].com=atoi(in);
	  break;}
case 'B':{printf("Enter new IRQ (10 to use standard):  ");
	  gets(in);
	  node[0].IRQ=atoi(in);
	  break;}
case 'C':{printf("Enter new path :  ");
	  gets(node[0].path);
	  break;}
case 'J':{printf("Enter node to jump to:  ");
	  gets(in);
	  snode=atoi(in);
	  break;}
case '<':
case ',':{snode--;
	  break;}
case '.':
case '>':{snode++;
	  break;}
}
nodehandle=open(filename,O_WRONLY|O_BINARY);
write(nodehandle,node,(sizeof(struct _nodes)*2));
close(nodehandle);
}while(cnode!='Q');
nodeend:
}


void save(void)
{
int savehandle;
if((savehandle=eopen("player.dat"))==-1){
	printf("\n\rMissing data file : player.dat.\n\r");
	printf("Unable to save data.\n\r");
	}
write(savehandle,data,(sizeof(struct player_info)*60));
close(savehandle);
if((savehandle=eopen("sett.ing"))==-1){
	printf("\n\rMissing data file : sett.ing.\n\r");
	printf("Unable to save data.\n\r");
	}
write(savehandle,setting,sizeof(struct settings));
close(savehandle);
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