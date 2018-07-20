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

struct monsters haywardfor[10] = {"Wolf", 2, 3, 0, 1, 1,
"Flesh rips from your leg as the wolf's teeth dig in.",
"With a quick sweep from his paw, the wolf scratches your chest.",
"The wolf attacks you like a maniac.  Blood pours from many wounds.",
"Ahead of you, a drooling wolf stares at you with hungry eyes.",
"With a quick kick, you knock the wolf onto his back.",
"The wolf doesn't attack.",
"Agility keeps you away from the hungry jaws of the wolf.", 0, 0, 14," ", " ",
2, 0, 0, " ", " ",
"Suddenly, a wolf appears on the path less than a step ahead of you.", 0, 1, "Some scary teeth",
"Bear", 4, 5, 0, 1, 0,
"The bear's massave claw rips the skin on your arm.",
"The bear hugs you so tigthly you lose your breath.  Struggling you break free.",
"A crunch tells you the bear nearly shattered your knee.",
"Ahead of you on the path stands a large Brown Bear on his hind legs growling.",
"The bear loses it's balance and falls to the ground.",
"With luck, you dodge the bear's forceful attack.",
"Quickness keeps you ahead of the bear's razor sharp teeth.", 0, 0,20," "," ",
6, 0, 0," "," ",
"From the bushes run and huge Brown Bear, you draw your weapon.", 0, 1, "Very big hands",
"Warplant", 4, 1, 0, 2, 2,
"You get too close and the warplant's razor leaves slices you arms.",
"Like a table saw, a leaf puts a large slit in your chest.",
"You step on the plant's roots which was a very bad idea.",
"Off in the woods you see a mighty Warplant.  You go greet your next victom.",
"You are able to dodge the plant's attack.",
"The Warplant just seems to sit there.",
"No action this time from the Warplant.",
5, 0, 16,
"A stream of acid pours onto your leg from the flower's bud.", " ",
30000,0,0," "," "," ", 30,0, "Leaves",
"Red Squirrel", 1, 2, 0, 1, 0,
"The Squirrel's razor sharp claws take some of your skin from your leg.",
"You yell as the Squirrel's two teeth dig in your upper thigh.",
"The little animal crawls all around you biting and clawing.",
"You see a red Squirrel come down the tree after you.  These things kill!",
"With quick hands, you roll the thing onto it's back.",
"A quick kick sends his attack in the other direction.",
"The little guy seems like a house pet for this round.", 0, 0, 8," "," ",30000, 0, 1," "," "," ",0,1, "Rodent Teeth",
"Red Rabbit", 2, 2, 0, 1, 1,
"Quick as lightning, the little animal inflicts small injuries.",
"His two front teeth dig into your arm and seem to hold on for eternity.",
"The Rabbit uses it's hind legs and nearly breaks your leg at the knee.",
"Ahead is a Red Rabbit, it looks mean and hungry.",
"It tries to kick your leg but you easily dodge it's blow.",
"The Rabbit stumbles over it's own feet.",
"You give the Rabbit a kick sending it rolling.",
0, 0, 9, " ", " ", 15, 0, 0, " ", " ",
"A Red Rabbit jumps out of the bushes next to you.  You draw your weapon.", 0, 1, "Rodent Teeth",
"Red Fox", 2, 2, 0, 1, 1,
"The vicous little fox bites a big hunk out of your leg.",
"The quick animal dodges your block and bites your groan.",
"A series of biting and clawing seems to tear the tendons from your leg.",
"You spot a Red Fox on a side path, you confront him.",
"The Fox stumbles over it's tail and falls over.",
"You easily jump out of the way of the Fox's claw.",
"The Fox's attack is uncoordinated and doesn't even touch you.",
0, 0, 12, " ", " ", 6, 0, 0, " ", " ",
"You hear some snarling from the bushes, then a fox jumps out in front of you.", 0, 1, "Razor Teeth",
"Rabid Dog", 3, 2, 0, 1, 1,
"The Rabid Dog takes a big chunk out of your leg.",
"The dog jumps on you biting and clawing.",
"The Rabid Dog knocks you down; you hit your head on a rock.",
"Drueling and Snarling, a Rabid Dog blocks your path ahead.",
"You kick the dog onto it's back as it tries to attack.",
"A jump keeps you ahead of the dog's fangs.",
"Luckily for you, the dog takes a rest this time through.",
0, 0, 14, " ", " ", 10, 0, 0, " ", " ",
"You turn around and come face to face with a vicous Rabid Dog.", 0, 0, "Spit and teeth",
"Savage", 3, 4, 5, 2, 2,
"The Savage's Short Sword makes a deep cut across your arm.",
"Watching his sword, the Savage sneaks a kick to your groan.",
"The Savage's sword cuts off a piece of your cheek.  Time for Makeup!",
"You see a savage cannibal coming towards you from the fields.",
"The Savage clumsily swings his sword far in front of you.",
"Shear skill allows you to block each of the Savage's attack.",
"You jump back just as the Savage thrusts his sword towards your chest.",
0, 0, 24, " ", " ", 5, 10, 0,
"A red spear flies through the air and then pierces you chest.",
"A red spear races through the air over your head.",
"A savage cannibal pops out of the woods and confronts you.",
35, 1, "Short Sword",
"Dwarf", 2, 1, 5, 2, 2,
"The Dwarf shows amaziny strength in his punch.",
"The Dwarf's dagger digs deeply into your leg.",
"Brute strength from the Dwarf flips you over onto your back.",
"You spot a short but muscular dwarf ahead of you.",
"The dwarf completely misses you.",
"The dwarf looks stupid as it tries to grap hold of you.",
"You quickly step out of the way of the dwarf's attack.",
0, 0, 6, " ", " ", 6, 0, 0, " ", " ",
"A Dwarf jumps out of the bushes and lands a foot in front of you.", 20, 0, "Dagger",
"Bill Clinton", 3, 2, 5, 1, 1,
"Bill Clinton swings around and busts your lip with his tie.",
"President Bill Clinton resigns!  NOOOO!",
"Bill suddenly brings Hillary out and she bites your lip, HARD.",
"You spot Bill Clinton down the path practicing his speech.",
"The monitor goes off and Bill says nothing.",
"Bill loses his job.",
"Hillary appears and keeps Bill from attacking.",
0, 0, 22, " ", " ", 30000, 8, 1,
"A pellet from a slingshot hits you in the forehead.",
"You hear a pellet rocket over your head.", " ", 23, 0, "Hillary"};

int main()
{
int a;
a = (sizeof(struct monsters)*10);
cout << "Writing "<< a << "bytes.";
handle=open("hayward.dat",O_RDWR|O_BINARY);
write(handle,haywardfor,(sizeof(struct monsters)*10));
return 0;
}


