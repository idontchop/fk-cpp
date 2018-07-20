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

struct monsters dragon[5] = {"Green Dragon", 16, 15, 15, 10, 6,
"You feel burning heat as the dragon's claw rakes across your neck.",
"The dragon's wing crashes into you knocking you hard to the ground.",
"Two teeth dig into your shoulder.",
"Far into the cave, you spot a Green Dragon.  He sees you, too.",
"You take off running and keep the dragon from hitting you.",
"You roll into a small hole to dodge the dragon's attack.",
"You shove your weapon into the dragon's mouth to keep him from biting.",
25, 18, 120,
"The Green dragon opens his mouth and unleashes a burning stream of fire.",
"The Dragon's tail wipes around and collides with your arm.", 8, 20, 0,
"A large fireball consumes your body.",
"A large fireball flies over your head and collides with the cave wall.",
"A Green Dragon drops down from a high-up passage.", 0, 2, "Fire",
"Red Dragon", 18, 15, 15, 8, 6,
"You feel burning heat as the dragon's claw rakes across your neck.",
"The dragon's wing crashes into you knocking you hard to the ground.",
"Two teeth dig into your shoulder.",
"Far into the cave, you spot a Red Dragon.  He sees you, too.",
"You take off running and keep the dragon from hitting you.",
"You roll into a small hole to dodge the dragon's attack.",
"You shove your weapon into the dragon's mouth to keep him from biting.",
75, 20, 150, "Fire from the dragon's mouth engulfs you.",
"The Red Dragon wraps your body with burning claws.", 10, 30, 0,
"A large fireball consumes your body.",
"A large fireball flies over your head and collides with the cave wall.",
"You turn around to discover a Red Dragon.", 0, 2,"Fire",
"Yellow Dragon", 14, 20, 12, 9, 6,
"You feel burning heat as the dragon's claw rakes across your neck.",
"The dragon's wing crashes into you knocking you hard to the ground.",
"Two teeth dig into your shoulder.",
"Far into the cave, you spot a Yellow Dragon.  He sees you, too.",
"You take off running and keep the dragon from hitting you.",
"You roll into a small hole to dodge the dragon's attack.",
"You shove your weapon into the dragon's mouth to keep him from biting.",
20, 0, 110, "A small stream of fire consumes you.", " ", 10, 20, 0,
"A large fireball consumes your body.",
"A large fireball flies over your head and collides with the cave wall.",
"A Yellow Dragon drops down from a high-up passage.", 0, 2,"Fire",
"Three-headed Dragon",19, 20, 20, 12, 6,
"Three claws on three hands rake across your neck.",
"One head nearly takes your hand off.",
"The dragon's wing knocks you to the ground.",
"It is the fearsome Three-headed Dragon!  Say some prayers.",
"You roll away from the dragon's claws.",
"You roll away from the dragon's claws.",
"You roll into a small hole to dodge the dragon's attack.", 110, 40, 205,
"From all three heads come a stream of fire.",
"All three heads close in and bite you at the waist.", 30000, 40, 0,
"Three fireballs meet at your face.",
"You see three fireballs fly through the air, luckily missing you.", " ", 0, 2, "Fire",
"Baby Dragon", 9, 8, 0, 6, 6,
"You feel burning heat as the dragon's claw rakes across your neck.",
"The dragon's wing crashes into you knocking you hard to the ground.",
"Two teeth dig into your shoulder.",
"Far into the cave, you spot a Baby Dragon.  He sees you, too.",
"You take off running and keep the dragon from hitting you.",
"You roll into a small hole to dodge the dragon's attack.",
"You shove your weapon into the dragon's mouth to keep him from biting.",
0, 0, 70, " ", " ", 6, 0, 5, " ", " ",
"A Baby dragon has snuck up on you.", 0, 2, "Claws"};

int main()
{
int a;
a = (sizeof(struct monsters)*5);
cout << "Writing "<< a << "bytes.";
handle=open("dragon.dat",O_WRONLY|O_BINARY);
write(handle,dragon,(sizeof(struct monsters)*5));
return 0;
}
