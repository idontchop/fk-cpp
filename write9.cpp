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

struct monsters deep[9] = {"Shang Tsung", 15, 16, 15, 7, 3,
"Shang Tsung hits you with all his strength.",
"You loose your breath as Shang Tsung jabs you in the gut.",
"Shang Tsung kicks you in the head.",
"You notice a demonic man in a long blue uniform approaching you.",
"Shang Tsung's foot soars past you.",
"You sweep Shang Tsung down and retire his attack.",
"You successfully dodge Shang Tsung's attack.", 0, 0, 100, " ", " ", 3, 30, 3,
"Eight flaming skulls collide with your head.",
"Just in time, you dodge eight flaming skulls.",
"You put your hand on a tree and it turns into Shang Tsung.", 45, 0, "Martial Arts",
"Minotaur", 14, 15, 0, 8, 3,
"The Minotaur kicks you in the head with his hoof.",
"The Minotaur jabs its horns into your side.",
"The Minotaur jumps and kicks you in the chest with his hooves.",
"You see a half-man, half-bull creature coming towards you.",
"You dodge the Minotaur's attack and then throw him back.",
"You easily dodge the Minotaur's attack.",
"You easily dodge the Minotaur's attack.", 0, 0, 100, " ", " ", 4,0,2,
" ", " ", "A Minotaur seems to have snuck up on you.", 0, 1, "Horns",
"Chimera", 14, 14, 0, 9, 4,
"The Chimera bites you.",
"The Chimera's teeth dig deep into your arm.",
"The Chimera kicks you to the ground.",
"You see a part-lion, part-goat, and part-dragon heading towards you.",
"The Chimera misses you completely.",
"The Chimera misses you completely.",
"You kick the Chimera back and retire his attack.", 25, 0, 110,
"The Chimera breaths into your face.", " ", 30000, 0, 2, " ", " ", " ", 0, 1, "teeth",
"Destroyer", 17, 16, 17, 9, 4,
"The Destroyer's claws rake across your chest.",
"The Destroyer's claws rake across your arm.  Blood gushes from the wound.",
"The Destroyer's claws rake across your chest.",
"Coming towards you is a demon with red wings and horns on its head.",
"You are able to dodge the attack.",
"You are able to dodge the attack.",
"You jump back from the Destroyer's attack.", 0, 0, 95, " ", " ", 30000, 30, 3,
"A fireball hits you in the face.",
"A fireball flies over your head and nearly toasts your hair.", " ", 0, 0, "Fire",
"Great Troll", 18, 16, 10, 7, 5,
"The Troll's sword is thrusted into your chest.",
"The Troll's sword slashes your arm.",
"The Troll's sword digs deep into your side.",
"Ahead of you is a huge monstrous beast.",
"You jump back from the Troll's attack.",
"You sweep the giant beast down to retire his attack.",
"You jump back from the Troll's attack.", 0, 0, 90, " " , " ", 30000, 6, 2,
"A pelet hits you in the chest.",
"A pelet rockets over your head.", " ", 20, 0, "Long Sword",
"Reaper", 18, 12, 0, 8, 3,
"A large claw-like branch knocks you down.",
"A branch swings through the air and knocks you to the ground.",
"The Reaper sticks a pointed branch into your gut.",
"You notice a moving tree ahead of you.",
"The Reaper's clumsy attack is easy to evade.",
"You roll away from the Reaper's attacking limb.",
"The Reaper's clumsy attack is easy to evade.", 0, 0, 105, " ", " ", 30000, 0, 3,
" ", " ", " ", 0, 0, "Branches",
"Spectre", 10, 20, 0, 9, 3,
"An invisible hand knocks you to the ground.",
"You are sweeped down and attacked with full force.",
"Some kind of force jumps inside you and tears away at your insides.",
" ",  "The Spectre doesn't attack.",
"The Spectre doesn't attack.",
"The Spectre doesn't attack.", 40, 0, 120,
"The Spectre unleashes a blinding flash of light then ambushes you.", " ",
0, 0, 0, " ", " ",
"Suddenly, a ghostly creature appears in front of you.", 0,0,"hands",
"Great Black Bear", 13, 15, 0, 11, 3,
"The bear's massave claw rips the skin on your arm.",
"The bear hugs you so tigthly you lose your breath.  Struggling you break free.",
"A crunch tells you the bear nearly shattered your knee.",
"Ahead of you on the path stands a large Black Bear on his hind legs growling.",
"The bear loses it's balance and falls to the ground.",
"With luck, you dodge the bear's forceful attack.",
"Quickness keeps you ahead of the bear's razor sharp teeth.", 0, 0,110," "," ",
6, 0, 2," "," ",
"From the bushes run and huge Brown Bear, you draw your weapon.", 0, 1, "Very big hands",
"Red Warplant", 15, 11, 0, 8, 3,
"You get too close and the warplant's razor leaves slices you arms.",
"Like a table saw, a leaf puts a large slit in your chest.",
"You step on the plant's roots which was a very bad idea.",
"Off in the woods you see a mighty Warplant.  You go greet your next victom.",
"You are able to dodge the plant's attack.",
"The Warplant just seems to sit there.",
"No action this time from the Warplant.",
35, 0, 86,
"A stream of acid pours onto your leg from the flower's bud.", " ",
30000,0,0," "," "," ", 30,0, "Leaves"};

int main()
{
int a;
a = (sizeof(struct monsters)*9);
cout << "Writing "<< a << "bytes.";
handle=open("deep.dat",O_WRONLY|O_BINARY);
write(handle,deep,(sizeof(struct monsters)*9));
return 0;
}