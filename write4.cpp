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
struct monsters denjun[10] = {"The evil Jester", 6, 4, 0, 1, 2,
"Malcom drives a dagger through your side, you scream in pain.",
"You scream with agony as Malcom cuts off a chunk of your thigh.",
"Malcom mooves quickly, and before you know it you have a dagger in your gut.",
"You notice a multi-colored jester coming towards you from down the path.",
"You quickly move as Malcom slashes at you with his dagger",
"Malcom swings so hard that he completely misses you and falls down",
"You hear a loud THUD! as malcoms dagger lands beside you",
8, 0, 29,
"You hear a swish and look down to notice a sceptor in your leg",
" ", 5, 0, 2, " ", " ",
"Suddenly out from a tree comes Malcom and takes you by surprise",
23, 0, "dagger",
"Bear", 5, 5, 0, 1, 0,
"The bear's massave claw rips the skin on your arm.",
"The bear hugs you so tigthly you lose your breath.  Struggling you break free.",
"A crunch tells you the bear nearly shattered your knee.",
"Ahead of you on the path stands a large Brown Bear on his hind legs growling.",
"The bear loses it's balance and falls to the ground.",
"With luck, you dodge the bear's forceful attack.",
"Quickness keeps you ahead of the bear's razor sharp teeth.", 0, 0, 26," "," ",
6, 0, 2," "," ",
"From the bushes run and huge Brown Bear, you draw your weapon.", 0, 1, "Very big hands",
"Pirate", 4, 4, 0, 2, 2,
"The Pirate's short sword slash takes you completely by surprise.",
"A deep cut from his short sword lands in your arm.",
"The Pirate thrusts his short sword deep in your gut.",
"Ahead, you see a pirate in torn and worn out cloths.  You greet him.",
"You spin the priate around.",
"You jump away from his attack",
"This guy is a imbecile, he didn't even try to hit you.",
0, 0, 30, " ", " ", 30000, 0, 3, " ", " ", " ", 23, 0, "Short Sword",
"Wolf Pirate", 6, 7, 10, 3, 2,
"The Pirate's sword cuts deep in your chest.",
"The Pirate's sword cuts deep in your chest.",
"He slashes his sword across you leg.",
"Ahead is a rebel pirate of the infamous wolf band.",
"The pirate misses in his attack by a long shot.",
"The guy swings furiously but doesn't even come close.",
"You laugh at the way he clumsily swings past you.",
0, 0, 32, " ", " ", 5, 10, 1,
"You hear a spear sizzle through the air.  It pierces you in the chest.",
"You see a spear rocket through the air right past you.",
"Out from the bushes, a rebel wolf pirate appears.  You doesn't look freindly.",
29, 0, "Pirate sword",
"Wolfman", 10, 6, 0, 3, 1,
"Wolfman gnaws some meat from your arm.",
"You shrick in agony as the Wolfman nearly bites your hand off.",
"The Wolfman kicks your knee and shatters the bone.",
"A half-man, half-wolf stares at you from down the path.",
"Wolfman's attack flies past you just missing you.",
"Wolfman grabs you but you get loose.",
"You quickly dodge one of Wolfman's attempt to bite you.",
0, 0, 22, " ", " ", 30000, 0, 0, " ", " ", " ", 0, 1, "Claws",
"Royal Wolf Pirate", 7, 7, 0, 5, 1,
"The Pirate's sword cuts deep in your chest.",
"The Pirate's sword cuts deep in your chest.",
"He slashes his sword across you leg.",
"Ahead is a rebel pirate of the infamous wolf band.",
"The pirate misses in his attack by a long shot.",
"The guy swings furiously but doesn't even come close.",
"You laugh at the way he clumsily swings past you.",
0, 0, 30, " ", " ", 4, 0, 1, " ", " ",
"A nicely dressed pirate jumps out in front of you.",
25, 0, "Long Sword",
"Wild Boar", 4, 5, 0, 1, 1,
"The Boar charges and knocks you on your butt.",
"The Boar kicks and nearly breaks your knee.",
"A strong kick to the groan paralyzes you for a moment.",
"Ahead you see a Wild Boar running down the path.",
"You throw the Boar on it's back.",
"You kick the Boar away for this round.",
"It seems all too easy to dodge the Boar's attack.",
0, 0, 18, " ", " ", 5, 0, 2, " ", " ",
"You hear a sound behind you.  You turn only to stare down a Wild Boar.", 0, 0, "A pig snout",
"Gremlin", 6, 5, 0, 3, 1,
"The little gremlin shows amazing quickness in striking you knee.",
"He pulls a knife from his overalls and stabs your knee.",
"The Gremlin jumps on your leg biting and clawing.",
"Below you is a little gremlin in overalls.  It doesn't look cuddly",
"You kick the gremlin back for this round",
"You step back from the gremlin's attack",
"He just stares at you for awhile",
0, 0, 25, " ", " ", 30000, 0, 1, " ", " ", " ", 10, 0, "Teeth",
"Red Parrot", 4, 6, 0, 3, 2,
"The Parrot pecks your eye.",
"You are attacked by a fluttering of wings.",
"The Parrot claws and pecks your forehead.",
"You notice a red bird following you.  It finally comes down to meet you.",
"The parrot doesn't attack.",
"You grab the parrot and retire its attack.",
"You grab the parrot and keep it from attacking.",
0, 0, 25, " ", " ", 4, 0, 2, " ", " ",
"A Red Parrot swoops down from the sky and takes you by surprise.", 0, 0, "Claws",
"Thief", 5, 4, 0, 3, 1,
"\"I want your money!\" he yells as he strikes you.",
"He thrusts his mace into your chest.",
"Your skull cracks as his mace crashes into your head.",
"Ahead is a man in a black suit.",
"You push the thief back.",
"You block the thief's attack.",
"You dodgethe thief's attack.",
0, 0, 35, " ", " ", 30000, 0, 3, " ", " ", " ", 65, 0, "Mace"};









int main()
{
int a;
a = (sizeof(struct monsters)*10);
cout << "Writing "<< a << " bytes.";
handle=open("theden.dat",O_RDWR|O_BINARY);
write(handle,denjun,(sizeof(struct monsters)*10));
return 0;
}
