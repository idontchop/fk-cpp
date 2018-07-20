#include "med.h"
#include <ctype.h>

extern struct player_info data[60];
extern int user;
extern struct settings setting[2];
extern struct info2 edata;

void fields(void)
{
char comd;
do{
  swrite("~12\n\rThe old, wide open fields show signs of constant use.  Many packed\n\r");
  swrite("patches in the grass outline the temporary beds adventurers like you\n\r");
  swrite("are forced to use.  You find one and sit down to rest.\n\r");
  swrite("~13\n\r");
  swrite("(~15P~13)  List players in the field\n\r(~15A~13)  Attack a player in the field\n\r");
  swrite("(~15S~13)  Statistics\n\r(~15E~13)  Eat food\n\r(~4C~13)  Commit Suicide\n\r(~15I~13)  Enable/Disable graphics\n\r");
  swrite("(~15G~13)  Get rid of companion\n\r(~15L~13)  Leave\n\r(~12Q~13)  Quit game and sleep for the night\n\r");
  comd = command("GIPASELCQ",9);
  switch(comd)
  {
  case 'G':{if(edata.compatt<1)
			{od_printf("`bright red`\n\rDummy!  You don't have one to get rid of.\n\r");
			break;}
		od_printf("\n\r`bright blue`Are you sure?  ");
		if(od_get_answer("yn")=='y')
			{
			od_printf("`bright white`\n\r%s packs up and leaves with a lowered head.",edata.compname);
			edata.compatt=-1;
			}
		break;
		}
  case 'I':{od_printf("\n\r`bright blue`Set preferences how?\n\r");
		  od_printf("`bright red`1.  `white`No colors, No graphics\n\r");
		  od_printf("`bright red`2.  `bright white`Colors, `white`No graphics\n\r");
		  od_printf("`bright red`3.  `bright white`Colors, Graphics   *\n\r");
		  od_printf("`bright blue`What do you think?  ");
		  switch(od_get_answer("123"))
		  {
		  case '1':{data[user].trueansi = FALSE;
				od_control.user_ansi = FALSE;
				data[user].ANSI = FALSE;
					break;}
		  case '2':{data[user].trueansi = TRUE;
				  od_control.user_ansi = TRUE;
				  data[user].ANSI = FALSE;
				  break;}
		  case '3':{data[user].trueansi = TRUE;
				  od_control.user_ansi = TRUE;
				  data[user].ANSI = TRUE;
				  break;}
		  }
		  od_printf("\n\r`bright magenta`Alrighty then.");
		break;
		}
  case 'P':{fieldlister();
		getreturng();
	    break;}
  case 'A':{if(edata.pfight == 0){
			od_printf("`red`\n\rNope, you have tried your share today.\n\r");
			getreturn();}
		else	fieldattacker();
	    break;}
  case 'S':{stats();
	    break;}
  case 'E':{char uio;
		  od_printf("`bright magenta`\n\rYou have:\n\r");
		  od_printf("%d meat\n\r",edata.i2);
		  od_printf("%d fish\n\r",edata.i0);
		  od_printf("%d bread\n\r",edata.i3);
		  od_printf("`bright blue`\n\r(M) Meat  (F) Fish  (B) Bread  (N)  nevermind\n\r");
		  uio = od_get_answer("MFBN");
		  switch(uio)
		  {
		  case 'M':{if(edata.i2 < 1)
					 od_printf("\n\rYou have none.\n\r");
				  else{if(edata.hunger == 'D')
						edata.hunger = 'B';
					  else edata.hunger = 'A';
					  edata.i2 -= 1;
					  }
				  break;
				  }
		  case 'F':{if(edata.i0 < 1)
					od_printf("\n\rYou have none.\n\r");
				  else{edata.i0 -= 1;
					goto change;}
				  break;
				  }
		  case 'B':{if(edata.i3 < 1)
					od_printf("\n\rYou have none.\n\r");
				  else{edata.i3 -= 1;
					  goto change;}
				  break;
				  }
		  }
		  break;
		  change:
		  if(edata.hunger == 'D')
			edata.hunger = 'C';
			else if(edata.hunger == 'C')
				edata.hunger = 'B';
				else if(edata.hunger == 'B')
					edata.hunger = 'A';
		  od_printf("`bright blue`\n\rYou feel a little better.\n\r");
		  data[user].hitpts++;
		  if(data[user].hitpts > data[user].totalhit)
			data[user].hitpts = data[user].totalhit;
		  break;
		  }
  case 'L':{data[user].location = 'Z';
	    break;}
  case 'C':{suicide();
	    break;}
  case 'Q':{char quit;
	    od_printf("\n\r`red`Are you sure?");
	    quit = od_get_answer("YN");
	    if(quit == 'Y'){
		od_exit(12,FALSE);}
	    else{break;}
	    }
   }
  }while(comd != 'L');
}

void fieldlister(void)
{
playsave('A',0,10);
int cc,ccc;
int order[50];
int temp;
for(cc=0;cc<setting[0].num_users;cc++)
	{
	order[cc] = cc;
	}
for(cc=0;cc<setting[0].num_users;cc++)
	{
	for(ccc=cc;ccc<setting[0].num_users;ccc++)
		{
		if(data[order[cc]].exp<data[order[ccc]].exp)
			{
			temp = order[cc];
			order[cc] = order[ccc];
			order[ccc] = temp;
			}
		}
	}
char endname;		//True if /0 has been encountered
od_clr_scr();
int screenlength;
screenlength = od_control.user_screen_length;
screenlength--;
int screencounter = 0;
int count;
od_printf("`bright blue`Name                                  Hit Points          Experience\n\r");
od_printf("`yellow`----------------------------------------------------------------------------\n\r");
for(count=0;count<setting[0].num_users;count++)
	{
	if((data[order[count]].online != -1) && (data[order[count]].online != 32000))
		continue;
		if((data[user].location == data[order[count]].location) && (data[user].town == data[order[count]].town) && (data[order[count]].hitpts > 0))
			{
			od_printf("`bright magenta`");
			endname = FALSE;
			for(cc = 0;cc<30;cc++)
			{
			if(endname == TRUE)
				od_putch(' ');
			else{
			if((data[order[count]].alias[cc] == 32) || (data[order[count]].alias[cc] == '\0'))
					{od_putch(' ');
			if(data[order[count]].alias[cc] == '\0')
				endname = TRUE;}
			else od_putch(data[order[count]].alias[cc]);
			}
			}
			if(data[order[count]].hitpts>99)
				od_printf("            %d",data[order[count]].hitpts);
			else if(data[order[count]].hitpts>9)
				od_printf("             %d",data[order[count]].hitpts);
			else od_printf("              %d",data[order[count]].hitpts);
			od_printf("`bright white`");
			if(data[order[count]].exp > 9999)
				od_printf("                  %u",data[order[count]].exp);
			else if(data[order[count]].exp > 999)
				od_printf("                   %u",data[order[count]].exp);
			else if(data[order[count]].exp > 99)
				od_printf("                    %u",data[order[count]].exp);
			else if(data[order[count]].exp > 9)
				od_printf("                     %u",data[order[count]].exp);
			else od_printf("                      %u",data[order[count]].exp);
			od_printf("\n\r");
			screencounter++;
			if(screencounter == screenlength){
				getreturng();
				screencounter = 0;}

			}

	}

}

void fieldattacker(void)
{
int count;
char atname[30];
fieldlister();
od_printf("`magenta`Who would you like to attack? (Full or Partial) > ");
od_printf("`yellow`");
od_input_str(atname,31,32,122);
count = users(atname);
if(count != 32000)
	{pattack(count);
	}
}

void suicide(void)
{
char uul;
od_printf("`red`\n\r\n\nAre you absolutely POSITIVE?  ");
od_clear_keybuffer();
uul = od_get_answer("YN");
if(uul == 'Y')
	{od_printf("`bright magenta`\n\rAs you wish!  Do come back.\n\r");
	strcpy(data[user].name,"suicide");
	data[user].hitpts = 0;
	life();}
}
void odd(void)
{
od_clr_scr();
char k;
do{
od_printf("\n\n\r`bright blue`What would you like to do, warrior?\n\r");
od_printf("\n\r`magenta`(`bright white`C`magenta`)  Continue exploring\n\r");
od_printf("(`bright white`R`magenta`)  Refresh at the tavern\n\r");
od_printf("(`bright white`Q`magenta`)  Quick mode        ");
if(edata.qf==TRUE)
	od_printf("`bright white`ON");
else od_printf("`bright white`OFF");
od_printf("\n\r`magenta`(`bright white`L`magenta`)  Leave\n\r");
od_printf("\n\r`bright blue`Exploring turns left`bright red`:  `bright white`%d        `bright blue`[`bright red`C`bright blue`]",edata.forest);
k = command("\n\rQRLC",6);
switch(k)
{
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
	jl = random(10);
	switch(data[user].town)
	{
	case 'W':{jl=random(7);
			monread("westsew.dat",7,jl);
			break;}
	}
	monattack();
	if(data[user].dex == 1)
		{od_printf("\n\r`bright white`After that fight, the thought of `bright red`training `bright white`comes to your head.\n\r");
		}
	break;
	}
case 'L':{data[user].location = 'Z';
	break;}
}
}while((k != 'L') && (k != 'R'));
}

void maps(void)
{
od_printf("\n\n\r");
od_clr_scr();
FILE *file;
char hit;
char a;
if((file=fopenr("maps.asc",2))==NULL)
	{
	od_printf("`red`\n\rMap file missing!  Please inform sysop!\n\r");
	getreturn();
	}
do{
a = fgetc(file);
if(a == '~')
	{
	a = fgetc(file);
	if(a == data[user].town)
		break;
	}
}while(1);
do{
a = fgetc(file);
if(a == '~')
	{
	a = fgetc(file);
	switch(a)
	{
	case '!':
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
else	if(a > 31) od_putch(a);
}while((a != '^')&&(a != EOF));
fclose(file);
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


