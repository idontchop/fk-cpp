#include <stdio.h>
#include <fcntl.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <dos.h>
#include <stdlib.h>

struct monsters{
char name[20];
int str;
int dex;
char aim;
char WP;
char AP;
char hit1[80];
char hit2[80];
char hit3[80];
char site[80];
char miss1[80];
char miss2[80];
char miss3[80];
char special1;
char special2;
char hit;
char spe1[80];
char spe2[80];
int surprise;
char LP;
char run;
char longhit[80];
char longmiss[80];
char surpris[80];
int coins;
char skins;
char weapon[20];
} haywardfor[15];

int main()
{
int handle;
clrscr();
handle=open("hayward.dat",O_RDWR|O_BINARY);
read(handle,haywardfor,(sizeof(struct monsters)*15));
for(int count=0;count<16;count++){
cout << count << ":";
puts(haywardfor[count].name);}
return 0;
}