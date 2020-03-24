#include <stdio.h>
#include <stdlib.h>
#include "kbase.h"
#include "suwako.h"
#include "kanako.h"
/*	--	game	--	*/
typedef struct gmem 
{
	kanako suwa;
	suwako objlist[0x100];
} gmem;

/*	--	vars	--	*/
u8 fcmem[ KBSIZE(8) ];
gmem *gram = NULL;

int main(void)
{
	// init
	gram = (gmem*)fcmem;
	kanako *suwa = kanako_init(&gram->suwa,gram->objlist,0x100);
	// main
	for(u32 i=0; i<4; i++) printf("objs[%d]: %p\n",i,&suwa->objs[i]);
}

