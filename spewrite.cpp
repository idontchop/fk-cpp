#include <stdio.h>
#include <fcntl.h>
#include <io.h>

struct special{
char name[20];
char magic;
};

struct special sp[20] = {"Mystical Heal", 1,
"Bolt of Fire", 2,
"Fast Action Attack",3,
"Bum Rush",3,
"Great Heal",12,
"Vanish",3,
"Banish",7,
"Taunt",4,
"Deform",9,
"Smite Foe",20,
"Drain",10,
"Armageddon",20,
"Scissor Kick",10,
"",0,
"",0,
"",0,
"",0,
"",0,
"",0,
"",0};

void main()
{
int handle;
handle = open("special.dat",O_BINARY|O_WRONLY);
write(handle,sp,(sizeof(struct special)*20));
close(handle);
}
