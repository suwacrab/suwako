#include <stdio.h>
#include <stdlib.h>
#include "kbase.h"
#include "suwa_obj.h"

/*	--	game	--	*/
typedef struct gmem 
{
	obj_pool suwa_pool;
	suwa_obj objlist[0x400];
} gmem;

/*	--	vars	--	*/
u8 fcmem[ MBSIZE(4) ];
gmem *gram = (gmem*)fcmem;

int main(void)
{
	printf("pntr size: %04lX\n",sizeof(void*));
	printf("suwa_obj size: $%04lX\n",sizeof(suwa_obj));
	obj_pool *suwa_pool = obj_pool_init(&gram->suwa_pool,gram->objlist,0x400);
	for(u32 i=0; i<4; i++) printf("objs[%d]: %p\n",i,&suwa_pool->objs[i]);

	printf("first: %d\n",suwa_pool->first);
	obj_pool_updt(suwa_pool);
	printf("first: %d\n",suwa_pool->first);
	
	{ u32 h; scanf("%d",&h); }
}

