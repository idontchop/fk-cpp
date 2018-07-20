#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

char bbsname[30];
long regist(void);

void main()
{
cout << "Enter bbs name:  ";
gets(bbsname);
cout << "Number:  " << regist();
getch();

}

long regist(void)
{
long j = 0;
int cc;
for(cc=0;cc<30;cc++)
	{
	if(bbsname[cc]=='\0')
		break;
	j += toupper(bbsname[cc]);
	}
j = j+50000;
j = j/5;
j = j+2;
return j;
}

