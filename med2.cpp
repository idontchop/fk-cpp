#include "med.h"
char fishevent(void); //for use with fishing for events

extern struct player_info data[60];
extern int user;
extern struct info2 edata;
struct special sp[20];
extern struct settings setting[2];
void pspec(char spec);


void taverno(int a)
{
if(data[user].coins < a)
			od_printf("`red`\n\rSorry, you don't have enough coins.\n\r");
   else if(edata.hunger == 'A')
		od_printf("`red`\n\rYou are not hungry at all!\n\r");
    else{od_printf("`cyan`\n\rYou have %u coins.",data[user].coins);
    od_printf("  The meal costs %d coins,\n\rdo you still want one?",a);
    int orderag;
    orderag = od_get_answer("YN");
    if(orderag == 'Y')
	{od_printf("`bright cyan`\n\rYou call to the bartender for a plate of food and another plate and\n\r");
	od_printf("another plate.  After you pretty much have covered the entire table, you\n\r");
	od_printf("finally feel satisfied.  In fact, you can hardly move.  You thank the\n\r");
	od_printf("bartender and pay the %d gold coins.\n\r",a);
	data[user].coins -= a;
	edata.hunger = 'A';}
	}
}

void taverng(int a,int filling)
{
char gch;
char dring;
filling += 20;
if(filling == 620)
	{
	gch='D'; a+= 8;
	goto drinkdragon;
	}
if(a<10)
od_printf("\n\n\r`bright blue`Troll's Sweat           `bright red`%d\n\r",a);
else od_printf("\n\n\r`bright blue`Troll's Sweat          `bright red`%d\n\r",a);
od_printf("`bright blue`Dragon's Blood         `bright red`%d\n\r",(a + 8));
od_printf("\n\r`bright red`\"Need something refreshing, ehh?  What'll it be?\" [`bright white`D`bright red`/`bright white`T`bright red`]\n\r");
gch = od_get_answer("DT ?/\\h");
if(gch == 'D')
	{filling = 600;
	a += 8;}
drinkdragon:
if((gch != 'T') && (gch != 'D'));
else if(data[user].coins<a)
	od_printf("`red`\n\rSorry, you can't afford it.\n\r");
else{if(filling != 620)
	{
	od_printf("`bright blue`\n\rYou have %u gold coins.",data[user].coins);
    od_printf("\n\rA drink cost %d gold coins.\n\r",a);
    od_printf("Do you still want a drink?  [Y/N]");
    dring = od_get_answer("YN");
    }
    else dring = 'Y';
    if(dring == 'Y')
		{od_printf("\n\r\n`magenta`The drink soothes your throat as it goes down.  Although it\n\r");
		od_printf("makes you a little dizzy, you feel as though you have more energy.\n\r");
		data[user].coins -= a;
		int dringg;
		dringg = (data[user].totalhit - filling);
		if(data[user].hitpts >= dringg)
				data[user].hitpts = data[user].totalhit;
		else data[user].hitpts += filling;
		}
}
}

char pattack(int a)
{
playsave('B',a,20);
od_clr_scr();
if(data[a].honor<0)
	honoradd(1);
else honoradd(-1);
char pw[15];
char ew[15];
strcpy(pw,data[user].stype);
strcpy(ew,data[a].stype);
int jj, ll, mm, nn;
int first;
char co;
longagain:
od_printf("`bright magenta`\n\rYou quickly close in on %s.\n\r",data[a].alias);
od_printf("`bright blue`You see that your enemy is holding a %s.\n\r",ew);
getreturn();
char sender[80];
sprintf(sender,"%s attacked you in the fields.\r\n",data[user].alias);
data[a].newmessage = TRUE;
perlogwrite(sender,a);
int php, ehp, pch, ech, chance, chance2, lspe, s, hg, mn;
char ph, eh;
do{
od_clr_scr();
if(edata.qf == FALSE)
{
od_set_cursor(14,1);
od_printf("`bright blue`컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\r");
od_printf("`bright cyan`      (A)ttack        (D)efend        (R)un        (S)tats        redra(W)\n\r");
od_printf("`bright blue`컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컫컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\r");
od_printf("`bright magenta`YOU:`bright blue`                                   �\n\r");
od_printf("                                       �\n\r");
od_printf("`bright cyan`Strength:   `bright blue`                           � `red`Strength:\n\r");
od_printf("`bright cyan`Dexterity:   `bright blue`                          � `red`Dexterity:\n\r");
od_printf("`bright cyan`Hit Points:  `bright blue`                          � `red`Hit Points:\n\r");
od_printf("`bright cyan`Weapon:  `bright blue`                              � `red`Noted Weapon:");
}
do{
disfight(data[a].strength,data[a].dex,data[a].hitpts,data[a].totalhit, ew, data[a].alias);
co = od_get_answer("AMDRSW\n\r");
if((co == 'A') || (co == 'D') || (co == 10) || (co == 13))
	{
	php = ((data[user].strength - (data[a].strength/2)) + (data[user].weaponshort - data[a].armor) + random(4));
	ehp = ((data[a].strength - (data[user].strength/2)) + (data[a].weaponshort - data[user].armor) + random(4));
	pch = (data[user].dex - data[a].dex);
	ech = (data[a].dex - data[user].dex);
	if(php < 1)
		php = (random(3) + 1);
	if(ehp < 1)
		ehp = (random(3) + 1);
	}
first = 5;
s = 0;
switch(co)
{
case 'M':{od_set_cursor(1,1);
		od_printf("\n\rNaw... wouldn't want him mad at you.\n\r");
		sleep(1);
		od_printf("\r");
		od_clr_line();
		break;}
case 10:
case 13:
case 'A':{if(edata.qf == FALSE) od_set_cursor(7,1);
	  od_clr_line();
	  if(edata.qf == FALSE) od_set_cursor(12,1);
	  od_clr_line();
	  if(edata.qf == FALSE) delay(200);
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
	  else if(pch>-8)
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
	first = random(2);
	pattack:
	switch(first)
	{
	case 0:{if(ph == TRUE)
			{
			hg = random(3);
			if(edata.qf == FALSE) od_set_cursor(12,1);
			od_clr_line();
			switch(hg)
			{
			case 0:{od_printf("`bright red`With a strong slash, you bury your %s in your opponent's gut.\n\r",pw);
				break;}
			case 1:{od_printf("`bright red`You thrust your weapon into your opponent's side.\n\r");
				break;}
			case 2:{od_printf("`bright red`You sweep the enemy down and bring the butt of your %s to his face.\n\r",pw);
				break;}
			}
			if(edata.qf == FALSE) delay(200);
			data[a].hitpts -= php;
			if(data[a].hitpts<1)
				goto mondead;
			}
		else if(ph == FALSE)
			{
			hg = random(3);
			if(edata.qf == FALSE) od_set_cursor(12,1);
			od_clr_line();
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
			if(edata.qf == FALSE) delay(200);
			}
		if(s != 1)
			{s = 1;
			first = 1;
			goto pattack;}
		break;
		}
	case 1:{if(eh == TRUE)
			{
			hg = random(3);
			if(edata.qf == FALSE) od_set_cursor(7,1);
			od_clr_line();
			switch(hg)
			{
			case 0:{od_printf("`bright red`Your enemy thrusts his %s into your side.\n\r",ew);
				break;}
			case 1:{od_printf("`bright red`You are wacked in the head with the butt of a %s.\n\r",ew);
				break;}
			case 2:{od_printf("`bright red`Your enemy shows amazing ability in stabbing your back.\n\r");
				break;}
			}
			data[user].hitpts -= ehp;
			if(edata.qf == FALSE) delay(200);
			plife(a);
			}
		else if(eh == FALSE)
			{
			hg = random(3);
			if(edata.qf == FALSE) od_set_cursor(7,1);
			od_clr_line();
			switch(hg)
			{
			case 0:{od_printf("`yellow`Your opponent clumsily swings wildly by you.\n\r");
				break;}
			case 1:{od_printf("`yellow`Your enemy misses by a mile.\n\r");
				break;}
			case 2:{od_printf("`yellow`You quickly jump back from the attack.\n\r");
				break;}
			}
			if(edata.qf == FALSE) delay(200);
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
case 'D':{if(edata.qf == FALSE) od_set_cursor(7,1);
	  od_clr_line();
	  if(edata.qf == FALSE) od_set_cursor(12,1);
	  od_clr_line();
	  if(edata.qf == FALSE) delay(200);
	  if(edata.qf == FALSE) od_set_cursor(7,1);
	  od_printf("`bright red`Your enemy thrusts his %s into your side.\n\r",ew);
	  skip:
	  if(data[user].shield>=ehp)
		{if(edata.qf == FALSE) od_set_cursor(12,1);
		od_clr_line();
		od_printf("`bright red`You successfully block the attack.\n\r");
		}
	  else {if(edata.qf == FALSE) od_set_cursor(12,1);
		od_clr_line();
		od_printf("`bright magenta`The attack seems to go right through your shield.\n\r");
		data[user].hitpts -= ehp;
		plife(a);
		}
	  break;
	  }
case 'R':{hg = random(3);
	  if((hg == 0) || (hg == 1))
		{if(edata.qf == FALSE) od_set_cursor(12,1);
		od_clr_line();
		od_printf("`bright blue`You turn around and run like hell.\n\r");
		sprintf(sender,"%s ran from your might.\n",data[user].alias);
		perlogwrite(sender,a);
		goto end;
		}
	  else{if(edata.qf == FALSE) od_set_cursor(12,1);
		od_clr_line();
		od_printf("`red`As you turn around, you are slammed to the ground.\n\r");
		data[user].hitpts -= 2;
		plife(a);
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

int inter;
char interr[14];
sprintf(sender,"You were defeated by %s.",data[user].alias);
perlogwrite(sender,a);
if(edata.qf == FALSE) delay(200);
sprintf(sender,"%s has killed %s.",data[user].alias,data[a].alias);
logwrite(sender);
od_clr_scr();
od_printf("`bright cyan`\n\rYou stand over your victom's body, triumphant.\n\r");
data[user].kills++;
if(data[user].kills > 60000)
	data[user].kills = 60000;
if(data[a].coins == 0)
	od_printf("`bright red`You find no coins.\n\r");
else od_printf("`bright red`You are able to scavenge %u coins.",data[a].coins);
data[user].coins += data[a].coins;
coins();
data[a].coins = 0;
data[a].hitpts = -100;
int uu;
uu = (data[a].strength + data[a].dex + data[a].weaponshort + data[a].armor + data[a].totalhit + data[a].weaponlong + data[a].skill);
exper(uu);
if(data[a].honor>-1)
	honoradd(-5);
else honoradd(5);
if(data[a].weaponshort > data[user].weaponshort)
	{od_printf("`bright blue`Since his weapon is better, you take it.\n\r");
	inter = data[user].weaponshort;
	strcpy(interr,data[user].stype);
	data[user].weaponshort = data[a].weaponshort;
	strcpy(data[user].stype,data[a].stype);
	data[a].weaponshort = inter;
	strcpy(data[a].stype,interr);}
if(data[a].weaponlong > data[user].weaponlong)
	{od_printf("`bright yellow`You take his long-range weapon.\n\r");
	inter = data[user].weaponlong;
	strcpy(interr,data[user].ltype);
	data[user].weaponlong = data[a].weaponlong;
	strcpy(data[user].ltype,data[a].ltype);
	data[a].weaponlong = inter;
	strcpy(data[a].ltype,interr);}
skill();
od_printf("`bright cyan`\n\rWay to go!\n\r");
getreturn();
end:
playsave('C',a,20);
getreturn();
od_clr_scr();
if(data[a].hitpts==-100)
	return TRUE;
else return FALSE;
}



void marketbuy(int meat, int fish, int bread)
{
char oby;
od_clr_scr();
obm:
od_printf("\n\r`magenta`");
od_printf("  Item                 Price\n\r\n\r");
od_printf("`bright magenta`");
od_printf("M.  Meat                  %d\n\r", meat);
od_printf("F.  Fish                  %d\n\r", fish);
od_printf("B.  Bread                 %d\n\r", bread);
od_printf("N.  nevermind\n\r");
od_printf("`bright cyan`\n\rWhich one would you like?  ");
oby = od_get_answer("MFBN?");
switch(oby)
{
case 'M':{if(edata.i2 > 4)
		{od_printf("`red`\n\rSorry, you can't carry any more meat.\n\r");
		break;}
	  if(data[user].coins < meat)
		{od_printf("`red`\n\rSorry, you don't have enough money.\n\r");
		break;}
	  od_printf("\n\r`bright blue`You are now the proud owner of a piece of meat.\n\r");
	  edata.i2++;
	  data[user].coins -= meat;
	  break;
	  }
case 'F':{if(edata.i0 > 4)
		{od_printf("`red`\n\rSorry, it appears you can't carry anymore.\n\r");
		break;}
	  if(data[user].coins < fish)
		{od_printf("`red`\n\rSorry, check your wallet.\n\r");
		break;}
	  od_printf("\n\r`bright blue`You now have some sushi!\n\r");
	  edata.i2++;
	  data[user].coins -= fish;
	  break;
	  }
case 'B':{if(edata.i3 > 4)
		{od_printf("`red`\n\rSorry, it appears you can't carry any more.\n\r");
		break;}
	  if(data[user].coins < bread)
		{od_printf("`red`\n\rYou are an adventurer not a theif!  In short, you can't afford it.\n\r");
		break;}
	  od_printf("\n\r`bright blue`You now have a nice loaf of bread.\n\r");
	  edata.i3++;
	  data[user].coins -= bread;
	  break;
	  }
case 'N':{break;}
case '?':{od_printf("`yellow`Press the letter of the item you wish to buy:\n\r");
	  goto obm;}
default:{od_printf("`red`Error!\n\r");}
}

}

void move(int price)
{
char move,mh,mj;
do{
od_printf("`bright magenta`\n\rMove options:  \n\r");
od_printf("`bright blue`\n\r(L)  See Land\n\r(I)  Information on towns\n\r(M)  Move\n\r(S)  Stay (don't move)\n\r");
move = od_get_answer("LIMS");
switch(move)
{
case 'L':{od_hotkey_menu("land.ans"," ",FALSE);
		getreturng();
		break;}
case 'I':{od_control.od_page_pausing=TRUE;
		od_hotkey_menu("towns"," ",FALSE);
		od_control.od_page_pausing=FALSE;
		getreturng();
		break;}
case 'M':{od_printf("`bright magenta`\n\rWhere to?\n\r");
		if(data[user].location == 'D')
			{od_printf("`bright blue`\n\r(H)  Hayward\n\r(D)  The Den\n\r(M)  Trimmail\n\r(P)  Pomdirgunua\n\r(S)  Sussenex\n\r(F)  Forget it\n\r");
			if(edata.prodeath > 1)
				mh = od_get_answer("HDMPSF*");
			else	mh = od_get_answer("HDMPSF");
			if(mh == data[user].town)
				{od_printf("`red`\n\rYou are already there!\n\r");
				break;}
			else if(mh == 'F')
				break;
			else{if(edata.turns <5)
					{od_printf("`bright red`Sorry, you don't have enough turns.  You need 5.\n\r");
					break;}
			od_printf("`bright red`\n\rMoving costs you 5 turns.  Are you sure you want to move?  [Y/N]");
			mj = od_get_answer("YN");
			if(mj == 'Y')
				{if(data[user].ANSI == TRUE)
					{od_hotkey_menu("move"," ",FALSE);
					od_printf("\r\n\n");}
				else od_printf("`bright red`\n\rYou take a final look around and then board the boat and leave.\n\r");
				edata.turns -= 5;
				data[user].town = mh;
				data[user].coins -= price;
				move = 'K';
				}
			else break;
			}
			}
		else{od_printf("`bright blue`\n\r(E)  Trimmail\n\r(P)  Pomdirgunua\n\r(S)  Sussenex\n\r(T)  Tiw\n\r(B)  Burkshire\n\r(F)  Forget it\n\r");
			mh = od_get_answer("TPSEBF");
			if(mh == data[user].town)
				{od_printf("`red`\n\rYou are already there!\n\r");
				break;}
			else if(mh == 'F')
				break;
			else{if(edata.turns <5)
					{od_printf("`bright red`Sorry, you don't have enough turns.  You need 5.\n\r");
					break;}
			od_printf("`bright red`\n\rMoving costs you 5 turns.  Are you sure you want to move?  [Y/N]");
			mj = od_get_answer("YN");
			if(mj == 'Y')
				{od_printf("`bright red`\n\rYou take a final look around before you sattle up and head out.\n\r");
				edata.turns -= 5;
				data[user].town = mh;
				move = 'K';
				}
			else break;
			    }
			}
		break;
		}
case 'S':{if(price != 0){
		od_printf("`bright blue`\n\rThe sailor sure seems mad when he has to give your money back.\n\r");}
		break;}
}
}while((move != 'S') && (move != 'K'));
}

void converse(void)
{
char yn;
char string[79];
FILE *fp;
od_clr_scr();
od_printf("`magenta`");
od_control.od_page_pausing = TRUE;
fkread(fopenr("conver.asc",1));
od_control.od_page_pausing = FALSE;
od_printf("`bright magenta`\n\rAdd to conversation? [Y/N] ");
yn = od_get_answer("YN");
if(yn == 'N')
	goto conend;
od_printf("`bright blue`\n\rEnter one line:\n\r");
od_input_str(string,79,32,123);
fp=fopenw("conver.asc",10);
fprintf(fp,"\n\r~9%s~12:~15\r\n",data[user].alias);
fprintf(fp,string);
fclose(fp);
conend:
}


void skill(void)
{
exp();
if(data[user].coins>60000)
	data[user].coins = 60000;
int a = 0;
while(1)
{
switch(data[user].skill)
{
case 1:{if(data[user].exp >= 30)			//30
		{a = 1;
		edata.trainpts++;
		data[user].skill = 2;
		}
	break;
	}
case 2:{if(data[user].exp >= 250)            //250
		{a = 1;
		data[user].skill = 3;
		edata.trainpts+=2;
		}
	break;
	}
case 3:{if(data[user].exp >= 400)            //400
		{a = 1;
		data[user].skill = 4;
		edata.trainpts++;
		}
	break;
	}
case 4:{if(data[user].exp >= 750)            //750
		{a = 1;
		data[user].skill = 5;
		edata.trainpts+=2;
		}
	break;
	}                                       //930
case 5:{if(data[user].exp >= 930)
		{a = 1;
		data[user].skill = 6;
		edata.trainpts++;
		}
	break;
	}
case 6:{if(data[user].exp >= 1300)           //1300
		{a = 1;
		data[user].skill = 7;
		edata.trainpts++;
		}
	break;
	}
case 7:{if(data[user].exp >= 1800)           //1800
		{a = 1;
		data[user].skill = 8;
		edata.trainpts+=2;
		}
	break;
	}
case 8:{if(data[user].exp >= 2600)           //2600
		{a = 1;
		data[user].skill = 9;
		edata.trainpts++;
		}
	break;
	}
case 9:{if(data[user].exp >= 3900)           //3900
		{a = 1;
		data[user].skill = 10;
		edata.trainpts+=2;
		}
	break;
	}
case 10:{if(data[user].exp >= 5400)          //5400
		{a = 1;
		data[user].skill = 11;
		edata.trainpts++;
		}
	break;
	}
case 11:{if(data[user].exp >= 6800)          //6800
		{a = 1;
		data[user].skill = 12;
		edata.trainpts++;
		}
	break;
	}
case 12:{if(data[user].exp >= 8300)          //8300
		{a = 1;
		data[user].skill = 13;
		edata.trainpts++;
		}
	break;
	}
case 13:{if(data[user].exp >= 10000)         //10000
		{a = 1;
		data[user].skill = 14;edata.trainpts+=3;
		}
	break;
	}
case 14:{if(data[user].exp >= 11800)         //11800
		{a = 1;
		data[user].skill = 15;
		edata.trainpts+=2;
		}
	break;
	}
case 15:{if(data[user].exp >= 13600)         //13600
		{a = 1;
		data[user].skill = 16;
		edata.trainpts+=2;
		}
	break;
	}
case 16:{if(data[user].exp >= 15800)         //15800
		{a = 1;
		data[user].skill = 17;
		edata.trainpts++;
		}
	break;
	}
case 17:{if(data[user].exp >= 17000)         //17000
		{a = 1;
		data[user].skill = 18;
		edata.trainpts++;
		}
	break;
	}
case 18:{if(data[user].exp >= 20000)         //20000
		{a = 1;
		data[user].skill = 19;
		edata.trainpts++;
		}
	break;
	}
case 19:{if(data[user].exp >= 25000)         //25000
		{a = 1;
		data[user].skill = 20;
		edata.trainpts++;
		}
	break;
	}
case 20:{if(data[user].exp >= 30000)         //30000
		{a = 1;
		data[user].skill = 21;
		edata.trainpts++;
		}
	break;
	}
case 21:{if(data[user].exp >= 36000)         //36000
		{a = 1;
		data[user].skill = 22;
		edata.trainpts++;
		}
	break;}
case 22:{if(data[user].exp >= 42000)         //42000
		{a = 1;
		data[user].skill = 23;
		edata.trainpts+=5;
		}
	break;}
case 23:{if(data[user].exp >= 48000)         //48000
		{a = 1;
		data[user].skill = 24;
		edata.trainpts+=5;
		}
	break;}
case 24:{if(data[user].exp >= 60000)         //60000
		{a = 2;
		data[user].skill = 25;
		edata.trainpts+=10;
		}
	break;}
}
if(a == 1)
	{od_printf("\n\r`white`You have increased a skill level!\n\r");
	a = 0;
	char buff[70];
	sprintf(buff,"%s increased a level!",data[user].alias);
	logwrite(buff);
	}
else if(a == 2)
	{od_printf("\n\r`white`You have reached skill level 25!\n\r");
	a=0;
	char bufff[80];
	edata.trainpts += 20;
	getreturn();
	sprintf(bufff,"%s reached skill level 25!",data[user].alias);
	logwrite(bufff);
	break;
	}
else break;
}

}

void marketsell(int meat, int fish, int bread)
{
char numstr[3];
int num,price;
char oms;
od_clr_scr();
hjkd:
od_printf("\n\r`magenta`");
od_printf("  Item                     Price\n\r");
od_printf("`bright magenta`\n\r");
od_printf("M.  Meat                      %d\n\r",meat);
od_printf("F.  Fish                      %d\n\r",fish);
od_printf("B.  Bread                     %d\n\r",bread);
od_printf("N.  nevermind\n\r");
od_printf("`bright cyan`\n\rWhich one will you sell me?  ");
oms = od_get_answer("MFBN?");
od_printf("\n\r");
switch(oms)
{
case 'M':{if(edata.i2 == 0)
		{od_printf("`red`Are you kidding?  You don't have any!\n\r");
		break;}
	  sellmeatagain:
	  od_printf("`bright magenta`I will buy one for %d coins.\n\r",meat);
	  od_printf("How many would you like to sell? 0-%d  ",edata.i2);
	  od_input_str(numstr,2,45,58);
	  num = atoi(numstr);
	  if((num > edata.i2) || (num < 0))
		{od_printf("`bright red`\n\rInvalid\n\r");
		goto sellmeatagain;}
	  price = (num * meat);
	  od_printf("`bright blue`\n\rHere is your %d coins.\n\r",price);
	  data[user].coins += price;
	  coins();
	  edata.i2 -= num;
	  break;
	  }
case 'F':{if(edata.i0 == 0)
		{od_printf("`red`But...   You don't have any.\n\r");
		break;}
	  sellfishagain:
	  od_printf("`bright magenta`\n\rI will buy one for %d coins.\n\r",fish);
	  od_printf("How many would you like to sell? 0-%d  ",edata.i0);
	  od_input_str(numstr,2,45,58);
	  num = atoi(numstr);
	  if((num > edata.i0) || (num < 0))
		{od_printf("`bright red`\n\rInvalid\n\r");
		goto sellfishagain;}
	  price = (num * fish);
	  od_printf("`bright blue`\n\rHere is your %d coins.\n\r",price);
	  data[user].coins += price;
	  coins();
	  edata.i0 -= num;
	  break;
	  }
case 'B':{if(edata.i3 == 0)
		{od_printf("`red`You don't have any.\n\r");
		break;}
	  sellbreadagain:
	  od_printf("`bright magenta`\n\rI will buy one for %d coins.\n\r",bread);
	  od_printf("How many would you like to sell? 0-%d  ",edata.i3);
	  od_input_str(numstr,2,45,58);
	  num = atoi(numstr);
	  if((num > edata.i3) || (num < 0))
		{od_printf("`bright red`\n\rInvalid\n\r");
		goto sellbreadagain;}
	  price = (num * bread);
	  od_printf("`bright blue`\n\rHere is your %d coins.\n\r",price);
	  data[user].coins += price;
	  coins();
	  edata.i3 -= num;
	  break;
	  }
case 'N':{break;}
case '?':{od_printf("`yellow`Type the letter of the food you wish to sell:\n\r");
	  goto hjkd;}
default:{od_printf("`red`Error\n\r");}
}

}


void fur(int sell, int buy, int dragon)
{
char co, hi;
do{
swrite("~12Furs from all kinds of animals hang on the walls.  Some you have seen and some");
swrite("\n\ryou don't know what animal it could be from.  A woman stands ready to help you.\n\r");
swrite("\n\r~15(~9B~15)  Buy fur suit\n\r(~9S~15)  Sell skins\n\r(~9D~15)  Get dragon scales fixed up");
swrite("\n\r(~9T~15)  Talk to woman\n\r(~9L~15)  Leave\n\r");
co = command("BSDTL",5);
switch(co)
{
case 'B':{if(edata.i6 == TRUE)
			{od_printf("`bright blue`\n\rYou already have a suit.\n\r");
			break;}
		else if(data[user].coins < sell)
			{od_printf("`bright red`\n\rYou don't have the cash to pay for one.  %d coins\n\r",sell);
			break;}
		else{od_printf("`bright magenta`\n\rFur suits cost %d coins.  Do you want one?  [Y/N] ",sell);
			hi = od_get_answer("YN");
			if(hi == 'Y')
				{od_printf("`bright blue`\n\rYou now own a fur suit.\n\r");
				edata.i6 = TRUE;
				data[user].coins -= sell;
				break;
				}
			else break;
			}
		}
case 'S':{char numstr[3];
		int num, price;
		if(edata.i1 < 1)
			{od_printf("`bright red`\n\rYou have none to sell.\n\r");
			break;}
		else{sellagain:
			od_printf("`bright blue`\n\rI will buy them for %d coins each.\n\r",buy);
			od_printf("How many would you like to sell? 0-%d \n\r",edata.i1);
			od_input_str(numstr,2,45,58);
			num = atoi(numstr);
			if((num > edata.i1) || (num < 0))
				{od_printf("`bright red`\n\rInvalid\n\r");
				goto sellagain;}
			price = (num * buy);
			od_printf("`bright blue`\n\rHere is your %d coins.\n\r",price);
			data[user].coins += price;
			coins();
			edata.i1 -= num;
			}
		break;
		}
case 'D':{if(edata.i5 < 1)
			{od_printf("`bright red`\n\rYou don't have any dragon skins.\n\r");
			break;}
		else if(data[user].coins < dragon)
			{od_printf("`bright red`\n\rIt costs %d coins, you don't have it.\n\r",dragon);
			break;}
		else{od_printf("`bright blue`\n\rI can make a shield or armour out of these scales for %d coins.\n\r",dragon);
			od_printf("`bright magenta`(S)  Shield\n\r(A)  Armour\n\r(F)  Forget it\n\r");
			hi = od_get_answer("SAF");
			switch(hi)
			{
			case 'S':{if(data[user].shield != 0)
						{od_printf("`bright red`\n\rYou may want to sell your other shield.\n\r");
						break;}
					od_printf("`bright blue`\n\rYou hand her the scales and wait ");
					sleep(2);
					od_printf("and wait ");
					sleep(2);
					od_printf("and wait ");
					sleep(2);
					od_printf("and wait ");
					sleep(2);
					od_printf("`bright magenta`\n\rFinally, she hands you your new dragon-skin shield.  \n\rIt feels sturdy on your arm.\n\r");
					data[user].coins -= dragon;
					data[user].shield = 120;
					edata.shtype = 'D';
					edata.i5 -= 1;
					break;
					}
			case 'A':{if(data[user].armor != 0)
						{od_printf("`bright red`\n\rYou may want to sell your other armour.\n\r");
						break;}
					od_printf("`bright blue`\n\rYou hand her the scales and wait ");
					sleep(2);
					od_printf("and wait ");
					sleep(2);
					od_printf("and wait ");
					sleep(2);
					od_printf("and wait ");
					sleep(2);
					od_printf("`bright magenta`\n\rFinally, she hands you your new dragon-skin armour.\n\r");
					data[user].coins -= dragon;
					data[user].armor = 6;
					strcpy(edata.artype,"Dragon-skin");
					edata.i5 -= 1;
					break;
					}
			case 'F':{break;}
			}
			}
		break;
		}
case 'T':{od_printf("`bright magenta`\n\n\r\"Anytime you want to go up in the mountains, you need a fur suit.  You will \n\r");
		od_printf("die if you don't have one.  I also buy skins that you may have gotten from the\n\r");
		od_printf("forest.  If by any means you have gotten dragon scales, I can make a shield\n\r");
		od_printf("or suit of armour out of them.  So, do you need a fur suit?\"\n\r");
		break;
		}
case 'L':{data[user].location = 'Z';
	  break;}
}
}while(co != 'L');
}

char swrite(char *a)
{
int count = 0;
do{
if(a[count] == '~')
	{
	count++;
	switch(a[count])
	{
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
	case '1':{count++;
			switch(a[count])
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
					od_putch(a[count]);
					break;}
			}
			break;
			}
	}



	}
else{if(a[count] == '\0')
		break;
	else od_putch(a[count]);
	}
count++;
}while(count < 160);
return TRUE;
}



void coins(void)
{
if(data[user].coins > 60000)
	data[user].coins = 60000;
}

void exp(void)
{
if(data[user].exp > 60000)
	data[user].exp = 60000;
}

void stats(void)
{
od_clr_scr();
od_printf("`bright magenta`Name: `bright blue`%s\n\r",data[user].alias);
od_printf("`bright magenta`Honor:       ");
if(data[user].honor<0)
	od_printf("`bright red`");
else od_printf("`white`");
od_printf("%d\n\r",data[user].honor);
od_printf("`bright magenta`Sex:         `bright blue`%c\n\r",data[user].sex);
od_printf("`bright magenta`Strength:    `bright blue`%d\n\r",data[user].strength);
od_printf("`bright magenta`Dexterity:   `bright blue`%d\n\r",data[user].dex);
od_printf("`bright magenta`Aim:         `bright blue`%d\n\r",data[user].aim);
od_printf("`bright magenta`Skill level: `bright blue`%d\n\r",data[user].skill);
od_printf("`bright magenta`Experience:  `bright blue`%u\n\r",data[user].exp);
od_printf("`bright magenta`Hit Points:  `bright blue`%d`bright magenta`/`bright blue`%d\n\r",data[user].hitpts,data[user].totalhit);
od_printf("`bright magenta`Location:    ");
od_printf("`bright blue`");

switch(data[user].town)
{
case 'H':{od_printf("Hayward\n\r");
	  break;}
case 'T':{od_printf("Tiw\n\r");
		break;}
case 'P':{od_printf("Pomdirgunua\n\r");
		break;}
case 'D':{od_printf("The Den\n\r");
		break;}
case 'S':{od_printf("Sussenex\n\r");
		break;}
case 'B':{od_printf("Burkshire\n\r");
		break;}
case '*':{od_printf("Wolf Hideout\n\r");
		break;}
case 'E':{od_printf("East Trimmail\n\r");
		break;}
case 'W':{od_printf("West Trimmail\n\r");
		break;}
}
od_printf("`bright magenta`Coins:       `bright blue`%u\n\r",data[user].coins);
od_printf("`bright magenta`Short-range weapon:  ");
if(stricmp(data[user].stype,"none")==0)
	od_printf("`magenta`");
else od_printf("`bright blue`");
od_printf("%s\n\r",data[user].stype);
od_printf("`bright magenta`Long-range weapon:   ");
if(stricmp(data[user].ltype,"none")==0)
	od_printf("`magenta`");
else od_printf("`bright blue`");
od_printf("%s\n\r",data[user].ltype);
if(stricmp(data[user].ltype,"none")!=0)
	{od_printf("`bright magenta`Ammo:  `bright blue`%d\n\r",data[user].ammo);
	}
od_printf("`bright magenta`Shield:  ");
od_printf("`bright blue`");
switch(edata.shtype)
{
case 'Z':{od_printf("`magenta`none\n\r");
	  break;}
case 'A':{od_printf("Small Wooden\n\r");
	break;}
case 'B':{od_printf("Wooden\n\r");
	break;}
case 'C':{od_printf("Brass\n\r");
	break;}
case 'D':{od_printf("Dragon-skin\n\r");
	break;}
}

od_printf("`bright magenta`Armour:  ");
if(stricmp(edata.artype,"none")==0)
	od_printf("`magenta`");
else od_printf("`bright blue`");
od_printf("%s\n\r",edata.artype);
od_printf("`bright magenta`Hunger:  ");
od_printf("`bright blue`");
switch(edata.hunger)
{
case 'A':{od_printf("stuffed\n\r");
	  break;}
case 'B':{od_printf("fine\n\r");
	  break;}
case 'C':{od_printf("little hungry\n\r");
	  break;}
case 'D':{od_printf("starving\n\r");
	  break;}
}
od_printf("`bright magenta`Turns left:  `bright blue`%d\n\r",edata.turns);
od_printf("\n\r`bright blue`[`bright magenta`Enter`bright blue`]`bright magenta`=continue       `bright blue`[`bright magenta`M`bright blue`]`bright magenta`ore info");
if(od_get_answer("\n\rm")=='m')
	{
	od_clr_scr();
	od_printf("`bright magenta`   Fish:   `bright blue`%d\n\r",edata.i0);
	od_printf("`bright magenta`   Meat:   `bright blue`%d\n\r",edata.i2);
	od_printf("`bright magenta`   Bread:  `bright blue`%d\n\r",edata.i3);
	od_printf("`bright magenta`   Skins:  `bright blue`%d\n\r",edata.i1);
	od_printf("`bright magenta`   Horse:  ");
	od_printf("`bright blue`");
	if(edata.i4 == TRUE)
		od_printf("Yes\n\r");
		else od_printf("No\n\r");
	od_printf("`bright magenta`   Fur Suit:  ");
	od_printf("`bright blue`");
	if(edata.i6 == TRUE)
		od_printf("Yes");
		else od_printf("No");
	od_printf("`bright white`\n\rCompanion:  `bright blue`%s\n\r",edata.compname);
	od_printf("`bright white`Special attacks:\n\r");
	for(int p=0;p<10;p++)
		{
		od_printf("   `bright blue`%d.`bright white`  ",p);
		pspec(p);
		od_printf("\n\r");
		}
	od_printf("`bright magenta`Special attacks:  `bright white`%d`bright blue`/`bright white`%d\n\r",edata.spec,edata.spectotal);
	od_printf("`bright magenta`Number of kills:  `bright white`%u\n\r",data[user].kills);
	getreturn();
	}
od_clr_scr();
}

void farmsteal(void)
{
int steal;
switch(data[user].skill)
{
case 1:{steal = 25;
	break;}
case 2:{steal = 25;
	break;}
case 3:{steal = 30;
	break;}
case 4:{steal = 34;
	break;}
case 5:{steal = 37;
	break;}
case 6:{steal = 40;
	break;}
case 7:{steal = 44;
	break;}
case 8:{steal = 48;
	break;}
case 9:{steal = 52;
	break;}
case 10:{steal = 56;
	break;}
case 11:{steal = 60;
	break;}
case 12:{steal = 65;
	break;}
case 13:{steal = 70;
	break;}
case 14:{steal = 75;
	break;}
case 15:{steal = 80;
	break;}
case 16:{steal = 85;
	break;}
case 17:{steal = 90;
	break;}
case 18:{steal = 95;
	break;}
case 19:{steal = 100;
	break;}
case 20:{steal = 105;
	break;}
case 21:{steal = 110;
	break;}
case 22:{steal = 120;
	break;}
case 23:{steal = 135;
	break;}
case 24:{steal = 150;
	break;}
case 25:{steal = 175;
	break;}
}
switch(data[user].town)
{
case 'H':{steal += 5;
	break;}
case 'E':{steal += 45;
	break;}
case 'P':{steal += 30;
	break;}
case 'B':{steal += 10;
	break;}
}
steal += random(5);
od_printf("\n\r`magenta`You find %d coins in the house.\n\r",steal);
data[user].coins += steal;
coins();
}

void fishing(void)
{
char co;
swrite("\n\r~11You whip out your fishing pole and begin \n\rsome quiet fishing.");
do{
od_printf("`bright blue`\n\n\r[`bright white`C`bright blue`]  Cast");
od_printf("`bright blue`\n\r[`bright white`L`bright blue`]  Leave\n\r");
od_printf("\n\r`bright blue`Fishing turns left`bright red`:  `bright white`%d            `bright blue`[`bright red`C`bright blue`]",edata.fish);
co = command("QCLS\n\r",4);
switch(co)
{
case 10:
case 13:
case 'C':{
	  if(turncheck(1) == 0)
		break;
	  if(fishevent() == 0)
		{
	  od_printf("\n\r`cyan`You cast out and wait for a bite.\n\r");
	  od_printf("`blue`.  .");
	  od_printf("  .  .");
	  int fishi;
	  fishi = random(7);
	  if((fishi >= 0) && (fishi < 4))
		{fishdisplay();
		data[user].exp += 2;
		exp();
		skill();
		edata.i0++;
		if(edata.i0 > 10){
			od_printf("You throw it back for you have no room in your pack.\n\r");
			edata.i0 = 10;}
		}
	  else{od_printf("\n\rWith a little nibble, you can tell the fish\n\r");
		od_printf("got away with your bait, you reel it in.\n\r");}
		}
	  break;}
case 'S':{stats();
	  break;}
case 'L':{od_printf("\n\r`bright green`You pack up and leave the shore.\n\r");
		data[user].location = 'Z';
		break;}
}
}while(co != 'L');
}

char fishevent(void)
{
void house(void);
char buf[120];
if(edata.compatt == 0)	//sheena
	{
	od_clr_scr();
	od_printf("\n\r`bright blue`As you begin to cast out, you spot a young beautiful woman walking toward\n\r");
	od_printf("you.  You lay your pole down and great the stranger.\n\r");
	od_printf("`bright red`\"How art thou?  My name is Sheena.  I am looking for someone to travel with.\n\r");
	od_printf("In exchange, I will help you in battle and anywhere else I might be able to.\n\r");
	od_printf("Twould be an honor.\"  `bright blue`[`bright red`Y`bright blue`/`bright red`n`bright blue`]  ");
	if(od_get_answer("yn\n\r")!='n')
		{od_printf("\n\r`bright red`\"Great.  I'm ready to go.\"  `bright blue`You welcome your new companion.\n\r");
		od_printf("`bright red`\n\r\"By the way, you may want to talk to an old man that lives in\n\rand off of the forest.  Press `bright white`H`bright red` when hunting.\"\n\r");
		 edata.compatt=3;
		 strcpy(edata.compname,"Sheena");
		 strcpy(edata.compa,"Sheena jumps forward with a quick swipe of sword");
		 honoradd(2);
		 }
	else{od_printf("`bright red`\n\r\"Fine.  I appreciate your time.\"\n\r\n");
		edata.compatt=-1;
		honoradd(-2);
		}
	getreturn();
	return 1;
	}
else if((random(5)==4)&&(checkspec(2)==FALSE)&&(data[user].skill>1))  //fire bolt
	{
	od_clr_scr();
	sprintf(buf,"~9%s~15 has learned~12 Bolt of Fire~15.",data[user].alias);
	logwrite(buf);
	od_printf("`bright cyan`Under a rock, you find a scroll.");
	getreturn();
	od_printf("`bright blue`As you read it, it disappears in your hands...\n\r");
	delay(200);
	od_printf("`bright white`You have learned `bright red`BOLT OF FIRE`bright white`.\n\r");
	getreturn();
	addspec(2);
	return 1;
	}
else if((random(10)==2)&&(data[user].skill>2)&&(checkspec(8)==FALSE)&&(edata.i0>0)&&(data[user].town=='H')) //young man wants fish in hayward
	{
	od_clr_scr();
	od_printf("`bright white`A man approaches you and says:\n\r");
	od_printf("`bright blue`\"Give me that fish and I will tell you a secret.\"\n\r");
	od_printf("`bright white`Y`white`es or `bright white`N`white`o?\n\r");
	if(od_get_answer("yn")=='y')
		{
		od_printf("\n\r`bright blue`\"If you know where to look, many secrets can be found.  I have friends in the\n\r");
		od_printf("tavern.  Ask them about the `bright white`Taunt`bright blue` spell.\"\n\r");
		edata.i0--;
		getreturn();
		}
	return 1;
	}
else if(random(70)==20)
	{
	od_clr_scr();
	int coins;
	coins = (5 + random(5));
	od_printf("`bright cyan`You find `cyan`%d`bright cyan` coins behind a rock!\n\r",coins);
	data[user].coins += coins;
	if(data[user].coins > 60000)
		data[user].coins = 60000;
	exper(2);
	getreturn();
	return 1;
	}
else if((data[user].town=='H')&&(edata.spectotal<5)&&(random(25)==2)) //bolt of lightning in hayward
	{
	od_clr_scr();
	sprintf(buf,"~9%s~15 has been hit by lightning!",data[user].alias);
	logwrite(buf);
	swrite("~8The cloudy sky releases a powerful bolt of electricity that strikes the ground\n\r");
	swrite("near you.  The impact rocks the ground around you and you back away from the\n\r");
	swrite("scorched earth.");
	getreturn();
	swrite("~15Then suddenly the sky unleashes another bolt of lightning this time striking\n\r");
	swrite("you on the head.");
	getreturn();
	swrite("~9In the startling, although painless, jolt, you can feel a new source of\n\r");
	swrite("power radiating throughout your body.");
	getreturn();
	specialadd(2);
	return 1;
	}
else if((data[user].skill>3)&&(random(50)==20)&&(stricmp(edata.compname,"Rosncrntz")!=0)) //rosencrantz
	{
	od_clr_scr();
	od_printf("\n\r`bright blue`From behind you comes a sullen looking man.  He peers at you with black eyes.\n\r");
	od_printf("`bright red`\"I was not always like this.\"  `bright blue`he says.  `bright red`\"May I come with you and regain my\n\rhonor?\"\n\r");
	if(edata.compatt>0)
		{
		od_printf("`bright cyan`You know you will have to let %s go if you do...\n\r",edata.compname);
		}
	od_printf("`bright blue`[`bright red`Y`bright blue`/`bright red`N`bright blue`]");
	if(od_get_answer("yn")=='y')
		{
		od_printf("`bright blue`\n\rYou welcome your new companion.\n\r");
		honoradd(4);
		strcpy(edata.compname,"Rosncrntz");
		edata.compatt=4;
		strcpy(edata.compa,"Rosencrantz knocks your enemy over with a kick");
		}
	else{if(edata.compatt<1)
			{
			honoradd(-1);
			}
		}
	return 1;
	}
else if(data[user].town == 'H'&& random(50)==3 && checkspec(9) == FALSE)
	{
	od_clr_scr();
	od_printf("`bright white`A young girl approaches...\n\r");
	sleep(1);
	od_printf("`bright blue`\"I can feel your importance to this world.  Would you like to have power over\n\r");
	od_printf("nature?  In The Den, there is a `bright white`leaf`bright blue`, eat of it to gain the ability.\"\n\r");
	od_printf("`white`And then the girl disappears from site.\n\r");
	od_printf("\"Enough strange things for a day.\"  You say to yourself.");
	getreturn();
	return 1;
	}
else if(data[user].town == 'D'&&random(3)==2&&checkspec(4)==FALSE)
	{
	swrite("\n\n\r~10In your stroll along the beach, you have come upon a little house sitting\n\r");
	swrite("on the edge of the ocean.  Do you knock on the door?\n\r");
	swrite("    ~15Y~7es or ~15N~7o   ");
	if(od_get_answer("YN")=='Y')
		house();
	else{swrite("\n\n\r~10You walk away with your tail between your legs.");
		edata.fish++;
		}
	return 1;
	}
else if(data[user].town == 'H'&& random(40)==2) //young boy in hayward
	{
	od_clr_scr();
	od_printf("`bright white`A young boy approaches...\n\r");
	sleep(1);
	od_printf("`bright blue`\"Can I have 10 coins for my family, please?\"  `white`The boy's face looks\n\r");
	od_printf("extremely pitiful but full of hope.\n\r");
	swrite("  ~15Y~7es or ~15N~7o?  ");
	if(od_get_answer("yn")=='y')
		{
		if(checkspec(7)==FALSE)
			{
			od_printf("\n\r`bright blue`\"Thank you kind person, here is a piece of info:  T\"\n\r");
			}
		else od_printf("\n\r`bright blue`\"Thank you kind person.\"\n\r");
		honoradd(2);
		}
	else honoradd(-2);
	od_printf("`bright red`\n\rThe boy leaves.");
	getreturn();
	return 1;
	}
else return 0;
}

void house(void)
{
if(stricmp(edata.compname,"Rosncrntz")!=0)
	{
	swrite("~5A middle-aged man answers the door and asks what your business is.\n\r");
	delay(300);
	swrite("~13You answer just to chat.\n\r");
	delay(300);
	swrite("~9\"My friend is lost, he last went to Hayward.  You want to chat?\n\r");
	swrite("Will you please find him?\"");
	getreturn();
	}
else{swrite("~5A middle-aged man answers the knock.\n\r");
	delay(300);
	swrite("~13As soon as he and Rosencrantz see each other, they laugh and shake hands.\n\r");
	swrite("They both invite you inside.  You are healed with the dinner.\n\r");
	data[user].hitpts=data[user].totalhit;
	swrite("~9\"So, what brings you here?\"  asks the man.\n\r");
	swrite("~13\"Just happened upon it while fishing.  But since we are here, how about\n\r");
	swrite("teaching this man your fighting technique?\"  asks Rosencrantz.\n\r");
	delay(600);
	if(data[user].strength < 10)
		{
		swrite("\n\r~9\"But he isn't strong enough to execute the attack.  Maybe after he\n\r");
		swrite("gets a little stronger.\"\n\r");
		}
	else{swrite("\n\r~9\"Well, I have been wanting to get some practice anyway!\"\n\r");
		delay(300);
		swrite("\n\r~5The man, Rosencrantz, and you start to wrestle and attack each other\n\r");
		swrite("football charging style.  After several hours of knocking each other off\n\r");
		swrite("their feet, you begin to get good at it.\n\r");
		swrite("~15You have learned ~12Bum Rush~15.\n\r");
		addspec(4);
		}
	swrite("~12Rosencrantz and the man say goodbye as you leave.\n\r");
	getreturn();
	}
}

void fishdisplay(void)
{
od_printf("`bright cyan`");
if((data[user].town == 'B') || (data[user].town == 'T'))
	{switch(random(5))
	{
	case 0:{od_printf("\n\rYou reel in a bass.\n\r");
		break;}
	case 1:{od_printf("\n\rYou catch a nice-sized Trout.\n\r");
		break;}
	case 2:{od_printf("\n\rYou catch a small crappie.\n\r");
		break;}
	case 4:{od_printf("\n\rYou catch a huge Large-Mouth Bass.\n\r");
		break;}
	default:{od_printf("\n\rWOW, you reel in a spoonbill.\n\r");
		break;}
	}
	}
else{
switch(random(5))
{
case 0:{od_printf("\n\r`bright cyan`You catch a nice-sized salmon.\n\r");
	break;}
case 1:{od_printf("\n\r`bright cyan`You catch a small sword-fish.\n\r");
	break;}
case 2:{od_printf("\n\rWow!  You reel in a sea turtle.\n\r");
	break;}
case 3:{od_printf("\n\rYou catch a large Tuna.\n\r");
	break;}
default:{od_printf("\n\rYou catch a huge brown wierd-looking fish.\n\r");
	break;}
}
}
}

void exper(int gain)
{
if(gain < 0)
	{
	if(data[user].exp<(gain*-1))
		data[user].exp=0;
	return;
	}
data[user].exp += gain;
if(data[user].exp > 60000)
	data[user].exp=60000;
if(gain > 0)
	od_printf("\n\r`bright blue`You gain `bright red`%d `bright blue`experience points.\n\r",gain);
if(gain < 0)
	{gain = gain * -1;
	od_printf("\n\r`bright blue`You loose `bright red`%d `bright blue`experience points.\n\r",gain);}
}

FILE *returnfile(char spec)
{
int shandle;
if((shandle=eopen("special.dat",4))==-1)
	{od_printf("`red`WOOOWOWOWOW!  Big error, inform sysop, missing file: special.dat");
	od_exit(1,FALSE);
	}
read(shandle,sp,(sizeof(struct special)*20));
close(shandle);
char filename[12];
sprintf(filename,"spe%d.dat",edata.spe[spec]);
FILE *hello;
if((hello=fopenr(filename,3))==NULL)
	{
	od_printf("`red`WOW big error, infor sysop, missing file: %s",filename);
	od_exit(1,FALSE);
	}
return hello;
}

void printspec(char spec)
{
FILE *shandle;
int count;
char file[12];
char p;
if(edata.spe[spec]==0)
	{
	od_printf("`white`- - none - -");
	}
else{sprintf(file,"spe%d.dat",edata.spe[spec]);
	if((shandle = fopenr(file,1))==NULL)
		{
		od_printf("`red`Oh no!  Big error, inform sysop missing data file: %s.\n\r",file);
		return;
		}
	do{
	p = fgetc(shandle);
	if(p=='~')
		{
		p=fgetc(shandle);
		if(p == 'N')
			{
			do{
			p = fgetc(shandle);
			if(p == '~')
				break;
			else od_putch(p);
			}while(p != EOF);
			}
		else if(p == 'M')
			{
			fscanf(shandle,"%d",&count);
			od_printf("    `white`%d",count);
			break;
			}
		}
	}while(p!=EOF);
	if(p == EOF)
		od_printf("`red`Error: inform sysop of corrupted data file: %s\n\r",file);
	}
fclose(shandle);
}


void pspec(char spec)
{
FILE *shandle;
char p;
char file[12];
if(edata.spe[spec]==0)
	{
	od_printf("`white`- - none - -");
	}
else{sprintf(file,"spe%d.dat",edata.spe[spec]);
	if((shandle = fopenr(file,1))==NULL)
		{
		od_printf("`red`Oh no!  Big error, inform sysop missing data file: %s.\n\r",file);
		return;
		}
	do{
	p = fgetc(shandle);
	if(p=='~')
		{
		p=fgetc(shandle);
		if(p == 'N')
			{
			do{
			p = fgetc(shandle);
			if(p == '~')
				{p = 1;
				break;}
			else od_putch(p);
			}while(p != EOF);
			}
		}
	}while((p!=EOF)&&(p!=1));
	if(p == EOF)
		{
		od_printf("`red`Error: inform sysop of corrupted data file: %s\n\r",file);
		}
	}
fclose(shandle);
}



void addspec(char add)
{
for(int slide = 0;slide<10;slide++)
	{
	if(edata.spe[slide] == 0)
		{edata.spe[slide]=add;
		break;}
	}
if(slide == 10)
	{
	char whi;
	int which;
	od_printf("\n\r`bright white`You will lose one of these special attacks:  ");
	swrite("\n\r~150.  "); printspec(0);
	swrite("\n\r~151.  "); printspec(1);
	swrite("\n\r~152.  "); printspec(2);
	swrite("\n\r~153.  "); printspec(3);
	swrite("\n\r~154.  "); printspec(4);
	swrite("\n\r~155.  "); printspec(5);
	swrite("\n\r~156.  "); printspec(6);
	swrite("\n\r~157.  "); printspec(7);
	swrite("\n\r~158.  "); printspec(8);
	swrite("\n\r~159.  "); printspec(9);
	swrite("\n\r~15F.  ~9For that sucky spell!  Forget that.");
	od_printf("\n\r`bright magenta`Which one?  ");
	whi=od_get_answer("F0987654321");
	switch(whi)
	{
	case '0':which=0;
			break;
	case '1':which=1;break;
	case '2':which=2;break;
	case '3':which=3;break;
	case '4':which=4;break;
	case '5':which=5;break;
	case '6':which=6;break;
	case '7':which=7;break;
	case '8':which=8;break;
	case '9':which=9;break;
	case 'F':which=10;break;
	}
	if(which!=10) edata.spe[which]=add;
	}
}

char speccheck(char check)
{
FILE *shandle;
char file[12];
char p;
int comp;
sprintf(file,"spe%d.dat",check);
if((shandle = fopenr(file,2))==NULL)
	{
	od_printf("`red`Big Error!  Inform sysop, missing data file: %s.",file);
	od_exit(0,FALSE);
	}
do{
p = fgetc(shandle);
if(p=='~')
	{
	p = fgetc(shandle);
	if(p == 'M')
		{fscanf(shandle,"%d",comp);
		break;}

	}

}while(p != EOF);
if(p == EOF)
	{od_printf("`red`Big Error!  Inform sysop, error in data file: %s",file);
	return FALSE;}
if(edata.spec < comp)
	return FALSE;
else{edata.spec-=comp;
	return TRUE;}
}



char checkspec(char check)
{
for(int slide = 0;slide<10;slide++)
	{
	if(edata.spe[slide]==check)
		break;
	}
if(slide == 10)
	return FALSE;
else return TRUE;
}

void hevent(void);
void monks(void);
void cemetary(void);

void eventsplit(char swit)
{
void leaf(void);
if(turncheck(2)==0);
else{
switch(swit)
{
case 'A':{if(data[user].town == 'P')
			{
			od_printf("`bright white`\n\rIt seems that you have been infused with a great magic.\n\r");
			od_printf("You have learned `bright red`Armageddon`bright white`!\n\r");
			addspec(12);
			}
		else edata.forest++;
		break;
		}
case 'H':{hevent();
		break;}
case 'M':{monks();
		break;}
case 'T':{cemetary();
		break;}
case 'D':{leaf();
		break;}
}
}
}

void leaf(void)
{
if(checkspec(9)==TRUE||data[user].town!='D')
	edata.forest++;
else{
od_clr_scr();
od_printf("`bright white`The jungle opens up around the creek and you easily spot the sparkling\n\r");
od_printf("leaves.  Do you take one and bite out of it?\n\r");
od_printf("   Y`white`es or `bright white`N`white`o\n\r");
if(od_get_answer("YN")=='Y')
	{
	od_printf("`bright blue`Ignoring the smirks of the townspeople, you take a large bite out the leaf.\n\r");
	od_printf("And...\n\r");
	sleep(1);
	od_printf("`bright red`You Fall Over Dead!");
	getreturn();
	od_printf("`bright white`Just Kidding!\n\r");
	od_printf("You have learned `bright red`DEFORM`bright white`.\n\r");
	addspec(9);
	specialadd(1);
	}
else{od_printf("`bright blue`Listening to the advice of the townspeople, you walk away from the leaf.");
	getreturn();
	}
}
}

void monks(void)
{
char monkcom;
if(checkspec(8)==TRUE||data[user].town!='H')
	{edata.forest++;
	}
else{
do{
od_clr_scr();
od_printf("`bright magenta`");
swrite("You come upon a small camp of tents and small houses built into the side of\n\r");
swrite("trees.  Many cloaked figures walk the camp.  Some turn towards you while\n\r");
swrite("others do not notice your present.\n\n\r");
swrite("~11(~15R~11)  Talk to red cloaked man\n\r");
swrite("(~15T~11)  Talk to green cloaked man\n\r");
swrite("(~15G~11)  Go into stone temple\n\r");
swrite("(~15L~11)  Leave\n\r");
monkcom = command("RTGL",4);
switch(monkcom)
{
case 'R':{od_printf("\n\r`bright red`He says nothing, instead he points to the stone temple.\n\r");
		getreturn();
		break;}
case 'T':{od_printf("\n\r`bright green`\"Come for power?  When asked the riddle, think not of physical objects.  When\n\r");
		od_printf("thy mind is upon the mystical world, thou shalt gain thy reward.\"\n\r");
		getreturn();
		break;}
case 'G':{od_printf("\n\r`bright white`You enter the small stone temple...");
		getreturn();
		od_clr_scr();
		if((checkspec(8)==TRUE) || (data[user].skill < 3))
			{od_printf("`bright red`\"LEAVE!  We can teach your uneducated kind nothing!\"\n\r");
			od_printf("`bright blue`With a blast of smoke, you are back outside.\n\r");
			getreturn();
			break;
			}
		od_printf("`bright red`\"Will you take the challenge for power knowing failure may cost you dearly?\"\n\r  `bright white`Y`white`es or `bright white`N`white`o?");
		if(od_get_answer("yn") == 'n')
			{od_printf("`bright red`\n\r\"Then leave!  Miserable soul!\"\n\r");
			getreturn();
			break;}
		od_printf("\n\r\n`bright white`My soul surrounds you.\n\r");
		swrite("You hear me, but I make no sound.\n\r");
		swrite("You see me, but I am invisible.\n\r");
		swrite("In my eyes, you were born,\n\r");
		swrite("and in my hands, you will die.\n\r");
		swrite("You can not kill me,\n\r");
		swrite("nor can you stop me.\n\r");
		swrite("Only in my wish, will you answer this question.\n\r\n");
		swrite("~9What am I?\n\r~7>~15 ");
		char answer[14];
		od_input_str(answer,14,30,150);
		if(stricmp(answer,"destiny")==0)
			{
			od_printf("\n\r`bright cyan`\"CORRECT!  Your reward is this scroll.\"\n\r");
			od_printf("`bright white`You have learned `bright red`TAUNT`bright white`.\n\r");
			addspec(8);
			exper(10);
			char buf[80];
			sprintf(buf,"~9%s ~15has visited the Monk's stone temple and solved the riddle!",data[user].alias);
			logwrite(buf);
			if(data[user].sex=='M')
			sprintf(buf,"He has learned ~12Taunt~15.\n");
			else sprintf(buf,"She has learned ~12Taunt~15.\n");
			logwr(buf);
			getreturn();
			}
		else{od_printf("\n\r`bright red`\"You have failed the challenge.  Your reward is death.\"\n\r");
			od_printf("`bright cyan`The cloaked figure raises his staff!\n\r\n");
			swrite("~11[~15B~11]  ~13Cry and Plead for your life\n\r");
			swrite("~11[~15T~11]  ~13Stand stout and take it like a man\n\r");
			if(od_get_answer("bt")=='b')
				{honoradd(-5);
				od_printf("`bright red`\n\r\"A coward you are!\"  `bright blue`And a light comes from his staff.\n\r");
				od_printf("`red`Hitpoints go down to 1!\n\r");
				data[user].hitpts=1;
				getreturn();
				break;
				}
			else{honoradd(5);
				od_printf("\n\r`bright red`\"A brave man you are, but bravery can be a person's downfall!\"\n\r");
				od_printf("`bright blue`A light comes from his staff.\n\r");
				od_printf("`red`Hitpoints go down to 1!\n\r");
				data[user].hitpts=1;
				getreturn();
				break;
				}
			}
		break;
		}
}
}while(monkcom != 'L');}
}

void hevent(void)
{
char hcom;
if(data[user].town=='H')
	{
	do{
	od_clr_scr();
	od_printf("`green`You are standing in a small cabin obviously made from the forest around\n\r");
	od_printf("it.  A short puggy man stands ready to assist you.\n\r");
	od_printf("\n\r(`bright white`A`green`)  Ask for Advice\n\r");
	od_printf("(`bright white`L`green`)  Leave\n\r");
	hcom=command("AL",2);
	if(hcom == 'A')
		{
		if(checkspec(1)==FALSE)
			{
			od_printf("\n\r`bright red`\"I see.\"`bright blue`  The man waves his hand over your head. `bright red`\"Now you ");
			od_printf("have the magical\n\rability to heal yourself in battle.  But this is a fraction ");
			od_printf("of your ability.  \n\rCome back when you are more learned in the way of the land.\"\n\r");
			addspec(1);
			getreturn();
			}
		else if((data[user].skill>3)&&(checkspec(6)==FALSE))
			{
			od_printf("\n\r`bright cyan`\"Perhaps you are ready for an advancement in your magical ability.  See this\n\r");
			od_printf("bowl of liquid.  Inhale it but do not touch.  If you are ready to advance,\n\r");
			od_printf("you will learn a helpful spell.\"\n\r");
			getreturn();
			od_printf("`bright blue`You inhale it deeply, and your magic level increases.");
			od_printf("\n\r`bright white`You have learned `bright red`VANISH`bright white`.");
			addspec(6);
			specialadd(1);
			getreturn();
			}
		else if(data[user].skill > 4)
			{
			od_printf("\n\r`bright cyan`I could help you, but it would cost you your chance for training until the\n\r");
			od_printf("next skill level.  Still want training?  [`bright blue`Y`bright cyan`/`bright blue`n`bright cyan`]  ");
			if(od_get_answer("yn\n\r")=='n')
				{
				od_printf("\n\r`bright cyan`\"Sorry, you don't have a training point to use.\"\n\r");
				getreturn();
				}
			else{
				if(edata.trainpts<1)
					od_printf("\n\r`bright blue`It appears you cannot advance.\n\r");
				else{
				od_printf("\n\r`bright blue`The man waves his hand...");
				specialadd(1);
				edata.trainpts--;}
				getreturn();
				}
			}
		else{od_printf("\n\r`bright red`\"There is nothing I can do for you right now.\"");
		getreturn();
		}
		}
	}while(hcom!='L');
	}
else edata.forest++;
}

void cemetary(void)
{
if(checkspec(7)==TRUE||data[user].town!='H')
	{edata.forest++;
	}
else{
od_clr_scr();
swrite("~15You are standing in the middle of an old and run-down cemetary.  Most of the\n\r");
swrite("tombstones, if standing, are chipped and cracked making them unreadable.\n\r");
sleep(1);
swrite("~7As you are about to leave, a dense mist forms around a large masoleum and\n\r");
swrite("~7a ghostly figure forms in front of you.  It appears that it is trying to\n\r");
swrite("speak but you can hear no words.\n\r");
swrite("~8A vial of potion materaulizes in your hand.\n\r");
swrite("Drink it down?  ~15Y~8es or ~15N~8o\n\r");
if(od_get_answer("yn")=='y')
	{
	swrite("~15You drink the potion down...\n\r");
	sleep(1);
	swrite("You have learned ~12BANISH~15.\n\r");
	addspec(7);
	specialadd(1);
	getreturn();
	}
else{
	swrite("~15You run out of the cemetary with your tail between your legs.");
	getreturn();
	}
}
}

void tiashi(void)
{
char com;
void tiashit(void);
od_clr_scr();
do{
od_printf("`green`\n\rIn a small mountain valley, a group of small huts and large meeting halls\n\r");
od_printf("sit under the few trees here.  Many short men scurry around doing chores and\n\r");
od_printf("practicing martial arts.  Despite the coldness and shrill winds, this appears\n\r");
od_printf("to be a cozy little village.\n\r");
swrite("\n\r~10(~15S~10)  Speak with little boy");
swrite("\n\r~10(~15R~10)  Building with red flags\n\r");
swrite("(~15B~10)  Building with black flags\n\r");
swrite("(~15M~10)  Main meeting hall\n\r");
swrite("(~15L~10)  Leave\n\r");
com = command("SRBML",5);
switch(com)
{
case 'S': swrite("\n\n\r~5The small boy looks incredibly famished...\n\r");
		swrite("You say hi but the boy says nothing.\n\r");
		swrite("He instead holds out his hand as if he wants something...\n\r");
		swrite("~5(~15F~5)ish   (~15B~5)read   (~15M~5)eat   (~15C~5)oin   (~15N~5)o way, I worked for these.\n\r");
		swrite("~7Do you give something?\n\r");
		switch(od_get_answer("FBMCN"))
		{
		case 'F':{if(edata.i0 <1)
					{od_printf("`red`\n\rYou have none.");
					break;}
				od_printf("\n\r");honoradd(2);
				swrite("~5\n\rYou hand the little boy a fish.\n\r");
				swrite("~13\"Thank you, kind sir.  This camp was made to get away from the king, want to\n\r");
				swrite("know more?  hehe...\" ~5He looks at your bag.\n\r");
				edata.i0--;
				break;}
		case 'M':{
				if(edata.i2 <1)
					{od_printf("`red`\n\rYou have none.");
					break;}
				od_printf("\n\r");honoradd(2);
				swrite("~5\n\rYou hand the little boy a hard-earned piece of meat.\n\r");
				swrite("~13\"Thanks, Tiashi plans to raid Tiw as soon as he is strong enough.  But that\n\r");
				swrite("may be awhile.\"  ~5He looks at your bag.\n\r");
				edata.i2--;
				break;
				}
		case 'B':{
				if(edata.i3<1)
					{od_printf("`red`\n\rYou have none.");
					break;}
				od_printf("\n\r");honoradd(2);
				swrite("~5\n\rYou hand the little boy a piece of bread.\n\r");
				swrite("~13\"Oh!  We don't see much bread up here.  If Tiashi seems a little hostile\n\r");
				swrite("toward you, say something about killing the king.\"\n\r");
				edata.i3--;
				break;
				}
		case 'C':{
				if(data[user].coins < 1)
					{od_printf("`red`\n\rYou have none.");
					break;}
				od_printf("\n\r");honoradd(1);
				swrite("~13\n\r\"Why thanks!  Don't know what I would use it for, we aren't allowed in town.\"\n\r");
				data[user].coins--;
				break;
				}
		case 'N':{od_printf("\n\r");
				honoradd(-5);
				break;}
		}
		getreturn();
		break;
case 'R': swrite("\n\n\r~13Walking into the red training hall, you see many young boys practicing \n\r");
		swrite("their fighting skills.  After a moment of looking around, an older man \n\r");
		swrite("approaches you.\n\r");
		getreturn();
		swrite("~15\"What are you doing here?\"\n\r");
		swrite("~13How do you answer?\n\r");
		swrite("(~15T~13)  To get training\n\r");
		swrite("(~15F~13)  To fight!\n\r");
		swrite("(~15L~13)  Nevermind, I'm outta here!\n\r");
		swrite("? ");
		switch(od_get_answer("TFL"))
			{
		case 'T':{if(checkspec(3)==TRUE)
					{swrite("~15\n\r\"There is nothing I can teach you, sorry.\"");
					getreturn();
					break;}
				swrite("\n\r~15We do not normally train those who are outside our little community.  But, my\n\r");
				swrite("children and pupils are hungry, so if you give me 5 pieces of bread, 5 large\n\r");
				swrite("slabs of meat and 10 fish, I will show you an attack that will punish any\n\r");
				swrite("who attempt to oppose you.  ");
				swrite("[~9Y~15/~9n~15]  ");
				if(od_get_answer("YN\n\r") == 'N')
					{
					swrite("~15\n\r\"Come back when you feel more passionate.\"\n\r");
					break;
					}
				else{
					if((edata.i0<10)||(edata.i2<5)||(edata.i3<5))
						{
						swrite("\n\r\n~15\"You do not have enough to pay for my training.  Please find some and return.\"");
						getreturn();
						break;}
					else{edata.i0-=10;
						edata.i2-=5;
						edata.i3-=5;
						swrite("~13\n\rThrough hours of training, you finally come to grips with the ~9Fast Action\n\r");
						swrite("Attack~13.  Now you can attack from all directions in under a second.\n\r");
						swrite("~15\"Thank you for helping our children here, and I hope this helps you.\"");
						getreturn();
						addspec(3);
						break;}
					}
				}
		case 'F':{swrite("\n\r~15\"I see...\"");
				getreturn();
				swrite("~13Suddenly, the short old man jumps at you with a barrage of kicks.  He easily\n\r");
				swrite("beats you back to the wall, and then to the door, and then out the door.\n\r");
				getreturn();
				break;}
		case 'L':{swrite("\n\r~15\"Leave our village if you have no business here.\"");
				getreturn();
				break;
				}
			}
		break;
case 'B': od_printf("\n\r`bright black`A man in a black ninja suit appoaches you...");
		getreturn();
		if(data[user].dex<12)
			{od_printf("\n\r`white`\"You are a big brute that can't move at all.  Make yourself more agile and\n\r");
			od_printf("come back.  Until then, you are not wanted here.\"");
			getreturn();
			}
		else if(checkspec(13)==FALSE)
			{od_printf("\n\r`white`\"For 500 coins, I will teach you a very powerful martial arts move.\"");
			od_printf("\n\r   `bright white`Y`white`es or `bright white`N`white`o");
			if(od_get_answer("YN")=='N')
				{od_printf("\n\r`white`\"Then leave, you are not wanted here.\"\n\r");
				getreturn();
				break;}
			if(data[user].coins < 500)
				{
				od_printf("\n\r`white`\"You do not have enough coins.  You are not wanted here.\"\n\r");
				getreturn();
				break;}
			data[user].coins -= 500;
			od_printf("\n\r`bright black`Through hours of training, you come to grips with a very powerful tactic\n\r");
			od_printf("that could drop most foes to their knees before you.\n\r");
			addspec(13);
			getreturn();
			break;
			}
		else{od_printf("\n\r\"You are no longer wanted here.\"\n\r");
			getreturn();
			}

		break;

case 'M': if(stricmp(edata.compname,"Tiashi")==0)
			{od_printf("`bright blue`\n\rThere is noone here.\n\r");
			getreturn();
			break;}
		od_printf("`bright blue`\n\rYou walk into the main hall and on a throne sits Tiashi Ci.\n\r");
		od_printf("You approach him.");
		getreturn();
		tiashit();
		break;

}
}while(com!='L');
}

void tiashit(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rBefore you is a man in excellent condition.  You would dread a fight\n\r");
od_printf("with him, yet he looks like a powerful ally.\n\r");
od_printf("`bright cyan`Name\n\rCamp\n\rBye\n\r");
talknagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"My name is Tiashi Ci and I am not to be played with.  State your business and\n\r");
	od_printf("move on.  Why are you here?\"");
	}
else if(stricmp(diap,"camp")==0)
	{od_printf("\"We moved up here when Tiw was taken over by the soldiers in the academy.\"");
	}
else if(stricmp(diap,"soldiers")==0)
	{od_printf("\"They have a fighting tactic to put most men down.  However, we have developed\n\r");
	od_printf("martial arts to put them down.\"");}
else if((stricmp(diap,"hilder")==0)||(stricmp(diap,"hilder said hi")==0))
	{od_printf("\"He said hi, ehh?  He tried to exterminate us once but we easily drove the\n\r");
	od_printf("force off.\"");
	}
else if(stricmp(diap,"king")==0)
	{od_printf("`bright magenta`Tiashi frowns and pulls a knife from his belt.  `bright blue`\"What about him?\"");
	}
else if((stricmp(diap,"kill king")==0)||(stricmp(diap,"kill")==0))
	{od_printf("`bright magenta`The look on Tiashi's face brightens up.  `bright blue`\"Indeed, that would be marvelous.\"\n\r");
	od_printf("`bright magenta`He looks you over...");
	getreturn();
	if((checkspec(13)==FALSE)||(checkspec(3)==FALSE))
		{od_printf("`bright blue`\"But I can't trust you.  Maybe if you knew our ways...\"");
		}
	else if(data[user].skill<15)
		{od_printf("`bright blue`\"But you are not strong enough to make one wart on his rear-end.  Maybe gain\n\r");
		od_printf("more power, and we can be allies.\"");
		}
	else if(data[user].honor<0)
		{od_printf("`bright blue`\"How could I trust you?  I can tell your honesty is lacking.\"");
		}
	else{od_printf("`bright blue`\"Yes, I do believe we can be allies.  I will join you.  Ok?\"\n\r");
		if(edata.compatt>0)
			{od_printf("`bright magenta`You will have to let `bright white`%s`bright magenta` go.\n\r",edata.compname);
			}
		od_printf("   `bright white`Y`white`es or `bright white`N`white`o\n\r");
		if(od_get_answer("YN")=='Y')
			{
			od_printf("`bright blue`\"Let us go to the Deep Forest, where my master lives.  He will help more.\"");
			strcpy(edata.compname,"Tiashi");
			strcpy(edata.compa,"Tiashi slices with his Samuri");
			edata.compatt=12;
			}
		else od_printf("`bright blue`\"Very well, but I believe you are unwise.\"");
		}
	}
else if((stricmp(diap,"bye")==0)||(stricmp(diap,"")==0))
	{
	od_printf("`bright blue`\"Please take your leave of this valley.\"");
	goto endtalk;
	}
goto talknagain;
endtalk:
}
/*  Finish if time permits
void guildmaster(void)
{
if(data[user].skill == 1)
			{od_printf("Thou art a bit puny.  Best needs get some training.\n\r");
			od_printf("Don't ye got some money?  Catch some fish, sell it!.\n\r");
			}
		else if((data[user].skill > 1) && (data[user].skill < 4))
			{od_printf("Ahh, a new adventurer has enter the guild.  Welcome aboard.\n\r");
			od_printf("A few helpful hints thou'll need:  Don't fight a cat when thyself\n\r");
			od_printf("art but a mouse.  The Den... well young man, thou dost needest to go.\n\r");
			}
		else if(data[user].skill > 3)
			{od_printf("Wow!  Thou art a strapping lad!  Get off this island.  Check out the\n\r");
			od_printf("other one!.\n\r");
			}
} */

