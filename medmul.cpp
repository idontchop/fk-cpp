#include "med.h"
#include <share.h>
#include <time.h>
#include <errno.h>

extern struct settings setting[2];
extern struct player_info data[60];
extern int user;
extern struct info2 edata;
FILE *efopen(char *fil,int wait);
void oattack(int a,char firs);
/*int a sends the user number that will be battled,
char first notifies who will get the first strike.
TRUE if user will
FALSE if other player will*/

void guildhall(void)
{
playsave('A',0,3);

//for chat
unsigned char key;
int stringnum;
//chat control

char n[2],m[2];
char x;
if(user < 50)
	od_clr_scr();
int ucount;
char rran;
char message[20];
int ran;
od_printf("\n\r`bright blue`Other players in the guild hall`bright red`:\n\r");
int jjj;
for(jjj=0;jjj<50;jjj++)
	{if(data[jjj].location == '$')
		od_printf("`bright white`%s`bright red`, ",data[jjj].alias);
	}
od_printf("`bright magenta`\n\r");
od_printf("`bright magenta`Type `bright white` \\? `bright magenta`for help.\n\r");
od_printf("`bright magenta black`");
unsigned char string[160];
char a,fileo[12];
unsigned char b;
FILE *fp1,*fp2;
fp2=fopenw("chat.log",10);
fprintf(fp2,"~9%s~15 has entered guild hall.~$",data[user].alias);
fclose(fp2);
if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
	{od_printf("\n\rAn error has occurred in the game!\n\r");
	goto chatend;}
fseek(fp1,0,SEEK_END);
data[user].location = '$';
playsave('A',0,3);
while(1){
do{
do{
a = fgetc(fp1);
do{
if(a=='~')
	{
	a=fgetc(fp1);
	switch(a)
	{
	case '=':{fclose(fp1);
			sprintf(fileo,"fight%d.flg",user);
			if((fp2=_fsopen(fileo,"r",SH_DENYNONE))==NULL)
				{if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
					{od_printf("\n\rAn error has occurred in the game!\n\r");
						goto chatend;}
					fseek(fp1,0,SEEK_END);
				break;}
			fscanf(fp2,"%d",&ran);
			fclose(fp2);
			remove(fileo);
			sprintf(fileo,"acc%d.flg",ran);
			od_printf("`bright blue`%s has challenged you to a fight in the arena.  Accept? [Y/N]",data[ran].alias);
				rran = od_get_answer("YN");
				if(rran == 'Y')
					{od_printf("`bright white`\n\rPrepare for battle!");
					fp2=fopenw("chat.log",10);
					fprintf(fp2,"~!");
					fclose(fp2);
					fp2=fopenw(fileo,4);
					fprintf(fp2,"%d",user);
					fclose(fp2);
					sleep(1);
					data[user].location = '@';
					oattack(ran,TRUE);
					data[user].location = '$';
					}
			if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
					{od_printf("\n\rAn error has occurred in the game!\n\r");
						goto chatend;}
					fseek(fp1,0,SEEK_END);
			playsave('A',0,2);
			break;
			}
	case '!':{fclose(fp1);
			sprintf(fileo,"acc%d.flg",user);
			if((fp2=fopen(fileo,"r"))==NULL)
				{if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
					{od_printf("\n\rAn error has occurred in the game!\n\r");
						goto chatend;}
					fseek(fp1,0,SEEK_END);
				break;}
			fscanf(fp2,"%d",&ran);
			fclose(fp2);
			remove(fileo);
			od_printf("%s has accepted your challenge.  Prepare for battle.",data[ran].alias);
			data[user].location = '@';
			oattack(ran,FALSE);
			if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
				{od_printf("\n\rAn error has occurred in the game!\n\r");
				goto chatend;}
			fseek(fp1,0,SEEK_END);
			data[user].location = '$';
			playsave('A',0,2);
			break;
			}
	case '*':{fclose(fp1);
			playsave('A',0,10);
			if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
				{od_printf("\n\rAn error has occurred in the game!\n\r");
				goto chatend;}
			fseek(fp1,0,SEEK_END);
			break;}
	case '$':{od_printf("\n\r");
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
	case '1':{a = fgetc(fp1);
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
	a=fgetc(fp1);
	}
}while(a=='~');
}while(a=='~');
if(a != EOF)
	od_putch(a);
}while(a != EOF);
b = od_get_key(FALSE);
if(b=='\\')
	{
	od_printf("`bright cyan`");
	od_putch(b);
	od_input_str(string,15,32,126);
	if(stricmp(string,"who")==0)
		{
		fclose(fp1);
		playsave('A',0,10);
		for(ran=0;ran<setting[0].num_users;ran++)
			{
			if(data[ran].location == '$')
				od_printf("\n\r`bright white`%s`bright red`, ",data[ran].alias);
			if(data[ran].location == '@')
				od_printf("\n\r`bright blue`IN ARENA:  `bright white`%s`bright red`, ",data[ran].alias);
			}
		for(ran=50;ran<60;ran++)
			{
			if(data[ran].location == '$')
				od_printf("\n\r`bright blue`VISITING:  `bright white`%s  `bright blue`(can't challenge or send messages)\n\r",data[ran].alias);
			}
		od_printf("\n\r");
		if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
				{od_printf("\n\rAn error has occurred in the game!\n\r");
				goto chatend;}
			fseek(fp1,0,SEEK_END);
		}
	else if(stricmp(string,"challenge")==0)
		{
		od_printf("`red`\n\rSorry, but this is under construction.  Look for a higher version.\n\r");
		if(user > 49)
			{od_printf("\n\r`red`Sorry, you will have to play Farmers and Kings 2.0 to do this.\n\r");
			}
		else{
		playsave('A',0,2);
		od_printf("`bright blue`\n\rWho would you like to challenge?\n\r> `bright white`");
		od_input_str(message,20,32,136);
		if(stricmp(message,"")!=0)
			{
			ran=pusers(message);
			if((data[ran].trueansi == FALSE) || (data[user].trueansi == FALSE))
				od_printf("`red`Sorry, both players must have ansi enabled.\n\r");
			else{
			if((data[ran].online == -1) || (data[ran].location != '$'))
				od_printf("\n\r`red`THAT USER IS NOT IN THE GUILD HALL\n\r");
			if((ran!=32000)&&(data[ran].online!=-1)&&(data[ran].location=='$'))
				{
				fclose(fp1);
				sprintf(fileo,"fight%d.flg",ran);
				fp2=fopen(fileo,"w");
				fprintf(fp2,"%d",user);
				fclose(fp2);
				fp2=fopenw("chat.log",10);
				fprintf(fp2,"~=");
				fclose(fp2);
				if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
					{od_printf("\n\rAn error has occurred in the game!\n\r");
					goto chatend;}
				fseek(fp1,0,SEEK_END);
				od_printf("`bright red`\n\rYou have challenged %s.",data[ran].alias);
				od_printf("`bright blue`\n\rYou wait for a response.\n\r");
				}
			}

			}
		}
		}
	else if(stricmp(string,"send")==0)
		{
		if(user>49)
			{
			od_printf("`red`\n\rSorry, try playing `bright white`Farmers and Kings\n\r");
			}
		else{
		fclose(fp1);
		od_printf("`bright blue`\n\rWho would you like to send a message to?\n\r>`bright white`");
		od_input_str(message,20,32,136);
		if(stricmp(message,"")!=0)
			{
			ran=pusers(message);
			if(data[ran].online == -1)
				od_printf("\n\r`red`THAT USER IS NOT ONLINE\n\r");
			if((data[ran].online!=32000)&&(data[ran].online!=-1)&&(ran != 32000))
				{
				char msg[160];
				od_printf("\n\r`bright blue`Enter up to a two-line message:\n\r> `bright white`");
				od_input_str(msg,160,32,126);
				if(stricmp(msg,"")!=0)
					{
					FILE *mfp;
					char film[12];
					fclose(fp1);
					sprintf(film,"mail%d.txt",ran);
					mfp=efopen(film,20);
					fprintf(mfp,"~15Mail from ~12%s~9:\n\r",data[user].alias);
					fprintf(mfp,"~13%s\n\r",msg);
					fclose(mfp);
					if((fp2=fopenw("chat.log",10))==NULL)
						{od_printf("`red`AN ERROR HAS OCCURRED IN THE GAME!");
						goto chatend;}
					fprintf(fp2,"~*");
					fclose(fp2);
					if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
						{od_printf("\n\rAn error has occurred in the game!\n\r");
						goto chatend;}
					fseek(fp1,0,SEEK_END);
					}
				}
			}
		if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
				{od_printf("\n\rAn error has occurred in the game!\n\r");
				goto chatend;}
			fseek(fp1,0,SEEK_END);
		}
		}
	else if((stricmp(string,"?")==0) || (stricmp(string,"help")==0))
		{
		od_printf("\n\r");
		od_printf("`bright red`\\?         `bright white` Help screen\n\r");
		od_printf("`bright red`\\who        `bright white`Who is in Guild Hall\n\r");
		od_printf("`bright red`\\online     `bright white`Who is online\n\r");
		od_printf("`bright red`\\challenge `bright white` To challenge a player to a fight\n\r");
		od_printf("`bright red`\\send       `bright white`Send message to user online not in chat\n\r");
		od_printf("`bright red`\\send       `bright white`Send private message to a user in chat\n\r");
		od_printf("`bright red`\\x          `bright white`Leave Guild Hall\n\r\n");
		od_printf("`bright red`~            `bright white`For colors:  ~14`bright yellow`yellow ~2`green`green\n\r");
		}
	else if(stricmp(string,"online")==0)
		{
		fclose(fp1);
		playsave('A',0,20);
		for(ran=0;ran<setting[0].num_users;ran++)
			{
			if((data[ran].online != -1) && (data[ran].online != 32000))
				{od_printf("\n\r`bright blue`%s`bright red`,",data[ran].alias);
				}
			}
		for(ran=50;ran<60;ran++)
			{
			if(data[ran].location == '$')
				od_printf("`bright red`\n\rVISITING THE GUILDHALL:  `bright white`%s\n\r",data[ran].alias);
			}
		od_printf("\n\r");
		if((fp1=_fsopen("chat.log","r",SH_DENYNONE))==NULL)
				{od_printf("\n\rAn error has occurred in the game!\n\r");
				goto chatend;}
			fseek(fp1,0,SEEK_END);
		}
	else if((stricmp(string,"exit")==0) || (stricmp(string,"bye")==0) || (stricmp(string,"x")==0))
		{
		fp2=fopenw("chat.log",10);
		fprintf(fp2,"~9%s~15 has exited guild hall.~$",data[user].alias);
		fclose(fp2);
		goto exitchat;
		}
	else if(stricmp(string,"remark11222222")==0)
		{
		if((fp2=_fsopen("rude.no","r",SH_DENYNONE))==NULL)
			{
			fclose(fp2);
			od_printf("`bright blue`\n\rMake a rude remark to who?\n\r>`bright white`");
			od_input_str(message,20,32,136);
			if(stricmp(message,"")!=0)
				{
				ran=pusers(message);
				if(data[ran].online == -1)
					od_printf("\n\r`red`THAT USER IS NOT ONLINE\n\r");
				else{
				if((data[user].sex == 'M') && (data[ran].sex == 'F'))
					{
					switch(random(3))
					{
					case 0:{sprintf(message,"~$~6%s~14 laughs aloud at~6 %'s~14 ugly dress.",data[user].alias,data[ran].alias);
						break;}
					case 1:{sprintf(message,"~$~6%s~14 orders ~6%s ~14to fetch another drink.",data[user].alias,data[ran].alias);
						break;}
					case 2:{sprintf(message,"~$~6%s~14 grabs ~6%s's ~14backside and barks loud.",data[user].alias,data[ran].alias);
						break;}
					}
					}
				else if((data[user].sex == 'F') && (data[ran].sex == 'M'))
					{
					switch(random(3))
					{
					case 0:{sprintf(message,"~$~6%s~14 kicks ~6%s~14 in the butt and says \"move!\"",data[user].alias,data[ran].alias);
						break;}
					case 1:{sprintf(message,"~$~6%s~14 trips ~6%s~14 and the whole crowd laughs.",data[user].alias,data[ran].alias);
						break;}
					case 2:{sprintf(message,"~$~6%s~14 scratches %s across the face.",data[user].alias,data[ran].alias);
						break;}
					}
					}
				else{switch(random(4))
					{
					case 0:{sprintf(message,"~$~6%s~14 throws a pie and hits %s in the face.",data[user].alias,data[ran].alias);
						break;}
					case 1:{sprintf(message,"~$~14With a sword, ~6%s ~14cuts ~6%s's~14 suspenders.  Pants go falling.",data[user].alias,data[ran].alias);
						break;}
					case 2:{sprintf(message,"~$~6%s ~14throws a mug of beer on ~6%s~14.",data[user].alias,data[ran].alias);
						break;}
					case 3:{sprintf(message,"~$~6%s ~14belches in ~6%s~14's face.",data[user].alias,data[ran].alias);
						break;}
					}
					}
				fp2=fopenw("chat.log",4);
				fprintf(fp2,message);
				fclose(fp2);
				}
				}
			}
		else{od_printf("\n\r`bright red`Sorry, that feature has been prohibited by your sysop.\n\r");
			fclose(fp2);
			}
		}
	}
else if(b != 0){
	od_printf("`magenta`:");
	od_printf("`bright magenta`");
	od_putch(b);
	string[0] = b;
	stringnum=1;
   for(;;)                              /* (Repeats for each character typed) */
	 {
	  key=(char)od_get_key(TRUE);         /* Get next keystroke from keyboard */

	 if((key != 13) && (key != 10))
		if(stringnum>156)
			continue;

	 if(key==13 || key==10)            /* IF USER PRESSED [ENTER] / [RETURN] */
	    {
	    od_printf("\n\r");
	    break;
	    }


	 else if(key==8)                            /* IF USER PRESS [BACKSPACE] */
	    {
	    if(stringnum > 0)        /* If not at left of screen */
		  {
		  stringnum--;
		  string[stringnum]='\0';
		  od_printf("\b \b");           /* Erase last character from screen */
		  }
	    }

	 else if(key>=32)                  /* IF USER TYPED A PRINTABLE CHARACTER */
	    {                                  /* PERFORM WORD WRAP IF NECESSARY */
	    od_putch(key);
	    string[stringnum]=key;
	    stringnum++;

	    }
	 }

	string[stringnum]='\0';
	if(stringnum>0)
	{

	if((fp2=fopenw("chat.log",20))==NULL)
		{od_printf("\n\rAn error has occurred!\n\r");
		goto chatend;}
	if((b != '~') && (string[0] != '`'))
		fprintf(fp2,"~15%s~12:~$",data[user].alias);
	fprintf(fp2,"~9%s~$",string);
	if((string[0] == '~') && (string[1] == '}'))
		fprintf(fp2,"~14I'm worth a million dollars, you penny person!~$");
	if((string[2] == '~') && (string[3] == '{'))
		fprintf(fp2,"~15I'm the master!~$");
	fclose(fp2);
	}
	}
}
exitchat:
chatend:
fclose(fp1);
data[user].location = 'G';
}

FILE *efopen(char *fil,int wait)
{
   FILE *fpFile = NULL;
   time_t StartTime = time(NULL);


   /* Attempt to open the file while there is still time remaining. */
   while(((fpFile = fopen(fil,"a")) == NULL)
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


void oattack(int a,char firs)
{
playsave('A',0,20);
edata.qf = FALSE;
int strike;   //switch for whose turn it is.  TRUE for user's, FALSE for enemy's
char holy = FALSE;
FILE *rfp;
FILE *wfp;
FILE *test;
int hit;
time_t Stime;
char wfile[12];
char pw[15];
char ew[15];
char mee[79];
int ph;	//TRUE if enemy gets to hit you, FALSE if not
int php;  //the number of hitpts attack will take away
int pch;	//the chance of player hitting enemy
char co;	//command the user enters
char b;	//reads character from file
char chance;	//used  to calculate chance of hitting
int hg;		//used to decide what text to use
if(firs==TRUE)
	sprintf(wfile,"fight%d.%d",user,a);
else sprintf(wfile,"fight%d.%d",a,user);
fclose(fopen(wfile,"w"));
if((rfp=fopenr(wfile,1))==NULL)
	{od_printf("\n\r`red`An error has occurred in the game.");
	goto end;}
od_clr_scr();
od_printf("`bright cyan`You enter the arena, slap yourself in the face a couple times\n\r");
od_printf("and prepare for `bright red`BATTLE`bright cyan`...");
sleep(4);
od_printf("`bright red`\n\rWaiting for other node's response. (could possibly take awhile)\n\r");
if((wfp=fopenw(wfile,10))==NULL)
	{od_printf("`red`\n\rOther node is not responding...\n\r");
	goto end;}
od_clr_scr();
if(firs == TRUE)
	{
	od_printf("`bright blue`You get the first strike.");
	strike=TRUE;
	}
else{strike=FALSE;
	od_set_cursor(2,1);
	od_printf("`bright blue`Your enemy gets the first strike...");
	holy = TRUE;
	}

strcpy(pw,data[user].stype);
strcpy(ew,data[a].stype);
redraw:			//if users chooses redraw, returns here
od_set_cursor(14,1);
od_printf("`bright blue`컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\r");
od_printf("`bright cyan`    (A)ttack         S(U)rrender       (S)tats       (Y)ell      redra(W)\n\r");
od_printf("`bright blue`컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컫컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\r");
od_printf("`bright magenta`YOU:`bright blue`                                   �\n\r");
od_printf("                                       �\n\r");
od_printf("`bright cyan`Strength:   `bright blue`                           � `red`Strength:\n\r");
od_printf("`bright cyan`Dexterity:   `bright blue`                          � `red`Dexterity:\n\r");
od_printf("`bright cyan`Hit Points:  `bright blue`                          � `red`Hit Points:\n\r");
od_printf("`bright cyan`Weapon:  `bright blue`                              � `red`Noted Weapon:");
attack:			//where the control is returned to
disfight(data[a].strength,data[a].dex,data[a].hitpts,data[a].totalhit, ew, data[a].alias);
php = ((data[a].strength - (data[user].strength/2)) + (data[a].weaponshort - data[user].armor) + random(4));
pch = (data[a].dex - data[user].dex);
if(php < 1)
	php = (random(3) + 1);
wait:	//go here to wait for results to come back
if(strike == TRUE)
{

	co = od_get_answer("AUSYW?");
	switch(co)
	{
	case 'Y':{od_set_cursor(25,1);
			od_printf("`bright blue`Enter a one-line message to yell at your enemy.\n\r>`bright white`");
			od_input_str(mee,79,32,136);
			if(stricmp(mee,"")==0)
				{goto redraw;}
			if((wfp=fopenw(wfile,10))==NULL)
				{od_printf("`red`\n\rOther node is not responding...\n\r");
				goto end;}
			fseek(wfp,0,SEEK_END);
			fprintf(wfp,"\n\r~%s~",mee);
			fclose(wfp);
			fseek(rfp,0,SEEK_END);
			goto redraw;
			}
	case 'S':{stats();
			goto redraw;
			}
	case '?':
	case 'W':{goto redraw;
			}
	case 'A':{fclose(rfp);
			if((wfp=fopenw(wfile,10))==NULL)
				{od_printf("`red`\n\rOther node is not responding...\n\r");
				goto end;}
			fseek(wfp,0,SEEK_END);
			fprintf(wfp,"A");
			fclose(wfp);
			if((rfp=fopenr(wfile,1))==NULL)
				{od_printf("\n\r`red`An error has occurred in the game.");
				goto end;}
			fseek(rfp,0,SEEK_END);
			strike=FALSE;
			goto wait;}
	case 'U':{fclose(rfp);
			if((wfp=fopenw(wfile,10))==NULL)
				{od_printf("`red`\n\rOther node is not responding...\n\r");
				goto end;}
			fseek(wfp,0,SEEK_END);
			fprintf(wfp,"U");
			fclose(wfp);
			if((rfp=fopenr(wfile,1))==NULL)
				{od_printf("\n\r`red`An error has occurred in the game.");
				goto end;}
			fseek(rfp,0,SEEK_END);
			strike=FALSE;
			goto wait;}
	}
//this } ends user choice
}
else{  //here starts the LONG return code   (7,1) - enemies (12,1) - yours
if(holy == TRUE)
	goto hol;
od_set_cursor(1,1);
od_clr_line();
od_printf("`white`Waiting for return...");
Stime = time(NULL);
od_clr_line();
while(1)
{
b = fgetc(rfp);
if(b == '*')
	{
	fscanf(rfp,"%d%d%d",&data[a].hitpts,&data[user].hitpts,&hit);
	if(hit == TRUE)
			{
			od_set_cursor(12,1);
			od_clr_line();
			switch(random(3))
			{
			case 0:{od_printf("`bright red`With a strong slash, you bury your %s in your opponent's gut.\n\r",pw);
				break;}
			case 1:{od_printf("`bright red`You thrust your weapon into your opponent's side.\n\r");
				break;}
			case 2:{od_printf("`bright red`You sweep the enemy down and bring the butt of your %s to his face.\n\r",pw);
				break;}
			}
			data[a].hitpts -= php;
			if(data[a].hitpts<1)
				goto endead;
			}
		else if(hit == FALSE)
			{
			od_set_cursor(12,1);
			od_clr_line();
			switch(random(3))
			{
			case 0:{od_printf("`yellow`Your opponent easily dodges your attack.\n\r");
				break;}
			case 1:{od_printf("`yellow`Your thrust is blocked.\n\r");
				break;}
			case 2:{od_printf("`yellow`You accidently leave your chest open and you are shoved back.\n\r");
				break;}
			}
			}
	break;
	}
else if(b == 'A')
	{
	goto plsur;
	}
else if(b == 'D')
	{
	od_printf("\n\r`bright red`Your enemy smiles and releases a swift blow below your chin\n\r");
	od_printf("\n\rand you remember nothing else...");
	sleep(4);
	data[user].hitpts = 0;
	goto end;
	}

if(difftime(time(NULL),Stime) > 20)
	{od_printf("`red`Other node is not responding!");
	goto end;}
}
hol:
holy = FALSE;
od_set_cursor(1,1);
od_clr_line();
od_printf("`white`Waiting for attack...");
retur:	//returns here to wait again
Stime = time(NULL);
od_set_cursor(1,1);
od_clr_line();
do{
b=fgetc(rfp);
if(difftime(time(NULL),Stime) > 100)
	{
	od_printf("`red`Other node is not responding!");
	goto end;
	}
}while(b == EOF);
if(b=='~')
	{od_set_cursor(1,1);
	od_clr_line();
	od_printf("`bright red`%s `bright white`yells at you:\n\r",data[a].alias);
	od_printf("`bright blue`");
	do{
	b=fgetc(rfp);
	od_putch(b);
	}while((b==EOF) && (b!='~'));
	od_printf("\n\r");
	od_set_cursor(1,1);
	od_clr_line();
	od_set_cursor(2,1);
	od_clr_line();
	od_set_cursor(3,1);
	od_clr_line();
	goto retur;
	}
switch(b)
{
case 'U':{od_set_cursor(1,1);
		od_printf("`bright red`Your enemy has offered a surrender.  Do want to...\n\r");
		od_printf("`bright blue`(`bright red`A`bright blue`)  Accept his surrender and demand his gold\n\r");
		od_printf("`bright blue`(`bright red`D`bright blue`)  Decapitate this pitiful human.\n\r\n> ");
		hg = od_get_answer("AD");
		if(hg == 'A')
			{fclose(rfp);
			if((wfp=fopenw(wfile,10))==NULL)
				{od_printf("`red`\n\rOther node is not responding...\n\r");
				goto end;}
			fseek(wfp,0,SEEK_END);
			fprintf(wfp,"A");
			fclose(wfp);
			if((rfp=fopenr(wfile,1))==NULL)
				{od_printf("\n\r`red`An error has occurred in the game.");
				goto end;}
			fseek(rfp,0,SEEK_END);
			goto ensur;}
		else if(hg == 'D')
			{fclose(rfp);
			if((wfp=fopenw(wfile,10))==NULL)
				{od_printf("`red`\n\rOther node is not responding...\n\r");
				goto end;}
			fseek(wfp,0,SEEK_END);
			fprintf(wfp,"D");
			fclose(wfp);
			if((rfp=fopenr(wfile,1))==NULL)
				{od_printf("\n\r`red`An error has occurred in the game.");
				goto end;}
			fseek(rfp,0,SEEK_END);
			od_printf("\n\r`bright white`You stand tall above your fallen enemy and with a clean swipe, his head\n\r");
			od_printf("flying towards the wall\n\r");
			}
		}
case 'A':{if(pch > 8)
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
		if(ph == TRUE)
			{
			hg = random(3);
			od_set_cursor(7,1);
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
			data[user].hitpts -= php;
			if(data[user].hitpts<1)
				goto pldead;
			}
		else if(ph == FALSE)
			{
			hg = random(3);
			od_set_cursor(7,1);
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
			}
		//this ends case 'A'
		}
}
if(b != 'U')
	{if((wfp=fopenw(wfile,10))==NULL)
				{od_printf("`red`\n\rOther node is not responding...\n\r");
				goto end;}
			fseek(wfp,0,SEEK_END);
	fprintf(wfp,"*\n\r%d\n\r%d\n\r%d",data[user].hitpts,data[a].hitpts,ph);
	fclose(wfp);
	fseek(rfp,0,SEEK_END);}
strike=TRUE;
//here ends the LONG return code
}
endead:
od_clr_scr();
od_printf("`bright white`You are victorious in the Guild Arena!\n\r");
od_printf("`bright red`Two medics come and take away your victom after you scavenge\n\r");
od_printf("`bright blue`%d `bright red`coins.",data[a].coins);
od_printf("\n\n\r`bright white`You receive `bright red`%u `bright white`experience points.",(data[a].exp/4));
data[user].coins += data[a].coins;
data[a].coins = 0;
data[user].exp += (data[a].exp/4);
data[a].exp = (data[a].exp * 3/4);
data[a].hitpts = 1;
playsave('A',0,5);
goto end;
ensur:
od_clr_scr();
od_printf("`bright red`The entire crowd cheers at your strength and honor.\n\r");
od_printf("`bright white`You feel even stronger and slowly strut off the arena floor.\n\r");
data[user].coins += data[a].coins;
data[a].coins = 0;
data[a].hitpts = 1;
playsave('A',0,5);
goto end;
plsur:
od_clr_scr();
od_printf("`bright red`You give the enemy all of your gold and walk with lowered head out");
od_printf("\n\rof the arena.\n\r");
sleep(3);
data[user].coins = 0;
data[user].hitpts = 1;
goto end;
pldead:
od_clr_scr();
od_printf("`bright white`You have been defeated in the Guild Arena!\n\r");
od_printf("`bright red`You lose 1/4 of your experience and all your coins.\n\r");
od_printf("`bright white`You are carried away by medics and revived where you can walk again.\n\r");
sleep(3);
data[user].coins = 0;
data[user].hitpts = 1;
data[user].exp = (data[user].exp * 3/4);
end:
fclose(wfp);
fclose(rfp);
remove(wfile);
remove(wfile);
life();
}