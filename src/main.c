#include <stdio.h>
#include <stdlib.h>
#include "kbase.h"
#include "suwako.h"
#include "kanako.h"

/*	--	game	--	*/
typedef struct gmem 
{
	kanako suwa_pool;
	suwako objlist[0x400];
} gmem;

/*	--	vars	--	*/
u8 fcmem[ MBSIZE(4) ];
gmem *gram = NULL;

int main(void)
{
	// init
	gram = (gmem*)fcmem;
	kanako *suwa_pool = kanako_init(&gram->suwa_pool,gram->objlist,0x400);
	// main
	for(u32 i=0; i<4; i++) printf("objs[%d]: %p\n",i,&suwa_pool->objs[i]);
}

