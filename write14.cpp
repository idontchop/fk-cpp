#include <stdio.h>
#include <fcntl.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <dos.h>
#include <stdlib.h>


//this one holds West Trim sewers

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

struct monsters sewer[7] = {"Sewer Rat", 4, 5, 0, 4, 2,
"The sewer rat latches onto your leg",
"The sewer rat latches onto your leg",
"The sewer rat tears up your leg.",
"A giant sewer rat approaches.",
"The rat sits there and waits",
"The rat sits there and waits",
"The rat jumps past you",
0,0, 40, "", "", 4, 0,0,"","",
"A sewer rat attacks you from behind",
0,1,"Long teeth",
"Leonardo",
7,7,0,6,2,
"Leonardo's sword slashes across your chest",
"Leonardo's sword slashes across your chest",
"A sword comes from overhead down into you",
"Coming toward you is a really big turtle.",
"You kick Leonardo off his feet",
"You kick Leonardo off his feet",
"Luck keeps you ahead of Leonardo's attack",
15,0,40, "An extremely powerful thrust sticks your shoulder deep", "",
4, 0, 2,"","","From behind a corner appears a Teenage Mutant Ninja Turtle",
3,0,"Twin Swords",
"Raphael",8,7,0,6,2,
"Raphael sticks a sai in your gut",
"Raphael sticks a sai in your gut",
"Raphael rips your shirt wide open with his sai.  Time to Shop!",
"A big turtle approaches.",
"Raphael falls on his face in front of you",
"Raphael falls on his face in front of you",
"You sweep Raphael off his feet",
15,0,40,"An extremely powerful attack takes you off your balance.","",4,0,2,
"","","A big turtle steps out of the shadows behind you.",
2,0,"Sais",
"Michealangelo",7,8,0,6,2,
"A nun-chuck hurls into your side",
"A nun-chuck hurls into your side",
"The quick tutle really takes you with his attack",
"Ahead of you is a big turtle",
"You dodge the attack",
"You dodge the attack",
"You jump out of the way of Raphael's attack",
15,0,40,"Machealangelo hits you with a very strong rush attack","",
4,0,2,"","","A big turtle steps out of the shadows", 3, 0,"Nun-chucks",
"Donatello",
7,7,0,6,2,
"A staff wips around and cracks you in the head",
"A staff wips around and cracks you in the head",
"A staff takes you off your feet and then comes down in your gut",
"Coming towards you is a very big turtle on two legs",
"You jump out of the way of the attack",
"You jump out of the way of the attack",
"You are able to dodge the attack",  20,0,15,
"You are taken off-guard by an extremely powerful attack","", 4, 0,2,"","",
"From the shadows come a big turtle", 3, 0, "Staff",
"Bum",5,4,0,3,3,
"The bum hits your chest",
"The bum hits your chest hard",
"The bum takes you down",
"Sitting in the slimy water is a bum that raises as you approach",
"You push the bum back so he can't attack",
"You push the bum back so he can't attack",
"The bum takes a chill pill this round", 0,0,25,"","",30000,0,0,"","","",3,0,"beer bottle",
"Alligator",6,5,0,3,2,
"The massive jaws clamp on your leg",
"The massive jaws clamp on your leg",
"The jaws of the alligator bite into your side",
"An alligator approaches you.",
"You jump back from the alligator",
"You jump back from the alligator",
"You are able to dodge the alligator's attack",
0,0,30,"","", 3, 0, 0,"","",
"You step on an alligator that gets very mad", 0,0,"Teeth"};

int main()
{
int a;
a = (sizeof(struct monsters)*7);
cout << "Writing "<< a << "bytes.";
handle=open("westsew.dat",O_RDWR|O_BINARY);
write(handle,sewer,(sizeof(struct monsters)*7));
return 0;
}
