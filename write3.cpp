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

struct monsters farm[8] = {"Farm Owner", 4, 4, 0, 3, 0,
"With a swift kick, the wind is knocked out of you.",
"His mace digs into your arm",
"Blood gushes from your side as his mace digs deep in your gut",
" ",
"You sweep him down and retire his attack",
"You jump back and his mace slings through the air",
"Excellent agility keeps you ahead of him",
0, 0, 25, " ", " ", 0, 0, 0, " ", " ",
"You must have awakened the farm owner.  He looks mad.", 5, 0, "Mace",
"Farm Hand", 3, 2, 0, 3, 0,
"A mace swings and busts your skull",
"The farm hand trips you and brings the but of his mace to your face",
"The farm hand nearly crushes your knee with his mace",
" ",
"You easily evade his attack",
"You easily evade his attack",
"You jump back from the farm hand's attack",
0, 0, 18, " ", " ", 0, 0, 0, " ", " ",
"A Farm hand appears from among the cows", 4, 0, "Mace",
"Farm Owner", 6, 7, 0, 3, 3,
"With a swift kick, the wind is knocked out of you.",
"His mace digs into your arm",
"Blood gushes from your side as his mace digs deep in your gut",
" ",
"You sweep him down and retire his attack",
"You jump back and his mace slings through the air",
"Excellent agility keeps you ahead of him",
0, 0, 40, " ", " ", 0, 0, 0, " ", " ",
"You must have awakened the farm owner.  He looks mad.", 25, 0, "Mace",
"Farm Hand", 5, 4, 0, 3, 2,
"A mace swings and busts your skull",
"The farm hand trips you and brings the but of his mace to your face",
"The farm hand nearly crushes your knee with his mace",
" ",
"You easily evade his attack",
"You easily evade his attack",
"You jump back from the farm hand's attack",
0, 0, 38, " ", " ", 0, 0, 0, " ", " ",
"A Farm hand appears from among the cows", 12, 0, "Mace",
"Farm Owner", 7, 8, 0, 5, 3,
"With a swift kick, the wind is knocked out of you.",
"His Long Sword digs into your arm",
"Blood gushes from your side as his Long Sword digs deep in your gut",
" ",
"You sweep him down and retire his attack",
"You jump back and his Long Sword slings through the air",
"Excellent agility keeps you ahead of him",
0, 0, 55, " ", " ", 0, 0, 0, " ", " ",
"You must have awakened the farm owner.  He looks mad.", 25, 0, "Long Sword",
"Farm Hand", 6, 7, 0, 3, 3,
"A mace swings and busts your skull",
"The farm hand trips you and brings the but of his mace to your face",
"The farm hand nearly crushes your knee with his mace",
" ",
"You easily evade his attack",
"You easily evade his attack",
"You jump back from the farm hand's attack",
0, 0, 48, " ", " ", 0, 0, 0, " ", " ",
"A Farm hand appears from among the cows", 4, 0, "Mace",
"Farm Owner", 12, 13, 0, 6, 4,
"With a swift kick, the wind is knocked out of you.",
"His axe digs into your arm",
"Blood gushes from your side as his axe digs deep in your gut",
" ",
"You sweep him down and retire his attack",
"You jump back and his axe slings through the air",
"Excellent agility keeps you ahead of him",
0, 0, 85, " ", " ", 0, 0, 0, " ", " ",
"You must have awakened the farm owner.  He looks mad.", 5, 0, "Axe",
"Farm Hand", 10, 11, 0, 3, 4,
"A mace swings and busts your skull",
"The farm hand trips you and brings the but of his mace to your face",
"The farm hand nearly crushes your knee with his mace",
" ",
"You easily evade his attack",
"You easily evade his attack",
"You jump back from the farm hand's attack",
0, 0, 58, " ", " ", 0, 0, 0, " ", " ",
"A Farm hand appears from among the cows", 4, 0, "Mace"};

int main()
{
int a;
a = (sizeof(struct monsters)*8);
cout << "Writing "<< a << "bytes.";
handle=open("farm.dat",O_RDWR|O_BINARY);
write(handle,farm,(sizeof(struct monsters)*8));
return 0;
}