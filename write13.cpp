#include <stdio.h>
#include <fcntl.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <dos.h>
#include <stdlib.h>


//this one holds all the thief fighters

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

struct monsters thief[7] = {"Angry Mob",20,20,20,15,10,
"Fists and clubs and stuff hit you from all sides.",
"All kinds of weapons land right on your head.",
"Ouch!  You yell and your blood flies on the walls.",
"Suddenly, and angry mob of citizens is upon you.",
"You feel lucky to dodge those attacks.",
"You feel lucky to dodge those attacks.",
"You feel lucky to dodge those attacks.",
0, 0, 300,
" ", " ", 30000,
0, 0, " ", " ", " ", 0, 0,"Fists and clubs",
"Fellow thief", 10, 20, 15, 4, 1,
"The thief's Dagger crashes into your arm.",
"The thief trips you and brings the butt of his dagger to your face.",
"The thief's dagger slashes into your side.",
"The thief closes on you.",
"You dodge the thief's attack.",
"You dodge the thief's attack.",
"Quickness keeps you ahead of the thief.",
0, 0, 105, " ", " ", 30000, 10, 0,
"A spear flies through the air and pierces your chest.",
"You hear a screech as a spear races through the air.", " ", 45, 0,"Dagger",
"Guild member", 15, 14, 0, 7, 2,
"The man shows amaziny strength in his punch.",
"The guy's axe digs deep into your leg.",
"Brute strength from the dude flips you over onto your back.",
"You have disturbed a guild member.",
"The man completely misses you.",
"The guy looks stupid as it tries to grap hold of you.",
"You quikly step out of the way of the dude's attack.",
0, 0, 65, " ", " ", 30000, 0, 4, " ", " ",
".", 10, 0, "Axe",
"Guard", 13, 11, 0, 6, 0,
"The guard uses his longsword with clean strokes.",
"The guard knocks you off your feet and follows with a sharp kick.",
"An array of jabs leaves you without breath.",
"Coming towards you is a town guard.",
"You sweep the legs of the guard and drop him to the ground.",
"The guard's attack doesn't even come close.",
"You barely dodge the guard's attack.", 0, 0, 80,
"T", " ",
 30000, 0, 0, " ", " ",
"", 0, 0, "Longsword",
"Hayward guard", 4, 3, 0, 3, 2,
"The tip of the guard's mace digs into your chest.",
"With a quick sweep from the mace, you are left clueless.",
"The guard attacks you like a maniac.  Blood pours from many wounds.",
"Ahead of you, a hayward guard blocks your path.",
"With a quick kick, you knock the guard onto his back.",
"The guard doesn't attack.",
"Agility keeps you away from the guard's mace.", 0, 0, 38," ", " ",
30000, 0, 0, " ", " ",
"Suddenly, a wolf appears on the path less than a step ahead of you.", 5, 0, "Mace",
"Owner",4,6, 0, 4, 3,
"\"Get out of here\" yells the furious man.",
"A morningstar crashes right into your hip.",
"An array of attacks comes from the man.",
"It seems you have been caught by the owner of this place.",
"You kick the raging owner away.",
"You jump back from the owner's lungeing attack.",
"You kick the raging owver away.", 15, 0, 25,
"The man surprises you with a dagger in his left hand.", " ",
30000, 0, 0, " ", " ",
" ", 7, 0, "Morningstar",
"Owner",14,16, 0, 4, 3,
"\"Get out of here\" yells the furious man.",
"A morningstar crashes right into your hip.",
"An array of attacks comes from the man.",
"It seems you have been caught by the owner of this place.",
"You kick the raging owner away.",
"You jump back from the owner's lungeing attack.",
"You kick the raging owver away.", 15, 0, 55,
"The man surprises you with a dagger in his left hand.", " ",
30000, 0, 0, " ", " ",
" ", 7, 0, "Morningstar"
};

int main()
{
int a;
a = (sizeof(struct monsters)*7);
cout << "Writing "<< a << " bytes.";
handle=open("thief.dat",O_WRONLY|O_BINARY);
write(handle,thief,(sizeof(struct monsters)*7));
return 0;
}