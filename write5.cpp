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

struct monsters east[6] = {"Cyclops", 10, 9, 0, 4, 2,
"The Cyclops snaps your arm with a solid strike.",
"The Cyclops's club bashes your leg.",
"Cyclops swings his club and shatters your knee.",
"A huge one-eyed beast starts running toward you.",
"The Cyclops swings his club and hits a tree instead of you.",
"He didn't even get close with his attack.",
"The club screeches by your ear.",
10, 0, 50,
"The Cyclops backs up, and swings his club like a baseball bat onto your head.",
" ", 4, 0, 2, " ", " ",
"You hear noises behind you.",  53, 0, "Club",
"Hermes", 5, 10, 0, 4, 3,
"You momentarily loose site of Hermes and then your head starts to sting.",
"Hermes knees you in the groan.",
"Hermes leans back and jump-kicks you in the face.",
"A creature of darkness is approacking you at lightning speed.",
"His speed makes his kick pass right by you.",
"He jumps to kick you but is easily tripped.",
"He tries to kick you but you throw his leg back.",
9, 0, 40,
"Hermes disappears in a flash of light.  An array of kicks badly bruises you.",
" ", 2, 0, 2, " ", " ",
"A creature of darkness appears in front of you.",
40, 0, "Darkness",
"Flarney", 7, 8, 0, 4, 2,
"Flarney runs and kicks you in the knee.",
"Flarney punches you in the knee and you drop.",
"He bites a big chunk of flesh off your calf.",
"Ahead, you see a leprechaun sitting in a clover patch.",
"Flarney tries to kick too hard and falls down.",
"He swings at you but misses by a few inches.",
"Flarney tries to bite you but you shake him off.",
5, 5, 40,
"Flarney throws gold coins on the ground then ambushes you!",
"Flarney throws gold coins on the ground then ambushes you!", 30000, 0, 0,
" ", " ", " ", 160, 0, "Magic",
"Giant Warplant", 9, 8, 0, 4, 2,
"A branch sweeps you to the ground.",
"A leaf slits your arm.  This will need stitches.",
"Roots rise from the ground and whip your legs.",
"Off to the right, you see a Giant Warplant.  You go meet it.",
"The plant sits there for this round.",
"Amazingly, you are able to dodge the plant's attack",
"The plant sits there for this round.",
0, 0, 50, " ", " ", 30000, 0, 0, " ", " ", " ", 30, 0, "Big leaves",
"Griffin", 6, 7, 0, 4, 3,
"The Griffin's claws rake across your chest.",
"The Griffin's beak pierces your gut.",
"The Griffen scrapes your legs to shreds.",
"Ahead is a half-eagle, half-lion horror.",
"You kick the Griffin back so that he can't attack.",
"The Griffin studies you for this round.",
"You successfully block the Griffen's attack.",
0, 0, 45, " ", " ", 3, 0, 1, " ", " ",
"A half-eagle, half-lion flies down and meets you face to face.", 0, 1, "Claws",
"Centaur", 8, 6, 0, 4, 3,
"A massive fist crashes into your forehead.",
"The Centaur turns around and kicks you knocking you to the ground.",
"The Centaur picks you up and throws you down hard.",
"You meet a Centaur.  Half-man, half-horse.",
"You jump back from the Centaur's fist.",
"You run around the Centaur and easily dodge his attack.",
"You easily evade the Centaur's attack.",
0, 0, 35, " ", " ", 3, 0, 0, " ", " ",
"A half-man, half-horse creature jumps out of the bushes and startles you.", 20, 0, "Horse legs"};



int main()
{
int a;
a = (sizeof(struct monsters)*6);
cout << "Writing "<< a << "bytes.";
handle=open("pomdir.dat",O_RDWR|O_BINARY);
write(handle,east,(sizeof(struct monsters)*6));
return 0;
}
