#include "med.h"

void mainmenu(void);
void locallogon(void);  //to play locally
void newplayer(void);
void castle(void);
int bet(void);



void listusers(void);

//Universal town functions***************************************************
int farm(void);         //shows farm menu and returns com
int farmbreak(void);    //returns TRUE if breaking into farm successful
int farmowner(void);    //returns TRUE if killing farmowner successful
int farmhand(void);     //returns TRUE if successful killing farmhand
void stables(void);     //menus and handles all stable functions
void sellweapons(int wsword,int ssword, int mace, int morn, int lsword, int axe, int sl, int sp, int bow, int cross);
void buyweapons(int wsword,int ssword, int mace, int morn, int lsword, int axe, int sl, int sp, int bow, int cross);
void sellar(int lar, int car, int par, int dar, int sws, int ws, int bs, int ds);
void buyar(int lar, int car, int par, int sws, int ws, int bs);
void ammo(void);
void haywardspar(void);
void docks(void);
void unifarm(void);
void innb(int a);
void guild(void);
void forest(void);
char mountain(void);
char foresthunt(void);

//Guild Functions************************************************************
void personal(void);
void writelog(void);
void skillcheck(void);

//***************************************************************************

/*if game is to to be set up in chat mode only, arguement chat is sent
and user is set to 50-59 which makes it only able to hold 10 extra players
*/

int user;       //used to specify the array the player is
char newp = FALSE;
char newp2 = FALSE;
struct player_info data[60];
struct info2 edata;
struct settings setting[2];
extern struct monsters monster;
char dia[6];            //used for dialogue.  milord, milady

void main(int argc,char *argv[])
{
//main town functions********************************************************
void hayward(void);
void den(void);
void pom(void);
void midtrim(void);
void westtrim(void);
void easttrim(void);
void sus(void);
void burk(void);
void tiw(void);
void hideout(void);

/***************************************************************************/

od_control.od_cbefore_chat=fullscreen_chat;
strcpy(od_registered_to,"Jeb Dunn");
od_registration_key = 1658847232;
od_control.od_nocopyright = TRUE;
int count;
if(argc>1)
	{if((stricmp(argv[1],"-l") == 0) || (stricmp(argv[1],"local") == 0) || (stricmp(argv[1],"/l") == 0) || (stricmp(argv[1],"0") == 0))
		{od_control.od_disable |= DIS_INFOFILE;
		locallogon();
		}
	else{comr(atoi(argv[1]));
		}

	}
else{printf("\a\a\aNode not specified.");
	od_exit(0,FALSE);}
if(argc>2)
	{if(stricmp(argv[2],"chat")==0)
		{for(user=50;user<60;user++)
			{if(data[user].location != '$')
				{
				data[user].location = '$';
				strcpy(data[user].alias,od_control.user_name);
				od_printf("\n\r`bright white`Welcome to the guildhall of Farmers and Kings.\n\r");
				guildhall();
				data[user].location = 'G';
				playsave('A',0,2);
				od_exit(0,FALSE);
				}

			}
		if(user == 60)
			{od_printf("\n\r`red`Not enough space!");
			od_exit(0,FALSE);
			}
		}
	}
for(user=0;user<setting[0].num_users;user++)
	  {if(strcmp(data[user].name,od_control.user_name)==0)
	  break;}
if(user!=setting[0].num_users)
	data[user].online = od_control.od_node;
playsave('A',0,10);
od_control.od_before_exit=save;
od_control.od_before_chat=(char *)"\n\rA mist surrounds you and a voice enters your head...\n\r";
od_control.od_after_chat=(char *)"\n\rThe mist leaves as quickly as it came...\n\r";
od_control.od_after_shell=(char *)"\n\rThe Land Spirit has returned, everything returns to normal...\n\r";
od_control.od_before_shell=(char *)"\n\rThe Land Spirit is doing other things with his land (please hold)...\n\r";
od_control.od_help_text2=(char *)"[F1] basic         Farmers and Kings : version 1.72         [F10] Statusline off";
od_control.od_no_sysop=NULL;
od_control.od_paging=NULL;
od_control.od_status_line[1]=(char *)"%s from %s on at %u Baud";
od_control.od_help_text=(char *)"   Alt: [C]hat [H]angup [L]ockout [J]ump to Dos [K]eyboard-Off [D]rop to BBS    ";
od_control.od_page_pausing = FALSE;
od_autodetect(1);
randomize();
if(random(10002) < 5000)
{
if(od_hotkey_menu("intro.ans"," ",FALSE) == '\0')
	while(od_get_key(TRUE) == 0);
}
else{
if(od_hotkey_menu("intro2.ans"," ",FALSE) == '\0')
	while(od_get_key(TRUE) == 0);
}
od_control.od_page_pausing = FALSE;
  od_set_cursor(1,1);
  od_printf("`white brown`1`white black`1");
  od_set_cursor(1,1);
  od_clr_scr();

mainmenu();
if(user == setting[0].num_users)
  {
	  if(setting[0].num_users>=50){
	  od_printf("\n\rSorry, No room for more players.\n\r");
	  getreturn();
	  od_exit(12,FALSE);}
newplayer();}
char filedat[12];
int handle;
sprintf(filedat,"%d.dat",data[user].lognumber);
if((handle=eopen(filedat,2))==-1)
	{
	od_printf("`red`Error player data files not found.\n\r");
	od_printf("`bright white`Inform sysop!\n\r");
	od_exit(12,FALSE);
	}
read(handle,&edata,sizeof(struct info2));
close(handle);

if(data[user].online == 32000)
	{od_printf("`red`\n\rYou are currently very busy in a battle.  Wait for about 2 minutes and\n\rtry again.\n\r");
	getreturng();
	od_exit(0,FALSE);}
if(data[user].sex == 'M')
	{strcpy(dia,"milord");}
	else if(data[user].sex == 'F')
		strcpy(dia,"milady");
		else{od_printf("Error: lost data.  Fatal.");
			od_exit(12,FALSE);}
edata.inactivity = 0;
if((data[user].location == '$') || (data[user].location == '&'))
	data[user].location = 'F';
if((data[user].hitpts < 1) && (data[user].hitpts != -100))
	{od_printf("`red`\n\rSorry, you are dead.  Call back tomorrow.\n\r");
	getreturn();
	od_exit(0,FALSE);}
else if(data[user].hitpts == -100)
	{od_printf("`red`\n\rYou can faintly remember someone charging at you...\n\r");
	data[user].hitpts = 1;
	}
if(data[user].location == 'X')
	{od_printf("`bright red`\n\rYou can faintly remember two faries hovering over you.  Then you awake in\n\r");
	od_printf("the fields with hardly any energy and the cut that took your life is still\n\r");
	od_printf("sore but nearly healed.\n\r");
	data[user].location = 'F';
	data[user].hitpts = data[user].totalhit - 5;
	data[user].coins = 0;}
else if(data[user].location == 'F')
	{od_printf("`bright blue`\n\rYou wake up in the vast fields, pack up your gear, and go to work...\n\r");
	}
else if(data[user].location != 'Z')
	{od_printf("`bright cyan`\n\rYou wake up in your comfortable bed.  After drinking some coffee with the\n\r");
	od_printf("inkeeper, you feel ready to get out and fight again.\n\r");
	if(edata.hunger == 'B')
		edata.hunger = 'A';
	else edata.hunger = 'B';
	}
checkmail();
if(data[user].newmessage == TRUE)
		{
		od_printf("\n\r`bright blue`On your way to town, you stop by the guild hall to read your log...\n\r");
		getreturn();
		data[user].newmessage=FALSE;
		personal();
		data[user].location = 'Z';}
od_printf("`bright red`");
od_printf("\n\rRead today's log? [`bright blue`Y`bright red`/`bright blue`n`bright red`]  ");
od_clear_keybuffer();
if(od_get_answer("YUIONKDLSA \n\r")!='N')
	{od_printf("\n\r");
	od_clr_scr();
	fkread(fopenr("day0.log",1));
	getreturng();
	}
od_control.user_ansi = data[user].trueansi;
randomize();
while(1){
switch(data[user].town)
{
case 'H':{hayward();
		break;}
case 'D':{den();
		break;}
case 'P':{pom();
		break;}
case 'M':{midtrim();
		break;}
case 'E':{easttrim();
		break;}
case 'W':{westtrim();
		break;}
case 'S':{sus();
		break;}
case 'B':{burk();
		break;}
case 'T':{tiw();
		break;}
case '*':{hideout();
		break;}
}
}

}

void mainmenu(void)
{
char comm;
od_clr_scr();
od_printf("`bright blue`\n\r                               Farmers and Kings\n\n\r");
od_printf("`bright magenta`Version 2.0  Alpha\n\r");
od_printf("`magenta`Please report bugs or suggestions to `bright blue`Jeb Dunn\n\r");
od_printf("`magenta`on Stone Tower or `bright blue`Guardian@ok.azalea.net\n\r");
od_printf("`bright magenta`Registered to:  %s\n\r",setting[0].registeredto);
od_printf("`bright blue`Designed and Programmed by:  Jeb Dunn\n\r");
od_printf("`bright magenta`Copyright 1994 : Jeb Dunn\n\r");
od_printf("`magenta`The Stone Tower BBS:  (918) 478-4326\n\r");
od_printf("`bright blue`Programmed using Turbo C++\n\r");
od_printf("`bright magenta`\n\rSpecial thanks to Brian Pirie for\n\r");
od_printf("the Opendoors Programming Toolkit:  Opendoors BBS  (613) 526-4446\n\n\r");
do{
od_printf("`bright blue`---------------------------------------\n\r");
od_printf("`bright magenta`\n\r(`bright white`P`bright magenta`)  Play FK\n\r");
od_printf("(`bright blue`I`bright magenta`)  Instructions\n\r(`bright blue`U`bright magenta`)  Quick Instructions\n\r(`bright blue`Q`bright magenta`)  Quit\n\r\n");
od_printf("`bright blue`---------------------------------------\n\r");
comm = od_get_answer("PIQU");
switch(comm)
{
case 'P':{if(setting[0].win != 100)
			{od_printf("`bright red`\n\rSorry, the game has been won by %s.  Will restart tonight.\n\r",data[setting[0].win].alias);
			getreturn();
			od_exit(0,FALSE);}
		break;}
case 'I':{od_printf("`cyan`\n\r");
		od_control.od_page_pausing = TRUE;
		fkread(fopenr("instru.asc",10));
		od_control.od_page_pausing = FALSE;
		getreturng();
		break;}
case 'U':{fkread(fopenr("qinst.asc",2));
		getreturng();
		break;}
case 'Q':{od_exit(0,FALSE);
		break;}
}
}while(comm != 'P');
}


void getreturng(void)
{
od_clear_keybuffer();
od_printf("\n\r`bright blue`<`bright black`E`white`n`bright white`t`white`e`bright black`r`bright blue`>");
while(od_get_key(TRUE)!=13);
od_printf("\r        \r");
od_printf("\n\r");
}
void getreturn(void)
{
od_clear_keybuffer();
od_printf("\n\r`bright blue`<`bright black`E`white`n`bright white`t`white`e`bright black`r`bright blue`>");
while(od_get_key(TRUE)!=13);
if(od_control.user_ansi==TRUE)
{
od_printf("\b\b\b\b\b\b\b       \r");
}
else od_printf("\n\r");
}

void locallogon(void)
{
printf("\n\n\n\rLOCAL LOGON\n");
printf("-----------\n\n");
od_control.baud = 0;
printf("Enter your first and last name:  ");
gets(od_control.user_name);
if(strcmp(od_control.user_name,"") == 0)
	strcpy(od_control.user_name,"Test User");
strcpy(od_control.user_location, "LOCAL");
od_control.user_loginsec = 10;
od_control.user_timelimit = 120;
strcpy(od_registered_to,"Jeb Dunn");
od_registration_key = 1658847232;
od_control.od_force_local = TRUE;
od_control.od_node = 0;
od_init();
comr(0);
od_control.user_ansi = TRUE;
if(strcmp(od_control.user_name,"Testing123") == 0)
	od_control.user_ansi = 5;
}


void newplayer(void)
{
user = 50;  //temporary hold for new player
char a,b,c;
newp = TRUE;
newp2 = TRUE;
od_clr_scr();
strcpy(data[user].name,od_control.user_name);
od_printf("\n\r`flashing bright red`*`bright white`Sit back, put the keyboard in your lap, and prepare for total addiction`flashing bright red`*");
od_printf("\n\r`green`%s`bright blue`, thank you for playing.\n\r",data[user].name);
od_printf("\n\rWould you like to use an [`bright red`A`bright blue`]lias or go\n\r");
od_printf("by your [`bright red`B`bright blue`]BS name? ");
od_clear_keybuffer();
a = od_get_answer("AB");
if(a == 'A'){
	aliasagain:
	do{
	od_printf("\n\r`bright magenta`Enter the Alias you would like to use:  `magenta`");
	od_input_str(data[user].alias,21,32,122);
	if(strcmp(data[user].alias,"") == 0)
		goto aliasagain;
	od_printf("\n\r\n\r`bright cyan`%s\n\r",data[user].alias);
	od_printf("\n\r`bright magenta`Is this what you want to go by? [`bright blue`Y`bright magenta`/`bright blue`N`bright magenta`]");
	b = od_get_answer("YN");
	}while(b == 'N');
	int c1;
	for(c1=0;c1<setting[0].num_users;c1++){
		if(stricmp(data[c1].alias,data[user].alias) == 0){
		od_printf("\n\rSorry, `yellow`%s `bright magenta`is already used.\n\r",data[user].alias);
		goto aliasagain;}
		}
	}
else if(a == 'B'){
	strcpy(data[user].alias,data[user].name);}
od_printf("\n\r`bright blue`Would you like to be (`bright red`M`bright blue`)ale or (`bright red`F`bright blue`)emale?\n\r");
c = od_get_answer("MF");
if(c == 'M'){
	od_printf("`bright magenta`Ok, milord.\n\r");
	data[user].sex = 'M';}
else if(c == 'F'){
	od_printf("`bright magenta`Ok, milady.\n\r");
	data[user].sex = 'F';}
data[user].strength = 1;
data[user].dex = 1;
data[user].skill = 1;
edata.jokesleft = setting[0].numjokes;
data[user].exp = 1;
data[user].coins = 40;
data[user].bankcoins = 5;
data[user].ammo = 0;
data[user].hitpts = 30;
data[user].totalhit = 30;
data[user].town = 'H';
data[user].location = 'Z';
edata.trainpts = 1;
edata.turns = setting[0].num_turns;
edata.fish = setting[0].fish;
edata.forest = setting[0].forest;
edata.mountains = setting[0].mountains;
edata.farm = setting[0].farm;
edata.hunger = 'A';
data[user].weaponshort = 1;
data[user].weaponlong = 0;
data[user].armor = 0;
data[user].shield = 0;
edata.progress = 1;
data[user].aim = 6;
data[user].newmessage = FALSE;
edata.i0 = 0;
edata.i1 = 0;
edata.i2 = 0;
edata.i3 = 2;
edata.i4 = FALSE;
edata.i5 = 0;
edata.i6 = FALSE;
data[user].trueansi = TRUE;
edata.prodeath = 0;
edata.proscor = 0;
edata.protiw = 0;
edata.undead = FALSE;
data[user].kills = 0;
edata.qf = FALSE;
edata.pfight = setting[0].pfight;
edata.well = FALSE;
strcpy(data[user].stype,"Dagger");
strcpy(data[user].ltype,"none");
strcpy(edata.artype,"none");
edata.shtype = 'Z';
edata.conv = FALSE;
data[user].theif = 0;
data[user].honor = 1;
for(edata.spe[0]=0;edata.spe[0]<10;edata.spe[0]++)
	{edata.spe[edata.spe[0]] = 0;
	}
edata.spe[0] = 0;
edata.spec = 1;
edata.spectotal = 1;
strcpy(edata.compname,"none");
edata.compatt=0;
strcpy(edata.compa,"none");
char iop;
char iki;
while(1){
	od_printf("\n\r`magenta`I need to know if you have ANSI.  Do you?\n\r`bright blue`");
	od_printf("(Y)es  (N)o  (T)est (H)elp `bright red`");
	iki = od_get_answer("YNTH");
	if(iki == 'Y')
		{od_printf("\n\rOK, Using ANSI.\n\r");
		data[user].ANSI = TRUE;
		data[user].trueansi = TRUE;
		od_control.user_ansi = TRUE;
		break;
		}
	else if(iki == 'N')
		{od_control.user_ansi = FALSE;
		od_printf("`bright cyan`Ok, Disabling ANSI.\n\r");
		data[user].trueansi = FALSE;
		break;}
	else if(iki == 'T')
		{od_control.user_ansi = TRUE;
		od_printf("`red`\n\rRED  `bright white`WHITE  `blue`BLUE\n\r");
		od_printf("\n\r`white`Can you see these colors?  [Y/N] ");
		iop = od_get_answer("YN");
		if(iop == 'Y')
			{od_printf("`bright cyan`\n\rThen you have ANSI.  Do you want to use it? [Y/N] ");
			iki = od_get_answer("YN");
			if(iki == 'Y')
				{data[user].trueansi = TRUE;
				break;}
			else{od_control.user_ansi = FALSE;
				data[user].trueansi = FALSE;
				break;}
			}
		else{od_control.user_ansi = FALSE;
			data[user].trueansi = FALSE;
			od_printf("\n\rYou don't have ANSI.  Sorry.\n\r");
			break;}
		}
	else if(iki == 'H')
		{od_printf("\n\rANSI, often referred to as \"ANSI graphics\", is a protocol which allows\n\r");
		od_printf("in this case, BBS software to perform certain display functions such as\n\r");
		od_printf("text colors and moving the cursor among the screen.  Most terminals, though\n\r");
		od_printf("not all, have ANSI capibility.  Choose (T)est to find out or if you know\n\r");
		od_printf("that you do, choose (Y)es.  If you know that you don't have it, choose (N)o.\n\r");
		}
	}
od_printf("`bright blue`");
swrite("~9? ~13One last question~9:  ~12Are you ~15[~9R~15]~12ich or ~15[~9P~15]~12owerful~9 ?");
data[user].coins = (od_get_answer("RP") == 'R')?100 : 40;
if(data[user].coins == 100)
	{od_printf("`bright blue`\n\rGood choice:  `bright red`Money can get anything in this world.\n\r");
	}
else{od_printf("\n\r`bright blue`Wise choice:  `bright red`The weak fear the mighty.\n\r");
	edata.trainpts=0;
	data[user].strength = 3;
	data[user].dex=3;
	data[user].totalhit = 30;
	edata.spectotal=2;
	edata.spec=2;}

sleep(1);
od_printf("`bright white`B`white`e prepared.  Only the strong and intelligent will survive`bright black`...");
getreturn();
od_clr_scr();
od_control.od_page_pausing = FALSE;
fkread(fopenr("new.asc",10));
getreturng();
od_clr_scr();
od_printf("`bright blue`As you limp onto the main street, you vow to avenge your life's work...\n\r");
getreturng();
od_printf("`bright red`*`bright white`SAVING YOUR INFORMATION, PLEASE WAIT`bright red`*\n\r");
int newhandle;
if((newhandle=eopen("sett.ing",20))==-1)
	{od_printf("Fatal error - unable to open data file");
	od_exit(0,FALSE);}
if(read(newhandle,setting,(sizeof(struct settings)))==-1)
	{printf("error");
	getreturng();}
if(setting[0].num_users == 50)
	{od_printf("Sorry... someone on another node has beaten you to the last open spot.");
	od_exit(0,FALSE);}
user=setting[0].num_users;
data[user] = data[50];
setting[0].num_users++;
data[user].lognumber = setting[0].num_log;
setting[0].num_log++;
lseek(newhandle,0,SEEK_SET);
if(write(newhandle,setting,sizeof(struct settings))==-1)
	{printf("error");
	getreturng();}
close(newhandle);
char newplay[60];
sprintf(newplay,"~8%s's~15 house has been burned...",data[user].alias);
logwrite(newplay);
char newfile[12];
sprintf(newfile,"%d.dat",data[user].lognumber);
fclose(fopen(newfile,"w"));
if((newhandle=eopen(newfile,1))==-1)
	{
	od_printf("`red`Please report a read error to the sysop.");
	od_exit(12,FALSE);
	}
else write(newhandle,&edata,sizeof(struct info2));
close(newhandle);
if((strcmp(setting[0].registered,"GLSKDMTEPDOGKFS") != 0)&&(setting[0].regis!=regist()))
{
od_printf("`bright white`Something to remember`bright red`:  `bright blue`Sysops are not Rich.  To see the rest\n\r");
od_printf("of the land of Trimmail, help him register`bright red`:");
getreturn();
od_hotkey_menu("land.ans"," ",FALSE);
od_printf("`bright white`\rDon't you want to explore more than `bright red`Hayward`bright white`?  press enter...");
while(od_get_key(TRUE)!=13);
od_printf("`bright blue`");
od_printf("\n\rDragons in `bright red`Burkshire`bright blue`.  Pirates in `bright red`The Den`bright blue`.  And\n\r");
od_printf("many mysteries to be solved.\n\r");
}
if(data[user].trueansi==FALSE)
	edata.qf=TRUE;
playsave('A',0,5);
}

void hideout(void)
{
char com;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("hideout.ans","FDH",TRUE);
			od_set_cursor(1,1);
		  od_printf("`white brown`1`white black`1");
		  od_set_cursor(1,1);
		  od_clr_scr();
			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("FDH");
			od_printf("\n\n\r");}
		break;
		}
case 'F':{fields();
		break;}
case 'D':{docks();
		break;}
case 'H':{swrite("\n\r~9The little building is crawling with pirates.  Only one looks worthy enough\n\r");
		swrite("to talk to.\n\n\r");
		swrite("~15(~9J~15)  Join conversation at bar\n\r(~9T~15)  Talk to Wolf Pirate\n\r(~9L~15)  Leave\n\r");
		com = command("JTL",3);
		switch(com)
		{
		case 'J':{tavlog();
				break;}
		case 'T':{talkhidepir();
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
}
}while(data[user].town == '*');
}


void tiw(void)
{
char com, chj;
char fight = FALSE;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("tiw.ans","EAGHTRYWMSFGP",TRUE);
			od_set_cursor(1,1);
		  od_printf("`white brown`1`white black`1");
		  od_set_cursor(1,1);
		  od_clr_scr();
			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("EAGHTRWMSFGYP");
			od_printf("\n\n\r");
			}
		break;
		}
case 'T':{swrite("\n\r~12Many warriors crowd this comtempory tavern.  You are careful not to bump\n\r");
		swrite("into any considering their reputation.~9`\n\r");
		swrite("\n\r(~15J~9)  Join conversation at bar\n\r(~15T~9)  Talk to Bartender\n\r");
		swrite("(~15R~9)  Get a room\n\r(~15G~9)  Get a drink\n\r");
		swrite("(~15H~9)  Down some Dragon's Blood\n\r(~15O~9)  Order a meal\n\r(~15S~9)  Sit down at a table\n\r");
		swrite("(~15B~9)  Back door to mountains\n\r(~15L~9)  Leave\n\r");
		com = command("RGBOSJLTH",9);
		switch(com)
		{
		case 'J':{tavlog();
				break;}
		case 'T':{od_printf("`bright white`\n\n\r\"Rooms are 20, drinks are 10, and dinners are 25.  Have you met Tiashi Ci?\n\r");
				od_printf("He runs a training camp of Martial Artists in the mountains.  They are\n\r");
				od_printf("opposed to the armour and weapons of the soldiers.  I don't know how to get\n\r");
				od_printf("there, but someone in town must know.  Ask them about `bright blue`Tiashi`bright white`.\"\n\r");
				getreturn();
				break;}
		case 'R':{innb(20);
				break;}
		case 'G':{taverng(10, 15);
				break;}
		case 'H':{taverng(10,600);
			break;}

		case 'O':{taverno(25);
				break;}
		case 'S':{if(edata.protiw > 1)
					od_printf("`bright red`\n\rThere are no warriors left.\n\r");
				else{
				od_printf("`bright blue`\n\rYou see two warriors at two different tables.  Which one would you like\n\r");
				od_printf("to ask for company?\n\r");
				od_printf("`bright white`\n\r(J)  Juliet\n\r(V)  Vadius\n\r(F)  Forget it\n\r");
				chj = od_get_answer("JVF");
				switch(chj)
				{
				case 'J':{fight = juliet();
						break;}
				case 'V':{fight = vardius();
						break;}
				}
				}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		case 'B':{if(mountain()==FALSE)
					data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'E':{swrite("\n\r~9The Mountains are not as cold as you thought they would be, but it is still\n\r");
		swrite("cold enough for you to rot a couple of limbs off.  The city of Tiw looks\n\r");
		swrite("fabulous from this height.\n\r");
		getreturn();
		mountain();
		break;}
case 'F':{fields();
		break;}
case 'S':{swrite("~13\n\rThe stables look nearly exactly like the one in Hayward.\n\r");
		stables();
		break;}
case 'M':{od_printf("`bright green`\n\rThe market place is extremely crowded.  You push through the mob.\n\r");
		do{
		swrite("~2\n\r(~15B~2)  Buy food\n\r(~15S~2)  Sell food\n\r(~15L~2)  Leave\n\r");
		com = command("BSL",3);
		switch(com)
		{
		case 'B':{marketbuy(16, 9, 9);
				break;}
		case 'S':{marketsell(8, 5, 4);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(com != 'L');
		break;
		}
case 'W':{swrite("\n\r~13This small shop looks like it is centuries old, and doesn't look like it\n\r");
		swrite("might close soon.  Many fine pieces of weaponry line the walls.\n\r");
		swrite("~9\n\r(~15W~9)  Buy/Sell weapons\n\r");
		swrite("(~15A~9)  Buy/Sell armour\n\r(~15L~9)  Leave\n\r");
		com = command("WAL",3);
		switch(com)
		{
		case 'W':{do{
				od_printf("`bright white`\n\r(B)  Buy weapons\n\r(S)  Sell weapons\n\r(A)  Ammo\n\r(Q)  Quit\n\n\r");
				chj = command("BSAQ",4);
				switch(chj)
				{
				case 'B':{buyweapons(1200,70, 125, 180, 250, 480, 35, 80, 190, 600);
				   break;}
				case 'S':{sellweapons(1000,15, 35, 80, 120, 200, 5, 25, 70, 250);
				   break;}
				case 'A':{ammo();
				   break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'A':{do{
				od_printf("`bright white`\n\r(B)  Buy armour\n\r(S)  Sell armour\n\r(Q)  Quit\n\r\n");
				chj = command("BSQ",3);
				switch(chj)
				{
				case 'B':{buyar(55, 150, 350, 50, 140, 300);
				    break;}
				case 'S':{sellar(15, 35, 120, 300, 15, 45, 130, 300);
				    break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'G':{od_printf("`green`\n\rThe Guild Hall very much resembles the one in Hayward.\n\r");
		guild();
		break;}
case 'R':{fur(40,15,150);
		break;}
case 'H':{while(1){od_printf("`bright magenta`\n\rThe Tyrial Training Academy doesn't look like anything real special.  Many\n\r");
		if(od_get_key(FALSE) == 13) break;
		od_printf("weapons line the walls, and there are many warriors training but nothing\n\r");
		if(od_get_key(FALSE) == 13) break;
		od_printf("impresses you.\n\r");
		break;}
		if(edata.protiw < 3)
			{od_printf("`bright red`\n\r(N)  Talk to Nadiera\n\r(T)  Train with Nadiera\n\r(J)  Talk to Julius\n\r(S)  Spar with Julius\n\r(L)  Leave\n\r");
			com = od_get_answer("NTJSL");
			}
		else if(edata.protiw == 3)
			{od_printf("`bright red`\n\r(J)  Talk to Julius\n\r(S)  Spar with Julius\n\r(L)  Leave\n\r");
			com = od_get_answer("JSL");}
		else{od_printf("Noone available is here.\n\n\r`bright red`(L)  Leave\n\r");
			com = od_get_answer("L");}
		switch(com)
		{
		case 'N':{fight = nadiera();
				break;}
		case 'T':{if(data[user].coins < 50)
					{od_printf("`red`\n\rYou don't have 50 coins.\n\r");}
				else if(edata.trainpts < 1)
					{od_printf("`red`\n\rYou need another skill level.\n\r");}
				else if((data[user].dex == 20) || (data[user].totalhit >190))
					{od_printf("`bright red`\n\rYou don't need this training.\n\r");}
				else{od_printf("`bright red`You pay for the training and Nadiera spars with you for while and then\n\r");
					od_printf("takes you through an obstacle course to build endorance.\n\r");
					data[user].coins -= 50;
					data[user].dex++;
					data[user].totalhit += 10;
					edata.trainpts--;
					}
				break;}
		case 'J':{fight = julius();
				break;}
		case 'S':{if(data[user].coins < 50)
					{od_printf("`red`\n\rYou don't have 50 coins.\n\r");}
				else if(edata.trainpts < 1)
					{od_printf("`red`\n\rYou need another skill level.\n\r");}
				else if((data[user].strength == 20) || (data[user].aim == 20))
					{od_printf("`bright red`\n\rYou don't need this training.\n\r");}
				else{od_printf("`bright blue`\n\rYou give Julius the money and start to spar and do various exercises to\n\r");
					od_printf("build up your muscles.  Then, you go with him behind the building to an\n\r");
					od_printf("archery range.  There he gives you pointers to how to better aim\n\r");
					od_printf("your long-range shots.\n\r");
					data[user].coins -= 50;
					data[user].strength++;
					data[user].aim++;
					edata.trainpts--;
					}
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'A':{if(fight == TRUE)
			{monread("stryline.dat",9,edata.protiw);
			od_printf("`bright blue`\n\rYou face your opponent in the wide open arena.\n\r");
			getreturn();
			if(monattack() == TRUE)
				{edata.protiw++;
				getreturn();
				if(edata.protiw == 4)
					{char buffer[70];
					edata.progress++;
					sprintf(buffer,"%s has beaten Julius!",data[user].alias);
					logwrite(buffer);
					if(data[user].weaponshort < 10)
						{od_printf("`bright red`\n\rYou take Julius's Diamond Sword.\n\r");
						getreturng();
						data[user].weaponshort = 10;
						strcpy(data[user].stype,"Diamond Sword");}
					}
				}
			fight = FALSE;
			data[user].location = 'Z';
			}
		else{od_printf("`bright blue`\n\rTwo guards hold you out for you have no fight scheduled.\n\r");
			getreturng();
			data[user].location = 'Z';
			break;}
		break;
		}
case 'Y':{swrite("~9\n\rThe soldier academy is extremely crowded with people in soldier uniforms.\n\r");
		swrite("You walk into the main building and see the main instructor.\n\r");
		swrite("~13\n\r(~15T~13)  Talk to Hilder\n\r(~15L~13)  Leave\n\r");
		com = command("TL",2);
		switch(com)
		{
		case 'T':{hilder();
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'P':{fishing();
		break;}
}
}while(data[user].town == 'T');
}

void burk(void)
{
char com, chj;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("burkshir.ans","TEFSNMWGVRH",TRUE);
		  od_set_cursor(1,1);
		  od_printf("`white brown`1`white black`1");
		  od_set_cursor(1,1);
		  od_clr_scr();

			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("TEFSNMWGVRH");
			od_printf("\n\n\r");
			}
		break;
		}
case 'T':{swrite("~9\n\rThis is a strange looking tavern.  There are no walls.  Alot of poles hold\n\r");
		swrite("up the roof.  The bar is in the middle with a few tables scattered around.  A\n\r");
		swrite("pretty young woman stands behind the bar.\n\r\n");
		swrite("~12(~15J~12)  Join conversation at bar\n\r(~15T~12)  Talk to Bartender\n\r(~15G~12)  Get a drink\n\r");
		swrite("(~15H~12)  Down some Dragon's Blood\n\r(~15O~12)  Order a meal\n\r(~15S~12)  Sit down at a table\n\r");
		swrite("(~15B~12)  Back door to forest\n\r(~15L~12)  Leave\n\r");
		com = command("BJTGOSLH",8);
		switch(com)
		{
		case 'J':{tavlog();
				break;}
		case 'H':{taverng(3,600);
				break;}
		case 'T':{od_printf("\n\r\"Wait!  Before you ask (every visitor soon asks), there is no inn in town.  We\n\r");
				od_printf("don't get enough visitors to keep an inn in business.  But my tavern does\n\r");
				od_printf("make a pretty good business.  Drinks for 3 coins and dinner for 15.\"\n\r");				break;
				}
		case 'G':{taverng(3,10);
				break;}
		case 'O':{taverno(15);
				break;}
		case 'S':{talkburkpatrons();
				break;}
		case 'B':{if(foresthunt()==FALSE)
				data[user].location='E';
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;}
case 'E':{do{
		swrite("\n\r~1The Deep Forest is a dark and lonely place.  Just by looking into the\n\r");
		swrite("shadows, you start to tremble in fear.\n\r");
		swrite("~3\n\r(~15H~3)  Hunt\n\r(~15D~3)  Dragon's Lair\n\r(~15T~3)  Take abandoned road\n\r(~15L~3)  Leave\n\r");
		com = command("=HDLT",5);
		if((com == '=') && (edata.prodeath < 3))
			com = 'O';
		switch(com)
		{
		case '=':{int deathhandle;
				deathhandle=eopen("sett.ing",20);
				read(deathhandle,setting,sizeof(struct settings));
				if(setting[0].death == TRUE)
					{data[user].weaponshort = 15;
					strcpy(data[user].stype,"Death Scythe");
					setting[0].death = FALSE;
					lseek(deathhandle,0,SEEK_SET);
					write(deathhandle,setting,sizeof(struct settings));
					close(deathhandle);
					od_hotkey_menu("death"," ",FALSE);
					getreturng();
					char bufff[70];
					sprintf(bufff,"%s has recovered the Death Scythe.",data[user].alias);
					logwrite(bufff);}
				else if(setting[0].death == FALSE)
					{close(deathhandle);
					od_hotkey_menu("deathg"," ",FALSE);
					getreturng();
					}
				break;
				}
		case 'T':{od_clr_scr();
				swrite("~13After hours and hours of walking, you finally come upon a site.");
				getreturn();
				swrite("~11In the middle of the forest is a massive stone temple, the like you have\n\r");
				swrite("never seen.  Entering the open front door, you are surprised at the specious\n\r");
				swrite("hall.  But around you is men and women practicing martial arts.\n\r");
				getreturn();
				swrite("A man approaches you and says, ~9");
				if(stricmp(edata.compname,"tiashi")!=0)
					{od_printf("\n\r\"Leave!  Your type is not welcome here.\"\n\r");
					od_printf("`bright cyan`The firmness in his voice convinces you to depart.\n\r");
					getreturn();
					break;}
				if(stricmp(edata.artype,"serpent")==0)
					{
					swrite("\n\r\"Ah, you have succeeded in your quest.  Well done.\"\n\r");
					honoradd(5);
					swrite("\n\r~9\"This armour is the strongest ever known.\"\n\r");
					swrite("~11The man's tone changes.  ~9\"Your battle in your future...\n\r");
					swrite("\"You must be careful, your enemy will have a special attack that will cripple\n\r");
					swrite(" you no matter how strong you get before then.  Hit behind your shield to\n\r");
					swrite(" dodge the attack.  Perhaps not the information you wanted?  Glory is found\n\r");
					swrite(" in yourself.\"");
					getreturn();
					break;
					}
				swrite("\n\r\"Tiashi!  Welcome, welcome.  Why is it you come?\"\n\r");
				swrite("~13\"My master, this man appears to have the power and wisdom we need to defeat\n\r");
				swrite("the king!\"  ~11Answers Tiashi.\n\r");
				swrite("The master sizes you up.  ~9\"Why this weakling from Hayward?\"\n\r");
				swrite("~13\"His anger is deep for the king, yet he controls it.  In less than a day, he\n\r");
				swrite("  learned the moves of my camp.\"\n\r");
				swrite("~9\"I see... for now some advice.  I believe a major battle is in your future,\n\r");
				swrite("  you must learn the secrets in this world to survive.  Know this:  Defense\n\r");
				swrite("  is the only way to keep some attacks from hitting you.  You must learn\n\r");
				swrite("  when to use defense and when to attack.  Take Tiashi and go to Sussenex.\n\r");
				swrite("  Somewhere in the mountains is a secret.  Come back after you find it.\"\n\r");
				getreturn();
				break;
				}
		case 'H':{forest();
				break;}
		case 'D':{char local = 'O';
				if(data[user].ANSI == TRUE)
					{od_hotkey_menu("dragon.ans"," ",FALSE);
					getreturng();
					 od_set_cursor(1,1);
					  od_printf("`white brown`1`white black`1");
					  od_set_cursor(1,1);
					  od_clr_scr();}
				do{
				od_printf("`bright magenta`\n\rThe Dragon's Lair is dark, damp, and hot.\n\r");
				switch(local)
				{
				case 'O':{od_printf("You are at the opening.\n\r");
						od_printf("`bright blue`\n\r(G)  Go to large room.\n\r(S)  Search the cavern maze.\n\r(L)  Leave\n\r");
						local = od_get_answer("GSL");
						break;}
				case 'G':{char uoi;
						monread("dragon.dat",5,3);
						monster.WP--;
						uoi = monattack();
						if(uoi == TRUE)
							{char bufff[70];
							sprintf(bufff,"%s has beaten the three-headed dragon!",data[user].alias);
							logwrite(bufff);}
						if((edata.progress == 6) && (uoi == TRUE))
							{od_printf("`bright blue`\n\rSearching through the dirt, you find a set of keys.\n\r");
							edata.progress = 7;}
						local = 'O';
						break;
						}
				case 'S':{od_clr_scr();
						randomize();
						char k;
						do{
						od_printf("\n\r`magenta`(C)  Continue\n\r");
						od_printf("(L)  Leave to lair opening\n\r");
						k = command("CL",2);
						switch(k)
						{
						case 'C':{
								if(turncheck(2) == 0)
									break;
								int jl;
								jl = random(5);
								if(jl == 3)
									jl = 2;
								monread("dragon.dat", 5, jl);
								monattack();
								break;}
						case 'L':{local = 'O';
								break;}
						}
						}while(local == 'S');
						break;
						}
				}
				}while(local != 'L');
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(data[user].location == 'E');
		break;
		}
case 'F':{fields();
		break;}
case 'S':{swrite("~9\n\rNot many of the stalls in this large empty stable have roofs.  However,\n\r");
		swrite("not all the ones with roofs are filled up.\n\r");
		stables();
		break;}
case 'N':{swrite("~9\n\rThe mountains are cold.  The snowfall seems constant and you have trouble\n\r");
		swrite("finding your way.\n\r");
		getreturn();
		mountain();
		break;}
case 'M':{od_printf("`bright green`\n\rThere is but one foodstand in the small market place.\n\r");
		do{
		swrite("~2\n\r(~15B~2)  Buy food\n\r(~15S~2)  Sell food\n\r(~15L~2)  Leave\n\r");
		com = command("BSL",3);
		switch(com)
		{
		case 'B':{marketbuy(10, 6, 6);
				break;}
		case 'S':{marketsell(8, 5, 4);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(com != 'L');
		break;
		}
case 'W':{swrite("~13\n\rThis small shop looks like it is centuries old, and doesn't look like it\n\r");
		swrite("might close soon.  Many fine pieces of weaponry line the walls.\n\r");
		swrite("~9\n\r(~15W~9)  Buy/Sell weapons\n\r(~15A~9)  Buy/Sell armour\n\r(~15L~9)  Leave\n\r");
		com = command("WAL",3);
		switch(com)
		{
		case 'W':{do{
				od_printf("`bright white`\n\r(B)  Buy weapons\n\r(S)  Sell weapons\n\r(A)  Ammo\n\r(Q)  Quit\n\n\r");
				chj = command("BSAQ",4);
				switch(chj)
				{
				case 'B':{buyweapons(1000,40, 85, 130, 300, 400, 15, 40, 140, 550);
				   break;}
				case 'S':{sellweapons(1000,15, 35, 80, 120, 200, 5, 25, 70, 250);
				   break;}
				case 'A':{ammo();
				   break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'A':{do{
				od_printf("`bright white`\n\r(B)  Buy armour\n\r(S)  Sell armour\n\r(Q)  Quit\n\r\n");
				chj = command("BSQ",3);
				switch(chj)
				{
				case 'B':{buyar(35, 110, 300, 30, 100, 260);
				    break;}
				case 'S':{sellar(10, 30, 120, 320, 10, 40, 120, 320);
				    break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'G':{swrite("~2\n\rThe guild hall is the only non-wooden building in town.  As with all the\n\r");
		swrite("other guild halls, it looks like an old castle.\n\r");
		guild();
		break;}
case 'V':{od_printf("`bright red`\n\rThere is only one farm in this town.  Compared to other farms, this\n\r");
		od_printf("looks like an easy target...\n\r");
		unifarm();
		break;
		}
case 'R':{fur(20,15,80);
		break;}
case 'H':{char jjk;
		while(1){
		od_printf("`bright magenta`\n\rThe trainer's shop is just a little house made of trees.  Probably chopped\n\r");
		if(od_get_key(FALSE) == 13) break;
		od_printf("down and put together by the trainer himself.\n\r");
		if(od_get_key(FALSE) == 13) break;
		od_printf("`bright blue`\n\r(T)  Talk to trainer\n\r(G)  Get training\n\r(L)  Leave\n\r");
		break;}
		com = command("TGL",3);
		switch(com)
		{
		case 'T':{talkburktrain();
				break;}
		case 'G':{do{
				od_printf("`bright cyan`\n\rWhat would you like me to help you with?\n\r");
				od_printf("`bright white`\n\r(S)  Strength\n\r(D)  Dexterity\n\r(A)  Aim\n\r(H)  Hit Points\n\r(Q)  Quit\n\r");
				od_printf("`bright cyan`I charge 100 coins, what do you say?");
				jjk = command("SDAHQ",6);
				if(jjk != 'Q')
					{if(data[user].coins < 100)
						{od_printf("`red`\n\rYou don't have enough coins.\n\r");}
					else if(edata.trainpts < 1)
						{od_printf("`red`\n\rYou need to gain a skill level.\n\r");}
					else{switch(jjk)
						{
						case 'S':{if(data[user].strength > 19)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you gain strength.\n\r");
								data[user].strength += 2;
								if(data[user].strength>20)
									data[user].strength=20;
								edata.trainpts--;
								data[user].coins -= 100;
								break;
								}
						case 'A':{if(data[user].aim > 19)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you with your aim.\n\r");
								data[user].aim += 2;
								if(data[user].aim>20)
									data[user].aim=20;
								edata.trainpts--;
								data[user].coins -= 100;
								break;
								}
						case 'H':{if(data[user].totalhit > 199)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you with your power.\n\r");
								data[user].totalhit += 10;
								if(data[user].totalhit>200)
									data[user].totalhit=200;
								edata.trainpts--;
								data[user].coins -= 100;
								break;
								}
						case 'D':{if(data[user].dex > 19)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you with your agility.\n\r");
								data[user].dex += 2;
								if(data[user].dex>20)
									data[user].dex=20;
								edata.trainpts--;
								data[user].coins -= 100;
								break;
								}
						}
						}
					}
				else break;
				}while(1);
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
}
}while(data[user].town == 'B');
}

void sus(void)
{
char com;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("sussenex.ans","TMGHWISFBDEAR",TRUE);
			od_set_cursor(1,1);
		  od_printf("`white brown`1`white black`1");
		  od_set_cursor(1,1);
		  od_clr_scr();

			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("TMGHWISFBDEAR");
			od_printf("\n\r\n");
			}
		break;
		}
case 'D':{docks();
		break;}
case 'S':{od_printf("`bright red`\n\rThe stables are extremely large but extremely smelly.  However, the stalls\n\r");
		od_printf("are very well crafted and polished daily.\n\r");
		stables();
		break;}
case 'E':{od_printf("`bright cyan`\n\rThe mountains are extremely cold and the ground is covered with snow.\n\r");
		getreturn();
		mountain();
		break;}
case 'T':{swrite("~9\n\rThe tavern is very clean and nice-looking.  The owner must be an artist, too.\n\r");
		swrite("Each table looks like someone spent hours working on them.  The bar in the\n\r");
		swrite("back looks like it is washed off and polished daily.  This is a nice place.\n\r");
		swrite("~3\n\r");
		swrite("(~15J~3)  Join conversation at bar\n\r(~15T~3)  Talk to Bartender\n\r(~15O~3)  Order a meal\n\r");
		swrite("(~15G~3)  Get a drink\n\r(~15H~3)  Down some Dragon's Blood\n\r");
		swrite("(~15B~3)  Back door to mountains\n\r(~15L~3)  Leave\n\r");
		com = command("JTOGLBH",7);
		switch(com)
		{
		case 'J':{tavlog();
				break;}
		case 'T':{od_printf("`magenta`\n\r\"There is not a whole lot to talk about now, is there, %s?  I know you came\n\r",dia);
				od_printf("here because of Scorion and his axes.  So, I'm afraid I can't be much help.\n\r");
				od_printf("Maybe you should try the innkeeper.\n\r");
				od_printf("But if you would like a dinner for thirty coins or a drink for five.  I can\n\r");
				od_printf("help you there.\"\n\r");
				break;
				}
		case 'O':{taverno(30);
				break;}
		case 'G':{taverng(5, 10);
				break;}
		case 'H':{taverng(5,600);
				break;}
		case 'B':{if(mountain()==FALSE)
					data[user].location='Z';
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'R':{fur(30,10,100);
		break;}
case 'F':{fields();
		break;}
case 'I':{swrite("~13\n\rThe Inn is very clean and all tables, chairs, counters, the floor, the walls,\n\r");
		swrite("and the ceiling is very artistic.  A crystal chandalier hangs elegantly from\n\r");
		swrite("the high ceiling.~9\n\n\r");
		swrite("(~15T~9)  Talk to innkeeper\n\r(~15G~9)  Get a room\n\r(~15L~9)  Leave\n\r");
		com = command("TGL",3);
		switch(com)
		{
		case 'T':{od_printf("`magenta`\n\r\"I suppose you came here to see Scorion and his magnificent axes.  Well,\n\r");
				od_printf("he kinda stays out of the lights.  Alot of people come here to get an axe or\n\r");
				od_printf("just to see what all the fuss is about.  You look like the sort that would\n\r");
				od_printf("be interested in buying one so I will tell you how to find him.  Go to the\n\r");
				od_printf("Artisan's square.  There is a sewer where he keeps his shop.  He doesn't\n\r");
				od_printf("live there but he has his shop there so he can get some time to work.  He\n\r");
				od_printf("isn't exactly an unknown.\"  At the sqaure, press (!).\n\r");
				break;}
		case 'G':{innb(25);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'M':{od_printf("`bright green`\n\rThe market place is extremely crowded.  You fight your way through the mob\n\r");
		od_printf("to a small foodstand.\n\r");
		do{
		od_printf("`green`\n\r(B)  Buy food\n\r(S)  Sell food\n\r(L)  Leave\n\r");
		com = command("BSL",3);
		switch(com)
		{
		case 'B':{marketbuy(15,10,10);
				break;}
		case 'S':{marketsell(5, 4, 4);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(com != 'L');
		break;
		}
case 'G':{guild();
		break;}
case 'A':{od_printf("`bright red`\n\rThe Artisan's Square is nothing like you imagined it.  There are no artists\n\r");
		od_printf("that make anything that might be of use to you.\n\r");
		od_printf("`bright blue`\n\r(L)  Leave\n\r");
		com = od_get_answer("L!");
		switch(com)
		{
		case 'L':{data[user].location = 'Z';
				break;}
		case '!':{od_printf("`bright blue`\n\rYou find a sewer and walk deep into it until you find a small door that\n\r");
				od_printf("says \"Scorion's shop : Don't come in with out reason.\"  You decide you have\n\r");
				od_printf("a reason and go on in.\n\r");
				getreturng();
				talkscorion();
				break;}
		}
		break;}
case 'W':{char chj;
		swrite("~13\n\rThis large building sells and buys both weapons and armour.  It looks\n\r");
		swrite("like it does a horrible business, probably because of Scorion.");
		swrite("~15\n\r\n(~9W~15)  Buy/Sell weapons\n\r(~9A~15)  Buy/Sell armour\n\r(~9L~15)  Leave\n\r");
		com = command("WAL",3);
		switch(com)
		{
		case 'W':{do{
				od_printf("`bright white`\n\r(B)  Buy weapons\n\r(S)  Sell weapons\n\r(A)  Ammo\n\r(Q)  Quit\n\n\r");
				chj = command("BSAQ",4);
				switch(chj)
				{
				case 'B':{buyweapons(1500,50, 100, 160, 330, 500, 30, 60, 200, 650);
				   break;}
				case 'S':{sellweapons(500,30, 50, 100, 300, 440, 10, 35, 100, 300);
				   break;}
				case 'A':{ammo();
				   break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'A':{do{
				od_printf("`bright white`\n\r(B)  Buy armour\n\r(S)  Sell armour\n\r(Q)  Quit\n\r\n");
				chj = command("BSQ",3);
				switch(chj)
				{
				case 'B':{buyar(40, 120, 320, 40, 120, 300);
				    break;}
				case 'S':{sellar(10, 40, 140, 350, 10, 45, 150, 350);
				    break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'B':{od_printf("`bright magenta`\n\rYou find a nice smooth rock to sit on just a little ways from the docks.\n\r");
		fishing();
		break;}
case 'H':{char jjk;
		swrite("~13\n\rThis is certainly a horrible looking building compared to all the others\n\r");
		swrite("of the town.  A very strong man stands ready to train you.\n\r");
		swrite("~9\n\r(~15T~9)  Train\n\r(~15L~9)  Leave\n\r");
		com = command("TL",2);
		switch(com)
		{
		case 'T':{do{
				od_printf("`bright cyan`\n\rWhat would you like me to help you with?\n\r");
				od_printf("`bright white`\n\r(S)  Strength\n\r(A)  Aim\n\r(H)  Hit Points\n\r(Q)  Quit\n\r");
				od_printf("`bright cyan`I charge 75 coins, what do you say?");
				jjk = command("SAHQ",4);
				if(jjk != 'Q')
					{if(data[user].coins < 75)
						{od_printf("`red`\n\rYou don't have enough coins.\n\r");}
					else if(edata.trainpts < 1)
						{od_printf("`red`\n\rYou need to gain a skill level.\n\r");}
					else{switch(jjk)
						{
						case 'S':{if(data[user].strength > 19)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you gain strength.\n\r");
								data[user].strength += 2;
								if(data[user].strength>20)
									data[user].strength = 20;
								edata.trainpts--;
								data[user].coins -= 75;
								break;
								}
						case 'A':{if(data[user].aim > 19)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you with your aim.\n\r");
								data[user].aim += 2;
								if(data[user].aim>20)
									data[user].aim=20;
								edata.trainpts--;
								data[user].coins -= 75;
								break;
								}
						case 'H':{if(data[user].totalhit > 199)
									{od_printf("`red`\n\rYou don't need this training.\n\r");
									break;}
								od_printf("`bright red`\n\rHe helps you with your power.\n\r");
								data[user].totalhit += 10;
								if(data[user].totalhit > 200)
									data[user].totalhit=200;
								edata.trainpts--;
								data[user].coins -= 75;
								break;
								}
						}
						}
					}
				else break;
				}while(1);
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
}
}while(data[user].town == 'S');
}

void midtrim(void)
{
char com;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("midtrim.ans","DEWC",TRUE);
			od_set_cursor(1,1);
			  od_printf("`white brown`1`white black`1");
			  od_set_cursor(1,1);
			  od_clr_scr();
			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("DEWC");
			od_printf("\n\n\r");
			}
		break;
		}
case 'D':{docks();
		break;}
case 'E':{data[user].town = 'E';
		data[user].location = 'Z';
		break;}
case 'W':{data[user].town = 'W';
		data[user].location = 'Z';
		break;}
case 'C':{castle();
		break;}
}
}while(data[user].town == 'M');
}

void easttrim(void)
{
char com;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("easttrim.ans","ETRSVMFHD",TRUE);
			od_set_cursor(1,1);
		  od_printf("`white brown`1`white black`1");
		  od_set_cursor(1,1);
		  od_clr_scr();
			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("ETRSVMFHD");
			od_printf("\n\n\r");
			}
		break;
		}
case 'E':{swrite("~13\n\rYou slowly trek into the frozen mountainlands.  You find it hard to think\n\r");
		swrite("that there would be anything that could survive in this cold weather.\n\r");
		getreturn();
		mountain();
		break;}
case 'T':{swrite("~9\n\rThis is by far the most crowded tavern in the land.  The Bar is covered with\n\r");
		swrite("glasses and spilt whiskey.  Most of the patrons are laughing and having a\n\r");
		swrite("good time.  Others are sprawled out on the floor either by fights or \n\r");
		swrite("excessive drinking.\n\r");
		swrite("~3\n\r(~15J~3)  Join conversation at bar\n\r(~15T~3)  Talk to Innkeeper\n\r(~15G~3)  Get a room\n\r(~15D~3)  Get a drink\n\r");
		swrite("(~15H~3)  Down some Dragon's Blood\n\r(~15O~3)  Order a meal\n\r");
		swrite("(~15B~3)  Back door to mountains\n\r(~15L~3)  Leave\n\r");
		com = command("JTBHGDOL",8);
		switch(com)
		{
		case 'J':{tavlog();
				break;}
		case 'T':{talkeastinn();
				break;}
		case 'G':{innb(20);
				break;}
		case 'D':{taverng(12,10);
				break;}
		case 'H':{taverng(12,600);
				break;}
		case 'O':{taverno(25);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		case 'B':{if(mountain() == FALSE)
					data[user].location='Z';
				break;}
		}
		break;}
case 'R':{fur(40,10,180);
		break;}
case 'S':{od_printf("`bright blue`\n\rThe stables is by far the largest you've ever seen.\n\r");
		stables();
		break;}
case 'V':{swrite("~9\n\rPicking out a farm to visit is not a hard job.  There is only one.  The\n\r");
		swrite("farm is huge.  You are walking down a dirt road beside the crops and the crop\n\r");
		swrite("extends as far as you can see.  There is a mansion for a farmhouse.\n\r");
		unifarm();
		break;}
case 'M':{swrite("~10\n\rThe Market Place is extremely crowded and you can't seem to walk around\n\r");
		swrite("without bumping into some shoulders.  It is hard to pick out a cheap merchant\n\r");
		swrite("stand so you just pick out one.\n\r");
		do{
		od_printf("`cyan`\n\r(B)  Buy food\n\r(S)  Sell food\n\r(L)  Leave\n\r");
		com = command("BSL",3);
		switch(com)
		{
		case 'B':{marketbuy(25, 20, 10);
				break;}
		case 'S':{marketsell(15, 10, 10);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(data[user].location == 'M');
		break;
		}
case 'F':{fields();
		break;}
case 'H':{od_printf("`bright magenta`\n\rThe size of the training hall really surprises you.  There is only one\n\r");
		od_printf("trainer and it looks like the building is his house, too.\n\r");
		do{
		od_printf("`bright blue`\n\r(T)  Talk to trainer\n\r(S)  Spar with trainer\n\r(L)  Leave\n\r");
		com = command("TSL",3);
		switch(com)
		{
		case 'T':{talketrain();
				break;}
		case 'S':{if(data[user].coins < 70)
					{od_printf("`red`\n\rYou don't have 70 coins.\n\r");}
				else if(edata.trainpts < 1)
					{od_printf("`red`\n\rYou need another skill level.\n\r");}
				else if(data[user].totalhit == 200)
					{od_printf("`bright red`\n\rYou don't need this training.\n\r");}
				else{od_printf("`bright blue`\n\rYou place 70 coins in the trainer's hands and he starts his training.  It\n\r");
				od_printf("consists of excercises that seem to make you in better shape.\n\r\n");
				sleep(1);
				od_printf("Later, you fell ready to go out and take on some more monsters.\n\r");
				data[user].coins -= 70;
					edata.trainpts -= 1;
					data[user].totalhit += 10;
					if(data[user].totalhit > 200)
						data[user].totalhit = 200;
				}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(com != 'L');
		break;
		}
case 'D':{data[user].location = 'Z';
		data[user].town = 'M';
		break;}
}
}while(data[user].town == 'E');
}

void westtrim(void)
{
char com;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("westtrim.ans","MOWAHRGBFIS",TRUE);
			od_set_cursor(1,1);
		  od_printf("`white brown`1`white black`1");
		 od_set_cursor(1,1);
		 od_clr_scr();
			playsave('A',0,2);}
		else{maps();
			data[user].location = od_get_answer("MOWAHRGBFT");
			od_printf("\n\n\r");}
		break;
		}
case 'M':{data[user].location = 'Z';
		data[user].town = 'M';
		break;}
case 'O':{if(edata.progress > 5)
			{od_printf("`bright blue`\n\rThe building is closed down.\n\r");
			getreturng();
			data[user].location = 'Z';
			break;}
		od_printf("`bright blue`\n\rThe officer building is a bare stone room with one uniformed man behind a\n\r");
		od_printf("desk.");
		od_printf("`cyan`\n\n\r(T)  Talk to administrator\n\r(L)  Leave\n\r");
		com = command("TL",2);
		switch(com)
		{
		case 'T':{if(edata.progress < 5)
					{od_printf("`bright red`\n\r\"I'm sorry but I am extremely busy.\"\n\r");
					break;}
				else if(edata.progress == 5)
					{od_printf("`bright red`\n\r\"I heard about you and you must die.\"\n\r");
					getreturng();
					monread("stryline.dat",9,4);
					monster.run = 0;
					if(monattack() == FALSE)
						{data[user].location = 'Z';
						break;}
					if(monattack() == FALSE)
						{data[user].location = 'Z';
						break;}
					od_printf("`bright red`\n\r\"OK! OK!  Ha Ha!  I don't know why I didn't go ahead and tell you.  The key\n\r");
					od_printf("is in the Dragon's Lair in Burkshire!  Good luck!  I hid it there when I\n\r");
					od_printf("found out about Pomdirguna.  Ha Ha!\"\n\r");
					edata.progress = 6;
					break;}
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;}
case 'A':{swrite("~13\n\rThe Armour shop is clean but old.  Various kinds of antique armour hang\n\r");
		swrite("from the walls and many fine new pieces of armour lie on the floor.\n\r");
		swrite("~11\n\r(~15B~11)  Buy armour\n\r(~15S~11)  Sell armour\n\r(~15L~11)  Leave\n\r");
		com = command("BSL",3);
		switch(com)
		{
		case 'B':{buyar(35, 120, 280, 35, 95, 280);
			    break;}
		case 'S':{sellar(12, 40, 150, 380, 12, 45, 140, 480);
			    break;}
		case 'L':{data[user].location = 'Z';
			   break;}
		}
		break;}
case 'W':{swrite("~13\n\rThis stone building is decorated in all kinds of arms.  A man in overalls is\n\r");
		swrite("working over a fire in the back.  Another man stands ready to assist you.\n\r\n");
		swrite("~5(~15B~5)  Buy weapons\n\r(~15S~5)  Sell weapons\n\r(~15A~5)  Ammo\n\r(~15L~5)  Leave\n\n\r");
		com = command("BSAL",4);
		switch(com)
		{
		case 'B':{buyweapons(1300,50, 90, 160, 350, 550, 25, 50, 200, 650);
			break;}
		case 'S':{sellweapons(800,35, 50, 100, 300, 450, 15, 40, 100, 300);
			break;}
		case 'A':{ammo();
			break;}
		case 'L':{data[user].location = 'Z';
			break;}
		}
		break;
		}
case 'H':{swrite("~9\n\rThe training hall looks more like a showroom than anything else.  It is\n\r");
		swrite("decorated with various trophies and antique weapons.  A young man looks like\n\rthe only trainer available.\n\r");
		swrite("~13\n\r(~15T~13)  Talk to man\n\r(~15S~13)  Spar with man\n\r(~15L~13)  Leave\n\r");
		com = command("TSL",3);
		switch(com)
		{
		case 'T':{od_printf("`magenta`\n\r\"Well, I don't like to talk much but I can train for 80 coins.  I will show\n\r");
				od_printf("you how to dodge attacks and how to shoot a bow better.  All these trophies I\n\r");
				od_printf("got with just a single shot.\"\n\r");
				break;}
		case 'S':{if(data[user].coins < 80)
					od_printf("`red`\n\rYou don't have enough money.\n\r");
				else if(edata.trainpts < 1)
					od_printf("`red`\n\rYou need to gain a skill level.\n\r");
				else if((data[user].aim == 20) || (data[user].dex == 20))
					od_printf("`red`\n\rYou don't need this training.\n\r");
				else{od_printf("`bright blue`\n\rYou give the 80 coins to the trainer and he first shows you how to shoot\n\r");
					od_printf("a bow and arrow at a moving target.  Then you spend hours sparring with him.\n\r");
					sleep(1);
					od_printf("You feel much better after the lesson.\n\r");
					data[user].coins -= 80;
					edata.trainpts--;
					data[user].dex++;
					data[user].aim++;
					}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;}
case 'R':{fur(45,15,200);
		break;}
case 'G':{swrite("~2\n\rThe Guild is a bueatiful wooden building decorated with all kinds of weapons\n\r");
		swrite("and shields.  Many adventurers crowd the small building.\n\r");
		guild();
		break;}
case 'B':{fishing();
		break;}
case 'F':{fields();
		break;}
case 'I':{swrite("~12\n\rAn old woman stands behind a counter waiting to assist you.\n\r");
		swrite("~15\n\r(~9T~15)  Talk to innkeeper\n\r(~9G~15)  Get a room\n\r(~9L~15)  Leave\n\r");
		com = command("TGL",3);
		switch(com)
		{
		case 'T':{od_printf("`bright magenta`\n\r\"How are you?  Do you like Trimmail?  It's a nice city if you like big city\n\r");
				od_printf("life.  There is a little beach to fish on and a bueatiful town square.  Well,\n\r");
				od_printf("if you would like a room, I can fix you up for only forty coins.\"\n\r");
				break;
				}
		case 'G':{innb(40);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;}
case 'S':{od_clr_scr();
		swrite("~7You squeeze through the small gutter and make your way into the sewers.  The\n\r");
		swrite("smell is unbearable but you continue to explore.  There should be something to\n\r");
		swrite("kill done here.");
		getreturn();
		odd();
		break;
		}
}
}while(data[user].town == 'W');
}

void hayward(void)
{
char com;
do{
switch(data[user].location)
{
case 'V':{
	  swrite("~9\n\n\rWell away from your once thriving homestead, you come to a nice\n\r");
	  swrite("well worked farm.  Although, once you may have once visited this farm to\n\r");
	  swrite("swap some seeds or talk about the daily farm work, your life is in your head\n\r");
	  swrite("now and you plan to keep it no matter what.\n\r");
	  unifarm();
	  break;
	  }
case 'G':{
	  swrite("~10\n\rThe Guild Hall in this town looks like an old small converted castle.\n\r");
	  swrite("The Guild Sign hangs over the door like an advertisement, and the large\n\r");
	  swrite("thick wooden doors look as if they are used to hold something out.\n\r");
	  guild();
	  break;
	  }
case 'M':{
	  swrite("~2\n\rThe Market Place is crowded and loud.  After searching for\n\r");
	  swrite("awhile, you find a stand that sells foods.  The Merchant behind the\n\r");
	  swrite("stand is a rough old lady.  As you approach, a smile comes to her\n\r");
	  swrite("pitiful face.\n\r");
	  do{
	  swrite("~5\n\r(~15B~5)  Buy food\n\r(~15S~5)  Sell food\n\r(~15T~5)  Talk to the Merchant\n\r(~15L~5)  Leave\n\r");
	  com = command("TBSL",4);
	  switch(com)
	  {
	  case 'T':{talkoldmerchant();
		    break;}
	  case 'B':{marketbuy(15, 8, 5);
		    break;}
	  case 'S':{marketsell(10, 5, 4);
		    break;}
	  case 'L':{data[user].location = 'Z';
		   break;}
	  }
	  }while(com != 'L');
	  break;
	  }
case 'B':{od_printf("\n\r`bright red`You stroll down to the sandy beach and\n\r");
	  od_printf("take a seat on one of the only rocks close to the shore.\n\r");
	  fishing();
	  data[user].location = 'Z';
	  break;}
case 'D':{docks();
	  break;
	  }
case 'H':{
	  swrite("~13\n\rThe Training Hall is nothing but a large room devoted to sparing.  You see\n\r");
	  swrite("several other wouldbe adventurers practicing with trainers.  You see a trainer\n\rleaning against the wall next to the door.\n\r");
	  swrite("~11\n\r(~15T~11)  Talk to weapons master\n\r(~15S~11)  Spar with weapons master\n\r(~15L~11)  Leave\n\r");
	  com = command("TSL",3);
	  switch(com)
	  {
	  case 'T':{talkhaymaster();
		    break;}
	  case 'S':{haywardspar();
		   break;}
	  case 'L':{data[user].location = 'Z';
		   break;}
	  }
	  break;
	  }
case 'A':{
	  swrite("~13\n\rThe Armour shop is dirty and old.  Various kinds of antique armour hang\n\r");
	  swrite("from the walls and many fine new pieces of armour lie on the floor.\n\r");
	  swrite("~11\n\r(~15B~11)  Buy armour\n\r(~15S~11)  Sell armour\n\r(~15L~11)  Leave\n\r");
	  com = command("BSL",3);
	  switch(com)
	  {
	  case 'B':{buyar(25, 100, 250, 25, 75, 250);
		    break;}
	  case 'S':{sellar(15, 45, 160, 400, 15, 50, 150, 500);
		    break;}
	  case 'L':{data[user].location = 'Z';
		   break;}
	  }
	  break;}
case 'W':{
	  swrite("~13\n\rThis wooden building is decorated in all kinds of arms.  A man in overalls is\n\r");
	  swrite("working over a fire in the back.  Another man stands ready to assist you.\n\r\n");
	  swrite("~11(~15B~11)  Buy weapons\n\r(~15S~11)  Sell weapons\n\r(~15T~11)  Talk to man\n\r(~15A~11)  Ammo\n\r(~15L~11)  Leave\n\r");
	  com = command("BSTAL",5);
	  switch(com)
	  {
	  case 'B':{buyweapons(1200,50, 90, 160, 350, 550, 25, 50, 200, 650);
		break;}
	  case 'S':{sellweapons(1000,35, 50, 100, 300, 450, 15, 40, 100, 300);
		break;}
	  case 'T':{talksmith();
		break;}
	  case 'A':{ammo();
		break;}
	  case 'L':{data[user].location = 'Z';
		break;}
	  }
	  break;
	  }
case 'E':{
	  swrite("~1\n\rThe forest is very large but not thickly wooded.  There seems to be no paths\n\r");
	  swrite("or animal trails to follow.  In fact, you wonder if there are animals to\n\r");
	  swrite("kill in this peaceful forest.  But as you start getting deeper into it, you\n\r");
	  swrite("start to get an erie feeling that many eyes are stareing at you.\n\r");
	  forest();
	  break;}
case 'T':{
	  swrite("~11\n\rYou enter the Hayward Farmer's Tavern.  The tavern is basically\n\r");
	  swrite("one large room.  A long wooden bar spans the far wall and many round tables\n\r");
	  swrite("fill the hardwood floor.  The tavern doesn't seem like it does a booming\n\r");
	  swrite("business, but it definitely isn't on the verge of backruptcy.\n\r");
	  do{
	  swrite("~3\n\r(~15J~3)  Join conversation at bar\n\r(~15T~3)  Talk to the Bartender\n\r(~15O~3)  Order a meal\n\r");
	  swrite("(~15G~3)  Get a drink\n\r(~15H~3)  Down some Dragon's Blood\n\r(~15S~3)  Sit down at a table\n\r");
	  swrite("(~15B~3)  Back door to forest\n\r(~15L~3)  Leave\n\r");
	  com = command("JTOHGSBL",8);
	  switch(com)
	  {
	  case 'J':{tavlog();
			break;}
	  case 'T':{od_printf("\n\r`bright magenta`\"I heard what happened to your farm.  Sorry, %s.  The King is indeed a\n\r", dia);
		    od_printf("a foul ruler.  Too bad there is no army large enough to beat him.  Perhaps,\n\r");
		    od_printf("we don't need an army.  Maybe one person, a hero, could dethrone him.  Wouldn't\n\r");
		    od_printf("that be nice?  Well, would you like a drink or something to ease the grief?  I\n\r");
		    od_printf("have some fine wine for ten coins.  Also, for only thirty coins, you may have\n\r");
		    od_printf("a dinner plate, and eat till you can't eat any more.  Just let me know.\"\n\r");
		    break;}
	  case 'O':{taverno(30);
		    break;}
	  case 'H':{taverng(4,600);
			break;}
	  case 'G':{taverng(4, 8);
			break;}
	  case 'S':{od_printf("\n\r`bright blue`You walk to a table where three patrons are carrying on a conversation.  You\n\r");
		    od_printf("ask them if you can join them, and they welcome your company.\n\r");
		    talkhaywardpatrons();
		    break;}
	  case 'B':{if(foresthunt() == FALSE)
				data[user].location = 'E';
			break;}
	  case 'L':{data[user].location = 'Z';
		    break;}
	  }
	  }while((com != 'L') && (com != 'B'));
	  break;
	  }
case 'S':{od_printf("`brown`\n\rThis public stable is extremely smelly.  A small booth at the\n\r");
	  od_printf("entrance handles all the horse sells and stall rentals.\n\r");
	  stables();
	  break;}
case 'F':{fields();
	  break;
	  }
case 'I':{
		do{
	  swrite("~12\n\rThe old, dirty inn looks very poor and bare.  Behind a counter stands\n\r");
	  swrite("a bald man with a full gray beard.  He stares at you waiting for you to speak.\n\n\r");
	  swrite("~9(~15G~9) Get a room\n\r(~15T~9) Talk to Innkeeper\n\r(~15L~9) Leave\n\r");
	  com = command("GTL",3);
	  switch(com)
	  {
	  case 'G':{innb(10);
		    break;
		    }
	  case 'T':{od_printf("`bright magenta`\n\n\r\"Times are tough right now.  No one is wanting to visit this little island\n\r");
		    od_printf("anymore.  Not only is it dull and far away from everything but now\n\r");
		    od_printf("that the king is taking away all the land from the farmers, noone comes\n\r");
		    od_printf("here anymore for good food and prices from the Market.  I heard that\n\r");
		    od_printf("Pomdirgunua is also having some problems with the king's troops.\n\r");
		    od_printf("Good luck in your journeys!\"\n\r");
		    break;}
	  case 'L':{data[user].location = 'Z';
		    break;}
	  }
	  }while(data[user].location == 'I');
	  break;
	  }
case 'Z':{if(data[user].ANSI == TRUE)
		  {
	  od_control.od_page_pausing = FALSE;
	  data[user].location = od_hotkey_menu("hayward.ans","VGHMAWTSIFEDB",TRUE);
	  od_set_cursor(1,1);
	  od_printf("`white brown`1`white black`1");
	  od_set_cursor(1,1);
	  od_clr_scr();
	  playsave('A',0,2);
	  break;}
	  else{maps();
		  data[user].location = od_get_answer("VGHMAWTSIFEDB");
		  od_printf("\n\n\r");
		  }
	  break;
	  }
}
}while(data[user].town == 'H');
}

void den(void)
{
char com;
do{
switch(data[user].location)
{
case 'Z':{if(data[user].ANSI == TRUE)
			{
		data[user].location = od_hotkey_menu("den.ans","GSHFWMCTBJDO",TRUE);
	  od_set_cursor(1,1);
	  od_printf("`white brown`1`white black`1");
	  od_set_cursor(1,1);
	  od_clr_scr();
		playsave('A',0,2);
		break;}
		else{maps();
			data[user].location = od_get_answer("GFHWMCTBJDSO");
			od_printf("\n\n\r");
			break;
		}
		}
case 'F':{fields();
		break;}
case 'G':{swrite("~10\n\rIf it wasn't for the Guild sign hanging above the door, you would not\n\r");
		swrite("have guessed this to be a Guild hall.  Rather, it looks like an old\n\rluxerious mansion.\n\r");
		guild();
		break;
		}
case 'H':{swrite("~9\n\rThe training hall is packed with all types of people, mostly pirates.  The\n\r");
		swrite("few trainers that are not with someone already stare at you waiting.\n\r");
		swrite("~13\n\r(~15P~13)  Talk with pirate trainer\n\r(~15M~13)  Talk with arms master\n\r(~15T~13)  Train with pirate trainer\n\r");
		swrite("(~15A~13)  Train with arms master\n\r(~15L~13)  Leave\n\r");
		com = command("PMTAL",5);
		switch(com)
		{
		case 'P':{od_printf("\n\r\"My training costs 75 coins.  I can make you very nimble.\"\n\r");
				break;}
		case 'M':{talkdenmaster();
				break;}
		case 'T':{if(data[user].coins < 75)
					{od_printf("`red`\n\rYou don't have 75 coins.\n\r");}
				else if(edata.trainpts < 1)
					{od_printf("`red`\n\rYou need another skill level.\n\r");}
				else if(data[user].dex == 20)
					{od_printf("`bright red`\n\rYou don't need this training.\n\r");}
				else{od_printf("`bright blue`\n\rYou give the pirate 75 coins and he takes you through a number of streches\n\r");
					od_printf("then shows you how to better dodge attacks and land your own attacks.\n\r");
					sleep(1);
					od_printf("Soon, you feel like you could fight with more dexterity.\n\r");
					data[user].coins -= 75;
					edata.trainpts -= 1;
					data[user].dex += 2;
					if(data[user].dex > 20)
						data[user].dex = 20;
					}
				break;}
		case 'A':{if(data[user].coins < 45)
					{od_printf("`red`\n\rYou don't have 45 coins.\n\r");}
				else if(edata.trainpts < 1)
					{od_printf("`red`\n\rYou need to gain a skill level.\n\r");}
				else if((data[user].strength == 20) || (data[user].totalhit == 200))
					{od_printf("`bright red`\n\rYou don't need this training.\n\r");}
				else{od_printf("`bright blue`\n\rYou place 45 coins in the master's hand and he take you through some muscle\n\r");
				od_printf("building routines.  After that, he has a woman give you a massage and then\n\r");
				od_printf("beats on every inch of your skin making it tough.\n\r");
				data[user].coins -= 45;
				data[user].strength += 1;
				data[user].totalhit += 5;
				if(data[user].totalhit > 200)
					data[user].totalhit = 200;
				edata.trainpts -= 1;
				}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'D':{docks();
		break;}
case 'S':{fur(35,8,150);
		break;}
case 'J':{swrite("~10\n\rIt is extremely hard to believe that this bueatiful jungle could be home\n\r");
		swrite("to anything that might put up a fight.  Manmade paths are all throughout\n\r");
		swrite("making a cobweb maze.\n\r");
		forest();
		break;
		}
case 'O':{od_printf("`bright blue`\n\rThe oceanside is rocky and steep,\n\r");
		od_printf("You climb down and take a seat.\n\r");
		fishing();
		data[user].location = 'Z';
		break;}
case 'W':{char chj;
		swrite("~13\n\rThis large building sells and buys both weapons and armour.  It looks\n\r");
		swrite("like it does a booming business.\n\r");
		swrite("~15\n\r(~9W~15)  Buy/Sell weapons\n\r(~9A~15)  Buy/Sell armour\n\r(~9L~15)  Leave\n\r");
		com = command("WAL",3);
		switch(com)
		{
		case 'W':{do{
				od_printf("`bright white`\n\r(B)  Buy weapons\n\r(S)  Sell weapons\n\r(A)  Ammo\n\r(Q)  Quit\n\n\r");
				chj = command("BSAQ",4);
				switch(chj)
				{
				case 'B':{buyweapons(1600,60, 110, 190, 370, 580, 35, 70, 250, 750);
				   break;}
				case 'S':{sellweapons(1000,40, 55, 105, 310, 460, 10, 30, 110, 310);
				   break;}
				case 'A':{ammo();
				   break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'A':{do{
				od_printf("`bright white`\n\r(B)  Buy armour\n\r(S)  Sell armour\n\r(Q)  Quit\n\r\n");
				chj = command("BSQ",3);
				switch(chj)
				{
				case 'B':{buyar(45, 130, 340, 50, 150, 330);
				    break;}
				case 'S':{sellar(10, 40, 140, 350, 5, 35, 100, 400);
				    break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'M':{
	  swrite("~2\n\rThe Market Place is crowded and loud.  After searching for\n\r");
	  swrite("awhile, you find a stand that sells foods.\n\r");
	  do{
	  swrite("~5\n\r(~15B~5)  Buy food\n\r(~15S~5)  Sell food\n\r(~15L~5)  Leave\n\r");
	  com = command("BSL",3);
	  switch(com)
	  {
	  case 'B':{marketbuy(18, 10, 10);
		    break;}
	  case 'S':{marketsell(10, 5, 5);
		    break;}
	  case 'L':{data[user].location = 'Z';
		   break;}
	  }
	  }while(com != 'L');
	  break;
	  }
case 'T':{swrite("~9\n\rThe design of the Pirate's Tavern reminds you of an actual pirate ship.  Many\n\r");
		swrite("pirates sit at tables.  In fact, it seems most everyone in the tavern is a\n\r");
		swrite("pirate, including the bartender.\n\r");
		do{
		swrite("~3\n\r(~15J~3)  Join conversation at bar\n\r(~15T~3)  Talk to the Bartender\n\r(~15O~3)  Order a meal\n\r");
		swrite("(~15G~3)  Get a drink\n\r(~15H~3)  Down some Dragon's Blood\n\r(~15S~3)  Sit down at a table\n\r(~15P~3)  Talk to Pirate\n\r");
		swrite("(~15R~3)  Get a room\n\r(~15B~3)  Back door to Jungle\n\r(~15L~3)  Leave\n\r");
		com = command("JTOGSPRLHB",10);
		switch(com)
		{
		case 'H':{taverng(10,600);
				break;}
		case 'J':{tavlog();
				break;}
		case 'T':{od_printf("`bright magenta`\n\r\"Howdy, new to The Den, aren't you?  Come for the Baths and Casino, Aye? \n\r");
				od_printf("Well, my Tavern and Inn is a good place to stay and to make the time go\n\r");
				od_printf("by if you have some bad luck in the Casino.  I can give you a drink for\n\r");
				od_printf("10 coins.  I'm sure it will make you fill better.  Dinner is 45, Rooms\n\r");
				od_printf("are 40 coins.\"\n\r");
				 break;}
		case 'O':{taverno(45);
				  break;}
		case 'G':{taverng(10, 10);
				  break;}
		case 'S':{talkdenpatrons();
				  break;}
		case 'P':{talkdenpir();
				  break;}
		case 'R':{innb(40);
				  break;}
		case 'B':{if(foresthunt() == FALSE)
					data[user].location = 'J';
				break;}
		case 'L':{data[user].location = 'Z';
				  break;}
		}
		}while((com != 'L') && (com != 'B'));
		break;
		}
case 'C':{int be, win;
		char bett, bettt, one, two;
		do{
		swrite("~9\n\rThe casinqo is crowded with all kinds of people from pirates to soldiers.\n\r");
		swrite("There are many games to play but the ones that catch your attention are\n\rRoulette, Dice, and the coin toss.\n\r");
		swrite("~13\n\r(~15R~13)  Roulette\n\r(~15D~13)  Dice\n\r(~15C~13)  Coin toss\n\r(~15L~13)  Leave\n\r");
		com = command("RDCL",4);
		switch(com)
		{
		case 'R':{be = bet();
				if(be == 0)
					break;
				od_printf("`magenta`\n\r\nWould you like to bet on Red or Black? (R/B) ");
				bett = od_get_answer("RB");
				if(bett == 'R')
					bett = 0;
				else bett = 1;
				od_printf("`magenta`\n\rEnter a number to bet on. (0-9) :  ");
				bettt = od_get_answer("0123456789");
				switch(bettt)
				{
				case '0':{bettt = 0;
						break;}
				case '1':{bettt = 1;
						break;}
				case '2':{bettt = 2;
						break;}
				case '3':{bettt = 3;
						break;}
				case '4':{bettt = 4;
						break;}
				case '5':{bettt = 5;
						break;}
				case '6':{bettt = 6;
						break;}
				case '7':{bettt = 7;
						break;}
				case '8':{bettt = 8;
						break;}
				case '9':{bettt = 9;
						break;}
				}
				one = random(2);
				two = random(10);
				od_printf("`bright magenta`\n\rThe wheel in spinning:  ");
				sleep(1);
				if(one == 0)
					od_printf("`red`%d",two);
				else od_printf("`gray`%d",two);
				if(one == bett)
					{win = (be + (be/5));
					if(two == bettt)
						{win += be;
						win += (be*5);
						}
					od_printf("`bright blue`\n\rYou win %d coins!\n\r",win);
					data[user].coins += win;
					coins();
					}
				else{od_printf("`bright red`\n\rYou lose");
					data[user].coins -= be;}
				break;
				}
		case 'D':{be = bet();
				if(be == 0)
					break;
				od_printf("`bright magenta`\n\n\rPick a number from 1 to 6:  ");
				bett = od_get_answer("123456");
				switch(bett)
				{
				case '1':{bett = 1;
						break;}
				case '2':{bett = 2;
						break;}
				case '3':{bett = 3;
						break;}
				case '4':{bett = 4;
						break;}
				case '5':{bett = 5;
						break;}
				case '6':{bett = 6;
						break;}
				}
				od_printf("`bright blue`\r\nThe dice is rolled:  ");
				sleep(1);
				one = (1 + random(6));
				od_printf("`magenta`%d",one);
				if(bett == one)
					{win = (be + (be*3));
					od_printf("`bright magenta`\n\rYou win %d coins!\n\r",win);
					data[user].coins += win;
					coins();
					}
				else{od_printf("`bright red`\n\rYou lose.\n\r");
					data[user].coins -= be;}
				break;
				}
		case 'C':{be = bet();
				if(be == 0)
					break;
				od_printf("`bright magenta`\n\n\rWould you like to bet on (H)eads or (T)ails?\n\r");
				bett = od_get_answer("HT");
				if(bett == 'H')
					bett = 0;
				else bett = 1;
				one = random(2);
				if(one == 0)
					{od_printf("`bright red`\n\rHeads\n\r");
					}
				else od_printf("`bright red`\n\rTails\n\r");
				if(one == bett)
					{win = (be + (be/5));
					od_printf("`bright cyan`You win %d coins.\n\r",win);
					data[user].coins += win;
					coins();
					}
				else{data[user].coins -= be;
					od_printf("`bright red`\n\rYou lose.\n\r");}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		if((com == 'R') || (com == 'D') || (com == 'C'))
			getreturng();
		}while(com != 'L');
		break;
		}
case 'B':{swrite("~11\n\rThe baths have many half-naked men and women.  There is a small bar in the\n\r");
		swrite("center of the building with baths all around.  Some are steaming and some\n\r");
		swrite("are as calm as a plain of glass.  Many men and women are embraced soaking in\n\r");
		swrite("the baths.\n\r");
		swrite("~9\n\r(~15G~9)  Get a drink\n\r(~15C~9)  Converse with bar patrons\n\r(~15S~9)  Talk to Silvia\n\r");
		swrite("(~15O~9)  Talk to Oliver\n\r(~15L~9)  Leave\n\r");
		com = command("GCSOL",5);
		switch(com)
		{
		case 'G':{taverng(35, 10);
				break;}
		case 'C':{converse();
				break;}
		case 'S':{silvia();
				break;}
		case 'O':{oliver();
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
}
}while(data[user].town == 'D');
}


void pom(void)
{
char com;
do{
switch(data[user].location)
{
case '/':{int gemhandle;
		gemhandle=eopen("sett.ing",20);
		read(gemhandle,setting,sizeof(struct settings));
		if(edata.progress == 7)
			{if(setting[0].gem == TRUE)
				{setting[0].gem=FALSE;
				lseek(gemhandle,0,SEEK_SET);
				write(gemhandle,setting,sizeof(struct settings));
				close(gemhandle);
				od_printf("`bright red`\n\rYou walk into a small field and a gem appears in your hand.\n\r");
				getreturng();
				edata.progress = 8;
				char bufff[70];
				sprintf(bufff,"%s has found the gem of destruction.");
				logwrite(bufff);}
			else{close(gemhandle);
				od_printf("`red`\n\rSomeone must have beaten you to it.\n\r");}
			}
		else{od_printf("`bright red`\n\rYou can't find the gem.\n\r");
			getreturng();
			}
		data[user].location = 'Z';
		break;
		}
case 'L':{swrite("~12\n\rSorry, in this version, the library is nothing but scenery.\n\r");
		getreturng();
		data[user].location = 'Z';
		break;}
case 'E':{swrite("~12\n\rThe mystic power of this forest seems to tear at your insides.  Bushes\n\r");
		swrite("move around and every tree seems to have a face.  You walk deep into this\n\r");
		swrite("bright forest looking for something that might put up a fight.\n\r");
		forest();
		break;
		}

case '~':{swrite("~9\n\rThe fairy city is extremely easy to find.  The fairies are little green\n\r");
		swrite("people that stand to your waste.  You can't tell any of them apart.\n\r");
		swrite("~15\n\r(T)  Talk to Fairies\n\r(L)  Leave\n\r");
		com = command("TL*",2);
		switch(com)
		{
		case 'T':{if((edata.proscor == 1) || (edata.proscor == 2))
					{od_printf("`bright red`\n\r\"We can give you fairy dust if you destroy the Fire Hydra.  Push *.\"\n\r");
					edata.proscor = 2;}
				else if(edata.proscor == 3)
					{od_printf("`bright red`\n\r\"Thank you!  Here is the dust.\"");
					edata.proscor = 4;
					}
				else{od_printf("`bright red`\n\r\"We've done all we can.\"");}
				break;
				}
		case '*':{if(edata.proscor == 2)
					{monread("stryline.dat",9,7);
					if(monattack() == TRUE)
						edata.proscor = 3;
					}
				else od_printf("`bright cyan`\n\rYou don't know what you are doing.\n\r");
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'D':{docks();
		break;
		}
case 'G':{guild();
		break;}
case 'H':{swrite("~9\n\rThere is but one trainer in the small but stocked training hall.  He gives\n\r");
		swrite("you a friendly \"Hello\" and waits for you to reply.\n\r");
		swrite("~12\n\r(~15T~12)  Talk to armsmaster\n\r(~15S~12)  Spar with armsmaster\n\r(~15L~12)  Leave\n\r");
		com = command("TSL",3);
		switch(com)
		{
		case 'T':{talkpommaster();
				break;}
		case 'S':{if(data[user].coins < 55)
					{od_printf("`red`\n\rYou don't have 55 coins.\n\r");}
				else if(edata.trainpts < 1)
					{od_printf("`red`\n\rYou need another skill level.\n\r");}
				else if((data[user].strength == 20) || (data[user].aim == 20))
					{od_printf("`bright red`\n\rYou don't need this training.\n\r");}
				else{od_printf("`bright blue`\n\rThe armsmaster spars with you for a while then takes you to a small track\n\r");
					od_printf("outside the building.  After running for many hours, you fill much stronger.\n\r");
					od_printf("Next the trainer takes you to a small archery range and shows you some ways\n\r");
					od_printf("to make your long-range weaponry more on target.\n\r");
					od_printf("`bright cyan`\n\r\"I have shown you much in this day, but it is a fraction of your need.\"\n\r");
					data[user].strength++;
					data[user].aim++;
					data[user].coins -= 55;
					edata.trainpts--;
					}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'S':{swrite("~12\n\rThe cleanness of the stables surprises you.  There is not one bit\n\r");
		swrite("of horse waste on the ground.  Not even any hay strung about.\n\r");
		stables();
		break;
		}
case 'R':{fur(30,10,150);
		break;
		}
case 'I':{swrite("~12\n\rThe Inn looks new and completely clean just like everything else in town.\n\r");
		swrite("A bearded innkeeper stands behind a desk ready to help you.\n\r");
		swrite("~9\n\r(~15S~9)  Sit at a table\n\r(~15G~9)  Get a room\n\r(~15D~9)  Get a drink\n\r(~15B~9)  Back door to forest\n\r");
		swrite("(~15T~9)  Talk to Innkeeper\n\r(~15L~9)  Leave\n\r");
		com = command("SGBTDL",6);
		switch(com)
		{
		case 'S':{tavlog();
				break;}
		case 'G':{innb(30);
				break;}
		case 'T':{od_printf("`bright magenta`\n\r\"Times are tough right now in Pomdirgunua.  Soldiers have been taking land\n\r");
				od_printf("away from the farmers and merchants.  There used to be two taverns in town,\n\r");
				od_printf("the soldiers took one of them and simply burned it down.  The other tavern\n\r");
				od_printf("is now their headquarters, it seems.  I would stay away from there if I\n\r");
				od_printf("were you.  Well, if you would like a room, I charge 30 coins.  I also have\n\r");
				od_printf("some fine ale for 5 coins.\"\n\r");
				break;
				}
		case 'D':{taverng(5,10);
				break;}
		case 'L':{data[user].location = 'Z';
				break;
				}
		case 'B':{if(foresthunt()==FALSE)
					data[user].location='E';
				break;}
		}
		break;
		}
case 'T':{begin:
		if(edata.progress < 4)
		{od_printf("`bright blue`\n\rThe Tavern (or what was once a tavern) is crowded with soldiers and weapons.\n\r");
		do{
		od_printf("`bright magenta`\n\r(S)  Take a close look at soldiers\n\r(T)  Talk to soldier\n\r(A)  Attack soldiers\n\r(L)  Leave\n\r");
		com = command("STAL",4);
		switch(com)
		{
		case 'S':{od_printf("`magenta`\n\rMost of the soldiers are wearing chain armour and a green uniform with a\n\r");
				od_printf("red stripe.  The others are wearing plate armour and a green uniform with a\n\r");
				od_printf("blue stripe.  These you recognize to be Royal Soldiers of the Castle\n\r");
				od_printf("Trimmail.  The Royal soldiers are the same that burned your home.\n\r");
				break;
				}
		case 'T':{talkpomsol();
				break;
				}
		case 'A':{if(edata.progress < 3)
					{od_printf("`bright blue`\n\rYou draw your weapon and before you know it, the soldiers are upon you using\n\r");
					od_printf("a fighting tactic you have never seen before.  They easily beat you to the\n\r");
					od_printf("ground.  Luckily they let you up and throw you out of the tavern.\n\r");
					getreturng();
					data[user].location = 'Z';}
				else{monread("stryline.dat",9,4);
					monster.run = 0;
					if(monattack() == FALSE)
						{data[user].location = 'Z';
						break;}
					getreturng();
					if(monattack() == FALSE)
						{data[user].location = 'Z';
						break;}
					getreturng();
					od_printf("`bright red`\n\rAll the soldiers flee from your might!\n\r");
					edata.progress++;
					char solbuf[70];
					sprintf(solbuf,"%s has beaten the soldiers.",data[user].alias);
					logwrite(solbuf);
					goto begin;}
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;
				}
		}
		}while(data[user].location == 'T');
		}
		else{
		od_printf("`bright blue`\n\rThe Tavern is now empty with but one soldier waiting.\n\r");
		do{
		od_printf("`bright magenta`\n\r(T)  Talk to Royal Soldier\n\r(L)  Leave\n\r");
		com = command("TL",2);
		switch(com)
		{
		case 'T':{talkr();
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(com != 'L');
		}
		break;
		}
case 'W':{char chj;
		swrite("~13\n\rThis large building sells and buys both weapons and armour.  It looks\n\r");
		swrite("as if it hasn't had any business in years.  The smith sits and stares at\n\ryou.  He looks surprised you are here.\n\r");
		swrite("~15\n\r(~9W~15)  Buy/Sell weapons\n\r(~9A~15)  Buy/Sell armour\n\r(~9L~15)  Leave\n\r");
		com = command("WAL",3);
		switch(com)
		{
		case 'W':{do{
				od_printf("`bright white`\n\r(B)  Buy weapons\n\r(S)  Sell weapons\n\r(A)  Ammo\n\r(Q)  Quit\n\n\r");
				chj = command("BSAQ",4);
				switch(chj)
				{
				case 'B':{buyweapons(1200,40, 90, 150, 330, 540, 15, 50, 200, 650);
				   break;}
				case 'S':{sellweapons(1000,25, 40, 105, 260, 400, 10, 30, 140, 360);
				   break;}
				case 'A':{ammo();
				   break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'A':{do{
				od_printf("`bright white`\n\r(B)  Buy armour\n\r(S)  Sell armour\n\r(Q)  Quit\n\r\n");
				chj = command("BSQ",3);
				switch(chj)
				{
				case 'B':{buyar(35, 100, 300, 30, 60, 250);
				    break;}
				case 'S':{sellar(15, 45, 150, 370, 10, 50, 150, 400);
				    break;}
				case 'Q':{break;}
				}
				}while(chj != 'Q');
				break;
				}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		break;
		}
case 'V':{od_printf("`blue`\n\rYou sneak through the few farms there are in Pomdirgunua.  You finally\n\r");
		od_printf("find one that is worthy of breaking into.\n\r");
		unifarm();
		break;
		}
case 'F':{fields();
		break;}
case 'M':{od_printf("`bright green`\n\rThis Market Place is not near as crowded as the others in Trimmail.  There\n\r");
		od_printf("also isn't very many merchants here.  You easily find the cheapest.\n\r");
		do{
		od_printf("`cyan`\n\r(B)  Buy food\n\r(S)  Sell food\n\r(L)  Leave\n\r");
		com = command("BSL",3);
		switch(com)
		{
		case 'B':{marketbuy(15,8,8);
				break;}
		case 'S':{marketsell(10,5,5);
				break;}
		case 'L':{data[user].location = 'Z';
				break;}
		}
		}while(com != 'L');
		break;
		}
case 'B':{fishing();
		data[user].location = 'Z';
		break;}
case 'Z':{if(data[user].ANSI == TRUE)
			{data[user].location = od_hotkey_menu("pomdir.ans","~BMFVWTRSHGDIEL/",TRUE);
	  od_set_cursor(1,1);
	  od_printf("`white brown`1`white black`1");
	  od_set_cursor(1,1);
	  od_clr_scr();
			playsave('A',0,2);
			break;}
		else{maps();
			data[user].location = od_get_answer("B~MFIVWTRSHGDEL/");
			od_printf("\n\n\r");
			break;}
		}

}
}while(data[user].town == 'P');
}



char command(char *opp,int amm)
{
char command;
int kam;
coagain:
od_printf("`bright magenta`");
od_printf("\n\r(`bright blue`%d `bright magenta`turns),(`bright blue`/`bright magenta`=Quick Stats,`bright blue`\\`bright magenta`=Stats) Command>  ",edata.turns);
command = od_get_answer("\\?/=QWERTYUIOPLKJHGFDSAZXCVBNM123456789+)(* ~\n\r");
od_putch(command);
switch(command)
{
case '/':{qstat();
		goto coagain;
		}
case '\\':{stats();
		goto coagain;
		}
case '+':{if(random(2) == 1)
			{od_printf("\n\r`red`Five coins found!\n\r");
			data[user].coins += 5;}
		else{od_printf("\n\r`red`You drop five coins.\n\r");
			if(data[user].coins >= 5)
				data[user].coins -= 5;}
		break;
		}
case 10:
case 13:
case '=':
case '(':
case ')':
case '*':
case '~':break;
default:{for(kam = 0;kam<amm;kam++)
			{
			if(opp[kam] == command)
				break;
			}
		if(kam==amm)
			{od_printf("\n\r`magenta`Redisplay menu? [`bright blue`N`magenta`/`brightblue`y`magenta`]");
			command=od_get_answer("Y\n\rN");
			if(command == 'Y');
			else	goto coagain;
			}

		}
}

return command;
}


void listusers(void)
{
int screenlength;
screenlength = od_control.user_screen_length;
screenlength--;
int screencounter = 0;
char first; //True if hasn't reached first
first = TRUE;
int count;
unsigned int expcount;
char endname;
od_clr_scr();
playsave('A',0,3);
od_printf("`bright blue`Name                          Skill level         Location  Experience\n\r");
od_printf("`bright yellow`-------------------------------------------------------------------------------\n\r");
expcount=0;
for(count=0;count<setting[0].num_users;count++)
	{
	if(data[count].exp>expcount)
		expcount=data[count].exp;
	}
for(;expcount>0;expcount-=1)
{
for(count=0;count<setting[0].num_users;count++)
{
if(data[count].exp == expcount)
	{if(first == TRUE)
		{od_printf("`bright white on blue`");
		od_clr_line();
		}
	else	od_printf("`bright magenta on black`");
	endname = FALSE;
	if((od_get_key(FALSE) == 13) || (od_get_key(FALSE) == 32))
		break;
	if(count == 23)
		getreturng();
	for(int cc = 0;cc < 30;cc++)
		{if(endname == TRUE)
			od_putch(' ');
		else{
		if((data[count].alias[cc] == 32) || (data[count].alias[cc] == '\0'))
			{od_putch(' ');
		if(data[count].alias[cc] == '\0')
			endname = TRUE;}
		else od_putch(data[count].alias[cc]);
		}
		}
	if(first == TRUE)
		{od_printf("`bright red on blue`");
		}
		else	od_printf("`bright red`");
	if(data[count].skill > 9)
		od_printf("         %d      ",data[count].skill);
	else od_printf("          %d      ",data[count].skill);
	if(first == TRUE)
		od_printf("`bright magenta on blue`");
	else	od_printf("`bright magenta`");
	if(data[count].hitpts == 0)
		{if(first == TRUE)
				od_printf("`black on blue`     ");
		else od_printf("     ");
		od_printf("  `black on red`DEAD");
		}
	else{
	switch(data[count].town)
	{
	case 'H':{od_putch(' ');
			od_putch(' ');
			od_printf("  Hayward");
			break;}
	case 'E':{od_putch(' ');
			od_printf("  Trimmail");
			break;}
	case 'W':{od_putch(' ');
			od_printf("  Trimmail");
			break;}
	case 'S':{od_putch(' ');
			od_printf("  Sussenex");
			break;}
	case 'B':{od_printf("  Burkshire");
			break;}
	case 'T':{od_putch(' ');
			od_putch(' ');
			od_putch(' ');
			od_putch(' ');
			od_putch(' ');
			od_putch(' ');
			od_printf("  Tiw");
			break;}
	case 'D':{od_putch(' ');
			od_putch(' ');
			od_printf("  The Den");
			break;}
	case 'P':{od_printf("Pomdirgunua");
			break;}
	default:{od_putch(' ');
			od_putch(' ');
			od_printf("  unknown");
			break;}
	}
	}
	if(first == TRUE)
		{od_printf("`bright white on blue`");
		}
	else od_printf("`bright white`");
	if(data[count].exp>9999)
		od_printf("       %u",data[count].exp);
	else if(data[count].exp>999)
		od_printf("        %u",data[count].exp);
	else if(data[count].exp>99)
		od_printf("         %u",data[count].exp);
	else if(data[count].exp>9)
		od_printf("          %u",data[count].exp);
	else od_printf("           %u",data[count].exp);
	if(first == TRUE)
		{od_printf("`red blue`");
		first=FALSE;}
	else{od_printf("`red`");}
	if((data[count].online != -1) && (data[count].online != 32000))
		{od_printf(" ONLINE");}
	od_printf("\n\r");
	screencounter++;
			if(screencounter == screenlength){
				getreturng();
				screencounter = 0;}

	}

	}
	}
getreturng();
}

int turncheck(int a)
{
//1-fish,2-forest,3-mountains,4-farm
if(edata.hunger == 'D')
	{od_printf("`red`\n\rYOU ARE DYING OF HUNGER!\n\r");
	getreturng();
	data[user].hitpts -= 2;
	life();
	}
if(edata.turns<1)
	{
	od_printf("`red`\n\rSorry, no turns left.\n\r");
	return 0;
	}
switch(a)
{
case 1:{if(edata.fish < 1)
		{
		od_printf("`red`\n\rSorry, no fishing turns left.\n\r");
		return 0;
		}
		else{edata.fish--;}
	break;
	}
case 2:{if(edata.forest < 1)
		{
		od_printf("`red`\n\rSorry, no hunting turns left.\n\r");
		return 0;
		}
		else{edata.forest--;}
	break;
	}
case 3:{if(edata.mountains < 1)
		{
		od_printf("`red`\n\rSorry, no mountain hunting left.\n\r");
		return 0;
		}
		else{edata.mountains--;}
	break;
	}
case 4:{if(edata.farm < 1)
		{
		od_printf("`red`\n\rSorry, no farming turns left.\n\r");
		return 0;
		}
		else{edata.farm--;}
	break;
	}
}

edata.turns--;
if((edata.turns<=5) && (edata.turns>0))
	{
	int aga;
	aga = edata.turns;
	aga--;
	od_printf("\n\r`red`Warning: %d turns left!\n\r",aga);
	return 1;
	}
return 1;
}



void stables(void)
{
char com;
do{
swrite("~11\n\r(~15B~11)  Buy Horse\n\r(~15M~11)  Move to another city\n\r(~15L~11)  Leave\n\r");
com = command("BML",3);
if(com == 'B')
	{if(edata.i4 == TRUE)
		{od_printf("`bright blue`\n\rSorry, I don't buy old horses and you already have one!\n\n\r");
		}
	else{od_printf("`bright blue`\n\rI can sell you a horse for 350 coins.  Deal? [Y/N]");
		char yyy;
		yyy = od_get_answer("YN");
		if(yyy == 'Y')
			{if(data[user].coins<350)
				{od_printf("`red`\n\rBut you don't have enough coins!\n\r");}
			else{od_printf("`bright magenta`\n\rYou now own a great horse!\n\r");
				edata.i4 = TRUE;
				data[user].coins -= 350;}
			}
		else{od_printf("`red`\n\rThen why did you ask?!\n\r");}
	}
}
else if(com == 'M')
	{if(data[user].town == 'H')
		{od_printf("`red`\n\rIf you want to move from this island, use the docks.\n\r");
		}
	else if(edata.i4 == FALSE)
		{od_printf("`red`\n\rYou need to get a horse first.\n\r");}
	else{move(0);}
	}
else if(com == 'L')
	{data[user].location = 'Z';
	}
}while(com != 'L');
}


int farm(void)
{
int akl;
do{
swrite("~11\n\r(~15B~11)  Break into farmhouse\n\r(~15S~11)  Slaughter farm animals\n\r(~15L~11)  Leave\n\n\r");
od_printf("\r`bright blue`Farming turns left`bright red`:  `bright white`%d",edata.farm);
akl = command("BSL",3);
}while((akl != 'B') && (akl != 'S') && (akl != 'L'));
return akl;
}

int farmbreak(void)
{
randomize();
int breaki;
breaki = random(6);
int breakr;
switch(data[user].skill)
{
case 1:{if(breaki == 0)
	  breakr = TRUE;
	else breakr = FALSE;
	break;
	}
case 2:{if((breaki == 0) || (breaki == 1))
	breakr = TRUE;
	else breakr = FALSE;
	break;
	}
case 3:{if((breaki>-1) && (breaki<3))
	breakr = TRUE;
	else breakr = FALSE;
	break;
	}
case 4:{if((breaki>-1) && (breaki<4))
	breakr = TRUE;
	else breakr = FALSE;
	break;
	}
case 5:{if((breaki>-1) && (breaki<5))
	breakr = TRUE;
	else breakr = FALSE;
	break;
	}
default:{if((breaki>-1) && (breaki<6))
	breakr = TRUE;
	else breakr = FALSE;
	break;
	}
}
return breakr;
}

void forest(void)
{
char com50;
do{
playsave('A',0,1);
swrite("~5\n\r(~15H~5)  Hunt\n\r(~15S~5)  Search the forest\n\r(~15L~5)  Leave\n\r");
com50 = command("HSL",3);
if(com50 == 'H')
	{if(newp == TRUE)
		{if(od_hotkey_menu("horseman"," ",FALSE) == '\0')
			while(od_get_key(TRUE) == 0);
		}
	if(foresthunt() == TRUE)
		com50='L';
	}
else if(com50 == 'S')
	forestsearch();
else if(com50 == 'L')
	data[user].location = 'Z';
}while(com50 != 'L');

}

char foresthunt(void)
{
od_clr_scr();
char k;
do{
od_printf("\n\n\r`bright blue`What would you like to do, warrior?\n\r");
od_printf("\n\r`magenta`(`bright white`C`magenta`)  Continue hunting\n\r");
od_printf("(`bright white`R`magenta`)  Refresh at the tavern\n\r");
od_printf("(`bright white`Q`magenta`)  Quick mode        ");
if(edata.qf==TRUE)
	od_printf("`bright white`ON");
else od_printf("`bright white`OFF");
od_printf("\n\r`magenta`(`bright white`L`magenta`)  Leave\n\r");
od_printf("\n\r`bright blue`Hunting turns left`bright red`:  `bright white`%d        `bright blue`[`bright red`C`bright blue`]",edata.forest);
k = command("\n\rQWERTYUIOPLKJHGFDSAZXCVBNM",28);
switch(k)
{
case 'A':
case 'D':
case 'M':
case 'T':
case 'H':{eventsplit(k);
		break;}
case 'R':{if(data[user].town == 'P')
			data[user].location = 'I';
		else	data[user].location = 'T';
		break;}
case 'Q':{if(edata.qf==TRUE)
			edata.qf=FALSE;
		else edata.qf=TRUE;
		break;
	    }
case 10:
case 13:
case 'C':{
	if(turncheck(2) == 0)
		break;
	int jl;
	int ad;
	jl = random(10);
	ad = random(3);
	if(ad == 2)
		ad = 0;
	switch(data[user].town)
	{
	case 'H':{if(newp == TRUE)
			{
			monread("hayward.dat",10,3);
			}
			else{
				if(data[user].skill == 1)
					{
					switch(random(4))
						{
						case 0:{monread("hayward.dat",10,3);
								break;}
						case 1:{monread("hayward.dat",10,4);
								break;}
						case 3:
						case 2:{monread("hayward.dat",10,8);
								break;}
						}
					}
				else{
				if(ad == 0)
					monread("hayward.dat", 10, jl);
				else{jl = random(5);
					monread("hayward2.dat", 5, jl);}
				}
			}
			break;
			}
	case 'D':{monread("theden.dat",10,jl);
			break;}
	case 'P':{jl = random(6);
			monread("pomdir.dat",6,jl);
			break;}
	case 'B':{jl = random(9);
			monread("deep.dat",9,jl);
			break;}
	}
	monattack();
	if(data[user].dex == 1)
		{od_printf("\n\r`bright white`After that fight, the thought of `bright red`training `bright white`comes to your head.\n\r");
		}
	newp = FALSE;
	break;
	}
case 'L':{data[user].location = 'Z';
	break;}
}
}while((k != 'L') && (k != 'R'));
if(k == 'R')
 return TRUE;
else return FALSE;
}

char mountain(void)
{
od_clr_scr();
randomize();
char k;
do{
if(edata.i6 == FALSE)
	{od_printf("`bright cyan`\n\rThe cold air of the high altitude is eating at your skin.\n\r");
	od_printf("You don't think you can stand this well enough to fight.\n\r");}
od_printf("`bright blue`\n\rWhat would you like to do,  `bright magenta`%s`bright blue`?\n\r",data[user].alias);
od_printf("\n\r`magenta`(`bright white`C`magenta`)  Continue\n\r");
od_printf("(`bright white`R`magenta`)  Refresh at tavern\n\r");
od_printf("(`bright white`H`magenta`)  Healing well\n\r");
od_printf("(`bright white`L`magenta`)  Leave\n\r");
od_printf("\n\r`bright blue`Mountain hunting turns left`bright red`:  `bright white`%d        `bright blue`[`bright magenta`C`bright blue`]",edata.mountains);
k = command("\n\rCRTHL",7);
switch(k)
{
case 'T':{if(data[user].town=='T')
			tiashi();
		break;}
case 'R':{data[user].location = 'T';
		break;
		}
case 10:
case 13:
case 'C':{
	if(edata.i6 == FALSE)
		{data[user].hitpts -= 45;
		if(data[user].hitpts < 1)
			{od_printf("`bright cyan`\n\rThe cold takes your energy away.  Then your life.\n\r");
			getreturng();
			data[user].hitpts = 0;
			od_exit(0,FALSE);}
		}
	if(turncheck(3) == 0)
		break;
	if(mountainevent() == TRUE)
		break;
	int jl;
	switch(data[user].town)
	{
	case 'E':{jl = random(8);
			monread("eastm.dat",8,jl);
			break;}
	case 'S':{jl = random(7);
			monread("sussenex.dat",7,jl);
			break;}
	case 'B':{jl = random(5);
			monread("burk2.dat",5,jl);
			break;}
	case 'T':{jl = random(9);
			monread("tiw.dat",9,jl);
			break;}
	}
	monattack();
	break;
	}
case 'H':{healingwell();
		break;}
case 'L':{data[user].location = 'Z';
	break;}
}
}while((k != 'L') && (k != 'R'));
if(k=='R')
	return TRUE;
else return FALSE;
}

char life(void)
{
char abb;
if(data[user].hitpts<1)
	{if(newp2 == TRUE)
		{od_clr_scr();
		od_printf("`bright red`In your death sleep, two fairies appear.  They give your life back to you.\n\r");
		od_printf("\"Your life is important, this time you will be protected.\"\n\r");
		data[user].hitpts = data[user].totalhit;
		getreturng();
		od_clr_scr();
		abb=TRUE;
		newp2 = FALSE;}
	else{
	data[user].hitpts = 0;
	od_clr_scr();
	od_printf("`red`You fall to the ground.  Then you see your\n\r");
	od_printf("dead bloody body below you as you rise up.\n\r");
	getreturng();
	od_exit(12,FALSE);
	abb=FALSE;}
	}
if(abb==TRUE)
	return TRUE;
else return FALSE;
}

void disfight(int es, int ed, int eh, int eth, char *ew, char *en)
{
if(edata.qf == TRUE)
{
od_printf("`bright cyan`\n\r(`bright blue`A`bright cyan`)ttack        (D)efend        (R)un        (S)tats        redra(W)\n\r");
od_printf("`bright magenta`");
od_printf("YOU:   `bright blue`<`bright cyan`M`bright blue`>`bright white`agic                     %s:\n\r",en);
od_printf("`bright blue`Str`bright red`:  `bright white`%d                        `bright red`Str`bright blue`:  `bright white`%d  \n\r",data[user].strength,es);
od_printf("`bright blue`Dex`bright red`:  `bright white`%d                        `bright red`Dex`bright blue`:  `bright white`%d  \n\r",data[user].dex,ed);
od_printf("`bright blue`Hit`bright red`:  `bright white`%d/%d                    `bright red`Hit`bright blue`:  `bright white`%d/%d  \n\r",data[user].hitpts,data[user].totalhit,eh,eth);
od_printf("`bright blue`Special:`bright white`  %d                    `bright red`Noted Weapon`bright blue`:  `bright white`%s  \n\r\n",edata.spec,ew);
od_printf("`bright blue` >");
}
else{
od_set_cursor(17,7);
od_printf("`bright blue`Special Points left`bright red`:  `bright white`%d  ",edata.spec);
od_set_cursor(19,15);
od_printf("`bright white`%d  ",data[user].strength);
od_set_cursor(20,15);
od_printf("%d  ",data[user].dex);
od_set_cursor(21,14);
od_printf("%d`bright cyan`/`bright white`%d  ",data[user].hitpts,data[user].totalhit);
od_set_cursor(22,10);
od_printf("`bright blue`");
od_printf("%s",data[user].stype);
od_set_cursor(17,42);
od_printf("`bright magenta`%s  ",en);
od_set_cursor(19,55);
od_printf("`bright white`%d  ", es);
od_set_cursor(20,55);
od_printf("%d  ", ed);
od_set_cursor(21,55);
od_printf("%d`bright cyan`/`bright white`%d  ",eh,eth);
od_set_cursor(22,57);
od_printf("`bright blue`%s",ew);
}
}


void sellweapons(int wsword,int ssword, int mace, int morn, int lsword, int axe, int sl, int sp, int bow, int cross)
{
char sweap[15];
char lweap[15];
int amount;
strcpy(sweap,data[user].stype);
switch(data[user].weaponshort)
{
case 2:amount=ssword;break;
case 3:
case 4:amount=mace;break;
case 5:
case 6:amount=morn;break;
case 7:
case 8:amount=lsword;break;
case 9:
case 10:amount=axe;break;
case 11:
case 12:
default:
case 13:amount=wsword;break;
}

char yu;
if(data[user].weaponshort == 1)
	{od_printf("`bright blue`\n\r\nSorry, I don't deal in daggers.\n\n\r");
	}
else{
od_printf("`bright blue`\n\rI will buy your %s for %d coins.\n\r`cyan`Deal? ",sweap,amount);
yu = od_get_answer("YN");
if(yu == 'Y')
	{
	od_printf("`bright red`\n\n\rYou just agreed to sell your %s for %d.  Right?\n\n\r",sweap,amount);
	yu = od_get_answer("YN");
	if(yu == 'Y')
		{data[user].weaponshort = 1;
		strcpy(data[user].stype,"Dagger");
		data[user].coins += amount;
		coins();
		}
	}
}
switch(data[user].weaponlong)
{
default:
case 6:{
	amount = sl;
	break;}
case 10:{
	amount = sp;
	break;}
case 20:{
	amount = bow;
	break;}
case 30:{
	amount = cross;
	break;}
}
strcpy(lweap,data[user].ltype);
if(data[user].weaponlong != 0){
od_printf("\n\n\r`bright cyan`I will buy your %s for %d coins.  Deal? ",lweap,amount);
yu = od_get_answer("YN");
if(yu == 'Y')
	{
	od_printf("`bright red`\n\n\rYou just agreed to sell your %s for %d.  Right?\n\n\r",lweap,amount);
	yu = od_get_answer("YN");
	if(yu == 'Y')
		{data[user].weaponlong = 0;
		strcpy(data[user].ltype,"none");
		data[user].coins += amount;
		coins();
		}
	}
}
}


void buyweapons(int wsword,int ssword, int mace, int morn, int lsword, int axe, int sl, int sp, int bow, int cross)
{
mace+=50;
morn+=250;
lsword+=350;
axe+=520;
wsword+=1600;
od_clr_scr();
beginagain:
od_printf("`bright magenta`Short range\n\r");
od_printf("`magenta`");
od_printf("-----------------------------------\r");
od_printf("\n`bright white`");
od_printf("0.  White Sword                 %d\n\r",wsword);
od_printf("\n`bright cyan`");
od_printf("1.  Short Sword                 %d\n\r",ssword);
od_printf("2.  Mace                        %d\n\r",mace);
od_printf("3.  Morningstar                 %d\n\r",morn);
od_printf("4.  Long Sword                  %d\n\r",lsword);
od_printf("5.  Axe                         %d\n\r",axe);
od_printf("`bright magenta`\n\rLong range\n\r");
od_printf("`magenta`");
od_printf("-----------------------------------\n\r");
od_printf("`bright cyan`");
od_printf("6.  Slingshot                   %d\n\r",sl);
od_printf("7.  Spear                       %d\n\r",sp);
od_printf("8.  Bow                         %d\n\r",bow);
od_printf("9.  Crossbow                    %d\n\r",cross);
od_printf("F.  Forget it\n\r");
od_printf("\n\r`bright blue`Gold`bright red`:  `bright white`%u",data[user].coins);
od_printf("`cyan`\n\rWhich would you like to buy?  ");
char nn;
nn = od_get_answer("0123456789F");
if((nn == '1')||(nn == '2')||(nn == '3')||(nn== '4')||(nn == '5')||(nn == '0'))
	{if((data[user].weaponshort != 0) && (data[user].weaponshort != 1))
		{od_printf("`bright red`\n\rYou already have a short-range weapon.\n\r");
		goto beginagain;}
	}
	else if(nn != 'F')
		{if(data[user].weaponlong != 0)
			{od_printf("`bright red`\n\rYou already have a long-range weapon.\n\r");
			goto beginagain;}
		}

switch(nn)
{
case '0':{if(data[user].coins < wsword)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rUpon the touch of your new `bright white`White Sword`bright red` you can feel the sacred\n\r");
	od_printf("power flow from your hand all through your body.  You feel stronger!\n\r");
	data[user].weaponshort = 9;
	strcpy(data[user].stype,"White Sword");
	data[user].coins -= wsword;
	data[user].strength++;
	break;
	}
case '1':{if(data[user].coins < ssword)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	 od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	 data[user].weaponshort = 2;
	 strcpy(data[user].stype,"Short Sword");
	 data[user].coins -= ssword;
	 break;
	 }
case '2':{if(data[user].coins < mace)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	 od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	 data[user].weaponshort = 3;
	 strcpy(data[user].stype,"Mace");
	 data[user].coins -= mace;
	 break;
	 }
case '3':{if(data[user].coins < morn)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponshort = 5;
	strcpy(data[user].stype,"Morning Star");
	data[user].coins -= morn;
	break;
	}
case '4':{if(data[user].coins < lsword)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponshort = 6;
	strcpy(data[user].stype,"Long Sword");
	data[user].coins -= lsword;
	break;
	}
case '5':{if(data[user].coins < axe)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponshort = 7;
	strcpy(data[user].stype,"Axe");
	data[user].coins -= axe;
	break;
	}
case '6':{if(data[user].coins < sl)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponlong = 8;
	strcpy(data[user].ltype,"Slingshot");
	data[user].coins -= sl;
	break;
	}
case '7':{if(data[user].coins < sp)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponlong = 10;
	strcpy(data[user].ltype,"Spear");
	data[user].coins -= sp;
	break;
	}
case '8':{if(data[user].coins < bow)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponlong = 20;
	strcpy(data[user].ltype,"Bow");
	data[user].coins -= bow;
	break;
	}
case '9':{if(data[user].coins < cross)
		{od_printf("`red`\n\rYou don't have enough coins.");
		break;}
	od_printf("`bright red`\n\rYou hold your new weapon.\n\r");
	data[user].weaponlong = 30;
	strcpy(data[user].ltype,"Crossbow");
	data[user].coins -= cross;
	break;
	}
case 'F':{break;}
}

}

void ammo(void)
{
int num;
int price, number;
char numstr[3];
number = (30 - data[user].ammo);
if(data[user].weaponlong == 0)
	{od_printf("\n\r`red`You have no weapon to buy ammo for!\n\r");}
else{ammoagain:
	od_printf("\n\r`magenta`You buy pellets for Slingshots, more spears, arrows for bows, and\n\r");
	od_printf("bolts for Crossbows.  Ammo is five coins.  You have %u coins.  ",data[user].coins);
	od_printf("\n\rYou can carry %d more ammo.",number);
	od_printf("\n\rHow many would you like? 0-%d ",number);
	od_input_str(numstr,2,47,58);
	num = atoi(numstr);
	od_printf("%d",num);
	price = (num*5);
	if(price>data[user].coins)
	{od_printf("`red`\n\rYou don't have enough coins.\n\r");
	}
	else{number = data[user].ammo + num;
	  if(number > 30)
		{od_printf("`red`\n\rYou can't carry that many.\n\r");
		goto ammoagain;}
	  data[user].ammo += num;
	  data[user].coins -= price;
	  }
	}
}

int bet(void)
{
char num[3];
int number, betmax;
if(data[user].coins < 100)
	betmax = data[user].coins;
else betmax = 100;
betagain:
od_printf("`bright magenta`\n\rHow much would you like to bet?  0-%d ",betmax);
od_input_str(num,4,47,58);
number = atol(num);
if((number < 0) || (number > 100))
	{od_printf("`red`\n\rHouse limits bet to 100 coins.\n\r");
	goto betagain;}
if(number > data[user].coins)
	{od_printf("`red`\n\rYou don't have that many coins.\n\r");
	goto betagain;}

return number;
}

void haywardspar(void)
{
if(edata.trainpts < 1)
	{od_printf("`red`\n\rYou have to gain another skill level.\n\r");
	}
else if(data[user].coins < 50)
	{od_printf("`red`\n\rYou don't have 50 coins.\n\r");
	}
else if(data[user].strength == 20)
	{od_printf("`bright blue`\n\rYou don't need training.\n\r");}
else if(data[user].dex == 20)
	{od_printf("`bright blue`\n\rYou don't need training.\n\r");}
else{
	od_printf("`bright blue`\n\rYou place 50 coins in the weapons master's hands and...\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"On garde!\"  yells the master as he starts attacking you with a sword.\n\r");
	od_printf("The skill of the trainer is impressive as he easily has you beat.  He keeps\n\r");
	od_printf("all his blows from hitting you and soon you are able to block a few.\n\r");
	sleep(1);
	od_printf("`bright blue`\"I have taught you how to defend yourself better while also building\n\r");
	od_printf("your strength.  Should you come back, I may not want to go another round.\"\n\r");
	data[user].coins -= 50;
	if(data[user].strength == 1)
		{data[user].strength+=2;
		data[user].dex+=2;
		data[user].totalhit=40;
		edata.spec+=1;
		edata.spectotal+=1;}
	else{
	data[user].strength += 1;
	data[user].dex += 1;
	edata.trainpts -= 1;}
	getreturng();
	}
}

void sellar(int lar, int car, int par, int dar, int sws, int ws, int bs, int ds)
{
char ar[15];
int amount, samount;
char ans;
switch(data[user].armor)
{
case 1:{
	amount = lar;
	break;}
case 2:{
	amount = car;
	break;}
case 3:{
	amount = par;
	break;}
default:{
	amount = dar;
	break;}
}
strcpy(ar,edata.artype);

char sh[15];
switch(edata.shtype)
{
case 'A':{strcpy(sh,"Small Wooden");
	   samount = sws;
	   break;}
case 'B':{strcpy(sh,"Wooden");
	   samount = ws;
	   break;}
case 'C':{strcpy(sh,"Brass");
	   samount = bs;
	   break;}
case 'D':{strcpy(sh,"Dragon-skin");
	   samount = ds;
	   break;}
}

if(data[user].armor == 0)
	{od_printf("`bright red`\n\rYou have no armour to sell.\n\r");
	}
else{
od_printf("`white`\n\rI will buy your `bright red`%s`white` Armour for`bright cyan` %d`white`.\n\rDeal?  ",ar,amount);
ans = od_get_answer("YN");
if(ans == 'Y')
	{od_printf("`bright red`\n\rThank you very much.\n\r");
	data[user].coins += amount;
	coins();
	data[user].armor = 0;
	strcpy(edata.artype,"none");
	}
else{od_printf("`bright red`\n\rMaybe some other time.\n\r");
	}
}
if(data[user].shield == 0)
	{od_printf("`bright red`\n\rYou have no sheild to sell.\n\r");
	}
else{
od_printf("`bright blue`\n\rI will buy your `bright red`%s`bright blue` shield for `bright cyan`%d`bright blue`.\n\rDeal?  ",sh,samount);
ans = od_get_answer("YN");
if(ans == 'Y')
	{od_printf("`bright red`\n\rThank you very much.\n\r");
	data[user].coins += samount;
	coins();
	data[user].shield = 0;
	edata.shtype = 'Z';
	}
else{od_printf("`bright red`\n\rMaybe some other time.\n\r");
	}
}
}


void buyar(int lar, int car, int par, int sws, int ws, int bs)
{
char ans;
od_clr_scr();
od_printf("`bright magenta`Body armour`bright red`:\n\r");
od_printf("`bright cyan`");
od_printf("\n\r1.  Leather Armour             `bright blue`%d\n\r",lar);
od_printf("`bright cyan`2.  Chain Armour               `bright blue`%d\n\r",car);
od_printf("`bright cyan`3.  Plate Armour               `bright blue`%d\n\r",par);
od_printf("\n\r`bright magenta`Defensive armour`bright red`:\n\r\n");
od_printf("`bright cyan`4.  Small Wooden Shield        `bright blue`%d\n\r",sws);
od_printf("`bright cyan`5.  Wooden Shield              `bright blue`%d\n\r",ws);
od_printf("`bright cyan`6.  Brass Shield               `bright blue`%d\n\n\r",bs);
od_printf("`bright cyan`F.  forget it\n\r");
od_printf("`bright blue`\n\rGold`bright red`:  `bright white`%u",data[user].coins);
od_printf("`bright magenta`\n\rWhich one would you like?  ");
ans = od_get_answer("123456F");
switch(ans)
{
case '1':{if(data[user].coins<lar)
		{od_printf("`bright blue`\n\rYou can't afford it!\n\r");
		break;
		}
		else if(data[user].armor != 0)
			{od_printf("`bright blue`\n\rYou already have some armour.\n\r");
			break;}
	else{data[user].coins -= lar;
		data[user].armor = 1;
		strcpy(edata.artype,"Leather");
		od_printf("`bright red`\n\rYou slip into your new armour.\n\r");
		}
	break;
	}
case '2':{if(data[user].coins<car)
		{od_printf("`bright blue`\n\rYou can't afford it!\n\r");
		break;
		}
		else if(data[user].armor != 0)
			{od_printf("`bright blue`\n\rYou already have some armour.\n\r");
			break;}
	else{data[user].coins -= car;
		strcpy(edata.artype,"Chain");
		data[user].armor = 2;
		od_printf("`bright red`\n\rYou slip into your new armour.\n\r");
		}
	break;
	}
case '3':{if(data[user].coins<par)
		{od_printf("`bright blue`\n\rYou can't afford it!\n\r");
		break;
		}
		else if(data[user].armor != 0)
			{od_printf("`bright blue`\n\rYou already have some armour.\n\r");
			break;}
	else{data[user].coins -= par;
		strcpy(edata.artype,"Plate");
		data[user].armor = 3;
		od_printf("`bright red`\n\rYou slip into your new armour.\n\r");
		}
	break;
	}
case '4':{if(data[user].coins < sws)
		{od_printf("`bright blue`\n\rYou can't afford it!\n\r");
		break;}
		else if(data[user].shield != 0)
			{od_printf("`bright blue`\n\rYou already have a sheild.\n\r");
			break;}
		else{data[user].coins -= sws;
			data[user].shield = 6;
			edata.shtype = 'A';
			od_printf("`bright red`\n\rYour new shield fits nicely on your arm.\n\r");
			}
		break;
		}
case '5':{if(data[user].coins < ws)
		{od_printf("`bright blue`\n\rYou can't afford it!\n\r");
		break;}
		else if(data[user].shield != 0)
			{od_printf("`bright blue`\n\rYou already have a sheild.\n\r");
			break;}
		else{data[user].coins -= ws;
			data[user].shield = 10;
			edata.shtype = 'B';
			od_printf("`bright red`\n\rYour new shield fits nicely on your arm.\n\r");
			}
		break;
		}
case '6':{if(data[user].coins < bs)
			od_printf("`bright blue`\n\rYou can't afford it!\n\r");
		else if(data[user].shield != 0)
			od_printf("`bright blue`\n\rYou already have a shield.\n\r");
		else{data[user].coins -= bs;
			data[user].shield = 20;
			edata.shtype = 'C';
			od_printf("`bright red`\n\rYour new shield fits nicely on your arm.\n\r");
			}
		break;
		}
case 'F': break;
}

}

int farmowner(void)
{
char faro;
switch(data[user].town)
{
case 'H':{monread("farm.dat",8,0);
		break;}
case 'P':{monread("farm.dat",8,2);
		break;}
case 'E':{monread("farm.dat",8,4);
		break;}
case 'B':{monread("farm.dat",8,6);
		break;}
}
faro = monattack();
return faro;
}

int farmhand(void)
{
char farh;
switch(data[user].town)
{
case 'H':{monread("farm.dat",8,1);
		break;}
case 'P':{monread("farm.dat",8,3);
		break;}
case 'E':{monread("farm.dat",8,5);
		break;}
case 'B':{monread("farm.dat",8,7);
		break;}
}
farh = monattack();
return farh;
}


void writelog(void)
{
FILE *fp;
char line1[79];
char line2[79];
char kij;
od_printf("`bright magenta`\n\rEnter your honorable two line message:`bright blue`\n\r");
od_input_str(line1,79, 32, 123);
od_input_str(line2,79,32,123);
od_printf("\n\r\n`bright magenta`%s\n\r%s\n\r",line1,line2);
od_printf("`bright blue`Is this what you want to write? [`bright white`Y`bright blue`/`bright white`n`bright blue`] ");
kij = od_get_answer("YN\n\r");
if(kij != 'N')
	{fp = fopenw("day0.log",10);
	fprintf(fp,"\n~12---------------------------------------------------------------------~15");
	fprintf(fp,"\n%s\n%s\n",line1,line2);
	fprintf(fp,"~9                              %s\n\r",data[user].alias);
	fclose(fp);
	od_printf("\n\r`bright cyan`You write your message then sign your name with a flourish.\n\r");

	}

}

void personal(void)
{
FILE *fp;
char command;
char buf[12];
char entry[79];
od_printf("`bright blue`You sift through the numorous personal logs and finally find your own.\n\r");
od_printf("Making sure that noone is looking over your shoulder, you open the log.\n\r");
do{
od_printf("`magenta`\n\r(R)  Read your log\n\r(W)  Write an entry\n\r(C)  Clear log\n\r(Q)  Quit\n\r");
command = od_get_answer("RWCQ");
switch(command)
{
case 'R':{
		sprintf(buf,"%d.asc",data[user].lognumber);
		od_control.od_page_pausing=TRUE;
		od_printf("`cyan`\n\r");
		od_clr_scr();
		fkread(fopenr(buf,1));
		getreturng();
		data[user].newmessage=FALSE;
		od_control.od_page_pausing=FALSE;
		break;
		}
case 'W':{sprintf(buf,"%d.asc",data[user].lognumber);
		od_printf("\n\rYou may enter one line into your personal log:\n\r");
		od_input_str(entry,80,32,122);
		fp = fopenw(buf,10);
		fprintf(fp,"~15%s\n",entry);
		od_printf("\n\r");
		od_control.od_page_pausing=FALSE;
		fclose(fp);
		break;
		}
case 'C':{sprintf(buf,"%d.asc",data[user].lognumber);
		od_printf("`bright blue`Are you sure you want to clear your log?  [Y/N] ");
		char akk;
		akk = od_get_answer("YN");
		if(akk == 'Y')
			{if(remove(buf) == 0)
				{od_printf("`bright red`\n\rYour personal log has been erased.\n\r");
				data[user].newmessage=FALSE;
				break;}
			}
		else break;
		}
case 'Q':{break;}
}
}while(command != 'Q');
}

void docks(void)
{
char com;
	  swrite("~5\n\rThe docks are old and used.  Various sailboats, skiffs,\n\r");
	  swrite("and rowboats crowd the long dock.  A particular sign draws your\n\r");
	  swrite("attention.  It hangs on a tall pole in front of a large clipper\n\r");
	   if(data[user].town == 'H')
		  od_printf("ship.  It reads, \"Passage - 100 gold coins.\"\n\r");
	  else od_printf("ship.  It reads, \"Passage - 20 gold coins.\"\n\r");
	  do{
	  swrite("~13\n\r(~15T~13)  Talk to Ship Attendant\n\r(~15L~13)  Leave\n\r");
	  com = command("TL",3);
	  if(com == 'T')
		{
		if((strcmp(setting[0].registered,"GLSKDMTEPDOGKFS") == 0)&&(setting[0].regis==regist()))
			{if(data[user].town == 'H')
				od_printf("`green`\n\r\"Would you like passage for only 100 coins?\" the sailor asks.\n\r");
			else od_printf("`green`\n\r\"Would you like passage for only 20 coins?\" the sailor asks.\n\r");
			char dockscom;
			dockscom = od_get_answer("YN ");
			if(dockscom == 'Y')
				{if(data[user].town == 'H')
					{if(data[user].coins < 100)
						od_printf("\n\r`red`You don't have the cash!\n\r");
					else	move(100);
					}
				else{if(data[user].coins < 20)
						od_printf("\n\r`red`You don't have the cash!\n\r");
					else move(20);
					}
				}
			else if(dockscom == 'N')
				od_printf("`green`\"Come back anytime.\"");
			}
		else{od_printf("\n\r\"Sorry, we don't take scum like you,\" the sailor says.");
			od_printf("\n\r\n`bright magenta`Please help your sysop to register.\n\r");}
		}
	  else if(com == 'L')
		 data[user].location = 'Z';
	  }while(com != 'L');
}

void unifarm(void)
{
char com;
do{
	  com = farm();
	  switch(com)
	  {
	  case 'B':{if(turncheck(4) == 0)
				break;
			od_printf("\n\r`blue`You sneak around the house a couple times and finally pick out a back\n\r");
		    od_printf("window to make your way in.  The lock looks simple. \n\rDo you try to break it? [Y/N]");
		    char farmhay;
		    farmhay = od_get_answer("YN");
		    if(farmhay == 'Y')
			{if(farmbreak() == TRUE)
				{od_printf("\n\r`bright cyan`The lock breaks off and you crawl in.\n\r");
				getreturng();
				if(farmowner() == TRUE)
					{farmsteal();}
				}
			else{od_printf("\n\r`bright cyan`It doesn't look like today is the day.\n\r");}
			}
		    else if(farmhay == 'N')
			{od_printf("\n\r`bright cyan`You back away from the frightening lock.\n\r");}
		    break;}
	  case 'S':{if(turncheck(4) == 0)
				break;
		    od_printf("\n\r`blue`The livestock fence is completely out in the open.  There is no\n\r");
		    od_printf("way for you to sneak up.\n\r");
		    getreturng();
		    char farhayw;
		    farhayw = farmhand();
		    if(farhayw == TRUE)
			{od_printf("\n\r`bright blue`You jump the fence and quickly slaughter three cows.  This\n\r");
			od_printf("meat will take a great price at the Market.\n\r");
			edata.i2 += 3;
			if(edata.i2 > 5)
				edata.i2 = 5;
			}
		    break;}
	  case 'L':{data[user].location = 'Z';
		    break;}
	  }
	  }while(com != 'L');
}

void innb(int a)
{
od_printf("`bright white`\n\n\rThe Innkeeper smiles, \"I must charge %d coins for room and board a night.\n\r",a);
	    od_printf("Do you still want a room?\" [Y/N]");
	    char gc;
	    gc = od_get_answer("YN");
	    if(gc == 'Y')
		{if(data[user].coins < a)
			od_printf("`red`\n\rSorry, you don't have enough money.\n\r");
		else{od_printf("`bright magenta`\n\rYou pay the %d coins and head to your room.\n\r",a);
			data[user].coins -= a;
			od_exit(0,FALSE);}
		}
	    else if(gc == 'N')
		od_printf("`bright white`\n\r\"Very well.\"\n\r");
}

void guild(void)
{
char com;
void transfer(void);
char name[20];
	  do{
	  swrite("~2\n\r(~15P~2)  List Players\n\r(~15S~2)  Send Message\n\r");
	  swrite("(~15H~2)  Handle Personal Log\n\r(~15R~2)  Read logbook\n\r(~15W~2)  Write in logbook\n\r(~15U~2)  Quick instructions\n\r");
	  swrite("(~15E~2)  Exp needed for next skill level\n\r(~15T~2)  Transfer money\n\r");
	  swrite("(~12M~2)  Step into mystical teleporter  ~15(multi-node chat)\n\r");
	  swrite("~2(~15L~2)  Leave\n\r");
	  com = command("EMPSHRWULT",10);
	  switch(com)
	  {
	  case 'T':{transfer();
				break;
				}
	  case 'E':{skillcheck();
			break;}
	  case 'M':{guildhall();
			break;}
	  case 'P':{listusers();
		    break;}
	  case 'S':{send(-1);
		    break;}
	  case 'H':{od_clr_scr();
			personal();
		    break;}
	  case 'R':{readlog();
		    break;}
	  case 'W':{writelog();
		    break;}
	  case 'U':{od_printf("\n\r");
			fkread(fopenr("qinst.asc",2));
			getreturng();
			break;}
	  case 'L':{data[user].location = 'Z';
		    break;}
	  }
	  }while(com != 'L');
}

void transfer(void)
{
int cc;
FILE *fp;
unsigned int coins;
char filename[12];
char name[20];
od_printf("\n\n\r`bright green`Who would you like to transfer money to?  `bright white`");
od_input_str(name,20,32,123);
cc = pusers(name);
if(cc == 32000)
	return;
od_printf("\n\r`bright green`How much money to transfer?  `bright white`");
od_input_str(name,5,47,58);
coins = atoi(name);
if(coins>data[user].coins)
	{
	od_printf("`bright red`\n\rYou do not have that many coins!\n\r");
	return;
	}
if(coins < 1)
	return;
sprintf(filename,"%d.mal",data[cc].lognumber);
if((fp=fopenw(filename,2))==NULL)
	{
	od_printf("`red`\n\rError!  Transfer impossible.");
	return;}
fprintf(fp,"~~~3%s transfered ~C %u",data[user].alias,coins);
fclose(fp);
data[user].coins -= coins;
}

void perlogwrite(char *buf, int num)
{
FILE *fp;
char buf2[81];
char filename[12];
sprintf(filename,"%d.asc",data[num].lognumber);
fp=fopenw(filename,10);
sprintf(buf2,"~14%s~15\n",buf);
fprintf(fp,buf2);
fclose(fp);
}

void plife(int a)
{
if(data[user].hitpts<1)
	{int inter;
	char interr[14];
	data[user].hitpts = 0;
	od_clr_scr();
	od_printf("`red`You fall to the ground.  Then you see your\n\r");
	od_printf("dead bloody body below you as you rise up.\n\r");
	sleep(5);
	char sender[80];
	sprintf(sender,"You defeated %s.",data[user].alias);
	perlogwrite(sender,a);
	sprintf(sender,"%s has killed %s.",data[a].alias,data[user].alias);
	logwrite(sender);
	data[a].coins += data[user].coins;
	sprintf(sender,"You collected %u coins.\n",data[user].coins);
	perlogwrite(sender,a);
	data[user].coins = 0;
	int uu;
	uu = (data[user].strength + data[user].dex + data[user].weaponshort + data[user].armor + data[user].totalhit + data[user].weaponlong + data[user].skill + 30);
	data[a].exp += uu;
	if(data[user].weaponshort > data[a].weaponshort)
		{perlogwrite("You got the weapon.",a);
		inter = data[a].weaponshort;
		strcpy(interr,data[a].stype);
		data[a].weaponshort = data[user].weaponshort;
		strcpy(data[a].stype,data[user].stype);
		strcpy(data[user].stype,interr);
		data[user].weaponshort = inter;}
	if(data[user].weaponlong > data[a].weaponlong)
		{perlogwrite("You got the long-range weapon.",a);
		inter = data[a].weaponlong;
		strcpy(interr,data[a].ltype);
		data[a].weaponlong = data[user].weaponlong;
		strcpy(data[a].ltype,data[user].ltype);
		data[user].weaponlong = inter;
		strcpy(data[user].ltype,interr);}
	playsave('C',a,20);
	od_exit(12,FALSE);}
}




void castle(void)
{
if(edata.progress < 7)
	{od_printf("`bright red`\n\rThe gates to the castle are shut.\n\r");
	getreturng();
	data[user].location = 'Z';}
else{od_printf("`bright blue`\n\rYou find the hidden passage into the castle.  Your key slips into it the\n\r");
	od_printf("lock perfectly.  You rush in and look for the throne room.\n\r");
	od_printf("`bright cyan`. ");
	sleep(1);
	od_printf(". ");
	sleep(1);
	od_printf(". ");
	sleep(1);
	od_printf("`bright blue`\n\rAs you enter the throne room, a squadron of soldiers traps you.\n\r");
	getreturng();
	monread("stryline.dat",9,8);
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	monread("stryline.dat",9,4);
	monster.run = 0;
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	monread("stryline.dat",9,5);
	monster.run = 0;
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	if(monattack() == FALSE)
		{data[user].location = 'Z';
		goto end;}
	if(edata.progress == 8)
		{od_printf("`bright red`\n\n\rYou approach the king the king and unleash the power of the gem on him.\n\r");
		getreturng();
		od_hotkey_menu("end.ans"," ",FALSE);
		od_set_cursor(24,1);
		getreturng();
		od_clr_scr();
		od_printf("`bright red`\n\rThe entire world will remember your name!\n\r");
		sleep(3);
		int winhandle;
		if((winhandle=eopen("sett.ing",10))==-1)
			{od_printf("Possible network error!  Inform sysop.");
			od_exit(0,FALSE);}
		read(winhandle,setting,sizeof(struct settings));
		if(setting[0].win != 100)
			{od_printf("Congratulations!  However %s beat you to it on another node!",data[setting[0].win].alias);}
		else setting[0].win = user;
		lseek(winhandle,0,SEEK_SET);
		write(winhandle,setting,sizeof(struct settings));
		close(winhandle);
		getreturng();
		od_exit(0,FALSE);
		}
	else{od_printf("`bright red`\n\r\nThe king has some sort of magic armour that you are afraid to touch.  This\n\r");
		od_printf("must be the reason for his power.  You run from the castle.\n\r");
		getreturng();
		data[user].location = 'Z';
		goto end;}
	}
end:
}

void skillcheck(void)
{
int skillc;
switch(data[user].skill)
{
case 1:{skillc = 30;			//30
	break;
	}
case 2:{skillc = 250;            //250

	break;
	}
case 3:{skillc = 400;            //400
	break;
	}
case 4:{skillc = 750;            //750
	break;
	}                                       //930
case 5:{skillc =  930;
	break;
	}
case 6:{skillc =  1300;           //1300
	break;
	}
case 7:{skillc =1800;           //1800
	break;
	}
case 8:{skillc = 2600;           //2600
	break;
	}
case 9:{skillc = 3900;           //3900
	break;
	}
case 10:{skillc =  5400;          //5400
	break;
	}
case 11:{skillc = 6800;          //6800
	break;
	}
case 12:{skillc =  8300;          //8300
	break;
	}
case 13:{skillc =  10000;         //10000
	break;
	}
case 14:{skillc =  11800;         //11800
	break;
	}
case 15:{skillc = 13600;         //13600
	break;
	}
case 16:{skillc = 15800;         //15800
	break;
	}
case 17:{skillc =  17000;         //17000
	break;
}
case 18:{skillc = 20000;         //20000
	break;
	}
case 19:{skillc = 25000;         //25000
	break;
	}
case 20:{skillc = 30000;         //30000
	break;
	}
case 21:{skillc = 36000;         //36000
	break;}
case 22:{skillc = 42000;         //42000
	break;}
case 23:{skillc = 48000;         //48000
	break;}
case 24:{skillc = 60000;         //60000
	break;}
case 25:{od_printf("\n\r`bright white`You can gain no more.\n\r");
	break;}
}
skillc = (skillc - data[user].exp);

if(data[user].skill != 25)
	od_printf("`bright white`\n\rYou need `bright red`%d `bright white`more experience points.\n\r",skillc);
getreturng();
}

