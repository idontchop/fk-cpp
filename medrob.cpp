#include "med.h"

extern struct player_info data[51];
extern int user;
extern struct settings setting[2];
extern struct info2 edata;

//gotta write another varible in - thief turns - when this if finished

/*this is the theif file that holds all thief functions for the guild and
for the robbing of places.*/

//void tguild(void);	main guild function - have to press 8 from tavern
//this is the file that is in med.h.

/*void urob(void)     this fuction is also in med.h - have to press 9 in
almost any building to get here.  This splits off into individual town
fuctions*/

void talk(void);		//talk to guild master
void listt(void);		//list thieves
//void toss(void);		//knife toss gambleing
void spy(void);		//spying on other users

//town rob functions

void rhayward(void);
/*
void rden(void);
void reast(void);
void rwest(void);
void rmid(void);
void rsus(void);
void rpom(void);
void rtiw(void);
void rburk(void);
*/

void tguild(void)
{
char tcom,kn;
do{
od_printf("\n\n\r`bright yellow`You climb down a hole hidden under some barrels in the corner.  You are\n\r");
od_printf("standing in a small room with a couple other thieves.\n\n\r");
od_printf("`brown`(`bright yellow`T`brown`)  Talk to Guild master\n\r");
od_printf("(`bright yellow`B`brown`)  Buy thief knife\n\r");
od_printf("(`bright yellow`S`brown`)  Spy on enemies\n\r");
od_printf("(`bright yellow`R`brown`)  List thieves\n\r");
od_printf("(`bright yellow`K`brown`)  Knife toss\n\r");
od_printf("(`bright yellow`L`brown`)  Leave\n\r");
tcom = command("TBSRKL",6);
switch(tcom)
{
case 'T':{talk();
		break;}
case 'B':{if(data[user].weaponshort != 1)
			{od_printf("`red`\n\rYou may want to get rid of your other weapon.\n\r");
			getreturn();}
		else{
			od_printf("`bright blue`\n\rYou ask the guild master about getting a specilized knife...\n\r");
			od_printf("`bright red`\"I understand, you want a light, quiet weapon that cuts deep.  I have one for\n\r");
			od_printf("you, but I'm afraid I can ask no less than 1300 coins.  Want one?\"");
			kn = od_get_answer("YN");
			switch(kn)
			{
			case 'Y':{if(data[user].coins < 1300)
						od_printf("`red`\n\rYou don't have enough coins.");
					else{data[user].coins -= 1300;
						od_printf("`bright blue`\n\rThe blade shines bright and the razor-sharp edges gleam in the light.\n\r");
						od_printf("Yet, the knife feels no heavier than a roll of pennies.\n\r");
						data[user].weaponshort = 8;
						data[user].stype = 'K';
						}
					getreturn();
					break;
					}
			}
			}
		break;}
case 'S':{spy();
		break;}
case 'R':{listt();
		break;}
case 'K':{//toss();
		break;}
case 'L':{break;}
}
}while(tcom != 'L');
}

void spy(void)
{
char mesy[20];
char sexx[3];
int inty;
char yes;
do{
od_printf("\n\r\n`bright yellow`Oh which person would you like to spy? (`brown`Enter`bright yellow` for list)\n\r>");
od_input_str(mesy,20,32,122);
if(stricmp(mesy,"")==0)
	listusers();
}while(stricmp(mesy,"")==0);
inty = pusers(mesy);
if(inty != 32000)
	{if(data[user].coins <50)
		{od_printf("`brown`\n\rSorry, that information cost 50 coins and you don't have it.\n\r");
		}
	 else{
	 if(data[inty].sex == 'M')
		strcpy(sexx,"His");
	 else strcpy(sexx,"Her");
	od_printf("`bright white`\n\rThat information will cost you 50 coins, pay it? [`bright yellow`Y`bright white`/`bright yellow`n`bright white`] ");
	od_get_answer("YN\n\r");
	if(yes != 'N')
		{data[user].coins -= 50;
		od_printf("\n\r\n`bright white`%s `brown`is visiting `bright yellow`",data[inty].alias);
		switch(data[inty].town)
			{
			case 'H':{od_printf("Hayward");
				break;}
			case 'D':{od_printf("The Den");
				break;}
			case 'P':{od_printf("Pomdirgunua");
				break;}
			case 'M':{od_printf("Mid Trimmail");
				break;}
			case 'E':{od_printf("East Trimmail");
				break;}
			case 'W':{od_printf("West Trimmail");
				break;}
			case 'S':{od_printf("Sussenex");
				break;}
			case 'B':{od_printf("Burkshire");
				break;}
			case 'T':{od_printf("Tiw");
				break;}
			case '*':{od_printf("Pirate's Hideout");
				break;}
			}
		od_printf(".\n\r`brown`That person wields the `bright yellow`");
		switch(data[inty].stype)
		{
		case 'A':{od_printf("Dagger");
		  break;}
		case 'B':{od_printf("Short Sword");
			break;}
		case 'C':{od_printf("Mace");
			break;}
		case 'D':{od_printf("Morning Star");
			break;}
		case 'E':{od_printf("Long Sword");
			break;}
		case 'F':{od_printf("Axe");
			break;}
		case 'G':{od_printf("White Sword");
			break;}
		case 'H':{od_printf("Diamond Sword");
			break;}
		case 'I':{od_printf("Scorion's Axe");
			break;}
		case 'J':{od_printf("Death Scythe");
			break;}
		case 'K':{od_printf("Thief's knife");
			break;}
		}
		od_printf("`brown`\n\rand protects themself with `bright yellow`");
		switch(data[inty].artype)
		{
		case 'Z':{od_printf("no");
		  break;}
		case 'A':{od_printf("Leather");
			break;}
		case 'B':{od_printf("Chain");
			break;}
		case 'C':{od_printf("Plate");
			break;}
		case 'D':{od_printf("Dragon-skin");
			break;}
		}
		od_printf("`brown` armour.\n\r");
		od_printf("%s strength is `bright yellow`%d`brown` and his dexterity is `bright yellow`%d`brown`.",sexx,data[inty].strength,data[inty].dex);
		od_printf("\n\r%s health is `bright yellow`%d`brown`/`bright yellow`%d`brown`.",sexx,data[inty].hitpts,data[inty].totalhit);
		od_printf("\n\rThat person holds `bright yellow`%d`brown` coins at the moment.\n\r",data[inty].coins);
		if(data[inty].online != -1)
			od_printf("That user is currently `red`ONLINE`brown`.");
		od_printf("\n\r");
		getreturn();
		}
	}
	}


}

void talk(void)
{
char payment;
char diap[20];
od_clr_scr();
if(data[user].theif == 0)
{od_printf("`brown`\"SO!  Another adventurer has come to the thief's guild for a little extra cash.\n\r");
od_printf("Well, do you think you have the stomach for it?  You will need to prove it\n\r");
od_printf("with a small payment of 50 coins.\" `bright yellow`[Y/N] ");
payment = od_get_answer("YN");
if(payment == 'Y')
	{if(data[user].coins >= 50)
		{data[user].coins -= 50;
		data[user].theif=1;
		goto talkmsagain;
		}
	else goto endtalkms;
	}
}

talkmsagain:
od_printf("`brown`\n\n\r\"I can tell you about thiefs, training, knife, and robbing.\n\r");
od_printf("Just say bye when you are finished.\"\n\r");
od_printf("`cyan`\n\r >  ");
od_input_str(diap,21,32,123);
od_printf("`bright yellow`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"Tis a rather odd question.  I had better not tell you in case you are\n\rinteregated.\"");
	}
else if(stricmp(diap,"thiefs")==0)
	{od_printf("\"Although most of us are outcasts from society, that doesn't mean that we are\n\r");
	 od_printf("not a powerful group.  Stick with us and money and mystical objects will be\n\r");
	 od_printf("in your hands.  Some weapons and armour are only obtainable by stealing from\n\r");
	 od_printf("others.\"");
	 }
else if(stricmp(diap,"training")==0)
	{od_printf("\"Training?  Well, I just have one thing to say: Practice makes perfect.\"");
	}
else if(stricmp(diap,"knife")==0)
	{od_printf("\"I have a very good knife that will keep you consealed while invading a\n\r");
	od_printf("building.  But it costs a pretty penny.\"");
	}
else if(stricmp(diap,"robbing")==0)
	{od_printf("`brown`The guildmaster leans close to you.  `bright yellow`\"Press 9 when you want to\n\r");
	od_printf("rob a location, but it wouldn't be wise to rob something where other thieves\n\r");
	od_printf("are.  As in, don't try to rob this tavern.\"");
	}
else if((stricmp(diap,"bye")==0) || (stricmp(diap,"goodbye")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"q")==0))
	goto endtalkms;
goto talkmsagain;
endtalkms:
}

void listt(void)
{
playsave('A',0,10);
int cc;
unsigned int expcount;
char endname;		//True if /0 has been encountered
od_clr_scr();
int screenlength;
screenlength = od_control.user_screen_length;
screenlength--;
int screencounter = 0;
int count;
expcount = 0;
for(count=0;count<setting[0].num_users;count++)
	{
	if(data[count].exp>expcount)
		expcount = data[count].exp;
	}
od_printf("`bright blue`Name                               Thief ranking\n\r");
od_printf("`yellow`------------------------------------------------\n\r");
expcount=0;
for(count=0;count<setting[0].num_users;count++)
	{
	if(data[count].theif>=expcount)
		expcount=data[count].theif;
	}
for(;expcount>0;expcount--)
{
for(count=0;count<setting[0].num_users;count++)
	{
	if(data[count].theif == expcount)
		{
			od_printf("`bright magenta`");
			endname = FALSE;
			for(cc = 0;cc<30;cc++)
			{
			if(endname == TRUE)
				od_putch(' ');
			else{
			if((data[count].alias[cc] == 32) || (data[count].alias[cc] == '\0'))
					{od_putch(' ');
			if(data[count].alias[cc] == '\0')
				endname = TRUE;}
			else od_putch(data[count].alias[cc]);
			    }
			}
			od_printf("`bright white`");
			if(data[count].theif > 9999)
				od_printf("              %d",data[count].theif);
			else if(data[count].exp > 999)
				od_printf("               %d",data[count].theif);
			else if(data[count].exp > 99)
				od_printf("                %d",data[count].theif);
			else if(data[count].exp > 9)
				od_printf("                 %d",data[count].theif);
			else od_printf("                  %d",data[count].theif);

			screencounter++;
			if(screencounter == screenlength){
				getreturng();
				screencounter = 0;}
			od_printf("\n\r");

		}
	}
}
}








void urob(void)
{
if(data[user].theif == 0)
	{od_printf("`bright white`Listen buddy, just because you know how to press 9, it don't mean\n\ryou're a thief.\n\r");
	getreturn();
	}
else if(data[user].artype!='Z'&&data[user].artype!='A')
	{od_printf("`bright red`With this heavy armour, it appears you have been found...");
	getreturn();
	//code for mob attack
	}
else if(data[user].fish == 0)
	{od_printf("`bright red`Sorry, no more thieving turns left.\n\r");
	getreturn();
	}
else if(data[user].ANSI == FALSE)
	{od_printf("`bright red`Sorry, need ANSI graphics for thieving.\n\r");
	getreturn();}
else{
switch(data[user].town)
{
case 'H':{rhayward();
		break;}/*
case 'D':{rden();
		break;}
case 'P':{rpom();
		break;}
case 'M':{rmid();
		break;}
case 'E':{reast();
		break;}
case 'W':{rwest();
		break;}
case 'S':{rsus();
		break;}
case 'B':{rburk();
		break;}
case 'T':{rtiw();
		break;}*/
}
}
}

void rhayward(void)
{
switch(data[user].location)
{
case 'T':{od_printf("`bright blue`You wait till noone is watching and slip through the kitchen door.\n\r");
	break;}
case 'I':{break;}
}
}