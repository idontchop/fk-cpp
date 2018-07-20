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
int hit;
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
};

int handle;
struct monsters haywardfor[10] = {"George Bush", 2, 3, 5, 1, 1,
"George Bush rears up and kicks you in the head.",
"George brings out Dan Quayle and he nearly talks your head off, literally.",
"George runs for office again.",
"Walking down the path ahead of you is former president George Bush.",
"George thought he saw Bill and temporarily takes his eyes off you.",
"No action from the president now.",
"George's pants fall down and he trips.",
0, 0, 22, " ", " ", 30000, 10, 0,
"A fishing pole flies through the air and pierces your chest.",
"You hear a screech but nothing hits you.", " ", 14, 0, "Quayle",
"Dread Spider", 3, 2, 0, 2, 1,
"The Spider uses it's legs to severely buise you.",
"The Spider simply backs up and then charges knocking you to the ground.",
"An array of head thrusts leaves you without breath.",
"Coming towards you is a spider larger than a wolf.",
"You sweep the two front legs of the spider dropping him to the ground.",
"The spider's attack misses you by a long shot.",
"You barely jump out of the spider's way of his attack.", 8, 0, 17,
"The Dread spider covers you in with a blanket of webs.  Luckily you get free.", " ",
 5 , 0, 1, " ", " ",
"A dog-sized spider jumps onto the path right in front of you.", 0, 0, "Allota Legs",
"Barney", 4, 2, 0, 2, 1,
"Barney hits a bad note and your eardrum's burst.",
"Barney starts dancing and you get a terrible headache.",
"Barney's tail swings around and waps your legs.  You fall down.",
"You see small purple dinosaur singing and dancing down the path.",
"A punch from Barney is completely wild.",
"Barney trips over his tail as he tries to kick you.",
"Barney forgets he is fighting and starts singing.", 9, 0, 10,
"Barney steps back and starts singing \"I love you.\"  It draws away your blood.",
" ", 30000, 0, 2, " ", " ", " ", 15, 0, "Sweet Voice",
"IRS Agent", 4, 3, 0, 3, 2,
"You are audited!",
"The IRS Agent kicks your money pouch like a maniac.",
"You get no income tax back this year.",
"With a clipboard in his hands, a IRS Agent approaches you.",
"You successfully cheat on your tax returns.",
"You get lucky and knock the clipboard from his hands.",
"April 15 is finally over.",
0, 0, 25, " ", " ", 30000, 0, 0, " ", " ", " ", 40, 0, "The US government",
"Wild Boar", 3, 3, 0, 1, 1,
"The Boar charges and knocks you on your butt.",
"The Boar kicks and nearly breaks your knee.",
"A strong kick to the groan paralyzes you for a moment.",
"Ahead you see a Wild Boar running down the path.",
"You throw the Boar on it's back.",
"You kick the Boar away for this round.",
"It seems all too easy to dodge the Boar's attack.",
0, 0, 18, " ", " ", 5, 0, 0, " ", " ",
"You hear a sound behind you.  You turn only to stare down a Wild Boar.", 0, 0, "A pig snout"};

int main()
{
int a;
a = (sizeof(struct monsters)*5);
cout << "Writing "<< a << " bytes.";
handle=open("hayward2.dat",O_RDWR|O_BINARY);
write(handle,haywardfor,(sizeof(struct monsters)*5));
return 0;
}



