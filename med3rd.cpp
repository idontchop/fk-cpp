#include "med.h"
#include <time.h>
#include <conio.h>
#include <errno.h>
#include <share.h>
#include <ctype.h>

int opennoder(char *pszFileName);
void with(void);      //
void bank(void);      // for banking privilege
void check(void);     //
void dep(void);       //
extern struct player_info data[60];
extern struct settings setting[2];
extern struct info2 edata;
extern int user;
struct monsters monster;

struct _nodes{
int com;		//10 if read from drop
int IRQ;		//10 if standard
char path[80]; //path to drop file
}; 	//0 for local

struct _nodes node[2];

char more(void);
void fk_spawn(char *a);

struct _3rdparty{
char name[70];  //name of module
char location;  //town name
char path[80];  //path to module
} module[20];

void forestsearch(void)
{
FILE *fp;
char yon,numstr[2];
int fhandle,num,ccc;
int modnum = 0;
if((fp=fopenr("3rdparty.num",2))!=NULL)
	fscanf(fp,"%d",&modnum);
fclose(fp);
if((fhandle=open("3rdparty.dat",O_RDONLY|O_BINARY))==-1)
	{yon = FALSE;}
else{read(fhandle,module,(sizeof(struct _3rdparty)*20));
	close(fhandle);
	yon = TRUE;}
od_clr_scr();
searchagain:
od_printf("`bright green`\n\rSearching the forest, you find:\n\r");
od_printf("`green`\n\rH.  Healing Well\n\r");
if(data[user].town == 'H')
	od_printf("T.  Treasure Hole\n\r");
if(yon == TRUE){
for(ccc = 0;ccc<modnum;ccc++)
	{if(data[user].town == module[ccc].location)
		{od_printf("%d.  %s\n\r",ccc,module[ccc].name);
		}
	}
	}
od_printf("\n\rL.  Stop searching\n\r\n");
od_printf("`bright green`Where would you like to go?  ");
od_input_str(numstr,2,47,122);
if((numstr[0] == 'H') || (numstr[0] == 'h'))
	healingwell();
if(toupper(numstr[0])=='T')
	bank();
else if((numstr[0] != 'L') && (numstr[0] != 'l'))
	{num = atoi(numstr);
	if(module[num].location == data[user].town)
		fk_spawn(module[num].path);
	else goto searchagain;
	}
if((numstr[0]!='L')&&(numstr[0]!='l'))
	goto searchagain;
}

void healingwell(void)
{
char comm, sipran;
char sip = FALSE;
char drink = FALSE;
if(edata.well == TRUE)
	{od_printf("`bright red`\n\rYou can't seem to find the well again.");
	goto healingend;}
od_clr_scr();

do{

swrite("~10\n\rYou wander onto a clear blue spring.  A white light shines from the bottom\n\r");
swrite("of the pool.  The water looks very refreshing, do you sip some?\n\r");
swrite("~15\n\r(~9S~15)  Sip some of the water\n\r(~9D~15)  Drink all you can\n\r(~9L~15)  Leave\n\r~13");
comm = command("SDL",3);
switch(comm)
{
case 'S':{if(sip == TRUE)
			{od_printf("`bright red`\n\rYou have sipped all you want.");
			break;}
		sipran = random(4);
		if(sipran == 0)
			{od_printf("`bright red`\n\rFour extra forest fights awarded.");
			edata.forest += 4;}
		else if(sipran == 1)
			{od_printf("`bright red`\n\rFour extra fishing turns awarded.");
			edata.fish += 4;}
		else if(sipran == 2)
			{od_printf("`bright red`\n\rFour extra mountain turns awarded.");
			edata.mountains += 4;}
		else if(sipran == 3)
			{int rand;
			rand = random(5000);
			if(rand == 2500)
				{od_printf("`bright red`\n\rOne extra strength point awarded.");
				data[user].strength++;
				}
			else{od_printf("`bright red`\n\rOne extra farming turn awarded.");
				edata.farm++;
				}
			}
		sip = TRUE;
		break;
		}
case 'D':{if(drink == TRUE)
			{od_printf("`bright red`\n\rYou have drank all you can.");
			break;}
		else{
		od_printf("`bright red`\n\n\rYour hitpoints are restored!\n\r");
		data[user].hitpts = data[user].totalhit;
		drink = TRUE;}
		break;
		}
}
}while(comm != 'L');
edata.well=TRUE;
healingend:
}

void fk_spawn(char *a)
{
struct drop{
char name[30];             //*
char sex;                  //*
char ANSI;
int str;                   //*
int dex;                   //*
int skill;
int trainpts;              //*
unsigned int exp;          //*
int hitpts;                //*
int totalhit;              //*
unsigned int coins;        //*
char ws;				  //*
char wl;				  //*
char ar;				  //*
char weaponshort[14];	  //*
char weaponlong[10];	  //*
int ammo;                  //*
char armor[12];		  //*
char shield[11];
char fish;                 //*
char skins;                //*
char meat;                 //*
char bread;                //*
char horse;                //*
char dragon;               //*
char fur;                  //*
int turns;                 //*
char hunger;               //*
int aim;                   //*
int thief;                 //*
unsigned int kills;        //*
int honor;                 //*
char compname[10];         //*
char compatt;              //*
char compa[50];            //*
int comport;
int irq;
char path[80];
} d;
d.fish = edata.i0;
d.skins = edata.i1;
d.meat = edata.i2;
d.bread = edata.i3;
d.horse = edata.i4;
d.dragon = edata.i5;
d.fur = edata.i6;
d.turns = edata.turns;
d.hunger = edata.hunger;
d.aim = data[user].aim;
d.thief = data[user].theif;
d.kills = data[user].kills;
d.honor = data[user].honor;
strcpy(d.compname,edata.compname);
d.compatt = edata.compatt;
strcpy(d.compa,edata.compa);
d.comport =  od_control.port;
d.irq = od_control.od_com_irq;
strcpy(d.path,od_control.info_path);
strcpy(d.name,data[user].alias);
d.sex = data[user].sex;
d.ANSI = data[user].ANSI;
d.str = data[user].strength;
d.dex = data[user].dex;
d.skill = data[user].skill;
d.trainpts = edata.trainpts;
d.exp = data[user].exp;
d.hitpts = data[user].hitpts;
d.totalhit = data[user].totalhit;
d.coins = data[user].coins;
d.ws = data[user].weaponshort;
d.wl = data[user].weaponlong;
d.ar = data[user].armor;
strcpy(d.weaponshort,data[user].stype);
strcpy(d.weaponlong,data[user].ltype);
d.ammo = data[user].ammo;
switch(edata.shtype)
{
case 'Z':{strcpy(d.shield,"none");
	  break;}
case 'A':{strcpy(d.shield,"Small Wooden");
	break;}
case 'B':{strcpy(d.shield,"Wooden");
	break;}
case 'C':{strcpy(d.shield,"Brass");
	break;}
case 'D':{strcpy(d.shield,"Dragon-skin");
	break;}
}
strcpy(d.armor,edata.artype);
char b[90],c[90];
int con;
int drophandle;
struct drop* dptr;
dptr=&d;
//alias-sex-str-dex-aim-exp-hitpts-totalhit-coins-ammo
if(od_control.baud == 0)
	sprintf(c,"fkdrop.dat");
else sprintf(c,"fkdrop%d.dat",od_control.od_node);
if((drophandle = open(c,O_WRONLY|O_BINARY|O_CREAT)) == -1)
	{od_printf("ERROR!  Report to sysop.");
	}
for(con=0;con<30;con++)
	{if(data[user].alias[con]=='\n')
		data[user].alias[con]='\0';
	}
write(drophandle,dptr,sizeof(struct drop));
close(drophandle);
if(od_control.baud == 0)
	{sprintf(b,"%s l",a);
	od_spawn(b);}
else{sprintf(b,"%s %d",a,od_control.od_node);
	od_spawn(b);}
drophandle = open(c,O_RDONLY|O_BINARY);
read(drophandle,dptr,sizeof(struct drop));
close(drophandle);
char tam = FALSE;
if(d.fish>10||d.fish<0)
	tam=TRUE;
if(d.skins>10||d.skins<0)
	tam=TRUE;
if(d.meat>10||d.meat<0)
	tam=TRUE;
if(d.bread>10||d.bread<0)
	tam = TRUE;
if(d.horse>1||d.horse<0)
	tam = TRUE;
if(d.dragon>10||d.dragon<0)
	tam = TRUE;
if(d.fur>10||d.fur<0)
	tam = TRUE;
if(d.turns>1000||d.turns<0)
	tam = TRUE;
if(d.hunger=='A'||d.hunger=='B'||d.hunger=='C'||d.hunger=='D')
	tam = TRUE;
if(d.aim>20 || d.aim <0)
	tam = TRUE;
if(d.thief>20||d.thief<0)
	tam = TRUE;
if(d.kills>60000)
	tam = TRUE;
if(d.honor>30000||d.honor<-30000)
	tam = TRUE;
if(d.compatt<0||d.compatt>50)
	tam = TRUE;
if(d.str>22||d.str<0)
	tam = TRUE;
if(d.dex>22||d.dex<0)
	tam = TRUE;
if(d.trainpts>100||d.trainpts<0)
	tam = TRUE;
if(d.exp>60000)
	tam = TRUE;
if(d.hitpts>220||d.hitpts<0)
	tam = TRUE;
if(d.totalhit>220||d.totalhit<0)
	tam = TRUE;
if(d.coins>60000)
	tam = TRUE;


if(tam==TRUE){
od_clr_scr();
od_printf("`bright red`IMPORTANT:\n\r");
od_printf("`bright grey`Please remember where you just came from and inform the sysop of\n\r");
od_printf("a 3rdparty program error.\n\r");
od_printf("All changes done by module destroyed.\n\r");
getreturn();}
else{
edata.i0 = d.fish;
edata.i1 = d.skins;
edata.i2 = d.meat;
edata.i3=d.bread;
edata.i4=d.horse;
edata.i5=d.dragon;
edata.i6=d.fur;
edata.turns=d.turns;
edata.hunger=d.hunger;
data[user].aim=d.aim;
data[user].theif=d.thief;
data[user].kills=d.kills;
data[user].honor=d.honor;
strcpy(edata.compname,d.compname);
edata.compatt=d.compatt;
strcpy(edata.compa,d.compa);
strcpy(data[user].alias,d.name);
data[user].strength=d.str;
data[user].dex=d.dex;
edata.trainpts=d.trainpts;
data[user].exp=d.exp;
data[user].hitpts=d.hitpts;
data[user].totalhit=d.totalhit;
data[user].coins=d.coins;
strcpy(data[user].stype,d.weaponshort);
strcpy(data[user].ltype,d.weaponlong);
strcpy(edata.artype,d.armor);
data[user].weaponshort = d.ws;
data[user].weaponlong = d.wl;
data[user].armor = d.ar;
}
int ac;
for(ac=0;ac<30;ac++)
	{if(data[user].alias[ac]=='\n')
		{data[user].alias[ac]='\0';}

	}
spawnend:
}

void logwrite(char *buf1)
{
FILE *fp;
fp = fopenw("day0.log",10);
fprintf(fp,"~12-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-~15\n\r");
fprintf(fp,"%s\n",buf1);
fclose(fp);
}

void logwr(char *buf1)
{
FILE *fp;
fp = fopenw("day0.log",10);
fprintf(fp,"%s",buf1);
fclose(fp);
}

void readlog(void)
{
char youi;
od_printf("\n\r\n`bright white`T`bright magenta`.  Today\n\r");
swrite("~15Y~13.  Yesterday\n\r~152~13.  Two days ago\n\r~153~13.  Three days ago\n\r~154~13.  Four days ago.\n\r\n\r");
youi = od_get_answer("TY234");
od_printf("`cyan`\n\r");
od_control.od_page_pausing = TRUE;
od_clr_scr();
switch(youi)
{
case 'T':{fkread(fopenr("day0.log",1));
		break;}
case 'Y':{fkread(fopenr("day1.log",1));
		break;}
case '2':{fkread(fopenr("day2.log",1));
		break;}
case '3':{fkread(fopenr("day3.log",1));
		break;}
case '4':{fkread(fopenr("day4.log",1));
		break;}
}
od_printf("\n\r");
getreturng();
od_control.od_page_pausing = FALSE;
}

void qstat(void)
{
od_printf("`bright magenta`\n\r");
od_printf("`bright magenta`Name :  `bright blue`%s\n\r",data[user].alias);
od_printf("`bright magenta`Turns:  `bright blue`%d\n\r",edata.turns);
od_printf("`bright magenta`Coins:  `bright blue`%u\n\r",data[user].coins);
od_printf("`bright magenta`Skill:  `bright blue`%d\n\r",data[user].skill);
od_printf("`bright magenta`Exp:    `bright blue`%u\n\r",data[user].exp);
od_printf("`bright magenta`Short-range weapon:  ");
od_printf("`bright blue`");
od_printf("%s\n\r",data[user].stype);
od_printf("`bright magenta`Long-range weapon:  ");
od_printf("`bright blue`");
od_printf("%s\n\r",data[user].ltype);
od_printf("`bright magenta`Str:  `bright blue`%d\n\r",data[user].strength);
od_printf("`bright magenta`Dex:  `bright blue`%d\n\r",data[user].dex);
od_printf("`bright magenta`Hitpts:  `bright blue`%d`bright white`/`bright blue`%d",data[user].hitpts,data[user].totalhit);
getreturn();
}

void monread(char *file,int arraynum, int num)
{
int handle;
handle = eopen(file,5);
arraynum = num;
lseek(handle,(sizeof(struct monsters)*num),SEEK_SET);
read(handle,&monster,(sizeof(struct monsters)));
close(handle);
num = arraynum;
}

void comr(int nodenum)
{
int handle;
if(nodenum != 0){
	od_control.od_com_method = COM_INTERNAL;
	int nodehandle;
	char filename[12];
	if((nodenum > 999) || (nodenum < 1))
		od_exit(12,FALSE);
	sprintf(filename,"node%d.dat",nodenum);
	nodehandle = opennoder(filename);
	if((read(nodehandle,node,sizeof(struct _nodes)))==-1)
		printf("\a\a\aReading unsuccessful");
	close(nodehandle);
	if(node[0].com != 10)
		{od_control.port=node[0].com;
		if(node[0].IRQ != 10)
			od_control.od_com_irq=node[0].IRQ;
		}
	od_control.od_com_tx_buf=16384;
	strcpy(od_control.info_path,node[0].path);
	od_control.od_node=nodenum;
	od_init();
	}
if((handle=eopen("player.dat",10))==-1){
	od_printf("\n\rMissing data file : player.dat.  Inform Sysop.\n\r");
	getreturn();
	od_exit(0,FALSE);}
read(handle,data,(sizeof(struct player_info)*60));
close(handle);
if((handle=eopen("sett.ing",10))==-1){
	od_printf("\n\rMissing data file : sett.ing.  Inform Sysop.\n\r");
	getreturn();
	od_exit(0, FALSE);}
read(handle,setting,sizeof(struct settings));
close(handle);

}

int opennoder(char *pszFileName)
{
   int fpFile = -1;
   time_t StartTime = time(NULL);


   /* Attempt to open the file while there is still time remaining. */
   while(((fpFile = open(pszFileName,O_RDONLY|O_BINARY)) == -1)
	 && (errno == EACCES)
	 && (difftime(time(NULL), StartTime) < 20))
   {
	 /* If we were unable to open the file, call od_kernal, so that    */
	 /* OpenDoors can continue to respond to sysop function keys, loss */
	 /* of connection, etc.                                            */
   }

   /* Return FILE pointer for opened file, if any. */
   return(fpFile);
}

int eopen(char *pszFileName,int wait)
{
   int fpFile = -1;
   time_t StartTime = time(NULL);


   /* Attempt to open the file while there is still time remaining. */
   while(((fpFile = open(pszFileName,O_RDWR|O_BINARY)) == -1)
	 && (errno == EACCES)
	 && (difftime(time(NULL), StartTime) < wait))
   {
	 /* If we were unable to open the file, call od_kernal, so that    */
	 /* OpenDoors can continue to respond to sysop function keys, loss */
	 /* of connection, etc.                                            */
	 od_kernal();
   }

   /* Return FILE pointer for opened file, if any. */
   return(fpFile);
}

void save(void)
{
od_printf("\n\n\r`bright red`Returning to `bright white`%s\n\r",setting[0].bbsname);
int savehandle;
if((data[user].location != 'F') && (data[user].location != 'I') && (data[user].location != 'T'))
	{data[user].location = 'F';
	}
if(data[user].town == 'M')
	data[user].town = 'E';
data[user].online = -1;
if(user > 49)
	data[user].location = '$';
playsave('E',0,20);
char savefile[12];
sprintf(savefile,"%d.dat",data[user].lognumber);
savehandle=eopen(savefile,4);
write(savehandle,&edata,sizeof(struct info2));
close(savehandle);
}

//to save during someone's play.  after killing someone or moving or after
//logging on.  so that online variable is known
void playsave(char swi,int fighter,int w)
{
FILE *mail;
if(swi != 'E'){
if((mail=fopen("maintain.!!!","r"))!=NULL)
	{od_printf("`red`\n\rOpps!  Gotta run maintanance on another node.\n\rPlay again in a couple minutes.");
	fclose(mail);
	od_exit(0,FALSE);}
}
struct player_info temp;
int play;
char filen[12];
play=eopen("player.dat",w);
temp=data[user];
if(swi == 'C')
	{data[fighter].online = -1;
	struct player_info fightertemp;
	fightertemp=data[fighter];
	read(play,data,(sizeof(struct player_info)*60));
	data[fighter].online = 199;
	data[fighter]=fightertemp;
	}
else read(play,data,(sizeof(struct player_info)*60));
data[user]=temp;
if(swi == 'B')
	{data[fighter].online = 32000;}
lseek(play,0,SEEK_SET);
if(swi == 'D')
	data[fighter].newmessage = TRUE;
write(play,data,(sizeof(struct player_info)*60));
close(play);
sprintf(filen,"mail%d.txt",user);
if((mail=_fsopen(filen,"r",SH_DENYNONE))!=NULL)
	{if(data[user].location != '$')
		od_printf("\n\r`bright red`A guild messenger on horseback stops you:\n\r");
	fkread(mail);
	getreturn();
	remove(filen);}
int setsave;
if((setsave=eopen("sett.ing",2))==-1)
	{od_printf("error - unable to open data file");
	}
if(read(setsave,setting,(sizeof(struct settings)))==-1)
	{printf("error");
	}
close(setsave);
}

int users(char *n)
{
playsave('A',0,10);
int count1; //number of characters in test
int count2; //structure being tested
int ab;     //array number tested on alias and test string
char yno;
yno = 'z';
for(count1=0;count1<30;count1++)
	{
	if(n[count1]=='\0')
		break;
	}
for(count2=0;count2<setting[0].num_users;count2++)
	{
	for(ab=0;ab<count1;ab++)
		{
		if(toupper(data[count2].alias[ab]) == toupper(n[ab]))
			{
			if(ab+1== count1)
				{od_printf("`bright blue`\n\rDo you mean `bright white`%s`bright blue`?  [Y/N]  ",data[count2].alias);
				yno = od_get_answer("YN");
				if(yno == 'N')
					break;
				else{goto send;}
				}
			else continue;
			 }
		else break;
		}
	}
od_printf("`red`\n\r<<Unknown User>>\n\r");
return 32000;

send:
if(count2 == user)
	{od_printf("`red`\n\rStick a sword in ya.\n\r");
	return 32000;}
else if(data[count2].location == 'Z')
	{od_printf("`red`\n\rHe looks kinda pale.  You shouldn't bother him.\n\r");
	return 32000;}
else if(data[count2].hitpts < 10)
	{od_printf("`bright red`\n\rHe is not in good condtion, attack against honor? [Y/n] ");
	if(od_get_answer("YN\n\r")=='N')
		return 32000;
	else{honoradd(-30);
		getreturn();
		}
	}
if(data[count2].online == 32000)
	{od_printf("`red`\n\rThat person is currently very busy.\n\r");
	return 32000;}
else if((data[user].location == data[count2].location) && (data[user].town == data[count2].town))
		edata.pfight--;
else{od_printf("`red`\n\rThat person is not here.\n\r");
	return 32000;}
return count2;
}

int pusers(char *n)
{
playsave('A',0,10);
int count1; //number of characters in test
int count2; //structure being tested
int ab;     //array number tested on alias and test string
char yno;
yno = 'z';
for(count1=0;count1<30;count1++)
	{
	if(n[count1]=='\0')
		break;
	}
for(count2=0;count2<setting[0].num_users;count2++)
	{
	for(ab=0;ab<count1;ab++)
		{
		if(toupper(data[count2].alias[ab]) == toupper(n[ab]))
			{
			if(ab+1== count1)
				{od_printf("`bright blue`\n\rDo you mean `bright white`%s`bright blue`?  [Y/N]  ",data[count2].alias);
				yno = od_get_answer("YN");
				if(yno == 'N')
					break;
				else{goto send;}
				}
			else continue;
			 }
		else break;
		}
	}
od_printf("`red`\n\r<<Unknown User>>\n\r");
return 32000;

send:
if(count2 == user)
	{od_printf("`red`\n\rStick a sword in ya.\n\r");
	return 32000;}
return count2;
}

FILE *fopenr(char *pszFileName,int wait)
{
   FILE *fpFile = NULL;
   time_t StartTime = time(NULL);


   /* Attempt to open the file while there is still time remaining. */
   while(((fpFile = _fsopen(pszFileName,"r",SH_DENYNONE)) == NULL)
	 && (errno == EACCES)
	 && (difftime(time(NULL), StartTime) < wait))
   {
	 /* If we were unable to open the file, call od_kernal, so that    */
	 /* OpenDoors can continue to respond to sysop function keys, loss */
	 /* of connection, etc.                                            */
	 od_kernal();
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
	 od_kernal();
   }

   /* Return FILE pointer for opened file, if any. */
   return(fpFile);
}

void fkread(FILE *file)
{
int screencounter;
screencounter=0;
char a;  //to read in variables
fseek(file,0,SEEK_SET);
do{
a = fgetc(file);
if(a == '~')
	{
	a = fgetc(file);
	switch(a)
	{
	case '~':{od_printf("\n\r");
			break;}
	case '0':{od_printf("`black`");
			break;}
	case '2':{od_printf("`green`");
			break;}
	case '3':{od_printf("`cyan`");
			break;}
	case '4':{od_printf("`red`");
			break;}
	case '5':{od_printf("`magenta`");
			break;}
	case '6':{od_printf("`yellow`");
			break;}
	case '7':{od_printf("`white`");
			break;}
	case '8':{od_printf("`gray`");
			break;}
	case '9':{od_printf("`bright blue`");
			break;}
	case '1':{a = fgetc(file);
			switch(a)
			{
			case '1':{od_printf("`bright cyan`");
					break;}
			case '0':{od_printf("`bright green`");
					break;}
			case '2':{od_printf("`bright red`");
					break;}
			case '3':{od_printf("`bright magenta`");
					break;}
			case '4':{od_printf("`bright yellow`");
					break;}
			case '5':{od_printf("`bright white`");
					break;}
			default:{od_printf("`blue`");
					od_putch(a);
					break;}
			}
			break;
			}
	}
	}
else{if(a == '\n')
		{od_printf("\n\r");
		screencounter++;
		if(screencounter == 22)
			{screencounter=0;
			if(more() == 'N')
				a = EOF;
			od_printf("\n\r");
			}
		}
	else	if(a > 31) od_putch(a);}
}while(a != EOF);
fclose(file);
}

char more(void)
{
char moree;
od_printf("(Y/n) MORE? ");
moree = od_get_answer("YN\n\r ");
return moree;
}

void bank(void)
{
char combank;
do{
combank=od_hotkey_menu("bank","DWCL?H",TRUE);
switch(combank)
{
case 'D':{dep();
		break;}
case 'W':{with();
		break;}
case 'C':{check();
		break;}
case 'L':{break;}
}
}while(combank != 'L');
}

void check(void)
{
od_printf("`bright yellow`\n\rMoney in hand:  `bright white`%u\n\r",data[user].coins);
od_printf("`bright yellow`Money in hole:  `bright white`%u\n\r",data[user].bankcoins);
getreturn();
}

void dep(void)
{
char numstr[5];
unsigned int num;
unsigned int total;
total = 60000 - data[user].bankcoins;
if(total > data[user].coins)
	total=data[user].coins;
od_printf("`bright yellow`\n\rHow much would you like to deposit? 1 for all (0-%u) ",total);
od_input_str(numstr,5,45,58);
num = atoi(numstr);
if(num > total)
	od_printf("\n\r`red`You don't have that many.");
else if(num==1)
	{data[user].bankcoins += total;
	od_printf("\n\r`bright red`%u deposited in Treasure Hole.",total);
	data[user].coins -= total;
	}
else if(num > 0)
	{od_printf("\n\r`bright red`%u deposited in Treasure Hole.",num);
	data[user].coins -= num;
	data[user].bankcoins += num;
	}
else od_printf("\n\r`red`Invalid number.\n\r");
getreturn();
}

void with(void)
{
char numstr[5];
unsigned int num;
unsigned int total;
total = 60000 - data[user].coins;
if(total > data[user].bankcoins)
	total=data[user].bankcoins;
od_printf("`bright yellow`\n\rHow much would you like to withdrawel? 1 for all (0-%u) ",total);
od_input_str(numstr,5,45,58);
num = atoi(numstr);
if(num > total)
	od_printf("\n\r`red`There isn't that many in the hole.");
else if(num==1)
	{data[user].coins += total;
	od_printf("\n\r`bright red`%u taken from the Treasure Hole.",total);
	data[user].bankcoins -= total;
	}
else if(num > 0)
	{od_printf("\n\r`bright red`%u taken from the Treasure Hole.",num);
	data[user].bankcoins -= num;
	data[user].coins += num;
	}
else od_printf("\n\r`red`Invalid number.\n\r");
getreturn();
}

void tavlog(void)
{
od_clr_scr();
char coo;
FILE *con;
char filename[12];
switch(data[user].town)
{
case 'H':{strcpy(filename,"hayward.con");
		break;}
case 'D':{strcpy(filename,"den.con");
		break;}
case 'P':{strcpy(filename,"pomdir.con");
		break;}
case 'E':{strcpy(filename,"easttrim.con");
		break;}
case 'S':{strcpy(filename,"sussenex.con");
		break;}
case 'B':{strcpy(filename,"burkshir.con");
		break;}
case 'T':{strcpy(filename,"tiw.con");
		break;}
case '*':{strcpy(filename,"hideout.con");
		break;}
}
if((con=fopenr(filename,5))==NULL)
	{con=fopenw(filename,1);
	fprintf(con,"~15Bartender~12:\n\r");
	fprintf(con,"~9How's it going there, pal.  Look a little sluggish.  Tough day?\n");
	fclose(con);
	con=fopenr(filename,5);
	}
fkread(con);
od_printf("\n\r`bright magenta`Add to the conversation? [Y/n] ");
coo=od_get_answer("Y\n\rN");
if(coo!='N')
	{od_printf("`bright white`");
	char op[79];
	od_printf("`bright blue`\n\rVoice your 1-line opinion:\n\r");
	od_input_str(op,79,32,126);
	if(stricmp(op,"")!=0)
		{con=fopenw(filename,10);
		fprintf(con,"~15%s~12:\n\r",data[user].alias);
		fprintf(con,"~9%s\n\r",op);
		fclose(con);
		if(edata.conv == FALSE)
			{exper(2);
			skill();
			edata.conv = TRUE;}
		}
	}
}

void honoradd(int honor)
{
int chan;	//amount of change
if(honor<0)
	{chan=(honor+(honor*-2));
	od_printf("`red`** `bright blue`Your honor goes down `bright red`%d `bright blue`points for this deed.",chan);
	}
else{chan=honor;
	od_printf("`bright white`** `bright blue`Your honor goes up `bright red`%d `bright blue`points for this deed.",chan);
	}
data[user].honor+=honor;
if(data[user].honor > 30000)
	data[user].honor=30000;
if(data[user].honor < -30000)
	data[user].honor=-30000;
}

void specialadd(int special)
{
edata.spec+=special;
if(edata.spec>40)
	edata.spec=40;
if(edata.spectotal==40)
	{
	od_printf("`bright red`\n\rYou have already reached your magical limit.\n\r");
	}
else{
edata.spectotal+=special;
if(edata.spectotal>40)
	{
	edata.spectotal = 40;
	od_printf("`bright red`\n\rYou have reached the limit of your magical ability.\n\r");
	}
else{if(special==1)	od_printf("\n\r`bright white`Magic ability raised `bright red`%d `bright white`point!\n\r",special);
	else od_printf("\n\r`bright white`Magic ability raised `bright red`%d `bright white`points!\n\r",special);
	}
}
}

char monattack(void)
{
//testing cuts

edata.spec=100;
edata.spe[0]=1;
edata.spe[1]=8;
edata.spe[2]=2;
edata.spe[3]=6;
edata.spe[4]=7;
edata.spe[5]=9;
edata.spe[6]=3;
edata.spe[7]=11;
edata.spe[8]=12;
edata.spe[9]=13;

FILE *sfp;
int am;
char z;
od_clr_scr();
char pw[15];
strcpy(pw,data[user].stype);
char cleanup=FALSE;
int spec;
int enemyhit;
int enemytotalhit;
enemyhit = monster.hit;
enemytotalhit = monster.hit;
int jj, ll, mm, nn, o;
int first;
char co;
first = random(2);
jj = random(monster.surprise);
if(jj != 0)
	{nn = random(monster.surprise);
if(nn == 0)
	{od_printf("`bright blue`\n\rYou surprise an animal:  %s.",monster.name);
	first = 1;
	o = 1;
	goto longagain;}}
if(jj != 0) od_printf("`bright magenta`\n\r%s",monster.site);
if(jj == 0)
	{
	first = 0;
	o = 1;
	goto longagain;}
od_printf("\n\r`bright white`Long-range combat`bright red`:");
longagain:
switch(first)
{
case 0:{if(monster.LP != 0){ll = random(13);
		mm = monster.aim/2;
		if(ll <= mm)
			{od_printf("`red`\n\r%s\n\r",monster.longhit);
			data[user].hitpts -= (monster.LP - data[user].armor);
			if(data[user].armor == 0)
				{od_printf("`bright cyan`\n\rSince you are wearing no armour, it takes your life.\n\r");
				data[user].hitpts = 0;
				getreturng();}
			life();}
		else{od_printf("`red`\n\r%s\n\r", monster.longmiss);}}
		else od_printf("`bright red`\n\rYour enemy has no long-range weapon.");
		if(o != 1)
			{o = 1;
			first = 1;
			goto longagain;}

	break;
	}
case 1:{if((data[user].weaponlong != 0) && (data[user].ammo != 0))
	{
	ll = random(13);
	mm = (monster.aim/2);
	if(ll > mm)
		{data[user].ammo--;
		od_printf("`bright cyan`\n\rYou aim is just a bit off and you miss.\n\r");
		}
	else{data[user].ammo -= 1;
		od_printf("`bright cyan`\n\rDead hit!  Right in the gut!\n\r");
		if(monster.AP == 0)
		{od_printf("`bright blue`\n\rWithout armour, %s drops dead.",monster.name);
		enemyhit = 0;
		getreturng();
		goto mondead;}
		enemyhit -= (data[user].weaponlong - monster.AP);
		if(enemyhit<1){
			goto mondead;}
	}
	}
	else od_printf("`bright cyan`\n\rYou either don't have a weapon or any ammo.");
	if(o != 1)
		{o = 1;
		first = 0;
		goto longagain;}
	break;
	}
}
if(jj == 0)
	od_printf("`bright magenta`\n\r%s\n\r",monster.surpris);
getreturng();
int php, ehp, pch, ech, chance, chance2, lspe, s, hg, mn;
char ph, eh;
do{
od_clr_scr();
if(edata.qf == FALSE)
{
od_set_cursor(14,1);
od_printf("`bright blue`컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\r");
od_printf("`bright cyan`      (`bright red`A`bright cyan`)ttack        (D)efend        (R)un        (S)tats        redra(W)\n\r");
od_printf("`bright blue`컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컫컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\r");
od_printf("`bright magenta`YOU:`bright blue`                                   �\n\r");
od_printf("         <`bright cyan`M`bright blue`>`bright white`agic attack`bright blue`                �\n\r");
od_printf("`bright cyan`Strength:   `bright blue`                           � `red`Strength:\n\r");
od_printf("`bright cyan`Dexterity:   `bright blue`                          � `red`Dexterity:\n\r");
od_printf("`bright cyan`Hit Points:  `bright blue`                          � `red`Hit Points:\n\r");
od_printf("`bright cyan`Weapon:  `bright blue`                              � `red`Noted Weapon:");
}
do{
if(edata.qf==FALSE) od_set_cursor(12,1);
disfight(monster.str,monster.dex,enemyhit,enemytotalhit, monster.weapon, monster.name);
od_clear_keybuffer();
co = od_get_answer("ADRSWM\n\r");
if(cleanup==TRUE&&edata.qf==FALSE)
	{od_set_cursor(1,1);
	od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
	}

od_printf("\n\r");
if((co == 'A') || (co == 'D') || (co == 10) || (co == 13))
	{
	php = ((data[user].strength - (monster.str/2)) + (data[user].weaponshort - monster.AP) + random(4));
	ehp = ((monster.str - (data[user].strength/2)) + (monster.WP - data[user].armor) + random(4));
	pch = (data[user].dex - monster.dex);
	ech = (monster.dex - data[user].dex);
	if(php < 1)
		php = (random(3) + 1);
	if(ehp < 1)
		ehp = (random(3) + 1);
	}
first = 5;
s = 0;
switch(co)
{
case 'M':{if(edata.qf==FALSE)
			{od_set_cursor(7,1);
			od_clr_line();
			od_set_cursor(11,1);
			od_clr_line();
			od_set_cursor(12,1);
			od_clr_line();
			od_set_cursor(1,1);}
		else od_printf("\n\r");
		swrite("~9(~110~9)  ~15"); printspec(0);
		swrite("\n\r~9(~111~9)  ~15"); printspec(1);
		swrite("\n\r~9(~112~9)  ~15"); printspec(2);
		swrite("\n\r~9(~113~9)  ~15"); printspec(3);
		swrite("\n\r~9(~114~9)  ~15"); printspec(4);
		swrite("\n\r~9(~115~9)  ~15"); printspec(5);
		swrite("\n\r~9(~116~9)  ~15"); printspec(6);
		swrite("\n\r~9(~117~9)  ~15"); printspec(7);
		swrite("\n\r~9(~118~9)  ~15"); printspec(8);
		swrite("\n\r~9(~119~9)  ~15"); printspec(9);
		swrite("\n\r~9(~11F~9)  ~12Forget that!\n\r");
		switch(od_get_answer("0987654321F"))
		{
		case '0':{spec=0;
				break;}
		case '1':{spec=1;
				break;}
		case '2':spec=2;break;
		case '3':spec=3;break;
		case '4':spec=4;break;
		case '5':spec=5;break;
		case '6':spec=6;break;
		case '7':spec=7;break;
		case '8':spec=8;break;
		case '9':spec=9;break;
		case 'F':spec=10;break;
		}
		if(spec==10)
			{cleanup=TRUE;
			break;}
		if(edata.qf == FALSE)
			{od_set_cursor(1,1);
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_clr_line();
			od_printf("\n\r");
			od_set_cursor(1,1);}
		else od_printf("\n\r");
		if(edata.spe[spec]==0)
			break;
		if(speccheck(edata.spe[spec])==FALSE)
		{od_printf("`red`You have no magic in you right now.\r");
		if(edata.qf==FALSE)
			cleanup=TRUE;
		else od_printf("\n");
			break;
		}
		if(edata.spe[spec]==10)
		{
		if(enemytotalhit>189)
					{od_printf("`bright red`On this monster?  Are you kidding?");
					cleanup=TRUE;
					break;}
			    else if(edata.spec < 20)
					{od_printf("`red`Not enough magic.\n\r");
					cleanup=TRUE;
					break;}
			    od_printf("`bright blue`Packing nearly all the magic energy you have, you send a beam of it\n\r");
			    od_printf("hurreling into the chest of %s.",monster.name);
			    od_printf("`bright cyan`\n\rBody parts, skin, brain, bones, and intestines fly in all directions. You\n\r");
			    od_printf("notice the large intestine hanging from your belt.\n\r");
			    edata.spec-=20;
			    getreturn();
			    goto mondead;
		}
		sfp = returnfile(spec);
		do{
		z = fgetc(sfp);
		if(z == '~')
			{
			z=fgetc(sfp);
			if(z == '|')
				break;
			}
		}while(z!=EOF);
		do{
		z = fgetc(sfp);
		if(z == '~')
			{
			z = fgetc(sfp);
			switch(z)
			{
			case '"':{od_printf("him");
				break;}
			case '~':{od_printf("\n\r");
				break;}
			case '0':{od_printf("`black`");
				break;}
			case '2':{od_printf("`green`");
				break;}
			case '3':{od_printf("`cyan`");
				break;}
			case '4':{od_printf("`red`");
				break;}
			case '5':{od_printf("`magenta`");
				break;}
			case '6':{od_printf("`yellow`");
				break;}
			case '7':{od_printf("`white`");
				break;}
			case '8':{od_printf("`gray`");
				break;}
			case '9':{od_printf("`bright blue`");
				break;}
			case '1':{z = fgetc(sfp);
				switch(z)
				{
				case '1':{od_printf("`bright cyan`");
						break;}
				case '0':{od_printf("`bright green`");
						break;}
				case '2':{od_printf("`bright red`");
						break;}
				case '3':{od_printf("`bright magenta`");
						break;}
				case '4':{od_printf("`bright yellow`");
						break;}
				case '5':{od_printf("`bright white`");
						break;}
				default:{od_printf("`blue`");
						od_putch(z);
						break;}
				}
				break;
				}

			case '=':od_printf("%s",monster.name);
					break;
			case '&':sleep(1);
					break;
			case 'E':z = fgetc(sfp);
					switch(z)
					{
					case 'S':fscanf(sfp,"%d",&am);
							monster.str+=am;
							break;
					case 'D':fscanf(sfp,"%d",&am);
							monster.dex+=am;
							break;
					case 'H':fscanf(sfp,"%d",&am);
							enemyhit+=am;
							break;
					}
					break;
			case 'P':z = fgetc(sfp);
					switch(z)
					{
					case 'H':fscanf(sfp,"%d",&am);
							data[user].hitpts+=am;
							break;
					}
					break;
			case 'F':fscanf(sfp,"%d",&am);
						if(enemytotalhit <= am)
							enemyhit = 0;
					break;
			case '|':goto life;
			}
			}
		else if(z!=13&&z!=10)
			od_putch(z);
		}while(z != EOF);
		life:
		do{
		z = fgetc(sfp);
		}while(z!='~'&&z!=EOF);
			if(z=='|'||z==EOF)
				goto finished;
			z = fgetc(sfp);
			if(z == 'D'&&enemyhit>0)
				{
				do{//advance to life message
				z = fgetc(sfp);
				if(z == '~')
					{z = fgetc(sfp);
					if(z == 'L')
					 break;
					}
				}while(z!=EOF);
				}
			do{
			z = fgetc(sfp);
			if(z == '~')
				{z = fgetc(sfp);
						switch(z)
						{
						case '=':od_printf("%s",monster.name);
								break;
						case '~':{od_printf("\n\r");
							break;}
						case '0':{od_printf("`black`");
							break;}
						case '2':{od_printf("`green`");
							break;}
						case '3':{od_printf("`cyan`");
							break;}
						case '4':{od_printf("`red`");
							break;}
						case '5':{od_printf("`magenta`");
							break;}
						case '6':{od_printf("`yellow`");
							break;}
						case '7':{od_printf("`white`");
							break;}
						case '8':{od_printf("`gray`");
							break;}
						case '9':{od_printf("`bright blue`");
							break;}
						case '"':{od_printf("him");
							break;}
						case '1':{z = fgetc(sfp);
							switch(z)
							{
							case '1':{od_printf("`bright cyan`");
									break;}
							case '0':{od_printf("`bright green`");
									break;}
							case '2':{od_printf("`bright red`");
									break;}
							case '3':{od_printf("`bright magenta`");
									break;}
							case '4':{od_printf("`bright yellow`");
									break;}
							case '5':{od_printf("`bright white`");
									break;}
							default:{od_printf("`blue`");
									od_putch(z);
									break;}
							}
							break;
							}
						case '|':
						case 'L':
						case 'D':goto finished;
						}
				}
			else if(z!=13&&z!=10)
					od_putch(z);
			  }while(z!=EOF);

		finished:
		fclose(sfp);
		if(enemyhit<1)
			{
			getreturn();
			goto mondead;
			}
		if(data[user].hitpts>data[user].totalhit)
			data[user].hitpts=data[user].totalhit;
		cleanup=TRUE;
	break;
	}
case 10:
case 13:
case 'A':{
	  if(edata.qf == FALSE){
	  od_set_cursor(7,1);
	  od_clr_line();
	  od_set_cursor(12,1);
	  od_clr_line();
	  od_set_cursor(11,1);
	  od_clr_line();
	    }
	  if(pch > 8)
		ph = TRUE;
	  else if((pch > 5) && (pch < 9))
		{chance = random(9);
		if(chance<8)
			ph = TRUE;
		else ph = FALSE;
		}
	  else if((pch>3) && (pch<6))
		{chance = random(8);
		if(chance<7)
			ph = TRUE;
		else ph = FALSE;
		}
	  else if((pch>0) && (pch<4))
		{chance = random(6);
		if(chance<5)
			ph = TRUE;
		else ph = FALSE;
		}
	  else if((pch>-2) && (pch<1))
		{chance = random(5);
		if(chance<4)
			ph = TRUE;
		else ph = FALSE;
		}
	  else if((pch>-4) && (pch<-1))
		{chance = random(4);
		if(chance<3)
			ph = TRUE;
		else ph = FALSE;
		}
	  else if((pch>-9) && (pch<-3))
		{chance = random(3);
		if(chance < 2)
			ph = TRUE;
		else ph = FALSE;
		}
	  else if(pch<-8)
		{chance = random(3);
		if(chance<1)
			ph = TRUE;
		else ph = FALSE;
		}
	  if(ech > 8)
		eh = TRUE;
	  else if((ech > 5) && (ech < 9))
		{chance = random(9);
		if(chance<8)
			eh = TRUE;
		else eh = FALSE;
		}
	  else if((ech>3) && (ech<6))
		{chance = random(8);
		if(chance<7)
			eh = TRUE;
		else eh = FALSE;
		}
	  else if((ech>0) && (ech<4))
		{chance = random(6);
		if(chance<5)
			eh = TRUE;
		else eh = FALSE;
		}
	  else if((ech>-2) && (ech<1))
		{chance = random(5);
		if(chance<4)
			eh = TRUE;
		else eh = FALSE;
		}
	  else if((ech>-4) && (ech<-1))
		{chance = random(4);
		if(chance<3)
			eh = TRUE;
		else eh = FALSE;
		}
	  else if((ech>-9) && (ech<-3))
		{chance = random(3);
		if(chance < 2)
			eh = TRUE;
		else eh = FALSE;
		}
	  else if(ech<-8)
		{chance = random(3);
		if(chance<1)
			eh = TRUE;
		else eh = FALSE;
		}
	  if(monster.special1>0)
		{chance2 = random(5);
		if(lspe == 0){
		if(chance2 == 0)
			{
			if(edata.qf == FALSE){
			od_set_cursor(7,1);
			od_clr_line();}
			od_printf("`bright cyan`%s\n\r",monster.spe1);
			if(edata.qf == FALSE)
				delay(200);
			lspe = 5;
			data[user].hitpts -= monster.special1;
			s = 1;
			first = 0;
			if(life() == TRUE)
				co = 'W';
			goto pattack;
			}
		}
		else lspe = 0;
		}
	  else if(monster.special2>0)
		{chance2 = random(5);
		if(lspe == 0){
		if(chance2 == 0)
			{if(edata.qf == FALSE){
			od_set_cursor(7,1);
			od_clr_line();}
			od_printf("`bright cyan`%s\n\r",monster.spe2);
			if(edata.qf == FALSE)
				delay(200);
			lspe = 5;
			data[user].hitpts -= monster.special2;
			if(life() == TRUE)
				co = 'W';
			s = 1;
			first = 0;
			goto pattack;
			}
		}
		else lspe = 0;
		s = 0;
		}
	if(first != 0)
		first = random(2);
	pattack:
	switch(first)
	{
	case 0:{if(ph == TRUE)
			{
			hg = random(3);
			if(edata.qf == FALSE){
			od_set_cursor(12,1);
			od_clr_line();}
			switch(hg)
			{
			case 0:{od_printf("`bright red`With a strong slash, you bury your %s in your opponent's gut.\n\r",pw);
				break;}
			case 1:{od_printf("`bright red`You thrust your weapon into your opponent's side.\n\r");
				break;}
			case 2:{od_printf("`bright red`You sweep the enemy down and bring the butt of your %s to his face.\n\r",pw);
				break;}
			}
			if(edata.qf == FALSE)
				delay(200);
			enemyhit -= php;
			if(enemyhit<1)
				goto mondead;
			if((edata.compatt>0) && (random(8)>3))
				{
				if(edata.qf==FALSE)
					od_set_cursor(11,1);
				od_printf("`bright cyan`%s.\n\r",edata.compa);
				enemyhit-=edata.compatt;
				}
			if(enemyhit<1)
				goto mondead;
			}
		else if(ph == FALSE)
			{
			hg = random(3);
			if(edata.qf == FALSE){
			od_set_cursor(12,1);
			od_clr_line();}
			switch(hg)
			{
			case 0:{od_printf("`yellow`Your opponent easily dodges your attack.\n\r");
				break;}
			case 1:{od_printf("`yellow`Your thrust is blocked.\n\r");
				break;}
			case 2:{if(s == 1)
					od_printf("`yellow`Your opponents last attack left you dazed.\n\r");
				else od_printf("`yellow`You accidently leave your chest open and you are shoved back.\n\r");
				break;}
			}
			if(edata.qf == FALSE)
				delay(200);
			}
		if(s != 1)
			{s = 1;
			first = 1;
			goto pattack;}
		break;
		}
	case 1:{if(enemyhit <= monster.run)
			{mn = random(3);
			if(mn == 0)
				{
				if(edata.qf == FALSE){
				od_set_cursor(7,1);
				od_clr_line();}
				od_printf("`red`Your enemy gets fearful and takes off into the shadows.");
				data[user].exp += 10;
				exp();
				goto end;
				}
			else{if(edata.qf == FALSE){
				od_set_cursor(7,1);
				od_clr_line();}
				od_printf("`red`He tries to run but you throw him to the ground.\n\r");
				enemyhit -= 1;
				if(enemyhit<1)
				goto mondead;
				if(s != 1)
				{s = 1;
				goto pattack;}
				else break;
				}
			}
		if(eh == TRUE)
			{
			hg = random(3);
			if(edata.qf == FALSE){
			od_set_cursor(7,1);
			od_clr_line();}
			switch(hg)
			{
			case 0:{od_printf("`bright red`%s\n\r",monster.hit1);
				break;}
			case 1:{od_printf("`bright red`%s\n\r",monster.hit2);
				break;}
			case 2:{od_printf("`bright red`%s\n\r",monster.hit3);
				break;}
			}
			data[user].hitpts -= ehp;
			if(edata.qf == FALSE)
				delay(200);
			if(life() == TRUE)
				co = 'W';
			}
		else if(eh == FALSE)
			{
			hg = random(3);
			if(edata.qf == FALSE){
			od_set_cursor(7,1);
			od_clr_line();}
			switch(hg)
			{
			case 0:{od_printf("`yellow`%s\n\r",monster.miss1);
				break;}
			case 1:{od_printf("`yellow`%s\n\r",monster.miss2);
				break;}
			case 2:{od_printf("`yellow`%s\n\r",monster.miss3);
				break;}
			}
			if(edata.qf == FALSE)
				delay(200);
			}
		if(s != 1){
			s = 1;
			first = 0;
			goto pattack;}
		break;
		}
	}
	break;
	}
case 'D':{
	  if(edata.qf==FALSE){
	  od_set_cursor(7,1);
	  od_clr_line();
	  od_set_cursor(12,1);
	  od_clr_line();
	  od_set_cursor(11,1);
	  od_clr_line();}
	  if(monster.special1>0)
		{chance2 = random(5);
		if(lspe == 0){
		if(chance2 == 0)
			{if(edata.qf == FALSE){
			od_set_cursor(7,1);
			od_clr_line();}
			od_printf("`bright cyan`%s\n\r",monster.spe1);
			lspe = 5;
			ehp = monster.special1;
			goto skip;
			}
		}
		else lspe = 0;
		}
	  if(monster.special2>0)
		{chance2 = random(5);
		if(lspe == 0){
		if(chance2 == 0)
			{if(edata.qf == FALSE){
			od_set_cursor(7,1);
			od_clr_line();}
			od_printf("`bright cyan`%s\n\r",monster.spe2);
			lspe = 5;
			ehp = monster.special2;
			goto skip;
			}
		}
		else lspe = 0;
		}
	  if(edata.qf == FALSE){
	  od_set_cursor(7,1);
	  hg = random(3);}
	  switch(hg)
	  {
	  case 0:{od_printf("`bright red`%s\n\r",monster.hit1);
			break;}
	  case 1:{od_printf("`bright red`%s\n\r",monster.hit2);
			break;}
	  case 2:{od_printf("`bright red`%s\n\r",monster.hit3);
			break;}
	  }
	  skip:
	  if(data[user].shield>=ehp)
		{if(edata.qf == FALSE){
		od_set_cursor(12,1);
		od_clr_line();}
		od_printf("`bright red`You successfully block the attack.\n\r");
		}
	  else{if(edata.qf==FALSE){
		od_set_cursor(12,1);
		od_clr_line();}
		od_printf("`bright magenta`The attack seems to go right through your shield.\n\r");
		data[user].hitpts -= ehp;
		if(life() == TRUE)
			co = 'W';
		}
	  break;
	  }
case 'R':{hg = random(7);
	  if((hg >= 0) && (hg < 7))
		{if(edata.qf==FALSE){
		od_set_cursor(1,1);
		od_clr_line();}
		od_printf("`bright blue`You turn around and run like hell.\n\r");
		goto end;}
	  else{if(edata.qf==FALSE){
		od_set_cursor(1,1);
		od_clr_line();}
		od_printf("`red`As you turn around, you are slammed to the ground.\n\r");
		data[user].hitpts -= 2;
		if(life() == TRUE)
			co = 'W';
		}
	  break;
	  }
case 'S':{stats();
	  break;}
case 'W':{break;}
}
}while((co != 'W') && (co != 'S'));
}while(1);

mondead:
od_clr_scr();
od_printf("`bright cyan`\n\rYou stand over your victom's body, triumphant.\n\r");
data[user].kills++;
if(data[user].kills > 60000)
	data[user].kills=60000;
if(monster.coins == 0)
	od_printf("`bright red`You find no coins.\n\r");
else {monster.coins += random(3);
	od_printf("`bright red`You are able to scavenge %d coins.\n\r",monster.coins);
	data[user].coins += monster.coins;}
coins();
if(monster.skins == 0)
	od_printf("`bright magenta`You can't get a decent skin from the monster.\n\r");
else if(monster.skins == 1)
	{od_printf("`bright magenta`You cut off a fine skin from the animal.\n\r");
	edata.i1 += 1;
	if(edata.i1 == 11)
		{od_printf("`red`You can't seem to carry this skin!");
		edata.i1 = 10;}
	}
else {od_printf("`bright magenta`You take as many dragon scales as you can from the %s.\n\r",monster.name);
	 edata.i5 += 1;
	 if(edata.i5 == 3)
	{od_printf("`red`You can't seem to carry all these scales.\n\r");
	edata.i5 = 2;}
	 }
int uu;
uu = (monster.str + monster.dex + monster.WP + monster.AP + monster.LP);
if((data[user].skill>9)&&((data[user].town=='H')||(data[user].town=='P')||(data[user].town=='D')))
	{
	od_printf("`bright red`\n\rMaybe you should try another town.\n\r");
	uu=uu/2;
	}
else if(data[user].town=='B'||data[user].town=='S')
	{
	uu=uu*2;
	}
exper(uu);
skill();
honoradd(1);
if(data[user].honor>30000)
	data[user].honor=30000;
od_printf("`bright cyan`\n\rWay to go!\n\r");
return TRUE;
end:
getreturng();
od_clr_scr();
return FALSE;
}

char mountainevent(void)
{
void cave(void);
void temple(void);
if(edata.spectotal<10&&random(100)==54)
	{
	od_clr_scr();
	od_printf("`bright red`The cold seems to have toughened you up a little.\n\r");
	specialadd(1);
	getreturn();
	return TRUE;
	}
else if(edata.spectotal>10&&edata.spectotal<15&&random(100)==51)
	{
	od_clr_scr();
	od_printf("`bright white`The high altitude has helped you out some.\n\r");
	specialadd(1);
	getreturn();
	return TRUE;
	}
else if(data[user].town=='E'&&checkspec(10)==FALSE&&data[user].skill>13&&random(5)==0)
	{
	od_clr_scr();
	if(od_hotkey_menu("soranth","yn",TRUE)=='y')
		cave();
	else{edata.mountains++;
		}
	return TRUE;
	}
else if(data[user].town=='S'&&stricmp(edata.compname,"tiashi")==0&&random(2)==0&&stricmp(edata.artype,"Serpent")!=0)
	{
	od_clr_scr();
	swrite("~9You have come upon the ruins of an ancient temple resting on the side of the\n\r");
	swrite("side of a mountain.\n\r");
	swrite("~13\"This is the serpent temple where the ancient serpent monks once praised\n\r");
	swrite("their snake gods.  It is said they left magnificent treasures behind.  We had\n\r");
	swrite("better prepare well before heading in,\" says Tiashi.\n\r");
	swrite("~9Do you enter?     ~15Y~7es or ~15N~7o  \n\r");
	if(od_get_answer("YN")=='Y')
		temple();
	return TRUE;
	}
else return FALSE;
}

void temple(void)
{
char ui;
swrite("\n\r~13\"By the way, supposedly there was something left behind to guard the\n\r");
swrite("treasures.  We should be cautious.\"\n\r");
do{
swrite("~15This temple is truly fascinating, and holds legends and secrets.\n\r");
swrite("     ~15E~7xplore    ~15L~7eave  ");
ui = od_get_answer("EL");
if(ui=='E')
	{monread("stryline.dat",0,10);
	if(monattack()==TRUE)
		{
		od_printf("\n\r`bright white`You have found `bright red`Serpent`bright white` Armour!\n\r");
		od_printf("`bright blue`This armour was getting old anyway.\n\r");
		strcpy(edata.artype,"Serpent");
		data[user].armor = 7;
		od_printf("`bright magenta`\"I think we should leave now,\" `bright cyan`says Tiashi.\n\r");
		}
	}
}while(ui!='L');
}

void cave(void)
{
void mageroom(void);
char caveloc = 0;
void deadend(void);
do{
od_clr_scr();
switch(caveloc)
{
//cave entrance
case 0:swrite("~15You are at the cave entrance...\n\r");
		swrite("   L~7eft    ~15S~7traight   ~15r~7ight   ~15B~7ack\n\r");
		switch(od_get_answer("RLSB"))
		{
		case 'R':deadend();//dead end
				break;
		case 'L':caveloc=1;//direct path
				break;
		case 'S':caveloc=2;//alternate path
				break;
		case 'B':caveloc=-1;
				break;
		}
	  break;
//direct path
case 1:{swrite("~15You are in a dank, dark room in the cave...\n\r");
	  swrite("   L~7eft   ~15R~7ight   ~15B~7ack\n\r");
	  switch(od_get_answer("rlb"))
	  {
	  case 'r':deadend();
			break;
	  case 'l':caveloc=3;	//direct path
			break;
	  case 'b':caveloc=0;
			break;
	  }
	  break;
	  }
case 2:{swrite("~15You are in a dry, small cave room...\n\r");
	  swrite("   ~15S~7traight   ~15R~7ight   ~15B~7ack");
	  switch(od_get_answer("rsb"))
	  {
	  case 'r':caveloc=4;
			break;
	  case 's':caveloc=5;
			break;
	  case 'b':caveloc=0;
			break;
	  }
	  break;
	  }
case 3:{swrite("~15You are in a dank, dark room in the cave...\n\r");
	  swrite("   L~7eft    ~15S~7traight   ~15R~7ight   ~15B~7ack");
	  switch(od_get_answer("rlsb"))
	  {
	  case 'r':caveloc=7;
			break;
	  case 'l':caveloc=6;break;
	  case 's':deadend();break;
	  case 'b':caveloc=1;break;
	  }
	  break;
	  }
case 4:{swrite("~15You are in a lifeless, void, dark room...\n\r");
	  swrite("   S~7traight   ~15R~7ight   ~15B~7ack");
	  switch(od_get_answer("rsb"))
	  {
	  case 'r':caveloc=8;break;
	  case 's':deadend();break;
	  case 'b':caveloc=2;break;
	  }
	  break;
	  }
case 5:{swrite("~15You are in a dry, lifeless room...\n\r");
	   swrite("   L~7eft   ~15R~7ight   ~15B~7ack");
	   switch(od_get_answer("rlb"))
	   {
	   case 'r':caveloc=10;break;
	   case 'l':caveloc=9;break;
	   case 'b':caveloc=2;break;
	   }
	   break;
	   }
case 6:{swrite("~15You are in a lifeless void and can see hardly anything...\n\r");
	   swrite("   l~7eft    ~15R~7ight   ~15B~7ack");
	   switch(od_get_answer("rlb"))
	   {
	   case 'r':caveloc=12;break;
	   case 'l':caveloc=11;break;
	   case 'b':caveloc=3;break;
	   }
	   break;
	   }
case 7:{swrite("~15You are in a dank, dark room in the cave...\n\r");
	   swrite("   ~15L~7eft   ~15R~7ight   ~15B~8ack");
	   switch(od_get_answer("rlb"))
	   {
	   case 'r':caveloc=14;break;
	   case 'l':caveloc=15;break;
	   case 'b':caveloc=3;break;
	   }
	   break;
	   }
case 8:{swrite("~15You are in a tight tunnel humid and muddy...\n\r");
		swrite("   S~7traight   ~15B~7ack");
		switch(od_get_answer("sb"))
		{
		case 's':deadend();break;
		case 'b':caveloc=4;break;
		}
		break;
		}
case 9:{swrite("~15You are at a three-way junction in small tunnels...\n\r");
		swrite("   L~7eft   ~15S~7traight   ~15R~7ight   ~15B~7ack");
		switch(od_get_answer("lsrb"))
		{
		case 's':caveloc=13;break;
		case 'l':deadend();break;
		case 'r':deadend();break;
		case 'b':caveloc=5;break;
		}
		break;
		}
case 10:{swrite("~15You are in a deep, dark room in the cave... lost...\n\r");
		swrite("   L~7eft   ~15R~7ight   ~15B~7ack");
		switch(od_get_answer("lrb"))
		{
		case 'r':deadend();break;
		case 'l':deadend();break;
		case 'b':caveloc=5;break;
		}
		break;
		}
case 11:{swrite("~15You are lost in a deep, dark cave...\n\r");
		swrite("   S~7traight   ~15B~7ack");
		switch(od_get_answer("sb"))
		{
		case 's':deadend();break;
		case 'b':caveloc=6;break;
		}
		break;
		}
case 12:{swrite("~15You are at a three-way fork...getting somewhere now...\n\r");
		swrite("   L~7eft    ~15S~7traight   ~15R~7ight   ~15B~7ack");
		switch(od_get_answer("rslb"))
		{
		case 'r':deadend();break;
		case 's':deadend();break;
		case 'l':deadend();break;
		case 'b':caveloc=6;break;
		}
		break;
		}
case 13:{swrite("~15You are in a lifeless room... again...\n\r");
		swrite("   S~7traight   ~15B~7ack");
		switch(od_get_answer("sb"))
		{
		case 's':deadend();break;
		case 'b':caveloc=9;break;
		}
		break;
		}
case 14:{swrite("~15You are in a dank, dark room...\n\r");
		swrite("   S~7traight   ~15R~7ight   ~15B~7ack");
		switch(od_get_answer("srb"))
		{
		case 's':mageroom();break;
		case 'r':deadend();break;
		case 'b':caveloc=7;break;
		}
		break;
		}
case 15:{swrite("~15You have strayed off the path...\n\r");
		swrite("   S~7traight   ~15B~7ack");
		switch(od_get_answer("sb"))
		{
		case 's':deadend();break;
		case 'b':caveloc=7;break;
		}
		break;
		}
}
}while(caveloc!=-1);

}

void deadend(void)
{
od_clr_scr();
swrite("~15You are at a dead end...\n\r");
swrite("   B~7ack\n\r");
od_get_answer("b");
}

void mageroom(void)
{
char magecom;
od_clr_scr();
do{
swrite("~9\n\rYou are standing in a large room lighted by mystical candles.  A tall man\n\r");
swrite("with a long white beard and mustauche in a blue robe stands stareing at you.\n\r");
swrite("\n\r~15(~9N~15)  Ask the man for his name\n\r");
swrite("(~9A~15)  Ask the man for help\n\r");
swrite("(~9S~15)  Ask the man for help in your skills\n\r");
swrite("(~9L~15)  Leave\n\r");
magecom=command("NASL",4);
switch(magecom)
{
case 'N':{od_printf("\n\r`bright magenta`\"My name?  Surely you did not travel through the mountains of Trimmail and my\n\r");
		od_printf("cavern maze simply for my name.  But if you must know, I am Soranthous.  I\n\r");
		od_printf("can see you are very inclined in the skills of magic and are in fact very\n\r");
		od_printf("intelligent.  Perhaps I can give you a special skill of mine...\"\n\r");
		getreturn();
		break;
		}
case 'A':{if(checkspec(10)==FALSE)
		{od_printf("\n\r`bright magenta`\"You can have my spell.  But first, you must enter my arena room and battle\n\r");
		od_printf("a monster all on your own then face another monster with my spell and the\n\r");
		od_printf("magic ability to defeat it.  Let me heal you...\"\n\r");
		od_printf("\"Would you like to take the test?\"  [`bright yellow`Y`bright magenta`/`bright yellow`n`bright magenta`]");
		data[user].hitpts = data[user].totalhit;
		if(od_get_answer("yn\n\r")=='n')
			{
			od_printf("`bright magenta`\"Very well.\"");
			break;
			}
		else{monread("deep.dat",4,4);
			monster.hit = 30;
			od_printf("`bright magenta`\n\r\"Fine prepare for battle.  It may be wise to use magic against this foe.\"\n\r");
			od_printf("`magenta`You enter the mage's arena room in the cave.");
			getreturn();
			if(monattack()==FALSE)
				{od_printf("`bright magenta`\"Sorry, I cannot teach you the spell.\"");
				getreturn();
				break;}
			monread("dragon.dat",3,3);
			monster.hit = 185;
			monster.WP = 125;
			monster.run = 0;
			monster.aim=1;
			od_printf("`bright magenta`\"Use this magic very carefully.  You now know the spell `bright red`Smite Foe`bright magenta`.\"\n\r");
			od_printf("`magenta`\n\rYou enter the mage's arena room for the second time.");
			getreturn();
			addspec(10);
			edata.spec+=20;
			if(monattack()==FALSE)
				{od_printf("`bright magenta`\n\r\"Keep the spell, even though you are a coward.  LEAVE.\"\n\r");
				getreturn();
				break;}
			od_printf("`bright magenta`\n\r\"A worthy opponent you are!  I hope I never have to fight you.\"\n\r");
			break;
			}


		}
		else{od_printf("\n\r`bright magenta`\"You already have my spell.\"");
		getreturn();}
		break;
		}
case 'S':{if(checkspec(10)==TRUE)
			{od_printf("\n\r`bright magenta`\"I would be happy to raise your magic ability but it will cost you 250 coins\n\r");
			od_printf("and 1 training point.  Sorry, I have to buy things every once in a while.\"\n\r");
			swrite("   ~15Y~7es or ~15N~7o\n\r");
			if(od_get_answer("yn")=='y')
				{swrite("~13Soranthous waves his hand.\n\r");
				if(data[user].coins<250)
					{swrite("~5Not enough coins.\n\r");
					break;}
				if(edata.trainpts < 1)
					{swrite("~5You need to gain a skill level.\n\r");
					break;}
				swrite("~15250 coins disappear from your pockets.\n\r");
				specialadd(3);
				}
			break;
			}
		else{od_printf("\n\r`bright magenta`\"I will not teach magic to a lower level magic user.\"\n\r");
		break;}
		}
}
}while(magecom!='L');
}



int findlog(int log)
{
int circle;
for(circle=0;circle<setting[0].num_users;circle++)
	{
	if(data[circle].lognumber == log)
		break;
	}
if(circle==setting[0].num_users)
	{od_printf("\n\r`bright red`** User not found\n\r");
	return -1;}
else return circle;
}

void send(int towho)
{

FILE *fp;
char comm;
int cc;
char filename[12];
char toname[30];
char mes1[80];
char mes2[80];
char mes3[80];
if(towho == -1)
{
od_printf("`bright blue`\n\rWho would you like to send a message to?  ");
od_input_str(toname,30,32,122);
cc=pusers(toname);
if(cc == 32000)
	goto end;
}
else {cc = findlog(towho);
	if(cc==-1)
		goto end;
	}
od_printf("\n\r`bright blue`For `bright cyan`%s`bright blue`'s log:  ",data[cc].alias);
od_printf("\n\r`bright blue`<`cyan`3 line MAX/72 character per line`bright blue`>`cyan` Blank line quits\n\r");
od_printf("`bright cyan`-----------------------------------------------------------------------------\n\r");
od_printf("`cyan`1>  `bright cyan`");
od_input_str(mes1,72,32,122);
if(stricmp(mes1,"") != 0)
	{od_printf("`cyan`2>  `bright cyan`");
	od_input_str(mes2,72,32,122);
	if(stricmp(mes2,"") != 0)
		{od_printf("`cyan`3>  `bright cyan`");
		od_input_str(mes3,72,32,122);}
	}
else return;
od_printf("\n\r`bright magenta`%s\n\r",mes1);
if(stricmp(mes2,"") != 0)
	{od_printf("%s\n\r",mes2);
	if(stricmp(mes3,"") != 0)
		od_printf("%s\n\r",mes3);
	}
od_printf("\n\r`bright blue`Do you want to send this message? [Y/N] ");
comm = od_get_answer("YN");
if(comm == 'Y')
	{char joke;
	sprintf(filename,"%d.mal",data[cc].lognumber);
	fp=fopenw(filename,5);
	fprintf(fp,"\n~15-* ~13Message by~9 %s~13.~15 *-\n",data[user].alias);
	if(edata.jokesleft > 0)
	{
	if((joke=sendjoke(data[cc].sex))!=0)
		{
		fprintf(fp,"~M%c %d ",joke,data[user].lognumber);
		fgetc(fp);
		}
	}
	fprintf(fp,"~12----------------------------------------------------------------------------~15\n");
	fprintf(fp,"\n%s\n",mes1);
	if(stricmp(mes2,"") != 0)
		{fprintf(fp,"%s\n",mes2);
		if(stricmp(mes3,"") != 0)
			fprintf(fp,"%s\n",mes3);
		}
	fprintf(fp,"\n~12----------------------------------------------------------------------------~15\n");
	fprintf(fp,"~R %d\n",data[user].lognumber);
	fclose(fp);
	od_printf("`bright green`\n\rMessage sent!\n\r");
	}
end:
playsave('A',0,5);
}

void checkmail(void)
{
FILE *fp;
char filename[12];
char hot;
int log;
unsigned int coins;
int replyto;
sprintf(filename,"%d.mal",data[user].lognumber);
if((fp=_fsopen(filename,"r",SH_DENYNONE))!=NULL)
{
	 char a;  //to read in variables
	fseek(fp,0,SEEK_SET);
	do{
	a = fgetc(fp);
	if(a == '~')
	{
	a = fgetc(fp);
	switch(a)
	{
	case '~':{od_printf("\n\r");
			break;}
	case '0':{od_printf("`black`");
			break;}
	case '2':{od_printf("`green`");
			break;}
	case '3':{od_printf("`cyan`");
			break;}
	case '4':{od_printf("`red`");
			break;}
	case '5':{od_printf("`magenta`");
			break;}
	case '6':{od_printf("`yellow`");
			break;}
	case '7':{od_printf("`white`");
			break;}
	case '8':{od_printf("`gray`");
			break;}
	case '9':{od_printf("`bright blue`");
			break;}
	case '1':{a = fgetc(fp);
			switch(a)
			{
			case '1':{od_printf("`bright cyan`");
					break;}
			case '0':{od_printf("`bright green`");
					break;}
			case '2':{od_printf("`bright red`");
					break;}
			case '3':{od_printf("`bright magenta`");
					break;}
			case '4':{od_printf("`bright yellow`");
					break;}
			case '5':{od_printf("`bright white`");
					break;}
			default:{od_printf("`blue`");
					od_putch(a);
					break;}
			}
			break;
			}
	case 'R':{fscanf(fp,"%d",&replyto);
			swrite("\n\r~9Reply? [~13Y~9/~13n~9] ");
			if(od_get_answer("YN\n\r") == 'N')
				break;
			swrite("\n\r");
			send(replyto);
			break;
			}
	case 'M':{getreturn();
			fscanf(fp,"%c %d",&hot,&log);
			recjoke(hot,log,data[findlog(log)].sex);
			od_printf("`white`The Letter Reads:\n\r");
			fgetc(fp);
			break;
			}
	case 'J':{a = fgetc(fp);
			hot = a;
			a = fgetc(fp);
			if(a == 't')
				{fscanf(fp,"%d",&log);
				recret(hot,log,TRUE);
				getreturn();
				}
			else{fscanf(fp,"%d",&log);
				recret(hot,log,FALSE);
				getreturn();
				}
			break;
			}
	case 'C':{fscanf(fp,"%u",&coins);
			od_printf("`bright white`%u `cyan`coins to you.\n\r",coins);
			if((60000-data[user].coins)<coins)
				data[user].coins = 60000;
			data[user].coins += coins;
			break;
			}
	}
	}
		else{if(a == '\n')
			{od_printf("\n\r");
			}

			else	if(a > 31) od_putch(a);
			}
	}while(a != EOF);
}
remove(filename);
}