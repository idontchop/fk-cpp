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

struct monsters sussenex[7] = {"Bigfoot",10,8,0,3,1,
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
"Snow Savage", 10, 10, 15, 4, 3,
"The savage's Morningstar crashes into your arm.",
"The savage trips you and brings the butt of his star to your face.",
"The metal ball of the savage's Morningstar crashes into your side.",
"Ahead you see a dirty savage wraped in many furs coming towards you.",
"You dodge the savage's attack.",
"You dodge the savage's attack.",
"Quickness keeps you ahead of the savage.",
0, 0, 65, " ", " ", 30000, 10, 3,
"A spear flies through the air and pierces your chest.",
"You hear a screech as a spear races through the air.", " ", 45, 0,"Morningstar",
"Snow Dwarf", 15, 14, 0, 7, 2,
"The Dwarf shows amaziny strength in his punch.",
"The Dwarf's axe digs deeply into your leg.",
"Brute strength from the Dwarf flips you over onto your back.",
"You spot a short but muscular dwarf ahead of you.",
"The dwarf completely misses you.",
"The dwarf looks stupid as it tries to grap hold of you.",
"You quickly step out of the way of the dwarf's attack.",
0, 0, 35, " ", " ", 6, 0, 4, " ", " ",
"A Dwarf jumps out of the snow and lands a foot in front of you.", 40, 0, "Axe",
"Snow Spider", 13, 11, 0, 6, 3,
"The Spider uses it's legs to severely buise you.",
"The Spider simply backs up and then charges knocking you to the ground.",
"An array of head thrusts leaves you without breath.",
"Coming towards you is a spider larger than a wolf.",
"You sweep the two front legs of the spider dropping him to the ground.",
"The spider's attack misses you by a long shot.",
"You barely jump out of the spider's way of his attack.", 18, 0, 57,
"The Dread spider covers you in with a blanket of webs.  Luckily you get free.", " ",
 5, 0, 3, " ", " ",
"A dog-sized spider jumps onto the path right in front of you.", 0, 0, "Allota Legs",
"Snow Wolf", 14, 13, 0, 6, 4,
"Flesh rips from your leg as the wolf's teeth dig in.",
"With a quick sweep from his paw, the wolf scratches your chest.",
"The wolf attacks you like a maniac.  Blood pours from many wounds.",
"Ahead of you, a drooling wolf stares at you with hungry eyes.",
"With a quick kick, you knock the wolf onto his back.",
"The wolf doesn't attack.",
"Agility keeps you away from the hungry jaws of the wolf.", 0, 0, 48," ", " ",
2, 0, 0, " ", " ",
"Suddenly, a wolf appears on the path less than a step ahead of you.", 0, 1, "Some scary teeth",
"Snow Leopard",14,16, 0, 7, 4,
"The Leopard's gigantic claws rake skin off your chest.",
"The Leopard digs it's long pointed teeth into your hip.",
"The Leopard jumps on you biting and clawing.",
"Coming towards you is a black-spotted, white Snow Leopard.",
"You kick the raging cat away.",
"You jump back from the cat's lungeing attack.",
"You kick the raging cat away.", 15, 0, 90,
"POWER MOVE!  The cat surprises you with an extremely strong attack.", " ",
4, 0, 2, " ", " ",
"From behind you, a large cat attacks you.", 0, 1, "Claws",
"Snowman",13,10,0,5,3,
"A massive fist crashes into your skull.",
"An elbow drives into your chest with overwhelming force.",
"The Snowman bites some flesh from your arm.",
"A monstrous, two-legged snow beast approaches you.",
"A fist flies past you.",
"A fist flies past your face.",
"You can feel the wind of his kick.",
24, 0, 85,
"The snowman's colossal foot strikes your skull with tremendous power.", " ", 30000,
0, 2, " ", " ", " ", 25, 0,"Fists and feet"};

int main()
{
int a;
a = (sizeof(struct monsters)*7);
cout << "Writing "<< a << "bytes.";
handle=open("sussenex.dat",O_WRONLY|O_BINARY);
write(handle,sussenex,(sizeof(struct monsters)*7));
return 0;
}
