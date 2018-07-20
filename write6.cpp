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

struct monsters eastm[8] = {"Bigfoot",10,8,0,3,1,
"Bigfoot's massive fist crashes into your skull.",
"Bigfoot's elbow drives into your chest with overwhelming force.",
"Bigfoot bites some flesh from your arm.",
"A monstrous, hairy two-legged beast approaches you.",
"Bigfoot's fist flies past you.",
"Bigfoot's fist flies past your face.",
"You can feel the wind of Bigfoot's kick.",
14, 0, 55,
"Bigfoot's colossal foot strikes your skull with tremendous power.", " ", 30000,
0, 4, " ", " ", " ", 35, 1,"Fists and feet",
"Xavier", 12, 10, 13, 6, 3,
"Xavier's sword stabs you in the gut.",
"Xavier's sword slashes your arm",
"Xavier's sword takes a flap of skin off your face.",
"You see an armoured cloaked man on a horse coming towards you.",
"You duck from Xavier's sword",
"You frighten Xavier's horse which keeps him from attacking.",
"Xavier's sword dropped to the snow.",
20, 0, 45,
"Xavier chants something and unleashes a flaming ball into your chest", " ", 5,
20, 3, "You hear a swish followed by a thud then you feel an arrow in your chest.",
"You barely catch site of an arrow flying past you.",
"Xavier, the cloaked horse-rider surprised you.", 30, 0, "Long Sword",
"Jolly Green Giant", 11, 10, 20, 6, 2,
"The giant's foot squashes you like a bag.",
"Jolly's hand crashes down on top of you.",
"A green bean knocks you to the ground.",
"You notice a massive green giant in front of you.",
"The giant forgets his height and swings over your head.",
"The giant slips on some spinach.",
"He kicks right past you.",
18, 0, 40,
"A huge brussel sprout smacks you on the forehead.", " ", 30000, 15, 5,
"A couple of brussel sprouts knocks you to the ground",
"You see some green balls fly past you.", " ", 5, 0, "vegatables",
"Igor", 10, 11, 0, 5, 3,
"Igor jabs a knife into your gut.",
"Igor knocks the breath out of you with his fist.",
"Igor kicks you in the groan.",
"A hunched-back man is coming towards you.",
"Igor swings but misses.",
"Igor falls backward because of his back.",
"You jump back from Igor's attack.",
10, 0, 40,
"Igor pulls out an axe and slashes your chest.", " ",
30000, 0, 2, " ", " ", " ", 15, 0, "Knifes",
"Snow Savage", 9, 8, 15, 4, 2,
"The savage's Morningstar crashes into your arm.",
"The savage trips you and brings the butt of his star to your face.",
"The metal ball of the savage's Morningstar crashes into your side.",
"Ahead you see a dirty savage wraped in many furs coming towards you.",
"You dodge the savage's attack.",
"You dodge the savage's attack.",
"Quickness keeps you ahead of the savage.",
0, 0, 60, " ", " ", 30000, 10, 3,
"A spear flies through the air and pierces your chest.",
"You hear a screech as a spear races through the air.", " ", 45, 0,"Morningstar",
"Snow Dwarf", 14, 13, 0, 7, 2,
"The Dwarf shows amaziny strength in his punch.",
"The Dwarf's axe digs deeply into your leg.",
"Brute strength from the Dwarf flips you over onto your back.",
"You spot a short but muscular dwarf ahead of you.",
"The dwarf completely misses you.",
"The dwarf looks stupid as it tries to grap hold of you.",
"You quickly step out of the way of the dwarf's attack.",
0, 0, 30, " ", " ", 6, 0, 4, " ", " ",
"A Dwarf jumps out of the snow and lands a foot in front of you.", 40, 0, "Axe",
"Snow Spider", 10, 11, 0, 5, 2,
"The Spider uses it's legs to severely buise you.",
"The Spider simply backs up and then charges knocking you to the ground.",
"An array of head thrusts leaves you without breath.",
"Coming towards you is a spider larger than a wolf.",
"You sweep the two front legs of the spider dropping him to the ground.",
"The spider's attack misses you by a long shot.",
"You barely jump out of the spider's way of his attack.", 18, 0, 37,
"The Dread spider covers you in with a blanket of webs.  Luckily you get free.", " ",
 5, 0, 3, " ", " ",
"A dog-sized spider jumps onto the path right in front of you.", 0, 0, "Allota Legs",
"Snow Wolf", 12, 10, 0, 5, 2,
"Flesh rips from your leg as the wolf's teeth dig in.",
"With a quick sweep from his paw, the wolf scratches your chest.",
"The wolf attacks you like a maniac.  Blood pours from many wounds.",
"Ahead of you, a drooling wolf stares at you with hungry eyes.",
"With a quick kick, you knock the wolf onto his back.",
"The wolf doesn't attack.",
"Agility keeps you away from the hungry jaws of the wolf.", 0, 0, 44," ", " ",
2, 0, 0, " ", " ",
"Suddenly, a wolf appears on the path less than a step ahead of you.", 0, 1, "Some scary teeth",};

int main()
{
int a;
a = (sizeof(struct monsters)*8);
cout << "Writing "<< a << "bytes.";
handle=open("eastm.dat",O_WRONLY|O_BINARY);
write(handle,eastm,(sizeof(struct monsters)*8));
return 0;
}






