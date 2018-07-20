#include "med.h"
#include <share.h>

/*following lines will need to go in med.h or another header file
void guildhall(void);
*/
extern struct player_info data[51];
extern int user;


void guildhall(void);
{
int handle,ucount;
int user_num[50];
if(_fsopen("chat.dat","r",SH_DENYNONE)==NULL)
	{fclose(fopen("chat.dat","w"));
	for(ucount=0;ucount<50;ucount)
	{
	user_num[ucount] = 32000;
	}
	}
if((handle = eopen("chat.dat",10))==-1)
	{od_printf("An error has occured in the game, chat unreachable.");
	goto chatend;}
read(handle,user_num,(sizeof(int)*50));
for(ucount = 50;ucount<50;ucount++)
{
if(user_num[ucount] == 32000)
	{user_num[ucount] = user;
	break;}
}
write(handle,user_num,(sizeof(int)*50));
close(handle);
od_printf("`bright blue`Other players in the guild hall`bright red`:\n\r");
int jjj;
for(jjj=0;jjj<50;jjj++)
	{if(user_num[jjj] != 32000)
		od_printf("`bright white`%s`bright red`, ",data[user_num[jjj]].alias);
	}
od_printf("`bright magenta`Type / to send a message to all\n\r");
od_printf("`bright magenta`Type `bright white` \\? `bright magenta`for help.\n\r");
char string[80];
FILE *fp1,*fp2;
//NEEDS A FUNCTION TO WAIT FOR TURN
fp2=_fsopen("chat.log","a",SH_DENYWR)






chatend:
}