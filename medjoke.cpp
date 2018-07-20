#include "med.h"
#include <opendoor.h>
#include <ctype.h>

extern struct player_info data[60];
extern int user;
extern struct info2 edata;

struct _joke
{
char name[40];
char warning[80];
char sex;		//S for same sex, D for different sex, A for any sex
char photkey;	//hotkey for playing joke
char ahotkey;
char astring[80];
int aexp;
int expreturn;
int ahonor;
char sstring[80];
int sexp;
int shonor;
char aname[50];
char shit;
char slog[140];
char alog[140];
char sucret[80];
char unsret[80];
char food;
}joke[11];

char readjoke(void);
int getarray(char choice);

int getarray(char choice)
{
int cc;
for(cc=0;cc<10;cc++)
	{if(choice==joke[cc].photkey)
		break;
	}
return cc;
}


char readjoke(void)
{
int handle;
handle=eopen("joke.dat",3);
if(handle==-1)
	return -1;
else read(handle,joke,(sizeof(struct _joke)*11));
close(handle);
return 0;
}

char sendjoke(char sex)
{
if(readjoke()==-1)
	{od_printf("`red`Error locating file \"joke.dat.\"");
	return 0;}
int count;
char num;
od_printf("\n\r`bright white`%s",joke[10].astring);
od_printf("  [`bright blue`N`bright white`/`bright blue`y`bright white`] ");
if(od_get_answer("YN\n\r") != 'Y')
	return 0;
char choose[10];
for(count=0;count<10;count++)
	{
	if(joke[count].photkey==0)
		break;
	if(sex==data[user].sex&&joke[count].sex=='S');
	else if(joke[count].sex=='A');
	else if(sex!=data[user].sex&&joke[count].sex=='D');
	else continue;
	od_printf("\n\r`bright blue`%c`bright red`.  `bright white`%s",toupper(joke[count].photkey),joke[count].name);
	choose[count]=joke[count].photkey;
	}
od_printf("\n\r`bright white`Which one?  ");
num=od_get_answer(choose);
od_printf("`bright magenta`\n\n\rDone!\n\r");
edata.jokesleft--;
return num;
}

void recjoke(char hot,int log,char sex)
{
int num;
char filename[12];
FILE *fp;
if(readjoke()==-1)
	{od_printf("`red`Error locating file \"joke.dat.\"");
	return;}
num=getarray(hot);
od_printf("\n\r\n`bright blue`%s.",joke[num].warning);
od_printf("\n\r`white`%s",joke[10].sstring);
char choose[10];
int c2;
for(int c=0;c<10;c++)
	{
	if(joke[c].ahotkey==0)
		break;
	for(c2=0;c2<c;c2++)
		{
		if(choose[c2] == joke[c].ahotkey)
			break;
		}
	if(c2!=c)
		break;
	if(joke[c].sex=='A');
	else	if(sex==data[user].sex&&joke[c].sex=='S');
	else if(sex!=data[user].sex&&joke[c].sex=='D');
	else continue;
	od_printf("\n\r`bright blue`%c`bright red`.  `bright white`%s",toupper(joke[c].ahotkey),joke[c].aname);
	choose[c]=joke[c].ahotkey;
	}
od_printf("`white`\n\rWhich one?");
if(toupper(od_get_answer(choose))==toupper(joke[num].ahotkey))
	{
	//successful
	od_printf("\n\n\r`bright white`%s\n\r",joke[num].astring);
	if(joke[num].ahonor!=0)
		honoradd(joke[num].ahonor);
	if(joke[num].aexp!=0)
		exper(joke[num].aexp);
	switch(joke[num].food)
	{
	case 1:{//fish
			edata.i0=0;
			break;}
	case 2:{//bread
			edata.i3=0;
			break;}
	case 3:{//meat
			edata.i2=0;
			break;}
	case 4:{//all
			edata.i2=0;
			edata.i3=0;
			edata.i0=0;
			break;}
	}
	getreturn();
	fp = fopenw("day0.log",10);
	fprintf(fp,"~12-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-~15\n\r");
	if(joke[10].ahotkey == 'r')
		fprintf(fp,joke[num].alog,data[user].alias,data[findlog(log)].alias);
	else fprintf(fp,joke[num].alog,data[findlog(log)].alias,data[user].alias);
	fprintf(fp,"\n");
	fclose(fp);
	sprintf(filename,"%d.mal",data[findlog(log)].lognumber);
	fp=fopenw(filename,5);
	fprintf(fp,"~J%c%c %d ",joke[num].photkey,'f',data[user].lognumber);
	fclose(fp);
	}
else{//unsuccessful
	od_printf("\n\n\r`bright white`%s\n\r",joke[num].sstring);
	if(joke[num].shonor!=0)
		honoradd(joke[num].shonor);
	if(joke[num].sexp!=0)
		exper(joke[num].sexp);
	if(joke[num].shit>0&&joke[num].shit<100)
		{od_printf("`bright red`\n\rYou loose `bright white`%d`bright red` percent of your hitpoints!\n\r",joke[num].shit);
		data[user].hitpts = ((data[user].hitpts*(100-joke[num].shit))/100);
		if(data[user].hitpts<1||data[user].hitpts>data[user].totalhit)
			data[user].hitpts=1;}
	getreturn();
	fp = fopenw("day0.log",10);
	fprintf(fp,"~12-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-~15\n\r");
	if(joke[10].aexp=='r')
		fprintf(fp,joke[num].slog,data[user].alias,data[findlog(log)].alias);
	else	fprintf(fp,joke[num].slog,data[findlog(log)].alias,data[user].alias);
	fprintf(fp,"\n");
	fclose(fp);
	sprintf(filename,"%d.mal",data[findlog(log)].lognumber);
	fp=fopenw(filename,5);
	fprintf(fp,"~J%c%c %d ",joke[num].photkey,'t',data[user].lognumber);
	fclose(fp);
	}
}

void recret(char log, int who, char suc)
{
od_printf("\n\r`bright white`");
if(readjoke()==-1)
	{od_printf("`red`Error locating file \"joke.dat\"");
	}
if(suc == TRUE)
	od_printf(joke[getarray(log)].sucret,data[findlog(who)].alias);
else od_printf(joke[getarray(log)].unsret,data[findlog(who)].alias);
if(suc == TRUE){
if(joke[getarray(log)].expreturn!=0)
	exper(joke[getarray(log)].expreturn);}
}