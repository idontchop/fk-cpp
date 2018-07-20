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

struct monsters line[11] = {"Juliet", 6, 5, 10, 6, 2,
"Juliet thrusts her Long Sword into your side.",
"Juliet slashes her Long Sword across your chest.",
"Juliet trips you and sticks her sword in you.",
"Get ready for a battle with Juliet.",
"He misses by a long-shot.",
"You dodge her attack easily.",
"You dodge her attack easily.", 0, 0, 65, " ", " ", 30000, 20, 0,
"An arrow soars through the air and strikes your chest.",
"You catch site of an arrow flying over your head.", " ", 20, 0, "Long Sword",
"Vardius", 8, 7, 10, 6, 3,
"Vardius thrusts his Long Sword into your side.",
"Vardius slashes his Long Sword across your chest.",
"Vardius trips you and sticks his sword in you.",
"Get ready for a battle with Vardius.",
"He misses by a long-shot.",
"You dodge his attack easily.",
"You dodge his attack easily.", 0, 0, 70, " ", " ", 30000, 20, 0,
"An arrow soars through the air and strikes your chest.",
"You catch site of an arrow flying over your head.", " ", 23, 0, "Long Sword",
"Nadiera", 10, 9, 15, 7, 2,
"Nadiera thrusts her Long Sword into your side.",
"Nadiera slashes her Long Sword across your chest.",
"Nadiera trips you and sticks her sword in you.",
"Get ready for a battle with Nadiera.",
"She misses by a long-shot.",
"You dodge her attack easily.",
"You dodge her attack easily.", 0, 0, 95, " ", " ", 30000, 20, 0,
"An arrow soars through the air and strikes your chest.",
"You catch site of an arrow flying over your head.", " ", 20, 0, "Axe",
"Julius", 11, 12, 10, 8, 3,
"Julius thrusts his Long Sword into your side.",
"Julius slashes his Long Sword across your chest.",
"Julius trips you and sticks his sword in you.",
"Get ready for a battle with Julius.",
"He misses by a long-shot.",
"You dodge his attack easily.",
"You dodge his attack easily.", 0, 0, 105, " ", " ", 30000, 30, 0,
"A bolt soars through the air and strikes your chest.",
"You catch site of a bolt flying over your head.", " ", 33, 0, "Diamond Sword",
"Soldier", 10, 9, 10, 6, 2,
"The soldier thrusts a sword into your gut.",
"The soldier thrusts a sword into your gut.",
"The soldier slashes a gash in your arm.",
"A soldier of Trimmail approaches.",
"You easily evade the attack.",
"You easily evade the attack.",
"You jump back from the attack.", 0, 0, 65, " ", " ", 3, 20, 15,
"An arrow pierces your chest.", "An arrow flies over your head.",
"You are surprised by a soldier of Trimmail.", 15, 0, "Long Sword",
"Royal Soldier", 15, 11, 15, 6, 3,
"The soldier thrusts a sword into your gut.",
"The soldier thrusts a sword into your gut.",
"The soldier slashes a gash in your arm.",
"A royal soldier of Trimmail approaches.",
"You easily evade the attack.",
"You easily evade the attack.",
"You jump back from the attack.", 0, 0, 90, " ", " ", 30000, 30, 0,
"A bolt pierces your chest.", "A bolt flies over your head.", " ", 10, 0, "Long Sword",
"Royal Wolf Pirate", 13, 10, 0, 7, 4,
"The Pirate hits you hard with his axe.",
"The Pirate's axe slams into your side.",
"The Pirate's axe slashes skin off your arm.",
" ", "You kick the pirate back.",
"You kick the pirate back.",
"You jump back and sweep the pirate down.", 0, 0, 85, " ", " ", 0, 0, 0,
" ", " ", "You are face to face with the Royal Wolf Pirate.", 20, 0, "Axe",
"Fire Hydra", 11, 11, 0, 4, 3,
"The Hydra's tentacle knocks you to the ground.",
"The Hydra's tentacle wraps around you and squeezes.",
"The Hydra's tentacle knocks you back.",
"You approach the Fire Hydra.",
"You easily evade the Hydra's attack.",
"You easily evade the Hydra's attack.",
"You easily evade the Hydra's attack.", 10, 0, 80,
"The Fire Hydra breaths a stream of fire onto you.", " ", 30000, 0, 0,
" ", " ", " ", 0, 0, "Fire",
"Guard Dog",6,11,0,2,0,
"The Guard Dog takes a big chunk out of your leg.",
"The dog jumps on you biting and clawing.",
"The Guard Dog knocks you down; you hit your head on a rock.",
"Drueling and Snarling, a Guard Dog blocks your path ahead.",
"You kick the dog onto it's back as it tries to attack.",
"A jump keeps you ahead of the dog's fangs.",
"Luckily for you, the dog takes a rest this time through.",
0, 0, 44, " ", " ", 2, 0, 0, " ", " ",
"A Guard dog jumps out right in front of you.", 0, 0, "Fangs",
"Guardian",15,22,20,9,3,
"Guardian hits you with a flaming ball in the gut, flames burn your body.",
"Guardian pulls out a semi-automatic rifle and cuts you down with it.",
"Your face is burned by Guardian's lightning breath.",
"Ahead of you is Guardian, the protector of the right to be called winner.",
"Guardian unleashes a fan of flames that you easily duck from.",
"The Guardian falls on his face below you.",
"Guardian tries to spear you, but fails.",
50,50, 110,
"The Guardian stands straight and sticks a claw in your chest.",
"From Guardian's hands come flames that torch your armour.",
30000,30,0,"A flaming spear crashes into your chest.",
"A flaming spear flies by your ear and sets fire to the curtains.",
"", 0, 0, "Magic and Power",
"Big Silver Gorilla",15,16,0,9,3,
"The arms of the gorilla rake your body.",
"The arms of the gorilla rake your body.",
"You are pulverized by the gorilla.",
"Running toward you is a VERY big silver gorilla.",
"The gorilla falls on its face",
"The gorilla falls on its face",
"The gorilla falls flat on its face",
0,0,110,"","",30000,0,0,"","","",0,1,"Paws"};

int main()
{
int a;
a = (sizeof(struct monsters)*11);
cout << "Writing "<< a << "bytes.";
handle=open("stryline.dat",O_RDWR|O_BINARY);
write(handle,line,(sizeof(struct monsters)*11));
return 0;
}
