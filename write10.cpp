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

struct monsters burk2[5] = {"Death", 14, 12, 0, 12, 5,
"Death swings his giant reaper and it slices your side.",
"Death's bulky arm crashes into your skull.",
"Death's reaper takes skin off your arm.",
"You see a dark figure holding a glowing scythe in his hand.",
"Death's reaper swings over your head, barely missing you.",
"Death's scythe misses you.",
"Death's scythe misses you.", 40, 0, 90,
"You feel yourself get paralyzed.  Death's scythe is run through you.", " ",
30000, 0, 1, " ", " ", " ", 45, 0, "Death Scythe",
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
0, 2, " ", " ", " ", 25, 0,"Fists and feet",
"Polar Bear", 14, 16, 0, 10, 3,
"The bear's massave claw rips the skin on your arm.",
"The bear hugs you so tigthly you lose your breath.  Struggling you break free.",
"A crunch tells you the bear nearly shattered your knee.",
"Ahead of you on the path stands a large white bear on his hind legs growling.",
"The bear loses it's balance and falls to the ground.",
"With luck, you dodge the bear's forceful attack.",
"Quickness keeps you ahead of the bear's razor sharp teeth.", 0, 0,110," "," ",
6, 0, 2," "," ",
"From the bushes run and huge white Bear, you draw your weapon.", 0, 1, "Very big hands"};

int main()
{
int a;
a = (sizeof(struct monsters)*5);
cout << "Writing "<< a << "bytes.";
handle=open("burk2.dat",O_RDWR|O_BINARY);
write(handle,burk2,(sizeof(struct monsters)*5));
return 0;
}