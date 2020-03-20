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
gmem *gram = (gmem*)fcmem;

int main(void)
{
	printf("pntr size: %04lX\n",sizeof(void*));
	printf("suwako size: $%04lX\n",sizeof(suwako));
	kanako *suwa_pool = kanako_init(&gram->suwa_pool,gram->objlist,0x400);
	for(u32 i=0; i<4; i++) printf("objs[%d]: %p\n",i,&suwa_pool->objs[i]);

	printf("first: %d\n",suwa_pool->first);
	kanako_updt(suwa_pool);
	printf("first: %d\n",suwa_pool->first);
	
	{ u32 h; scanf("%d",&h); }

}

