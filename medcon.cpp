#include "med.h"
extern struct player_info data[60];
extern int user;
extern struct info2 edata;

void silvia(void)
{
char diap[20];
char yes;
od_clr_scr();
od_printf("`bright blue`\n\rStanding before you is a beautiful, blonde girl.\n\r");
od_printf("`bright cyan`Name\n\rJob\n\rBye\n\r");
talksagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"Why, I'd be pleased if you called me Silvia.\"");}
else if(stricmp(diap,"job") == 0)
	{od_printf("\"Well... my job is to make any visitors here at the baths comfortable.  If\n\r");
	od_printf("you decide you would like to be more comfortable, just tell me.\"");}
else if(stricmp(diap,"baths") == 0)
	{od_printf("\"It is a great place.  I get much gold and I am always having fun.\"");}
else if(stricmp(diap,"comfortable") == 0)
	{od_printf("\"I make guests comfortable by giving them a bath, a massage, and for someone\n\r");
	od_printf("who wants some good companionship, we could go to the bedroom.\"");}
else if(stricmp(diap,"bath") == 0)
	{if(data[user].sex == 'M')
		{od_printf("\"Well, milord, that sounds like a good idea.\"");
		od_printf("`bright cyan`\n\rSilvia helps you out of your cumbersome armour and bathes you thouroghly\n\r");
		od_printf("using her body as a washcloth.");}
	else{od_printf("\"Well, milady, I can understand why you would like a woman to bathe you.\"");
		od_printf("`bright cyan`\n\rSilvia helps you out of your cumbersome armour and bathes you thouroghly.");
		}
	}
else if(stricmp(diap,"massage") == 0)
	{od_printf("\"Wonderful!  But I must charge 10 coins.  OK?\" [Y/N] ");
	yes = od_get_answer("YN");
	if(yes == 'Y')
		{if(data[user].coins < 10)
			od_printf("`red`\n\rYou don't have the coins.");
		else{data[user].coins -= 10;
			od_printf("`bright cyan`\n\rSilvia helps you out of your clothing and you lie down on a table.  She\n\r");
			od_printf("rubs your sore muscles down till they are loose and ready to fight again.");
			data[user].hitpts += 5;
			if(data[user].hitpts > data[user].totalhit)
				data[user].hitpts = data[user].totalhit;
			}
		}
	}
else if(stricmp(diap,"bedroom") == 0)
	{if(data[user].sex == 'M')
		{od_printf("\"That is a wonderful idea, milord.  Will you pay 45 coins?\"");
		yes = od_get_answer("YN");
		if(yes == 'Y')
			{if(data[user].coins < 45)
				{od_printf("`red`\n\rYou don't have enough coins.");
				}
			else{data[user].coins -= 45;
				od_printf("`bright cyan`\n\rSilvia leads you to a small room in the back with a single small bed in it.\n\r");
				od_printf("You both take off your clothes and lie down on the bed.  You leave the room\n\r");
				od_printf("a much happier adventurer.");
				if(data[user].hitpts == data[user].totalhit)
					data[user].hitpts += data[user].hitpts;
				else data[user].hitpts=data[user].totalhit;
				}
			}
		}
	else{od_printf("\"If that's what pleases you, fine.  But I must charge 65 coins.  Agreed?\"");
		yes = od_get_answer("YN");
		if(yes == 'Y')
			{if(data[user].coins < 65)
				od_printf("`red`\n\rYou don't have enough coins.");
			else{data[user].coins -= 65;
				od_printf("`bright cyan`\n\rSilvia leads you to a small room in the back with a single small bed in it.\n\r");
				od_printf("You both take off your clothes and lie down together on the bed.  You have\n\r");
				od_printf("much fun and leave the room happier.");
				od_printf("`bright cyan`\n\rSilvia leads you to a small room in the back with a single small bed in it.\n\r");
				od_printf("You both take off your clothes and lie down on the bed.  You leave the room\n\r");
				od_printf("a much happier adventurer.");
				}
			}
		}
	}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Please come back.\"");
	goto send;}
else{od_printf("\"I'm sorry?\"");}
goto talksagain;
send:
}




void oliver(void)
{
char diap[20];
char yes;
od_clr_scr();
od_printf("`bright blue`\n\rStanding before you is a handsome, blonde young man.\n\r");
od_printf("`bright cyan`Name\n\rJob\n\rBye\n\r");
talksagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"You can call me Oliver.\"");}
else if(stricmp(diap,"job") == 0)
	{od_printf("\"My job is to make any visitors here at the baths comfortable.  If\n\r");
	od_printf("you decide you would like to be more comfortable, just tell me.\"");}
else if(stricmp(diap,"baths") == 0)
	{od_printf("\"It is a great place.  I get much gold and I am always having fun.\"");}
else if(stricmp(diap,"comfortable") == 0)
	{od_printf("\"I make guests comfortable by giving them a bath, a massage, and for someone\n\r");
	od_printf("who wants some good companionship, we could go to the bedroom.\"");}
else if(stricmp(diap,"bath") == 0)
	{if(data[user].sex == 'F')
		{od_printf("\"Well, milady, that sounds like a good idea.\"");
		od_printf("`bright cyan`\n\rOliver helps you out of your cumbersome armour and bathes you thouroghly\n\r");
		od_printf("using his body as a washcloth.");}
	else{od_printf("\"Well, milord, I can understand why you would like a man to bathe you.\"");
		od_printf("`bright cyan`\n\rOliver helps you out of your cumbersome armour and bathes you thouroghly.");
		}
	}
else if(stricmp(diap,"massage") == 0)
	{od_printf("\"Wonderful!  But I must charge 10 coins.  OK?\" [Y/N] ");
	yes = od_get_answer("YN");
	if(yes == 'Y')
		{if(data[user].coins < 10)
			od_printf("`red`\n\rYou don't have the coins.");
		else{data[user].coins -= 10;
			od_printf("`bright cyan`\n\rOliver helps you out of your clothing and you lie down on a table.  He\n\r");
			od_printf("rubs your sore muscles down till they are loose and ready to fight again.");
			data[user].hitpts = data[user].totalhit;
			}
		}
	}
else if(stricmp(diap,"bedroom") == 0)
	{if(data[user].sex == 'F')
		{od_printf("\"That is a wonderful idea, milady.  Will you pay 45 coins?\"");
		yes = od_get_answer("YN");
		if(yes == 'Y')
			{if(data[user].coins < 45)
				{od_printf("`red`\n\rYou don't have enough coins.");
				}
			else{data[user].coins -= 45;
				od_printf("`bright cyan`\n\rOliver leads you to a small room in the back with a single small bed in it.\n\r");
				od_printf("You both take off your clothes and lie down on the bed.  You leave the room\n\r");
				od_printf("a much happier adventurer.");
				if(data[user].hitpts >= data[user].totalhit)
					data[user].hitpts = (data[user].totalhit*2);
				else data[user].hitpts = data[user].totalhit;}
			}
		}
	else{od_printf("\"If that's what pleases you, fine.  But I must charge 65 coins.  Agreed?\"");
		yes = od_get_answer("YN");
		if(yes == 'Y')
			{if(data[user].coins < 65)
				od_printf("`red`\n\rYou don't have enough coins.");
			else{data[user].coins -= 65;
				od_printf("`bright cyan`\n\rOliver leads you to a small room in the back with a single small bed in it.\n\r");
				od_printf("You both take off your clothes and lie down together on the bed.  You have\n\r");
				od_printf("much fun and leave the room happier.");
				if(data[user].hitpts >= data[user].totalhit)
					data[user].hitpts = (data[user].totalhit*2);
				else data[user].hitpts = data[user].totalhit;}

			}
		}
	}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Please come back.\"");
	goto send;}
else{od_printf("\"I'm sorry?\"");}
goto talksagain;
send:
}

void talkhidepir(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rThe dirty pirate has a bandanna on his head, a golden tooth, and a hook\n\r");
od_printf("for his right hand.\n\r");
od_printf("`bright cyan`Name\n\rDeath Scythe\n\rBye\n\r");
talknagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I be Mole.\"");}
else if(stricmp(diap,"death scythe") == 0)
	{od_printf("\"You want to know where the Death Scythe is, huh?  Ok, I'll tell you.  I\n\r");
	od_printf("mean, it does us no good and it never did.  We got rid of it so the king\n\r");
	od_printf("could not get it.  It is nothing but a weapon of death.  Go to the Deep\n\r");
	od_printf("Forest in Burkshire and look for the bald spot.\" (press \"=\")");
	if(edata.prodeath == 2)
		{od_printf("\n\r\"Here is 20 coins for passage away from here.  Don't come back.\"");
		data[user].coins += 20;
		coins();}
	if(edata.prodeath < 3)
		{edata.prodeath = 3;}
	}
else if(stricmp(diap,"king") == 0)
	{od_printf("\"I wouldn't doubt it if he was once a pirate by the way he acts.  He\n\r");
	od_printf("certainly has no place on the throne.\"");}
else if((stricmp(diap,"")==0)||(stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Be careful with that scythe.\"");
	goto hideend;}
else{od_printf("\"I don't know anything about that.\"");}
goto talknagain;
hideend:
}

void talkscorion(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`The famous man doesn't look like much of a star.  He is a short, bald\n\r");
od_printf("man with a long, gray beard.\n\r");
od_printf("`bright cyan`Name\n\rJob\n\rBye\n\r");
talknagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"You are probably the first to ask me that ever.  I'm Scorion.\"");}
else if(stricmp(diap,"job") == 0)
	{od_printf("\"If you don't know, then please leave.\"");}
else if((stricmp(diap,"axe") == 0) || (stricmp(diap,"scorions axe") == 0) || (stricmp(diap,"scorion's axe") == 0))
	{if(edata.proscor >= 5)
		{od_printf("\"I can't let you have another one.\"");}
	else if((edata.proscor > 0) && (edata.proscor < 4))
		{od_printf("\"Please, get the dust, then I can help you.  Remember, go to Pomdirgunua and\n\r");
		od_printf("press ~ to find the faires.  Then ask them for fairy dust.\"");}
	else if(edata.proscor == 4)
		{od_printf("\"Very good!  Thank you very much!  ");
			if(data[user].coins >= 700)
				{od_printf("I will make your axe now.\"\n\r");
				od_printf("You give him the 700 coins and he adds the dust to an already made axe.\n\r");
				od_printf("Then he gives it to you.");
				data[user].weaponshort = 12;
				strcpy(data[user].stype,"Scorion's Axe");
				data[user].coins -= 700;
				edata.proscor = 5;
				char bufff[70];
				sprintf(bufff,"%s has purchased Scorion's Axe.\n\r",data[user].alias);
				logwrite(bufff);
				}
			else{od_printf("You don't have enough coins.\"");}
		}
	else if(edata.proscor == 0)
		{od_printf("\"Sure, I can give you an axe for 700 coins.  But you must go to the East\n\r");
		od_printf("Forest to get me some fairy dust which is what gives the axe it's power.  Go\n\r");
		od_printf("to Pomdirgunua and look for the fairy city right outside of the farms.  Ask\n\r");
		od_printf("them for some.\"   Press \"~\" in Pomdirgunua.");
		edata.proscor = 1;}
	}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0)||(stricmp(diap,"")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Good idea.\"");
	goto scorend;}
else{od_printf("\"I'm just an axe-maker.\"");}
goto talknagain;
scorend:
}
void talkpomsol(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright magenta`\n\rThe old soldier looks battle worn.  He may give you information.\n\r");
od_printf("`bright cyan`Name\n\rsoldiers\n\rTavern\n\rpomdirgunua\n\rBye");
talkdenpatagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I am Sergeant Hendrix.\"");}
else if(stricmp(diap,"soldiers") == 0)
	{od_printf("\"The soldiers are the guardians of Trimmail and what it stands for.  We take\n\r");
	od_printf("land away from farmers and merchants in order to make the economy more\n\r");
	od_printf("stable.  So don't hassle me about it being the wrong thing.\"");}
else if(stricmp(diap,"tavern") == 0)
	{od_printf("\"We took this tavern as a headquarters.  The king plans to set up a summer\n\r");
	od_printf("home at the site of the old tavern.  We are here to make sure noone decides\n\r");
	od_printf("to get in the way of the construction when it happens.\"");}
else if(stricmp(diap,"king") == 0)
	{od_printf("\"He does what he thinks is best for the land of Trimmail.  Perhaps, taking\n\r");
	od_printf("as much land as he does is not necessary, but he uses that land in a good\n\r");
	od_printf("way.  Once, the city of Tiw was completely devoted to farming.  Now in\n\r");
	od_printf("place of the farms is a wonderful training academy for the soldiers.  If\n\r");
	od_printf("you would like to become a soldier, that is the place to go.\"");}
else if(stricmp(diap,"pomdirgunua") == 0)
	{od_printf("\"This town is such an easy target for the king.  It's bueatiful and\n\r");
	od_printf("peaceful.  We are getting so bored here.  Noone puts up a fight.  This town\n\r");
	od_printf("is nothing like Hayward.  When we went to take over a farm there, the owner\n\r");
	od_printf("sometimes made us kill him.  The last farm we took over there, the Royal\n\r");
	od_printf("soldiers did it all themselves.  The Royals are good.  They can tie up\n\r");
	od_printf("a person and drag him out in only seconds.\"");}
else if((stricmp(diap,"royal") == 0) || (stricmp(diap,"royals") == 0) || (stricmp(diap,"royal soldiers") == 0))
	{od_printf("\"They are also trained at the camp in Tiw.  Most have a special gift in\n\r");
	od_printf("fighting or are just very experienced.\"");}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0)||(stricmp(diap,"")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Don't mess with us soldiers.\"");
	goto pomsolend;}
else{od_printf("\"What do I look like, a scholar?\"");}
goto talkdenpatagain;
pomsolend:
}

void talkdenpir(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright magenta`\"How are you, Matey?\" asks the pirate.\n\r");
od_printf("`bright cyan`Name\n\rPirates\n\rTavern\n\rThe Den\n\rBye\n\r");
talkpiragain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I be Blacktooth.  Glad to meet you %s.",data[user].alias);}
else if(stricmp(diap,"leaf") == 0)
	{od_printf("\"Ey!  heard o it!  Maybe de armsmaster know where to find\"");
	}
else if(stricmp(diap,"pirates") == 0)
	{od_printf("\"Why, you knows alot there, don't ye?  Yea, de Wolfs are the most powerful\n\r");
	od_printf("pirate band in the land.  Nay, de most powerful pirate band anywhere.  Nay,\n\r");
	od_printf("de most powerful band anywhere.\"");}
else if(stricmp(diap,"tavern") == 0)
	{od_printf("\"Blimey!  Never had noone ask me about this tavern.  It's down roight fittin'.\"");}
else if(stricmp(diap,"the den") == 0)
	{od_printf("\"Why, tis the hangout of de Wolf ban.\"");}
else if((stricmp(diap,"death scythe") == 0) || (stricmp(diap,"death") == 0) || (stricmp(diap,"scythe") == 0))
	{od_printf("As you say that, the pirate starts to sweat and looks frigthened of something.\n\r");
	if(data[user].skill >= 10)
		{od_printf("\"Listen, if I tell thee about that, I be killed.  Go to Trimmail, look\n\r");
		od_printf("in de Inn for a ex-pirate.  If anyone will, he help you.\"");
		if(edata.prodeath < 1)
			edata.prodeath = 1;
		}
	else{od_printf("\"Ye don't scare me.  Get from me face!\"");
		goto pirend;}
	}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0)||(stricmp(diap,"")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Take it easy, Mate.\"");
	goto pirend;}
else{od_printf("\"What's that?\"");
	}
goto talkpiragain;
pirend:
}

void talkdenpatrons(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright magenta`\n\rYou sit down at a table with two drunk pirates.\n\r");
od_printf("`bright cyan`Names\n\rPirates\n\rTavern\n\rThe Den\n\rBye");
talkdenpatagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if((stricmp(diap,"name") == 0) || (stricmp(diap,"names") == 0))
	{od_printf("\"We be from the wolf pirate gang!\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"That's all you need to know.\"");}
else if(stricmp(diap,"leaf") == 0)
	{od_printf("\"Indeed!  But you must have courage...\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"Not sure we want the responsibility of your death, talk to the arms master.\"");
	}
else if(stricmp(diap,"pirates") == 0)
	{od_printf("\"That's right, he can be taught.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"That's all we are around here, fellow.\"");}
else if(stricmp(diap,"tavern") == 0)
	{od_printf("\"I like to drink here.  I hardly ever leave.\"");}
else if(stricmp(diap,"the den") == 0)
	{od_printf("\"The den will soon be only for pirates.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"Ya know, we did this about 50 years ago to another island.  Now that\n\r");
	od_printf("place is called the Wolf's Hideout.  Noone knows where it is.\"\n\r");
	sleep(1);
	od_printf("`bright blue`\n\r\"I can't believe you just told him that!\"");}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0)||(stricmp(diap,"")==0)|| (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("You quickly get away from their company.\"\n\r");
	goto denpatend;}
else if(stricmp(diap,"death scythe") == 0)
	{od_printf("\"Don't worry about it, you will stay alive longer!\"");}
else{od_printf("\"I don't know a thing about that.\"");}
goto talkdenpatagain;
denpatend:
}

void talkpommaster(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright red`The Armsmaster's face is extremely scarred.  Though, he has a peaceful look\n\r");
od_printf("just like everyone else in town.  He reminds you of a battle-scarred veteran.\n\r");
od_printf("He says to you,  \"Welcome, it's not very often that I get customers.\n\r");
talkpomagain:
od_printf("`bright blue`\n\r\"I can tell you about animals, training, Pomdirgunua, and the land.\n\r");
od_printf("Just say bye when you are finished.\"\n\r");
od_printf("`cyan`\n\r >  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I'm called Torix.\"");}
else if(stricmp(diap,"animals") == 0)
	{od_printf("\"The animals in the East Forest aren't very big.  But, the forest has magical\n\r");
	od_printf("abilities.  Every animal has a special attack.  Beware, though, of the Cyclops\n\r");
	od_printf("for it will drop even the most valient warrior in one strike.\"");}
else if(stricmp(diap,"special") == 0)
	{od_printf("\"A special attack is a king of special ability learned by an animal.  The\n\r");
	od_printf("special attack is usually much stronger than any other attack the animal can\n\r");
	od_printf("inflict.  The only thing you can count on with one of those attacks is that\n\r");
	od_printf("never will they do one and then right away do another.  To put that simply,\n\r");
	od_printf("you can defend a special attack, and then strike and not have to worry about\n\r");
	od_printf("another special attack hitting you.\"");}
else if(stricmp(diap,"cyclops") == 0)
	{od_printf("\"The Cyclops is a hidious beast with one eye in his forehead.  He carries\n\r");
	od_printf("a massive club, usually spiked.  He is the toughest in the East forest.\"\n\r");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"I put my students through a rigerous strength building program and then help\n\r");
	od_printf("them to straighten out his or her aim with bows.  I charge 55 coins.\"");}
else if(stricmp(diap,"pomdirgunua") == 0)
	{od_printf("\"I retired to this peaceful town to get away from war.\"");}
else if((stricmp(diap,"war") == 0) || (stricmp(diap,"retired") == 0))
	{od_printf("\"I was part of the Royal Guard of Trimmail when they were fighting what they\n\r");
	od_printf("should have been fighting which is the pirates.  Many lives were lost on both\n\r");
	od_printf("sides in that war.  Then, suddenly, the king stopped fighting the pirates and\n\r");
	od_printf("ordered an attack against some rebels on a farm at Trimmail.  We won flawlessly\n\r");
	od_printf("and the king kept the land.  Greed had overcome him and I retired.\"");}
else if(stricmp(diap,"king") == 0)
	{od_printf("\"He was once a great ruler.  Now, it's as if he is possessed.\"");}
else if((stricmp(diap,"the land") == 0) || (stricmp(diap,"land") == 0))
	{od_printf("\"Surely, by now you have seen it all.  Pomdirgunua is the safest town in the\n\r");
	od_printf("land as long as you stay out of the forest.  Noone here dare fights.\"\n\r");}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0)||(stricmp(diap,"")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Do come back.\"");
	goto pommasterend;}
else{od_printf("\"I wouldn't know anything about that.\"");}
goto talkpomagain;
pommasterend:
}

void talkdenmaster(void)
{
char diap[20];
od_clr_scr();
char ata;
od_printf("`bright magenta`The weapons master has the appearance of a noble.  You can tell with\n\r");
od_printf("just a glance that he brings in alot of money.\n\r");
od_printf("`bright cyan`\n\rThe weapons master looks at you, \"Sorry, I must charge ten coins\n\r");
od_printf("for information.  What do you say?\" [Y/N]  ");
ata = od_get_answer("YN");
if(ata == 'Y')
	{if(data[user].coins < 10)
		{od_printf("`bright red`\n\r\"Sorry, pal, I don't give out free info.  Get more coins.\"");
		goto masterend;}
	}
else{goto masterend;}
talkmasteragain:
od_printf("`bright blue`\n\r\"I can tell you about animals, training, The Den, and the land.\n\r");
od_printf("Just say bye when you're finished talking.\"\n\r");
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r\n");
if(stricmp(diap,"name") == 0)
	{od_printf("\"Don't worry about that, sonny.  If you want to make freindly talk,\n\r");
	od_printf("try the baths.\"");}
else if(stricmp(diap,"leaf") == 0)
	{od_printf("\"Perhaps the Jungle will provide the answers to your quest.  In the Jungle is\n\r");
	od_printf("a small `bright white`creek`bright blue`, the leaves line the creek.\"");
	}
else if(stricmp(diap,"creek") == 0)
	{
	od_printf("\"You really want to find them, ehh?  OK, find the creek by pressing D.  The\n\r");
	od_printf("rest is up to you.  hehe.\"");
	}
else if(stricmp(diap,"animals") == 0)
	{od_printf("\"The jungle animals are alot stronger than those creatures you are used to\n\r");
	od_printf("from the small, nowhere town of Hayward.  There is a deadly Red Parrot that\n\r");
	od_printf("hunts from the sky.  But the worst thing in the jungle, besides pirates, is\n\r");
	od_printf("the legendary wolfman.  He is half-man, half-wolf.\"");}
else if((stricmp(diap,"red parrot") == 0) || (stricmp(diap,"parrot") == 0))
	{od_printf("\"I've killed many of the vile things.  Usually the parrot will swoop down\n\r");
	od_printf("from the sky and take you by surprise.  Be careful when battling one.\"");}
else if(stricmp(diap,"wolfman") == 0)
	{od_printf("\"Many years ago, a group of adventurers led by myself went into the jungle\n\r");
	od_printf("to wipe these mistakes of nature from the island.  The beasts were much more\n\r");
	od_printf("numorous back then and a pack of them killed three fourths of my group.  We\n\r");
	od_printf("were able to kill all of them and now there are few left.  The strangest \n\r");
	od_printf("thing about those creatures is that they were first found in the deep forest\n\r");
	od_printf("of Burkshire.  How they got here, noone knows.\"");}
else if((stricmp(diap,"pirates") == 0) || (stricmp(diap,"pirate") == 0))
	{od_printf("\"Any Wolf pirate that decided to go freelance makes there home in the jungle\n\r");
	od_printf("robing anyone they can defeat.  Wolfs aren't only ones there though they are\n\r");
	od_printf("the strongest.  Don't mess with them.\"");}
else if(stricmp(diap,"hayward") == 0)
	{od_printf("\"Pah, nasty farming town.\"");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"My training will help you build muscles as well as your resistance to blows.\n\r");
	od_printf("Just by looking at you, I can tell you need it.  It costs 45 coins.\"");}
else if((stricmp(diap,"the den") == 0) || (stricmp(diap,"den") == 0))
	{od_printf("\"Well, I can't say that this is the place to raise children.  But it is the\n\r");
	od_printf("place to have lots of fun.  Just go to the Baths or the Casino.\"");}
else if(stricmp(diap,"baths") == 0)
	{od_printf("\"Now there you can get some clean entertainment.\"");}
else if(stricmp(diap,"casino") == 0)
	{od_printf("\"They have some great games to play there.  If your good, make some money.\"");}
else if(stricmp(diap,"land") == 0)
	{od_printf("\"Why would you want to know about the rest of the land?  Here is the best.\n\r");
	od_printf("Well, although there is no town as good as this town, Trimmail is the\n\r");
	od_printf("closest.  That capitol city is getting corrupted.  Not by pirates though\n\r");
	od_printf("instead by the king.  You need to check that town out.\"");}
else if(stricmp(diap,"trimmail") == 0)
	{od_printf("\"It is devided into two parts:  rich and poor.\"");}
else if((stricmp(diap,"bye") == 0) || (stricmp(diap,"x")==0)||(stricmp(diap,"")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Alright, take it easy.\"");
	goto masterend;}
else{od_printf("\"I can't tell you about that.\"");}
goto talkmasteragain;
masterend:
}

void talkoldmerchant(void)
{
char diam[20];
od_clr_scr();
od_printf("`bright magenta`\n\rThe wrinkled old lady stands behind the stand with a bored look on\n\r");
od_printf("her face.  She looks as if she has been a merchant her whole life.\n\r");
od_printf("\n\rType a word for something you would like to ask about.\n\r");
od_printf("Examples:\n\r");
od_printf("`bright cyan`Name\n\rPrices\n\rBread\n\rMeat\n\rFish\n\rBye\n\r");
od_printf("`bright magenta`There may be other questions to ask.\n\r");
talkoldmerchantagain:
od_printf("\n\r\n`cyan`  >  ");
od_input_str(diam,21,32,123);
od_printf("`bright blue`");
if(stricmp(diam,"name") == 0)
	{od_printf("\n\r\"My name is Molly.  Would you like something to eat?\"\n\r");}
else if(stricmp(diam,"prices") == 0)
	{od_printf("\n\r\"Well, I can't boast about having good prices, but I do have good food. I\n\r");
	od_printf("sell bread for five gold coins and I will buy it for four gold coins.  Fish\n\r");
	od_printf("is sold for eight coins and bought for five.  Meat is a little more expensive\n\r");
	od_printf("but is very good.  I sell it for fifteen and I buy it for ten.\"\n\r");}
else if(stricmp(diam,"bread") == 0)
	{od_printf("\n\r\"I have very good bread.  You can get it cheap.  I've heard that if you\n\r");
	od_printf("take my bread to Trimmail or one of the other big cities, you may even\n\r");
	od_printf("be able to make some money.  Who knows?\"\n\r");}
else if(stricmp(diam,"meat") == 0)
	{od_printf("\n\r\"I only sell whole chickens right now, but I would be happy to buy any\n\r");
	od_printf("other kinds of meat you may have gotten.\"\n\r");}
else if(stricmp(diam,"fish") == 0)
	{od_printf("\n\r\"Um, I love fish.  Therefore, my prices are a bit expensive but I am very\n\r");
	od_printf("happy to buy some.  Some of the best fishing in the land is at Hayward.\"\n\r");}
else if((stricmp(diam,"bye") == 0)||(stricmp(diam,"")==0))
	{od_printf("\n\r\"Due come back.\"\n\r");
	goto oldmerchantend;}
else if(stricmp(diam,"hayward") == 0)
	{od_printf("\n\r\"Splendid town, if you ask me.  Of course, I have no yern to be famous or\n\r");
	od_printf("rich.  Hayward is a good place for the simple folk, but heroes should leave\n\r");
	od_printf("as soon as possible.\"\n\r");}
else if(stricmp(diam,"tavern") == 0)
	{od_printf("\n\r\"I hear they have excellent beer there and fairly good food.  I can't afford\n\r");
	od_printf("it; therefor, I have never been there.  But if word about a place gets\n\r");
	od_printf("to people like me, it must be very good.\"\n\r");}
else{od_printf("\n\r\"Sorry, there isn't anything I can tell you about that.\"\n\r");}
goto talkoldmerchantagain;
oldmerchantend:
}

void talkhaywardpatrons(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright magenta`At the table sit three hard working farmers.  They act like they are\n\r");
od_printf("on the edge of being drunk.\n\n\r");
od_printf("`bright blue`Type a word for something you would like to ask.\n\r");
od_printf("Examples:\n\r");
od_printf("`bright cyan`Names\n\rFarms\n\rTavern\n\rHayward\n\rBye\n\rThere are many other things to ask about.\n\r");
talkhaywardbarpatronsagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
if((stricmp(diap,"name") == 0) || (stricmp(diap,"names") == 0))
	{od_printf("\n\r`bright red`\"HA HA,\" laughs a man, \"I'm Harvey.\"\n\r");
	sleep(1);
	od_printf("`bright blue`\n\"None of your business!\" says another.\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"Sorry for the rude words of my friends, I'm Bill.\"\n\n\r");
	sleep(1);}
else if((stricmp(diap,"taunt")==0)||(stricmp(diap,"taunt spell")==0))
	{od_printf("\n\r`bright magenta`\"There are seven strange monks that live on the other side of the forest.\n\r");
	od_printf("They are very knowledgeable in the mystical arts.  I am sure they can help.\"\n\r");
	sleep(1);
	od_printf("\n`bright red`\"Yeah, if you do not die in the process.\"\n\r");
	sleep(1);
	od_printf("\n`bright blue`\"Those seven have riddles and games to confuse the smartest of men.\"\n\r");
	sleep(1);
	od_printf("\n`bright magenta`\"Very true, but their rewards are wonderful.  When you are hunting, look for\n\r");
	od_printf("the letter M.\"\n\r\n");}
else if(stricmp(diap,"pomdirgunua") == 0)
	{od_printf("\n\r`bright red`\"They're goners.\"\n\r");
	sleep(1);
	od_printf("\n`bright magenta`\"It does look like the king is turning his attentions there.  For what reason\n\rwho knows?\"\n\r");
	sleep(1);}
else if(stricmp(diap,"farms") == 0)
	{od_printf("\n\r`bright red`Laughing, Harvey says, \"I grow alot!\"\n\n\r");
	sleep(1);
	od_printf("`bright blue`\"Yeah, I got a farm!\"\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"We three together manage the largest farm on the island of Hayward. I\n\r");
	od_printf("believe it is the biggest farm in the land-\"\n\n\r");
	sleep(1);
	od_printf("`bright blue`\"There is absolutely no way, Bill, in Trimmail there are farms as\n\r");
	od_printf("huge as this island.\"\n\r\n");
	sleep(1);
	od_printf("`bright magenta`Bill looks at you and says, \"He is not too proud of our farm.\"\n\r");
	sleep(1);
	od_printf("`bright blue`\n\r\"I just tell it as it is.\"\n\r");}
else if(stricmp(diap,"tavern") == 0)
	{od_printf("\n\r`bright red`\"It is a wonderful place to get drunk!\"\n\r");
	}
else if(stricmp(diap,"hayward") == 0)
	{od_printf("`bright red`\"A town I would love to drink to!\"\n\n\r");
	sleep(1);
	od_printf("`bright blue`\"Don't say a thing about this ugly town!\"\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"It is a small town but the soil is wonderful.  I only hope soldiers don't\n\r");
	od_printf("come and take our land away.  Oh sorry, I guess I may have hit a touchy\n\r");
	od_printf("subject.\"\n\r\n");
	sleep(1);
	od_printf("`bright red`\"Oh, who cares!  I'm getting drunk to get ready for it.\"\n\r\n");
	sleep(1);
	od_printf("`bright magenta`\"I heard Pomdirgunua is also having troule with losing lands to the king's\n\r");
	od_printf("soldiers.  Maybe they will turn all their attention there.\"\n\n\r");
	sleep(1);
	od_printf("`bright blue`\"Yeah right!\"\n\r");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("`bright blue`\"Good idea.  LEAVE!\"\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"Have a good day.\"\n\n\r");
	goto haytalkend;}
else if(stricmp(diap,"soldiers") == 0)
	{od_printf("`bright blue`\n\r\"Shut up!  I hate them.\"\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"When the soldiers came into the tavern the other night, he got in a fight\n\r");
	od_printf("with one of them.  He lost.\"\n\n\r");
	sleep(1);
	od_printf("`bright blue`\"He had a sword and better friends!\"\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"I don't think anyone could beat one of them in a fight.  Not only do they\n\r");
	od_printf("have excellant weapons, but they are never alone.\"\n\n\r");}
else if(stricmp(diap,"help") == 0)
	{od_printf("`bright blue`\"Talk to the armsmaster for that.\"\n\n\r");}
else if(stricmp(diap,"king") == 0)
	{od_printf("`bright red`\n\r\"There is one person I won't drink to.\"\n\n\r");
	sleep(1);
	od_printf("`bright magenta`\"All he can do is sit on his throne.  I bet he is truly a coward.\"\n\n\r");
	sleep(1);
	od_printf("`bright blue`\"I bet you can't say that to his face.\"\n\n\r");}
else{od_printf("`bright red`\n\r\"What's that you say?  Just say bye if your're ready to go.\"\n\r");}
goto talkhaywardbarpatronsagain;
haytalkend:
}

void talksmith(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright magenta`The weaponsmith looks like a humble, hard-working man.\n\r");
od_printf("`bright blue`Type a word to indicate the question you would like to ask.  Examples:\n\r");
od_printf("`magenta`Name\n\rHayward\n\rWeapons\n\rBye");
talksmithagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`");
if(stricmp(diap,"name") == 0)
	{od_printf("\n\r\"Most people just call me Smithy.\"");}
else if(stricmp(diap,"hayward") == 0)
	{od_printf("\n\r\"I have worked in this town all my life.  The dangerous forest and now the\n\r");
	od_printf("soldier scare has brought alot of business my way.  Also, since I am the only\n\r");
	od_printf("weaponsmith in town, that makes it easy on me.\"");}
else if(stricmp(diap,"weapons") == 0)
	{od_printf("\n\r\"I sell two kinds: short and long range.  Which would you like to know about?\"");}
else if((stricmp(diap,"short") == 0) || (stricmp(diap,"short-range") == 0) || (stricmp(diap,"short range") == 0))
	{od_printf("\n\r\"You absolutely must have a short-range weapon to survive.  The Axe is\n\r");
	od_printf("the best thing I sell.  I'm pretty sure it is the best thing anyone sells,\n\r");
	od_printf("but I do know of some special weapons.  Well, they are rumors but you never\n\r");
	od_printf("know.  I can point you in the right direction.");
	od_printf("\n\rI got a new weapon now called the White Sword.\"");
	}
else if((stricmp(diap,"long") == 0) || (stricmp(diap,"long-range") == 0) || (stricmp(diap,"long range") == 0))
	{od_printf("\n\r\"A long-range weapon is a very handy thing to have.  If your opponent is not\n\r");
	od_printf("wearing any armour, you can usually kill him without getting close.\"");}
else if((stricmp(diap,"special") == 0) || (stricmp(diap,"special weapon") == 0) || (stricmp(diap,"special weapons") == 0))
	{od_printf("\n\r\"There are two that I know about.  One is an axe made by a very talented\n\r");
	od_printf("artist that works in Sussenex.  Another is a magical reaper which pirates\n\r");
	od_printf("call the Death Scythe.  It is said that a group of pirates recovered the\n\r");
	od_printf("powerful weapon just floating in the ocean.  It had a strange blue glow\n\r");
	od_printf("and seemed to make the creatures it was used against lose their sense\n\r");
	od_printf("of direction.\"");}
else if(stricmp(diap,"soldiers") == 0)
	{od_printf("\n\r\"Luckily I've had no problems with them.\"");}
else if(stricmp(diap,"white sword") == 0)
	{od_printf("\n\r\"I have not used it, but it feels like it is very powerful.  It could even\n\r");
	od_printf("be magical.  The blade has a faint white glow.\"");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0)|| (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\n\r\"Good luck in your journeys.\"");
	goto smithend;}
else{od_printf("\n\r\"I can't tell you anything about that.  Ready to go?  Say bye.\"");}
goto talksmithagain;
smithend:
}

void talkhaymaster(void)
{
char diap[20];
od_clr_scr();
char ata;
od_printf("`bright magenta`The weapons master has the appearance of a noble.  You can tell with\n\r");
od_printf("just a glance that he brings in alot of money.\n\r");
od_printf("`bright cyan`\n\rThe weapons master looks at you, \"Sorry, I must charge ten coins\n\r");
od_printf("for information.  What do you say?\" [Y/N]  ");
ata = od_get_answer("YN");
if(ata == 'Y')
	{if(data[user].coins < 10)
		{od_printf("`bright red`\n\r\"Sorry, pal, I don't give out free info.  Get more coins.\"");
		goto masterend;}
	}
else{goto masterend;}
talkmasteragain:
od_printf("`bright blue`\n\r\"I can tell you about animals, training, Hayward, and the land.\n\r");
od_printf("Just say bye when you're finished talking.\"\n\r");
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r\n");
if(stricmp(diap,"name") == 0)
	{od_printf("\"That is the last thing you should worry about.\"");
	}
else if(stricmp(diap,"hayward") == 0)
	{od_printf("\"This is a wonderful town to start the adventures.  Although you had to start\n\r");
	od_printf("here, you picked a good place to get thrown out.\"\n\r");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"My training costs fifty coins.  That may sound kinda expensive but go out\n\r");
	od_printf("to the forest sometime and you will see where what I can teach you would\n\r");
	od_printf("be needed.  For that fifty coins, I can build up your strength and make\n\r");
	od_printf("you a more nimble fighter.\"\n\r");}
else if(stricmp(diap,"animals") == 0)
	{od_printf("\"The animals around here are mostly wussies, although they might give you\n\r");
	od_printf("some trouble.  Beware of the savages that roam the woods.  Some animals I\n\r");
	od_printf("know about are the Warplant, the wolf, and the bear.\"\n\r");}
else if(stricmp(diap,"warplant") == 0)
	{od_printf("\"The Warplant is a fearsome vegatable.  It has a special attack in which\n\r");
	od_printf("it shouts acid at you.  Be sure to be behind your sheild when that happens.\n\r");
	od_printf("With all things considered though, the Warplant is the perfect victom, it\n\r");
	od_printf("usually has a stash of coins from other warriors and is not very accurate\n\r");
	od_printf("with it's attacks.\"\n\r");}
else if(stricmp(diap,"wolf") == 0)
	{od_printf("\"A diligent attacker.  Don't plan on it getting fearful and running.\"\n\r");}
else if(stricmp(diap,"bear") == 0)
	{od_printf("\"If you can defeat a bear then you are ready to move out of Hayward.\"\n\r");}
else if(stricmp(diap,"special") == 0)
	{od_printf("\"The special attack on any animal will always be a strong attack.  The best\n\r");
	od_printf("thing to do if you discover that your enemy has a special attack is defend\n\r");
	od_printf("yourself until right after his special attack.  I've never seen two special\n\r");
	od_printf("attacks come right after another.\"\n\r");}
else if(stricmp(diap,"land") == 0)
	{od_printf("\"The land outside of Hayward is indeed a violent one.  In some places, Dragons\n\r");
	od_printf("control the town.  In others, the king forces his cruel rule upon.  Gambling\n\r");
	od_printf("and prostitution has corrupted the other island and pirates prey on merchant\n\r");
	od_printf("ships.  The country is truly a wonderful place.  At least, we don't have to\n\r");
	od_printf("worry about outside countries taking us over.  Too bad.\"\n\r");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Come back anytime.\"\n\r");
	goto masterend;}
else{od_printf("\"Sorry, I can't tell you anything about that.\"\n\r");
	}
goto talkmasteragain;
masterend:
}

void talkeastinn(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`The Innkeeper looks like a very unusual man.  He has a hook instead of\n\r");
od_printf("a right hand and has many scars on his face.\n\r");
od_printf("`bright cyan`Name\n\r");
od_printf("tavern\n\r");
od_printf("Trimmail\n\r");
od_printf("Bye\n\r");
talkpiragain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I like to call myself Minion.\"");}
else if(stricmp(diap,"tavern") == 0)
	{od_printf("\"I bought this tavern with some gold I managed to collect.  I can get you a\n\r");
	od_printf("drink for 12 coins, a meal for 25, and a room for 20 coins.\"");}
else if(stricmp(diap,"trimmail") == 0)
	{od_printf("\"Although corrupted by the king and his lackeys, it is really a peaceful\n\r");
	od_printf("city.  Have you seen the town at night?  The stars shine on the castle and\n\r");
	od_printf("mountains.  It is a wonderful site to see.\"");}
else if(stricmp(diap,"king") == 0)
	{od_printf("\"I've never seen him and never met him.  But judging by the way he runs the\n\r");
	od_printf("beautiful land of Trimmail, I'd bet he hasn't a good personality.\"");}
else if((stricmp(diap,"death scythe") == 0) || (stricmp(diap,"death") == 0) || (stricmp(diap,"scythe") == 0) || (stricmp(diap,"blacktooth") == 0))
	{if(edata.prodeath > 0)
		{od_printf("\"So, ol' Blacktooth sent you to me, aye?  Yep, I've seen the Scythe.  If you\n\r");
		od_printf("would like to see if you can obtain it.  Go to the Wolf's Hideout.  It is\n\r");
		od_printf("northeast of The Den.\"  (Push \"*\" when moving from the docks)");
		if(edata.prodeath < 2)
				edata.prodeath = 2;
		}
	else{od_printf("\"It's a mysterious and dangerous weapon.  It should have been thrown back\n\r");
		od_printf("into the sea.\"");}
	}
else if(stricmp(diap,"pirate") == 0)
	{od_printf("\"What are you saying?\"");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Come back soon.\"");
	goto trimpirend;}
else od_printf("\"I can't tell you much about that.\"");
goto talkpiragain;
trimpirend:
}

void talketrain(void)
{
od_clr_scr();
char diap[20];
od_printf("`bright blue`\n\rThe trainer is a bearded man who looks like he has much fighting experience.\n\r");
talkeagain:
od_printf("`bright cyan`\n\rName\n\ranimals\n\rTrimmail\n\rtraining\n\rbye\n\r");
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I really don't like to give strangers my name.\"");}
else if(stricmp(diap,"animals") == 0)
	{od_printf("\"I don't know much about the animals in the mountains.  For I have more\n\r");
	od_printf("brains than to go up there.  I do know that there are alot of giants there.\"");
	}
else if(stricmp(diap,"giants") == 0)
	{od_printf("\"I heard that from someone else.\"");}
else if(stricmp(diap,"trimmail") == 0)
	{od_printf("\"I have lived here all my life and may I say that I am tired of this\n\r");
	od_printf("corrupted town.  I would like to get out of here soon.\"");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"My training helps one to increase how much punishment he or she can take.  I\n\r");
	od_printf("charge 70 coins.  May I say that it is worth it.\"");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Yes, bye.\"");
	goto eend;}
else{od_printf("\"I wouldn't know anything about that.\"");}
goto talkeagain;
eend:
}

void talkburktrain(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rThe trainer is a bearded, dirty man who looks like he has much fighting\n\r");
od_printf("experience.  He looks tough as if he lives off the land.\n\r");
talkeagain:
od_printf("`bright cyan`\n\rName\n\ranimals\n\rBurkshire\n\rtraining\n\rbye\n\r");
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I be Flenn.\"");}
else if(stricmp(diap,"animals") == 0)
	{od_printf("\"Wow, now that's a thing to ask about!  I don't really know where to start.\n\r");
	od_printf("The dragons of course live in their little lair.  I'm sure you've heard of\n\r");
	od_printf("them before, though.  As of the animals in the deep forest, well, most of\n\r");
	od_printf("them are mystical and extremely powerful.  The Chimera is a mighty beast.\n\r");
	od_printf("Then, there is the Great Troll and the Sceptres which are not to be played\n\r");
	od_printf("with.  Which one would you like to know more about?\"");}
else if((stricmp(diap,"dragons") == 0) || (stricmp(diap,"dragon") == 0))
	{od_printf("\"Now, there is the toughest animal on the face of the planet.  The Red,\n\r");
	od_printf("Green, and Yellow are the intermediate dragons if you can call any of them\n\r");
	od_printf("intermidiate.  The Baby Dragon is the easiest to kill but still is not an\n\r");
	od_printf("easy target.  Then, there is the Three-headed Dragon.  Noone I've ever met\n\r");
	od_printf("has visited it and noone anyone has ever heard of has beaten it.\"");}
else if(stricmp(diap,"chimera") == 0)
	{od_printf("\"It breathes fire and has the face of a lion.  I have only killed one in my\n\r");
	od_printf("entire life for they put up a great fight.\"");}
else if((stricmp(diap,"great troll") == 0) || (stricmp(diap,"troll") == 0))
	{od_printf("\"He is very strong and very quick.  He usually carries a Long Sword stolen\n\r");
	od_printf("from us.\"");}
else if((stricmp(diap,"sceptre") == 0) || (stricmp(diap,"sceptres") == 0))
	{od_printf("\"To this day, I've never figured out where they come from.  It is a human\n\r");
	od_printf("form that is nearly invisible.\"");}
else if(stricmp(diap,"burkshire") == 0)
	{od_printf("\"This used to be a thriving town, but the forest seems to grow more and more\n\r");
	od_printf("each year.  And with the growing comes more animals.  Most people are afraid\n\r");
	od_printf("of this town.  Why, you are the first visitor I've seen in awhile.\"");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"I can train you in anything you want.  Though I do charge alot.  Sorry, but\n\r");
	od_printf("I don't see much money.  Anyway, for one hundred coins, I will train you.\"");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Be careful in this town.\"");
	goto burkend;}
else{od_printf("\"What's that you say?\"");}
goto talkeagain;
burkend:
}

void talkburkpatrons(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rTwo tough country men are sitting at a table.  You ask them if you can\n\r");
od_printf("join them.  They promptly reply, \"Sure!\"\n\r");
od_printf("`bright cyan`Names\n\rBurkshire\n\rtavern\n\rbye\n\r");
talkpagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"names") == 0)
	{od_printf("\"I'm Sam.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"And I be Floyd.\"");}
else if(stricmp(diap,"burkshire") == 0)
	{od_printf("\"Well, it's not exactly the place to raise a family, but if you want to get\n\r");
	od_printf("strong quick, just take a hike in the woods.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"That is...  you'll get strong if you can get out.\"");}
else if(stricmp(diap,"tavern") == 0)
	{od_printf("\"I go hunting in the morning and come back here afterwards.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"I just hope the dragons don't come and burn this place down.\"\n\r");
	sleep(1);
	od_printf("`bright blue`\n\r\"Those blasted beasts have burnt down alot of good places in this town.\"\n\r");
	}
else if((stricmp(diap,"dragon") == 0) || (stricmp(diap,"dragons") == 0))
	{od_printf("\"I wouldn't mind getting all the warriors in the land and just going in that\n\r");
	od_printf("lair on the side of that little hill and killing everyone of them.  The only\n\r");
	od_printf("problem is that you have to live in Burkshire to be that brave.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"There aren't a whole lot of warriors here.\"\n\r");
	sleep(1);
	od_printf("`bright blue`\n\r\"I've killed many of their baby dragons.  No matter how many I kill though,\n\r");
	od_printf("there is always more the next day.  Blasted creatures of darkness!\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"He lost his wife and kid to the Three-headed dragon.\"\n\r");
	sleep(1);
	od_printf("`bright blue`\n\r\"Yeah, and if I could get that gem from the East Forest, I'd kill it.\"");}
else if((stricmp(diap,"three-headed dragon") == 0) || (stricmp(diap,"three headed dragon") == 0))
	{od_printf("\"He lives in a large room towards the opening of the lair, can't miss it.\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"We don't even dare to go in there.\"\n\r");}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Be careful in this town.\"");
	goto pend;}
else if(stricmp(diap,"gem") == 0)
	{od_printf("\"It is said to have powers over death.  When someone honorable needs it to\n\r");
	od_printf("vanguish something demonicly evil, it will appear in the East Forest.  Press\n\r");
	od_printf("/ in town to find the hidden location of it.\"\n\r");}
else{od_printf("\"What's that you say?\"\n\r");
	sleep(1);
	od_printf("`bright red`\n\r\"We aren't too knowledgeable around here.\"");}
goto talkpagain;
pend:
}

char juliet(void)
{
char comm;
if(edata.progress == 0)
	{od_printf("`bright red`\n\r\"I don't know you.  Go meet Hilder at the academy.\"");
	goto julietend;}
if(edata.protiw > 0)
	{od_printf("`bright blue`\n\rNow that you think about it, Juliet's dead.\n\r");
	goto julietend;}
od_printf("`bright red`\n\r\"I see a new warrior has come to town.  Would you care to do battle?\" [Y/N] ");
comm = od_get_answer("YN");
if(comm == 'Y')
	{if(edata.turns == 0)
			od_printf("`red`\n\rSorry, not enough turns left.\n\r");
	else{od_printf("`bright red`\n\r\"Great!  Go to the arena!\"\n\r");
		return TRUE;}
	}
else{od_printf("\n\r\"Paw, puny human.\"\n\r");
	}
julietend:
return FALSE;
}


char vardius(void)
{
char comm;
if(edata.protiw > 1)
	od_printf("`bright blue`\n\rNow that you think about it, Vardius is dead.\n\r");
else if(edata.protiw == 0)
	od_printf("`bright red`\n\rVardius says to you, \"You are unworthy to talk to me!\"\n\r");
else{od_printf("`bright red`\n\r\"I see you are a valient warrior.  Would you care to do battle?\" [Y/N] ");
	comm = od_get_answer("YN");
	if(comm == 'Y')
		{if(edata.turns == 0)
				od_printf("`red`\n\rSorry, not enough turns left.\n\r");
		else{od_printf("`bright red`\n\r\"Great!  Go to the arena!\"\n\r");
			return TRUE;}
		}
	else{od_printf("\n\r\"Paw, puny human.\"\n\r");
		}
	}
return FALSE;
}

char nadiera(void)
{
char comm;
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rBefore you is a strong, beautiful woman.  You dread a fight with her.\n\r");
od_printf("`bright cyan`Name\n\rWarriors\n\rTraining\n\rChallenge\n\rbye\n\r");
talknagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I'm Nadiera, nearly the greatest warrior in Tiw.\"");}
else if(stricmp(diap,"warriors") == 0)
	{od_printf("\"Well, there is Juliet and Vadius who usually hang out in the tavern.  They\n\r");
	od_printf("are so weak, you could probably defeat them.  Then there is julius.  He trains\n\r");
	od_printf("as I do.  I've yet to challenge him.\"");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"I can train you to have better endorance and to better dodge attacks.\n\r");
	od_printf("My training costs fifty coins.\"");}
else if(stricmp(diap,"challenge") == 0)
	{if(edata.protiw < 2)
		od_printf("Nadiera says to you, \"You are unworthy to challenge me!\"\n\r");
	else{od_printf("\"I see you are a valient warrior.  Would you care to do battle?\" [Y/N] ");
		comm = od_get_answer("YN");
		if(comm == 'Y')
			{if(edata.turns == 0)
					od_printf("`red`\n\rSorry, not enough turns left.\n\r");
			else{od_printf("`bright red`\n\r\"Great!  Go to the arena!\"\n\r");
				return TRUE;}
			}
		else{od_printf("\n\r\"Paw, puny human.\"\n\r");
			}
		}
	}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Be careful in this town.\"");
	goto nend;}
else{od_printf("\"What?\"");}
goto talknagain;
nend:
return FALSE;
}

char julius(void)
{
char comm;
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rBefore you is a strong, handsome man.  You dread a fight with him.\n\r");
od_printf("`bright cyan`Name\n\rWarriors\n\rTraining\n\rChallenge\n\rbye\n\r");
talknagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"I am Julius, the greatest warrior in Tiw.\"");}
else if(stricmp(diap,"warriors") == 0)
	{od_printf("\"Talk to Nadiera about that.\"");}
else if(stricmp(diap,"training") == 0)
	{od_printf("\"I train in archery and to build strength for fifty coins.\"");}
else if(stricmp(diap,"challenge") == 0)
	{if(edata.protiw < 3)
		od_printf("Julius says to you, \"You are unworthy to challenge me!\"\n\r");
	else{od_printf("\"I see you are a valient warrior.  Would you care to do battle?\" [Y/N] ");
		comm = od_get_answer("YN");
		if(comm == 'Y')
			{if(edata.turns == 0)
					od_printf("`red`\n\rSorry, not enough turns left.\n\r");
			else{od_printf("`bright red`\n\r\"Great!  Go to the arena!\"\n\r");
				return TRUE;}
			}
		else{od_printf("\n\r\"Paw, puny human.\"\n\r");
			}
		}
	}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Be careful in this town.\"");
	goto nend;}
else{od_printf("\"What's that?\"");}
goto talknagain;
nend:
return FALSE;
}

void hilder(void)
{
char diap[20];
od_clr_scr();
od_printf("`bright blue`\n\rBefore you stands a royal soldier of the castle Trimmail.\n\r");
od_printf("`bright cyan`\n\rName\n\rSoldiers\n\rBye\n\r");
talkhagain:
od_printf("\n\r\n`cyan`>  ");
od_input_str(diap,21,32,123);
od_printf("`bright blue`\n\r");
if(stricmp(diap,"name") == 0)
	{od_printf("\"Most people call me Hilder.\"");}
else if(stricmp(diap,"soldiers") == 0)
	{
	if(edata.progress == 2)
		{od_printf("\"Ok, I will train you.\"  He shows you the exact tactics all the soldiers\n\r");
		od_printf("in the land use.  This should be useful in battling soldiers.\n\r");
		edata.progress++;}
	else if(edata.progress > 2)
		{od_printf("\"There is nothing more I can do for you.\"");}
	else{od_printf("\"I take it you want to be a soldier.  Soldiers have a special tactic they\n\r");
	od_printf("use in battle which makes them nearly invincable.  It is a very helpful\n\r");
	od_printf("thing to know.  Let's see, I don't know you and I can't train you without\n\r");
	od_printf("background history, but if you make yourself well-known in Tiw, I will\n\r");
	od_printf("train you.  Look in the tavern for opponents.\"\n\r");
	edata.progress = 1;
	}
	}
else if((stricmp(diap,"Tiashi Ci")==0)||(stricmp(diap,"camp")==0)||(stricmp(diap,"tiashi")==0))
	{
	od_printf("\"Ha!  Those outcasts!  You could even take them.  If you really want to know\n\r");
	od_printf("how to find them, I will tell you.  They live in the mountains only coming\n\r");
	od_printf("down to steal food and tools.  We have tried to exterminate them, but their\n\r");
	od_printf("survival skills have the soldiers beaten in the snow.  In the moutains press T\n\r");
	od_printf("to find the camp.  And tell them I said HI.\"\n\r");
	od_printf("`bright magenta`You think Hilder was doing a bit of exageratting.");
	}
else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
	{od_printf("\"Whatever.\"");
	goto hend;}
else{od_printf("\"I don't know.\"");}
goto talkhagain;
hend:
}

void talkr(void)
{
char diap[20];
od_clr_scr();
if(edata.progress < 5)
	{od_printf("`bright blue`\n\rBefore I will talk, you must best me!\n\r");
	getreturng();
	monread("stryline.dat",9,5);
	if(monattack() == TRUE)
		edata.progress++;
	}
if(edata.progress > 4)
	{od_printf("`bright cyan`\n\rName\n\rKing\n\rBye\n\r");
	talkragain:
	od_printf("\n\r\n`cyan`>  ");
	od_input_str(diap,21,32,123);
	od_printf("`bright blue`\n\r");
	if(stricmp(diap,"name") == 0)
		{od_printf("\"Please, I'd rather not tell you.\"");}
	else if(stricmp(diap,"king") == 0)
		{od_printf("\"So, you are trying to overthrow the king.  Good luck.  If you want to get\n\r");
		od_printf("into the castle, press C when you are in Mid Trimmail.  That will allow you\n\r");
		od_printf("to find the secret passageway.  But you will need a key to open the door\n\r");
		od_printf("into the castle.  Go to the officer building in West Trimmail.  The Head\n\r");
		od_printf("Adminastrator has it.  You may have to force an answer, though.  Other then\n\r");
		od_printf("that, I can tell you nothing.  Now, please let me heal from the wounds you\n\r");
		od_printf("inflicted upon me.\"");
		if(edata.progress < 5)
			edata.progress = 5;
		}
	else if((stricmp(diap,"bye") == 0)||(stricmp(diap,"")==0) || (stricmp(diap,"x")==0) || (stricmp(diap,"exit")==0) || (stricmp(diap,"goodbye")==0))
		{od_printf("\"I can't believe you beat me!\"\n\r");
		goto rend;}
	else{od_printf("\"I don't know.\"");}
	goto talkragain;
	rend:
	}
}
