#include <stdio.h>
#include <io.h>
#include <fcntl.h>

#define FALSE 0                               /* Boolean constant definitions */
#define TRUE !FALSE
#define MAYBE 2


struct _joke
{
char name[40];
char warning[80];
char sex;
char photkey;	//hotkey for playing joke
char ahotkey;
char astring[80];
int aexp;
int expreturn;
int ahonor;
char sstring[80];
int sexp;
int shonor;
char aname[50];
char shit;
char slog[140];
char alog[140];
char sucret[80];
char unsret[80];
char food;
};

struct _joke joke[11] = {"Exploding envelope",
"It appears there is something more than a letter in here.",
'A',
'b',
'a',
"Holding the envelope away from you, a nasty explosion rocks out.",
10,
10,
0,
"A powerful magical explosion rocks your body.  OUCH!  That really hurt.",
-10,
0,
"Open envelope away",
99,
"~13%s~15 has tricked ~13%s~15 into opening an exploding envelope!",
"~13%s~15 has foiled ~13%s~15's plan of sabotaging the mail with explosives.",
"Your exploding envelope against %s was successful.",
"Your exploding envelope against %s did not work.",
0,
"Stinking envelope",
"It appears there is something more than a letter in here.",
'A',
's',
'u',
"You open the envelope under a small creek and remove the letter.",
10,
10,
0,
"From the envelope comes the worst smell of your life!  This will haunt you.",
-5,
-1,
"Open envelope underwater",
0,
"~13%s~15 has changed the way ~13%s~15 smells.",
"~13%s~15 has discovered ~13%s~15's rotten eggs for breakfast.",
"Your rotten envelope against %s was successful.",
"Your stinking envelope against %s was unsuccessful.",
0,
"Sticky envelope",
"The color of this envelope looks awfully strange.",
'A',
'i',
'r',
"You run your sword through the end of the envelope and remove the letter.",
10,
10,
1,
"The envelope seems stuck to your hand, this'll take a day to get off.",
-10,
-2,
"Rip letter out with sword",
0,
"~13%s~15 gave ~13%s~15 a sticky envelope who was badly embarrassed!",
"~13%s~15 has seen through ~13%s~15's plan of a sticky envelope.",
"Your gluey envelope sent to %s succeeded.",
"Your sticky envelope plan against %s was avoided.",
0,
"Maggots and flies",
"It appears there is something more than a letter in here.",
'A',
'm',
's',
"You jump on and squash the envelope drastically before opening.",
10,
10,
0,
"Maggots and flies pour out the envelope and eat your food!",
-10,
-1,
"Squash envelope",
0,
"~13%s~15 gave ~13%s~15 an envelope full of maggots that ate all the food.",
"~13%s~15 killed all the maggots hidden in ~13%s~15's envelope.",
"The flies against %s ate his food.",
"The flies against %s were squished.",
4,
"","",'A',
0,
0,
"",
0,
0,
0,
"",
0,
0,
"",
0,
"",
"",
"","",
0,
"","",'A',
0,
0,
"",
0,
0,
0,
"",
0,
0,
"",
0,
"",
"","","",
0,
"","",'A',
0,
0,
"",
0,
0,
0,
"",
0,
0,
"",
0,
"",
"","","",
0,
"","",'A',
0,
0,
"",
0,
0,
0,
"",
0,
0,
"",
0,
"",
"","","",
0,
"","",'A',
0,
0,
"",
0,
0,
0,
"",
0,
0,
"",
0,
"",
"","","",
0,
"","",'A',
0,
0,
"",
0,
0,
0,
"",
0,
0,
"",
0,
"",
"","","",
0,
"Default Joke File", //settings structure.
"",'A',
FALSE,
'r',
"Would you like to put a joke in the envelope?",
's',
0,
0,
"You can detect something within the envelope, do you...",
0,
0,
"",
0,
"","","","",0};

void main()
{
int handle,a;
handle=open("joke.dat",O_WRONLY|O_BINARY);
a=(sizeof(struct _joke)*11);
printf("Writing %d bytes.",a);
write(handle,joke,(sizeof(struct _joke)*11));
close(handle);
}





